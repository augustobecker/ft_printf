/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revert_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 19:16:39 by acesar-l          #+#    #+#             */
/*   Updated: 2021/12/18 14:16:49 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_revert_str(char *str)
{
	int	start;
	int	final;

	start = 0;
	final = ft_strlen(str) - 1;
	while (start < final - start)
	{
		str[start] = str[start] ^ str[final - start];
		str[final - start] = str[start] ^ str[final - start];
		str[start] = str[start] ^ str[final - start];
		start++;
	}
	return (str);
}
