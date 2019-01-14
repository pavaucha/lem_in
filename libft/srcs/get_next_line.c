/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lezhang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 11:50:13 by lezhang           #+#    #+#             */
/*   Updated: 2018/01/11 12:33:05 by lezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

static char		*ft_read(const int fd, char *str)
{
	char	*buf;
	char	*endl;
	char	*temp;
	int		ret;

	if ((buf = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))) == NULL)
		return (NULL);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		temp = str;
		if ((str = ft_strjoin(str, buf)) == NULL)
			return (NULL);
		ft_strdel(&temp);
		if ((endl = ft_strchr(str, '\n')) != NULL)
			break ;
	}
	ft_strdel(&buf);
	return (str);
}

int				get_next_line(const int fd, char **line)
{
	static char		*gnl[OPEN_MAX] = {NULL};
	int				ret;

	if (BUFF_SIZE < 1 || read(fd, NULL, 0) == -1 || line == NULL ||
			fd > OPEN_MAX)
		return (-1);
	if (!gnl[fd] && (gnl[fd] = ft_strnew(1)) == NULL)
		return (-1);
	if ((gnl[fd] = ft_read(fd, gnl[fd])) == NULL)
		return (-1);
	if (gnl[fd][0] != '\0')
	{
		ret = 0;
		while (gnl[fd][ret] != '\n' && gnl[fd][ret] != '\0')
			ret++;
		if ((*line = ft_strsub(gnl[fd], 0, ret)) == NULL)
			return (-1);
		if (gnl[fd][ret] == '\0')
			ret--;
		gnl[fd] = ft_strncpy(gnl[fd], gnl[fd] + ret + 1, ft_strlen(gnl[fd]));
		return (1);
	}
	return (0);
}
