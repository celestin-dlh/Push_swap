/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned_long.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 13:29:49 by cdelahay          #+#    #+#             */
/*   Updated: 2019/02/22 13:29:51 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_str_len(unsigned long long n)
{
	size_t i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa_unsigned_long(unsigned long long n)
{
	char					*str;
	size_t					len;
	unsigned long long		n_cpy;

	len = get_str_len(n);
	n_cpy = n;
	if (!(str = ft_strnew(len)))
		return (NULL);
	str[--len] = n_cpy % 10 + '0';
	while (n_cpy /= 10)
		str[--len] = n_cpy % 10 + '0';
	return (str);
}
