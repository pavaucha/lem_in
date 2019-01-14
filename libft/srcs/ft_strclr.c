/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lezhang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:39:31 by lezhang           #+#    #+#             */
/*   Updated: 2017/12/04 12:44:51 by lezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_strclr(char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return ;
	while (*(s + i) != '\0')
	{
		*(s + i) = '\0';
		i++;
	}
}
