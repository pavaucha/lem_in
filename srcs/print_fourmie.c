/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fourmie.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 22:58:39 by pavaucha          #+#    #+#             */
/*   Updated: 2018/10/18 17:52:25 by lezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static int	finish_print(t_lem *lem, char **path)
{
	int		i;
	int		j;
	int		l;
	char	**tmp;

	i = -1;
	while (path[++i])
	{
		j = -1;
		tmp = ft_strsplit(path[i], '-');
		while (tmp[++j])
		{
			l = 0;
			while (ft_strcmp(tmp[j], lem->salles[l].nom) != 0)
				l++;
			if (ft_strcmp(tmp[j], lem->salles[l].nom) == 0 &&
				lem->salles[l].used == 1)
			{
				ft_strdel_tab(&tmp);
				return (0);
			}
		}
		ft_strdel_tab(&tmp);
	}
	return (1);
}

static int	path_exist_two(char **path, char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (path[i])
	{
		if (ft_strcmp(path[i], str) == 0)
			count++;
		i++;
	}
	return (count);
}

static void	print_fourmie3(t_lem *lem, char **tmp, int j, int l)
{
	int		k;

	k = -1;
	while (ft_strcmp(lem->salles[l].nom, tmp[j - 1]) != 0)
		l++;
	while (lem->nbs > ++k)
	{
		if (ft_strcmp(lem->salles[k].nom, lem->nom_end) == 0)
			lem->salles[k].used = 0;
		else
		{
			if (lem->salles[l].used == 0 &&
				ft_strcmp(lem->salles[k].nom, tmp[j]) == 0)
				lem->salles[k].used = 0;
			if (ft_strcmp(tmp[j], lem->salles[k].nom) == 0 &&
				lem->salles[k].fourmie_b != 0)
			{
				if (lem->salles[k].fourmie_a == lem->salles[l].fourmie_a)
					lem->salles[l].used = 0;
				lem->salles[k].used = 1;
				lem->salles[k].fourmie_a = lem->salles[k].fourmie_b;
				lem->salles[k].fourmie_b = 0;
			}
		}
	}
}

static void	print_fourmie2(char **path, t_lem *lem, int i)
{
	int		j;
	char	**tmp;
	int		k;

	j = 0;
	tmp = ft_strsplit(path[i], '-');
	if (path_exist_two(path, path[i]) > 1)
	{
		avance_fourmie(tmp, lem);
		if (lem->nbf > 0 && path[i + 1])
			ft_printf("\n");
	}
	else
		avance_fourmie(tmp, lem);
	while (tmp[++j + 1])
		print_fourmie3(lem, tmp, j, 0);
	if (lem->nbf == 0)
	{
		k = 0;
		while (ft_strcmp(lem->salles[k].nom, lem->nom_start) != 0)
			k++;
		lem->salles[k].used = 0;
	}
	ft_strdel_tab(&tmp);
}

void		print_fourmie(char **path, t_lem *lem)
{
	int		i;

	i = -1;
	while (++i < lem->nbs)
		lem->salles[i].used = 0;
	while (1)
	{
		i = 0;
		while (path[i])
		{
			print_fourmie2(path, lem, i);
			i++;
		}
		ft_printf("\n");
		if (finish_print(lem, path) == 1)
			break ;
	}
	if (lem->option == 2)
	{
		i = -1;
		ft_putchar('\n');
		while (path[++i])
			ft_printf("path%d: %s\n", i + 1, path[i]);
	}
	ft_strdel_tab(&path);
}
