/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 13:47:51 by pavaucha          #+#    #+#             */
/*   Updated: 2018/10/19 17:02:25 by lezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static void	check_salle_used(char **tmp, t_lem *lem, int *j)
{
	int		k;

	while (tmp[(*j)])
	{
		k = 0;
		while (k < lem->nbs)
		{
			if (ft_strcmp(lem->salles[k].nom, tmp[(*j)]) == 0 &&
				lem->salles[k].used == 1)
			{
				k = 0;
				break ;
			}
			k++;
		}
		if (k == lem->nbs)
			(*j)++;
		else
		{
			(*j) = 0;
			break ;
		}
	}
}

static char	**creat_n_path(char **path, int count, t_lem *lem)
{
	char	**str;
	int		i;
	int		j;
	int		k;
	char	**tmp;

	k = 0;
	i = -1;
	j = 0;
	if (count == 0)
		return (NULL);
	str = (char**)malloc(sizeof(char*) * (count + 1));
	str[count] = 0;
	while (path[++i])
	{
		j = 0;
		tmp = ft_strsplit(path[i], '-');
		check_salle_used(tmp, lem, &j);
		if (j != 0 && ft_strcmp(tmp[j - 1], lem->nom_end) == 0)
			str[k++] = ft_strdup(path[i]);
		ft_strdel_tab(&tmp);
	}
	return (str);
}

static int	ft_count(char **path, t_lem *lem)
{
	int		i;
	int		j;
	char	**tmp;
	int		count;

	count = 0;
	i = 0;
	while (path[i])
	{
		j = 0;
		tmp = ft_strsplit(path[i], '-');
		check_salle_used(tmp, lem, &j);
		if (j != 0 && ft_strcmp(tmp[j - 1], lem->nom_end) == 0)
			count++;
		ft_strdel_tab(&tmp);
		i++;
	}
	return (count);
}

static char	**change_path(char **path, char *str, t_lem *lem)
{
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	tmp = ft_strsplit(str, '-');
	while (tmp[i])
	{
		j = 0;
		while (j < lem->nbs)
		{
			if (ft_strcmp(lem->salles[j].nom, lem->nom_start) != 0
					&& ft_strcmp(lem->salles[j].nom, lem->nom_end) != 0
					&& ft_strcmp(lem->salles[j].nom, tmp[i]) == 0)
				lem->salles[j].used = 1;
			j++;
		}
		i++;
	}
	ft_strdel_tab(&tmp);
	tmp = creat_n_path(path, ft_count(path, lem), lem);
	ft_strdel_tab(&path);
	return (tmp);
}

void		choose_path(char **path, t_lem *lem)
{
	int		i;
	int		k;
	int		j;
	char	**tmp;

	i = -1;
	j = nb_path(lem);
	tmp = (char**)malloc(sizeof(char*) * (j + 1));
	tmp[j] = 0;
	while (++i < j)
	{
		k = get_path_length(path);
		tmp[i] = ft_strdup(path[k]);
		path = change_path(path, tmp[i], lem);
		if (path == NULL)
			break ;
	}
	if (path != NULL)
		ft_strdel_tab(&path);
	printlem(*lem);
	print_fourmie(tmp, lem);
}
