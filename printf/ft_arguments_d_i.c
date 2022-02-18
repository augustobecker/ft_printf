/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arguments_d_i.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 19:05:57 by acesar-l          #+#    #+#             */
/*   Updated: 2021/02/18 13:45:58 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr(int nb)
{
	int	soma;

	soma = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
		if (nb == -2147483648)
		{
			nb--;
			soma = 1;
		}
	}
	if (nb < 10)
		ft_putchar_fd(nb + 48 + soma, 1);
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10 + soma);
	}	
}

int	ft_arguments_d_i(int c)
{
	ft_putnbr(c);
	return (ft_decimal_length(c));
}
