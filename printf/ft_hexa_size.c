/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 12:56:00 by acesar-l          #+#    #+#             */
/*   Updated: 2022/02/18 12:57:02 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa_size(unsigned int nbr)
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
