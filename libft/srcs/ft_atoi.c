/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lezhang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:59:23 by lezhang           #+#    #+#             */
/*   Updated: 2017/12/04 12:41:21 by lezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_atoi(const char *str)
{
	int		i;
	int		sign;
	int		result;

	i = 0;
	sign = 1;
	result = 0;
	while (*(str + i) < 33 || *(str + i) > 126)
	{
		if (*(str + i) == '\0' || *(str + i) == '\200' || *(str + i) == 27)
			return (0);
		i++;
	}
	if (*(str + i) == '-' || *(str + i) == '+')
	{
		if (*(str + i) == '-')
			sign = -1;
		i++;
	}
	while (*(str + i) >= '0' && *(str + i) <= '9')
	{
		result = ((*(str + i) - '0') + (result * 10));
		i++;
	}
	return (result * sign);
}
