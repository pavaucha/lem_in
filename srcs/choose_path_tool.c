/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_path_tool.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lezhang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 17:34:43 by lezhang           #+#    #+#             */
/*   Updated: 2018/10/19 16:58:23 by lezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int		nb_path(t_lem *lem)
{
	int		i;
	char	**tmp;
	int		count[2];

	count[0] = 0;
	count[1] = 0;
	i = 0;
	while (lem->tube[i])
	{
		tmp = ft_strsplit(lem->tube[i], '-');
		if (ft_strcmp(tmp[0], lem->nom_start) == 0 ||
			ft_strcmp(tmp[1], lem->nom_start) == 0)
			count[0]++;
		if (ft_strcmp(tmp[0], lem->nom_end) == 0 ||
			ft_strcmp(tmp[1], lem->nom_end) == 0)
			count[1]++;
		ft_strdel_tab(&tmp);
		i++;
	}
	return (count[0] > count[1]) ? count[1] : count[0];
}

int		get_path_length(char **path)
{
	int		length;
	int		k;

	k = 0;
	length = -1;
	while (path[k])
	{
		if (ft_strlen(path[k]) < (size_t)length)
			length = ft_strlen(path[k]);
		else if (length == -1)
			length = ft_strlen(path[k]);
		k++;
	}
	k = 0;
	while (ft_strlen(path[k]) != (size_t)length)
		k++;
	return (k);
}
