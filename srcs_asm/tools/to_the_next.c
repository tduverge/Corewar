/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   to_the_next.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/23 17:30:34 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/23 17:32:39 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/asm.h"

int				to_the_next_char(char *str, int i)
{
	while (((str[i] >= 9) && (str[i] <= 13)) || (str[i] == ' '))
				i++;
	return (i);
}

int				to_the_next_line(char *str, int i)
{
	while (str[i] && str[i] != '\n')
				i++;
	return (str[i] == '\n' ? i + 1 : i);
}
