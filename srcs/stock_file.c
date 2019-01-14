/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lezhang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 17:17:14 by lezhang           #+#    #+#             */
/*   Updated: 2018/10/05 14:21:25 by lezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static int		check_error_2(char *str, t_lem *lem, int error)
{
	if (check_space(str))
	{
		error = 1;
		lem->error.start_space = 1;
	}
	else if (ft_strchr(str, '-') && check_tube(str))
	{
		error = 1;
		lem->error.tube = 1;
	}
	else if (ft_strchr(str, ' ') && check_salle(str))
	{
		error = 1;
		lem->error.salle = 1;
	}
	else if (!ft_strchr(str, ' ') && !ft_strchr(str, '-') && str[0] != '#')
	{
		error = 1;
		lem->error.line = 1;
	}
	return (error);
}

static int		check_error(char *str, t_lem *lem)
{
	int		error;

	error = 0;
	if (str[0] == '\0')
	{
		error = 1;
		lem->error.empty_line = 1;
	}
	else if (str[0] == '#' && is_comment(str))
		return (0);
	else if (lem->nbf == 0)
	{
		if (str[0] == '-' || !ft_strnum(str) || ft_atoi(str) < 1 ||
			str[0] == '#')
		{
			error = 1;
			lem->error.ants = 1;
		}
		else
			lem->nbf = ft_atoi(str);
	}
	else
		error = check_error_2(str, lem, error);
	lem->error.error = error;
	return (error);
}

static int		check_start_end2(t_lem *lem, int i, int start, int end)
{
	if (!lem->file[i] || (lem->file[i] && check_salle(lem->file[i])))
	{
		lem->stop_line = i + 1;
		lem->error.error = 1;
		lem->error.start_salle = (!start) ? 1 : 0;
		lem->error.end_salle = (!end) ? 1 : 0;
		while (lem->file[i])
		{
			ft_strdel(&lem->file[i]);
			i++;
		}
		return (1);
	}
	return (0);
}

static void		check_start_end(t_lem *lem)
{
	int		i;
	int		start;
	int		end;

	i = 0;
	while (lem->file[i])
	{
		if (lem->file[i][0] == '#' && !is_comment(lem->file[i]))
		{
			start = ft_strcmp("##start", lem->file[i]);
			end = ft_strcmp("##end", lem->file[i]);
			i++;
			lem->start += (!start) ? 1 : 0;
			lem->end += (!end) ? 1 : 0;
			while (lem->file[i] && lem->file[i][0] == '#' &&
				is_comment(lem->file[i]))
				i++;
			if (check_start_end2(lem, i, start, end))
				return ;
		}
		i++;
	}
}

void			stock_file(t_lem *lem)
{
	char	*line;
	char	*temp;
	char	*result;

	result = ft_strnew(0);
	while (get_next_line(0, &line))
	{
		lem->stop_line++;
		if (!line || check_error(line, lem))
		{
			ft_strdel(&line);
			break ;
		}
		temp = ft_strjoin(line, "\n");
		ft_strdel(&line);
		line = result;
		result = ft_strjoin(result, temp);
		ft_strdel(&line);
		ft_strdel(&temp);
	}
	if (result != NULL && result[0] != '\0')
		lem->file = ft_strsplit(result, '\n');
	ft_strdel(&result);
	if (lem->file)
		check_start_end(lem);
}
