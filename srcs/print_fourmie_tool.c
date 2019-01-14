/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fourmie_tool.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lezhang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 17:04:58 by lezhang           #+#    #+#             */
/*   Updated: 2018/10/19 11:45:39 by lezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static void		print_fourmie_salle(char **tmp, t_lem *lem, int l)
{
	int		i;
	int		j;
	int		k;

	i = 1;
	while (tmp[i])
	{
		j = 0;
		k = 0;
		while (ft_strcmp(lem->salles[j].nom, tmp[i]) != 0)
			j++;
		while (ft_strcmp(lem->salles[k].nom, tmp[i - 1]) != 0)
			k++;
		if (lem->salles[k].used == 1)
		{
			if (ft_strcmp(lem->salles[k].nom, lem->nom_start) == 0 &&
				lem->nbf > 0)
				lem->salles[j].fourmie_b = l;
			else
				lem->salles[j].fourmie_b = lem->salles[k].fourmie_a;
			ft_printf("L%i-%s ", lem->salles[j].fourmie_b, lem->salles[j].nom);
		}
		i++;
	}
}

void			avance_fourmie(char **tmp, t_lem *lem)
{
	static int	l = 0;
	int			i;

	i = 0;
	if (lem->nbf > 0)
	{
		while (ft_strcmp(lem->salles[i].nom, lem->nom_start))
			i++;
		lem->salles[i].used = 1;
		l++;
	}
	print_fourmie_salle(tmp, lem, l);
	if (lem->nbf > 0)
		lem->nbf--;
}
