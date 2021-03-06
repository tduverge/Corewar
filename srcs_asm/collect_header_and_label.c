/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   collect_header_and_label.c                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/23 14:45:16 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/23 17:34:42 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/asm.h"

void			collect_header_and_label(t_label **label, header_t *header, t_infos infos)
{
	int		i;
	int		step;

	i = 0;
	step = 0;
	while (infos.file[i])
	{
		i = to_the_next_char(infos.file, i);
		if (infos.file[i] && infos.file[i] != '\n' && infos.file[i] != COMMENT_CHAR)
		{
			i = step == 0 ? collect_name(header, infos.file, i) : i;
			i = step == 1 ? collect_comment( header, infos.file, i) : i;
			i = step == 2 ? collect_label(label, infos.file, i) : i;
			step == 0 || step == 1 ? step++ : 0;
		}
		else
			i = to_the_next_line(infos.file, i);
	}
}
