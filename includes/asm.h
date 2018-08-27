/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   asm.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/23 14:22:31 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/23 17:39:29 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../libft/header/libft.h"
# include "op.h"
# include <fcntl.h>

/*
** STRUCTURES
*/

typedef struct		s_label
{
	char			*name;
	int				add;
	struct s_label	*next;
}					t_label;

typedef struct		s_cmd
{
	char			opcode;
	char			bytecode;
	char			*param[3];
	struct s_cmd	*next;
}					t_cmd;

typedef struct		s_op
{
	char			*name;
	int				nb_arg;
	int				arg[3];
	char			opcode;
	int				time;
	char			codage;
	char			dir_size;
}					t_op;

typedef struct		s_infos
{
	char			*path;
	char			*file;
	char			option;
}					t_infos;

/*
** COLLECT
*/

void				collect_header_and_label(t_label **label, header_t *header, t_infos infos);
int					collect_name(header_t *header, char *file, int i);

/*
** OUTILS DIVERS
*/

int					start_by(char *str, char *name);
int					to_the_next_char(char *str, int i);
int					to_the_next_line(char *str, int i);
void				give_coline(char *str, int i, int *tab);

#endif
