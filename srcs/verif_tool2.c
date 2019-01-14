/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_tool2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lezhang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 14:40:56 by lezhang           #+#    #+#             */
/*   Updated: 2018/10/18 17:47:55 by lezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int		get_option(int argc, char **argv)
{
	if (argc > 1)
	{
		if (!ft_strcmp("-e", argv[1]))
			return (1);
		else if (!ft_strcmp("-p", argv[1]))
			return (2);
	}
	return (0);
}

int		is_comment(char *str)
{
	if (!ft_strcmp("##start", str) || !ft_strcmp("##end", str))
		return (0);
	return (1);
}

void	count_salle_tube(t_lem *lem)
{
	int		i;

	i = -1;
	if (lem->file == NULL)
		return ;
	while (lem->file[++i])
	{
		if (lem->file[i][0] == '#')
			continue ;
		else if (!check_salle(lem->file[i]))
			lem->nbs++;
		else if (!check_tube(lem->file[i]))
			lem->nbt++;
	}
}
