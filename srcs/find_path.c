/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lezhang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 17:17:37 by lezhang           #+#    #+#             */
/*   Updated: 2018/10/18 17:32:46 by lezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static void		next_tube(t_lem *lem, char **str, char **tmp, int (*i)[2])
{
	if (*str)
		ft_strdel(str);
	if (*tmp)
		ft_strdel(tmp);
	*str = ft_strdup(lem->nom_start);
	*tmp = ft_strdup(lem->nom_start);
	(*i)[0] = (*i)[1];
	(*i)[1]++;
}

static void		initialize_variable(char **str, char **tmp, int (*i)[2],
		t_lem *lem)
{
	(*i)[0] = -1;
	(*i)[1] = 0;
	*str = ft_strdup(lem->nom_start);
	*tmp = ft_strdup(lem->nom_start);
}

static char		*free_find_path(char ***dst, char **str, char **tmp)
{
	if (*dst)
		ft_strdel_tab(dst);
	if (*str)
		ft_strdel(str);
	if (*tmp)
		ft_strdel(tmp);
	return (NULL);
}

static char		*path_found(char ***dst, char **tmp, char *str)
{
	ft_strdel_tab(dst);
	ft_strdel(tmp);
	return (str);
}

char			*ft_find_path(t_lem *lem, char **path, char *tmp, char **dst)
{
	char		*str;
	int			i[2];

	initialize_variable(&str, &tmp, &i, lem);
	while (lem->tube[++i[0]])
	{
		dst = ft_strsplit(lem->tube[i[0]], '-');
		if ((ft_strcmp(dst[0], tmp) == 0 || ft_strcmp(dst[1], tmp) == 0))
		{
			dst = check_salle_find_less(lem, dst, tmp, &i);
			if (get_str_path(lem, dst, &tmp, &str))
				break ;
			if (path_repete(str) == 1)
				next_tube(lem, &str, &tmp, &i);
			else if (path_end(str, &tmp, lem) == 1)
			{
				if (path_exist(str, path) == 1)
					next_tube(lem, &str, &tmp, &i);
				else
					return (path_found(&dst, &tmp, str));
			}
		}
		ft_strdel_tab(&dst);
	}
	return (free_find_path(&dst, &str, &tmp));
}
