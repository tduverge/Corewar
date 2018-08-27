/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   collect_name.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/23 15:31:41 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/23 17:45:35 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/asm.h"

static int		error(char *file, int i)
{
	int		coline[2];

	give_coline(file, i, coline);
	ft_printf("Lexical error at [%d:%d]", coline[0], coline[1]);
	ft_strdel(&file);
	exit(1);
	return (0);
}

static int		write_the_name(char *file, int i, header_t header)
{
	int		j;

	j = 0;
	while (file[i] && file[i] != '"' && j < PROG_NAME_LENGHT)
	{
	}
	return (i);
}

int				collect_name(header_t *header, char *file, int i)
{
	if (!start_by(file + i, NAME_CMD_STRING))
		return (error(file, i));
	i += ft_strlen(NAME_CMD_STRING);
	i = to_the_next_char(file, i);
	if (file[i] != '"')
		return (error(file, i));
	return (i);
}
