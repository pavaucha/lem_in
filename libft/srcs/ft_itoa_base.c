/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lezhang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 13:16:33 by lezhang           #+#    #+#             */
/*   Updated: 2017/12/21 15:32:25 by lezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char	*ft_create_str(int base, int len, uintmax_t n, int sign)
{
	char	*str;
	char	letter;

	if ((str = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	str[len] = '\0';
	while (--len >= 0)
	{
		if (n % base >= 10)
			letter = 'A' - 10;
		else
			letter = '0';
		str[len] = n % base + letter;
		n /= base;
	}
	if (base == 10 && sign < 0)
		str[0] = '-';
	return (str);
}

char		*ft_itoa_base(uintmax_t n, int base, int sign)
{
	char		*str;
	int			len;

	len = ft_num_len(n, base);
	if (n == 0)
	{
		if ((str = (char*)malloc(sizeof(char) * (2))) == NULL)
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	if (base == 10 && sign < 0)
		len++;
	if ((str = ft_create_str(base, len, n, sign)) == NULL)
		return (NULL);
	return (str);
}
