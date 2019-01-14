/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lezhang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 15:14:29 by lezhang           #+#    #+#             */
/*   Updated: 2018/10/19 12:21:11 by lezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static void		init_error(t_lem *lem)
{
	lem->error.error = 0;
	lem->error.empty_line = 0;
	lem->error.start_space = 0;
	lem->error.ants = 0;
	lem->error.tube = 0;
	lem->error.salle = 0;
	lem->error.start_salle = 0;
	lem->error.end_salle = 0;
	lem->error.same_name = 0;
	lem->error.tube_salle = 0;
	lem->error.salle_null = 0;
	lem->error.line = 0;
	lem->error.no_path = 0;
}

static void		init_lem(t_lem *lem)
{
	lem->file = NULL;
	lem->nom_start = NULL;
	lem->nom_end = NULL;
	lem->nbf = 0;
	lem->nbs = 0;
	lem->nbt = 0;
	lem->start = 0;
	lem->end = 0;
	lem->stop_line = 0;
	lem->curr_salle = 0;
	lem->salles = NULL;
	lem->tube = NULL;
	lem->option = 0;
	init_error(lem);
}

static void		free_lem(t_lem *lem)
{
	int		i;

	i = -1;
	if (lem->file)
		ft_strdel_tab(&lem->file);
	if (lem->salles)
	{
		while (++i < lem->nbs)
			ft_strdel(&lem->salles[i].nom);
		free(lem->salles);
		lem->salles = NULL;
	}
	if (lem->tube)
		ft_strdel_tab(&lem->tube);
	if (lem->nom_start)
		ft_strdel(&lem->nom_start);
	if (lem->nom_end)
		ft_strdel(&lem->nom_end);
}

void			printlem(t_lem lem)
{
	int		i;

	i = -1;
	if (lem.file)
		while (lem.file[++i])
			ft_putendl(lem.file[i]);
	ft_putchar('\n');
}

int				main(int argc, char **argv)
{
	t_lem	lem;

	init_lem(&lem);
	stock_file(&lem);
	count_salle_tube(&lem);
	lem.option = get_option(argc, argv);
	if (lem.start != 1 || lem.end != 1 || lem.nbt == 0 || lem.nbs == 0 ||
		lem.file == NULL)
		lem.error.error = 1;
	if (lem.error.error == 1 && parse_error(lem))
		print_error(lem);
	else
	{
		if (!lem.error.error)
			lem.stop_line = 0;
		stock_info(&lem);
		if (lem.error.error == 1 && parse_error(lem))
			print_error(lem);
		else
			find_multi_path(&lem);
		if (lem.error.no_path)
			print_error(lem);
	}
	free_lem(&lem);
	return (0);
}
