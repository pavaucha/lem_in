/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lezhang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:51:47 by lezhang           #+#    #+#             */
/*   Updated: 2017/12/04 12:47:33 by lezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((i < n) && *(s1 + i) != '\0' && *(s2 + i) != '\0' &&
			*(s1 + i) == *(s2 + i))
		i++;
	if (i == n)
		i--;
	return (*(unsigned char*)(s1 + i) - *(unsigned char*)(s2 + i));
}
