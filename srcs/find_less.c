/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_less.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lezhang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 17:29:52 by lezhang           #+#    #+#             */
/*   Updated: 2018/10/18 17:33:18 by lezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static char		**get_dst(t_lem *lem, char **dst, char **test, int (*i)[3])
{
	if (ft_strcmp(lem->nom_start, lem->salles[(*i)[1]].nom) != 0)
	{
		if ((*i)[2] > lem->salles[(*i)[1]].used)
		{
			if (dst)
				ft_strdel_tab(&dst);
			if ((dst = (char**)malloc(sizeof(char*) * 3)) == NULL)
				return (NULL);
			dst[2] = 0;
			(*i)[2] = lem->salles[(*i)[1]].used;
			dst[0] = ft_strdup(test[0]);
			dst[1] = ft_strdup(test[1]);
			return (dst);
		}
	}
	return (dst);
}

static char		**find_less(char *tmp, t_lem *lem, int f)
{
	char	**test;
	char	*str;
	char	**dst;
	int		i[3];

	i[0] = -1;
	i[2] = f;
	dst = NULL;
	while (lem->tube[++i[0]])
	{
		test = ft_strsplit(lem->tube[i[0]], '-');
		if ((ft_strcmp(test[0], tmp) == 0 || ft_strcmp(test[1], tmp) == 0))
		{
			i[1] = -1;
			str = (ft_strcmp(test[0], tmp) == 0) ?
				ft_strdup(test[1]) : ft_strdup(test[0]);
			while (++i[1] < lem->nbs)
				if (ft_strcmp(lem->salles[i[1]].nom, str) == 0)
					break ;
			dst = get_dst(lem, dst, test, &i);
			ft_strdel(&str);
		}
		ft_strdel_tab(&test);
	}
	return (dst);
}

char			**check_salle_find_less(t_lem *lem, char **dst, char *tmp,
		int (*j)[2])
{
	int		i;
	char	**temp;

	i = -1;
	(*j)[0] = -1;
	while (++i < lem->nbs)
	{
		if ((ft_strcmp(lem->salles[i].nom, dst[0]) == 0
			|| ft_strcmp(lem->salles[i].nom, dst[1]) == 0)
			&& ft_strcmp(lem->salles[i].nom, lem->nom_start) != 0
			&& ft_strcmp(lem->salles[i].nom, lem->nom_end) != 0)
		{
			i = lem->salles[i].used;
			break ;
		}
	}
	temp = find_less(tmp, lem, i);
	if (temp == NULL)
		return (dst);
	else
	{
		ft_strdel_tab(&dst);
		return (temp);
	}
}
