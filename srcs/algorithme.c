/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 12:21:23 by pavaucha          #+#    #+#             */
/*   Updated: 2018/10/18 17:43:41 by lezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static void		initialize_variable(int (*i)[2], char ***path, char **tmp,
		char ***dst)
{
	(*i)[0] = -1;
	(*i)[1] = 1;
	*path = NULL;
	*tmp = NULL;
	*dst = NULL;
}

static char		**malloc_path(int i, int j, char **path)
{
	char	**tmp;

	if (j > 1)
	{
		i = -1;
		if ((tmp = (char**)malloc(sizeof(char*) * (j + 1))) == NULL)
			return (NULL);
		while (path[++i])
			tmp[i] = ft_strdup(path[i]);
		ft_strdel_tab(&path);
		tmp[i] = 0;
	}
	if ((path = (char**)malloc(sizeof(char*) * (j + 1))) == NULL)
		return (NULL);
	if (j > 1)
	{
		i = -1;
		while (tmp[++i])
			path[i] = ft_strdup(tmp[i]);
		ft_strdel_tab(&tmp);
	}
	path[j] = 0;
	path[j - 1] = 0;
	return (path);
}

void			find_multi_path(t_lem *lem)
{
	int		i[2];
	char	**path;
	char	*tmp;
	char	**dst;

	initialize_variable(&i, &path, &tmp, &dst);
	while (1)
	{
		if ((path = malloc_path(i[0], i[1], path)) == NULL)
			return ;
		if ((path[i[1] - 1] = ft_find_path(lem, path, tmp, dst)) == NULL)
		{
			if (i[1] == 1)
			{
				ft_strdel_tab(&path);
				lem->error.no_path = 1;
				return ;
			}
			break ;
		}
		i[1]++;
	}
	while (++i[0] < lem->nbs)
		lem->salles[i[0]].used = 0;
	choose_path(path, lem);
}
