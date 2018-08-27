/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main_asm.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/23 13:27:31 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/23 16:22:39 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/asm.h"

t_op    op_tab[16] =
{
	{"live", 1, {T_DIR}, 1, 10, 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6, 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6, 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6, 1, 0},
	{"zjmp", 1, {T_DIR}, 9, 20, 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25, 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25, 1, 1},
	{"fork", 1, {T_DIR}, 12, 800, 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50, 1, 1},
	{"lfork", 1, {T_DIR}, 15, 1000, 0, 1},
	{"aff", 1, {T_REG}, 16, 2, 1, 0},
};

static int	check_args(int ac, char **av, char *option, char **path)
{
	if (ac < 2)
		return (0);
	if (!ft_strcmp(av[1], "-a") && ac == 3)
	{
		*option = 1;
		*path = av[2];
		return (!ft_strcmp(av[2] + ft_strlen(av[2]) - 2, ".s") ? 1 : 0);
	}
	*option = 0;
	*path = av[1];
	return (ac == 2 && !ft_strcmp(av[1] + ft_strlen(av[1]) - 2, ".s") ? 1 : 0);
}

static int	usage(void)
{
	ft_printf("Usage: ./exe_asm [-a] <sourcefile.s>\n");
	ft_printf("\t-a : Instead of creating a .cor file, outputs a stripped ");
	ft_printf("and annotated version of the code to the standard output\n");
	return (0);
}

static char		*recup_file(char *path, int i)
{
	int		fd;
	char	line[50];
	char	*file;
	int		ret;
	char	*tmp;

	fd = open(path, O_RDONLY);
	file = NULL;
	while ((ret = read(fd, &line, 50)) > 0)
	{
		tmp = file;
		file = ft_memalloc(i + ret);
		if (tmp)
			ft_memcpy(file, tmp, i);
		ft_memcpy(file + i, line, ret);
		i += ret;
		if (tmp)
			free(tmp);
	}
	return (file);
}

int			main(int ac, char **av)
{
	t_label		*label;
	t_cmd		*cmd;
	header_t	header;
	t_infos		infos;

	if (!check_args(ac, av, &(infos.option), &(infos.path)))
		return (usage());
	infos.file = recup_file(infos.path, 0);
	collect_header_and_labels(&label, &header, infos);
	collect_instructions(label, &cmd, infos);
	if (!infos.option)
		write_cor(label, cmd, header, infos);
	else
		write_output(label, cmd, header, infos);
	return (free_all(label, cmd, infos));
}
