/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argument_p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 19:00:10 by acesar-l          #+#    #+#             */
/*   Updated: 2022/02/14 13:16:41 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_argument_size(unsigned long nbr)
{
	int	size;

	size = 0;
	while (nbr > 0)
	{
		nbr /= 16;
		size++;
	}
	return (size);
}

static int	ft_long_argument_p(unsigned long nbr)
{
	char		*num;
	int		i;

	i = 0;
	if (!nbr)
		return (ft_putchar_bw('0'));
	num = (char *)malloc(((ft_argument_size(nbr)) + 1) * sizeof(char));
	while (nbr)
	{
		num[i] = ft_hexa_converter(nbr % 16, 'x');
		nbr /= 16;
		i++;
	}
	num[i] = '\0';
	ft_revstr(num);
	ft_putstr_fd(num, 1);
	i = ft_strlen(num);
	ft_free_ptr(&num);
	return (i);
}

int	ft_argument_p(unsigned long address)
{
	int	bytes;

	if (!address)
	{
		ft_putstr_fd("(nil)", 1);
		bytes = 5;
		return (bytes);
	}
	ft_putstr_fd("0x", 1);
	bytes = 2;
	bytes += ft_long_argument_p(address);
	return (bytes);
}
