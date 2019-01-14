/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_tool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lezhang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 12:17:12 by lezhang           #+#    #+#             */
/*   Updated: 2018/10/11 13:10:29 by lezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void			verif_salle(t_lem *lem)
{
	int		i;
	int		j;

	i = 0;
	while (i < lem->nbs - 1)
	{
		j = i + 1;
		while (j < lem->nbs)
		{
			if (!ft_strcmp(lem->salles[i].nom, lem->salles[j].nom))
			{
				lem->error.error = 1;
				lem->error.same_name = 1;
				return ;
			}
			j++;
		}
		i++;
	}
}

static int		check_salle_name(t_lem *lem, char *salle)
{
	int		i;
	int		check;

	i = 0;
	check = 0;
	while (i < lem->nbs)
	{
		if (!ft_strcmp(lem->salles[i].nom, salle))
		{
			check = 1;
			break ;
		}
		i++;
	}
	return (check);
}

static void		get_error_line(t_lem *lem, char *line)
{
	int		i;

	i = 0;
	lem->stop_line = 0;
	while (lem->file[i])
	{
		lem->stop_line = i + 1;
		if (!ft_strcmp(lem->file[i], line))
			break ;
		i++;
	}
}

static void		new_file(t_lem *lem)
{
	int		i;

	i = lem->stop_line - 1;
	while (lem->file[i])
	{
		ft_strdel(&lem->file[i]);
		i++;
	}
	lem->nbs = 0;
	lem->nbt = 0;
	count_salle_tube(lem);
}

void			verif_tube(t_lem *lem)
{
	int		i;
	char	**temp;
	int		comp;
	int		check[2];

	i = 0;
	while (i < lem->nbt)
	{
		temp = ft_strsplit(lem->tube[i], '-');
		comp = ft_strcmp(temp[0], temp[1]);
		check[0] = check_salle_name(lem, temp[0]);
		check[1] = check_salle_name(lem, temp[1]);
		if (!comp || !check[0] || !check[1])
		{
			lem->error.tube_salle = (!comp) ? 1 : 0;
			lem->error.salle_null = (!check[0] || !check[1]) ? 1 : 0;
			lem->error.error = 1;
			ft_strdel_tab(&temp);
			get_error_line(lem, lem->tube[i]);
			new_file(lem);
			return ;
		}
		ft_strdel_tab(&temp);
		i++;
	}
}
