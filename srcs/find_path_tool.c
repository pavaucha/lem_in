/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path_tool.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lezhang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 17:20:30 by lezhang           #+#    #+#             */
/*   Updated: 2018/10/18 17:33:42 by lezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int				path_repete(char *str)
{
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	tmp = ft_strsplit(str, '-');
	while (tmp[i + 1])
	{
		j = i + 1;
		while (tmp[j])
		{
			if (ft_strcmp(tmp[i], tmp[j]) == 0)
			{
				ft_strdel_tab(&tmp);
				return (1);
			}
			j++;
		}
		i++;
	}
	ft_strdel_tab(&tmp);
	return (0);
}

static void		unused_salle(t_lem *lem, char *tmp, char *s1, char *s2)
{
	int		i;
	char	*str;

	i = 0;
	if (ft_strcmp(tmp, s1) == 0)
		str = ft_strdup(s2);
	else
		str = ft_strdup(s1);
	while (ft_strcmp(lem->salles[i].nom, str) != 0)
		i++;
	if (lem->salles[i].used != -1)
		lem->salles[i].used++;
	ft_strdel(&str);
}

int				get_str_path(t_lem *lem, char **dst, char **tmp, char **str)
{
	char	*del;

	unused_salle(lem, *tmp, dst[1], dst[0]);
	del = *str;
	*str = ft_strjoin(*str, "-");
	ft_strdel(&del);
	del = *tmp;
	*tmp = (ft_strcmp(dst[0], *tmp) == 0) ?
		ft_strdup(dst[1]) : ft_strdup(dst[0]);
	ft_strdel(&del);
	if (ft_strcmp(*tmp, lem->nom_start) != 0)
	{
		del = *str;
		*str = ft_strjoin(*str, *tmp);
		ft_strdel(&del);
	}
	else
		return (1);
	return (0);
}

int				path_exist(char *str, char **path)
{
	int		i;

	i = 0;
	while (path[i])
	{
		if (ft_strcmp(path[i], str) == 0)
			return (1);
		i++;
	}
	return (0);
}

int				path_end(char *str, char **tmp, t_lem *lem)
{
	int		j;
	char	**dst;

	j = 0;
	dst = ft_strsplit(str, '-');
	while (dst[j])
		j++;
	if (ft_strcmp(dst[j - 1], lem->nom_end) == 0)
	{
		ft_strdel_tab(&dst);
		ft_strdel(tmp);
		return (1);
	}
	ft_strdel_tab(&dst);
	return (0);
}
