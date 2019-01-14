/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lezhang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:50:38 by lezhang           #+#    #+#             */
/*   Updated: 2017/12/04 13:28:20 by lezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		found;

	i = 0;
	found = 0;
	c = (char)c;
	while (*(s + i) != '\0')
		i++;
	if (c == '\0')
		return ((char*)s + i);
	while (i > 0)
	{
		if (*(s + i - 1) == c)
		{
			found = 1;
			break ;
		}
		i--;
	}
	if (found == 0)
		return (NULL);
	return ((char*)s + i - 1);
}
