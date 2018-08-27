/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   start_by.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/23 17:20:58 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/23 17:21:02 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/asm.h"

int		start_by(char *str, char *name)
{
	int		i;

	if (ft_strlen(str) < ft_strlen(name))
		return (0);
	i = 0;
	while (i < ft_strlen(name))
	{
		if (name[i] != str[i])
			return (0);
		i++;
	}
	return (1);
}

