/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lezhang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 12:10:21 by lezhang           #+#    #+#             */
/*   Updated: 2018/10/08 14:38:49 by lezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static int		verif_same_tube(char *tube1, char *tube2)
{
	char		**temp1;
	char		**temp2;
	int			same;

	same = 0;
	temp1 = ft_strsplit(tube1, '-');
	temp2 = ft_strsplit(tube2, '-');
	if ((!ft_strcmp(temp1[0], temp2[0]) && !ft_strcmp(temp1[1], temp2[1])) ||
		(!ft_strcmp(temp1[0], temp2[1]) && !ft_strcmp(temp1[1], temp2[0])))
		same = 1;
	ft_strdel_tab(&temp1);
	ft_strdel_tab(&temp2);
	return (same);
}

static void		stock_new_tube(t_lem *lem, int nbt)
{
	char		**temp;
	int			i;
	int			j;

	if (!(temp = (char**)malloc(sizeof(char*) * (nbt + 1))))
		return ;
	temp[nbt] = 0;
	i = -1;
	j = -1;
	while (++i < lem->nbt)
	{
		if (lem->tube[i])
			temp[++j] = ft_strdup(lem->tube[i]);
	}
	i = -1;
	while (++i < lem->nbt)
	{
		if (lem->tube[i])
			ft_strdel(&lem->tube[i]);
	}
	free(lem->tube);
	lem->tube = temp;
	lem->nbt = nbt;
}

static void		check_same_tube(t_lem *lem)
{
	int		i;
	int		j;
	int		new_nbt;

	new_nbt = lem->nbt;
	i = -1;
	while (++i < lem->nbt - 1)
	{
		j = i + 1;
		while (++j < lem->nbt)
		{
			if (i != j && lem->tube[i] && lem->tube[j] &&
				verif_same_tube(lem->tube[i], lem->tube[j]))
			{
				ft_strdel(&lem->tube[j]);
				new_nbt--;
			}
		}
	}
	if (new_nbt != lem->nbt)
		stock_new_tube(lem, new_nbt);
}

static int		get_info(t_lem *lem, int *i, int *j)
{
	if (lem->file[(*i)][0] == '#')
	{
		if (check_diese(lem->file[(*i)], lem, i))
			return (1);
	}
	else if (ft_strchr(lem->file[(*i)], ' ') && !check_salle(lem->file[(*i)]))
		get_salle(lem, lem->file[(*i)], 0);
	else if (ft_strchr(lem->file[(*i)], '-') && !check_tube(lem->file[(*i)]))
		lem->tube[(*j)++] = ft_strdup(lem->file[(*i)]);
	return (0);
}

void			stock_info(t_lem *lem)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(lem->salles = (t_salle*)malloc(sizeof(t_salle) * (lem->nbs))))
		return ;
	if ((lem->tube = (char**)malloc(sizeof(char*) * (lem->nbt + 1))) == NULL)
		return ;
	lem->tube[lem->nbt] = 0;
	while (lem->file[i])
	{
		if (get_info(lem, &i, &j))
			return ;
		i++;
	}
	verif_salle(lem);
	verif_tube(lem);
	check_same_tube(lem);
}
