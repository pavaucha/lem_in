/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lezhang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 14:21:50 by lezhang           #+#    #+#             */
/*   Updated: 2018/10/10 03:21:24 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int		check_salle(char *str)
{
	char		**temp;
	int			j;
	int			error;

	if (!str || !ft_strchr(str, ' '))
		return (1);
	j = 0;
	error = 1;
	temp = ft_strsplit(str, ' ');
	while (temp[j])
		j++;
	if (j == 3 && temp[0][0] != '#' && temp[0][0] != 'L' &&
		ft_strnum(temp[1]) && ft_strnum(temp[2]) && !ft_strchr(temp[0], '-'))
		error = 0;
	ft_strdel_tab(&temp);
	return (error);
}

int		check_tube(char *str)
{
	char		**temp;
	int			j;
	int			error;

	if (!str || !ft_strchr(str, '-'))
		return (1);
	j = 0;
	error = 1;
	temp = ft_strsplit(str, '-');
	while (temp[j])
		j++;
	if (j == 2)
		error = 0;
	ft_strdel_tab(&temp);
	return (error);
}

void	get_salle(t_lem *lem, char *str, int pos)
{
	int		i;
	char	**temp;

	temp = ft_strsplit(str, ' ');
	i = lem->curr_salle;
	lem->salles[i].nom = ft_strdup(temp[0]);
	lem->salles[i].x = ft_atoi(temp[1]);
	lem->salles[i].y = ft_atoi(temp[2]);
	lem->salles[i].nb_tube = 0;
	lem->salles[i].fourmie_b = 0;
	lem->salles[i].fourmie_a = 0;
	lem->salles[i].used = (pos == 1 || pos == 2) ? -1 : 0;
	lem->curr_salle++;
	if (pos == 1 && lem->nom_start == NULL)
		lem->nom_start = ft_strdup(temp[0]);
	if (pos == 2 && lem->nom_end == NULL)
		lem->nom_end = ft_strdup(temp[0]);
	ft_strdel_tab(&temp);
}

int		check_diese(char *str, t_lem *lem, int *i)
{
	int		start_end_pos[3];

	if (is_comment(str))
		return (0);
	start_end_pos[0] = ft_strcmp("##start", str);
	start_end_pos[1] = ft_strcmp("##end", str);
	start_end_pos[2] = 0;
	if (!start_end_pos[0] || !start_end_pos[1])
	{
		start_end_pos[2] = (!start_end_pos[0]) ? 1 : 2;
		(*i)++;
		if (lem->file[(*i)])
		{
			while (lem->file[(*i)] && lem->file[(*i)][0] == '#' &&
				is_comment(lem->file[(*i)]))
				(*i)++;
			if (lem->file[(*i)])
				get_salle(lem, lem->file[(*i)], start_end_pos[2]);
		}
		else
			return (1);
	}
	return (0);
}

int		check_space(char *str)
{
	if (str[0] == ' ' || str[0] == '\t' || str[0] == '\n')
		return (1);
	return (0);
}
