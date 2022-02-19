/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argument_p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 19:00:10 by acesar-l          #+#    #+#             */
/*   Updated: 2022/02/18 21:04:37 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_argument_p(unsigned long address)
{
	char	*num;
	int	bytes;
	int	i;

	i = 0;
	if (!address)
		return (write(1, "0x0", sizeof(char) * 3));
	bytes = write(1, "0x", sizeof(char) * 2);
	num = (char *)malloc(((ft_hex_length(address)) + 1) * sizeof(char));
	while (address)
	{
		num[i] = ft_decimal_converter_to_hex(address % 16, 'x');
		address /= 16;
		i++;
	}
	num[i] = '\0';
	ft_revert_str(num);
	ft_putstr_fd(num, 1);
	bytes += ft_strlen(num);
	ft_free_ptr(&num);
	return (bytes);
}
