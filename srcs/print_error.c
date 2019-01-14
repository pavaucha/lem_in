/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lezhang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 15:27:23 by lezhang           #+#    #+#             */
/*   Updated: 2018/10/11 13:07:27 by lezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static void		print_error_with_line(t_lem lem)
{
	ft_putstr(ERROR_COLOR);
	ft_printf("Error line: %d\n", lem.stop_line);
	ft_putstr(RESET_COLOR);
	if (lem.error.empty_line)
		ft_putcolor(ERROR_COLOR, ERROR_EMPTY_LINE);
	if (lem.error.line)
		ft_putcolor(ERROR_COLOR, ERROR_LINE);
	else if (lem.error.start_space)
		ft_putcolor(ERROR_COLOR, ERROR_START_SPACE);
	else if (lem.error.ants)
		ft_putcolor(ERROR_COLOR, ERROR_ANTS);
	else if (lem.error.tube_salle)
		ft_putcolor(ERROR_COLOR, ERROR_TUBE_SALLE);
	else if (lem.error.salle_null)
		ft_putcolor(ERROR_COLOR, ERROR_SALLE_NULL);
	else if (lem.error.tube)
		ft_putcolor(ERROR_COLOR, ERROR_TUBE);
	else if (lem.error.salle)
		ft_putcolor(ERROR_COLOR, ERROR_SALLE);
	else if (lem.error.start_salle)
		ft_putcolor(ERROR_COLOR, ERROR_START_SALLE);
	else if (lem.error.end_salle)
		ft_putcolor(ERROR_COLOR, ERROR_END_SALLE);
}

static void		print_error_normal(t_lem lem)
{
	if (lem.file == NULL)
		ft_putcolor(ERROR_COLOR, ERROR_EMPTY_FILE);
	else if (lem.error.no_path)
		ft_putcolor(ERROR_COLOR, ERROR_NO_PATH);
	else if (lem.start == 0)
		ft_putcolor(ERROR_COLOR, ERROR_NO_START);
	else if (lem.start > 1)
		ft_putcolor(ERROR_COLOR, ERROR_MULTI_START);
	else if (lem.end == 0)
		ft_putcolor(ERROR_COLOR, ERROR_NO_END);
	else if (lem.end > 1)
		ft_putcolor(ERROR_COLOR, ERROR_MULTI_END);
	else if (lem.nbt == 0)
		ft_putcolor(ERROR_COLOR, ERROR_NO_TUBE);
	else if (lem.nbs == 0)
		ft_putcolor(ERROR_COLOR, ERROR_NO_SALLE);
	else if (lem.error.same_name)
		ft_putcolor(ERROR_COLOR, ERROR_SAME_NAME);
}

void			print_error(t_lem lem)
{
	if (lem.option != 1)
		ft_putstr(ERROR_MESSAGE);
	else
	{
		if (lem.error.ants || lem.error.empty_line |
			lem.error.start_space || lem.error.salle || lem.error.tube ||
			lem.error.line || lem.error.start_salle || lem.error.end_salle ||
			lem.error.tube_salle || lem.error.salle_null)
			print_error_with_line(lem);
		else if (lem.start != 1 || lem.end != 1 || lem.file == NULL ||
			lem.error.same_name || lem.nbt == 0 || lem.nbs == 0 ||
			lem.error.no_path)
			print_error_normal(lem);
	}
}

int				parse_error(t_lem lem)
{
	if (lem.start != 1 || lem.end != 1 || lem.file == NULL ||
		lem.error.ants || lem.error.same_name || lem.nbt == 0 ||
		lem.nbs == 0 || lem.error.start_salle || lem.error.end_salle)
		return (1);
	return (0);
}
