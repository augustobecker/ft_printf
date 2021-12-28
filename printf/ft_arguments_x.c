/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arguments_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 19:12:00 by acesar-l          #+#    #+#             */
/*   Updated: 2021/12/14 19:12:02 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_argument_size(unsigned int nbr)
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

int	ft_arguments_x(unsigned int nbr, char type)
{
	char	*num;
	int		size;
	int		i;

	i = 0;
	if (!nbr)
		return (ft_putchar_bw('0'));
	num = (char *)malloc((ft_argument_size(nbr) + 1) * sizeof(char));
	while (nbr)
	{
		num[i] = ft_hexa_converter(nbr % 16, type);
		nbr /= 16;
		i++;
	}
	num[i] = '\0';
	ft_revstr(num);
	ft_putstr_fd(num, 1);
	size = ft_strlen(num);
	ft_free_ptr(&num);
	return (size);
}
