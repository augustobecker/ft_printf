/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 19:28:57 by acesar-l          #+#    #+#             */
/*   Updated: 2021/02/18 13:01:14 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <unistd.h>

int   ft_printf(const char *str, ...);
int   ft_argument_c(char c);
int   ft_arguments_d_i(int c);
int   ft_argument_p(unsigned long nbr);
int   ft_argument_percent(void);
int   ft_argument_s(char *str);
int   ft_argument_u(unsigned int nbr);
int   ft_arguments_x(unsigned int nbr, char type);
int   ft_is_argument(char a);
int   ft_decimal_length(long int nbr);
void  ft_free_ptr(char **ptr);
char  ft_decimal_converter_to_hex(char digit, char type);
int   ft_hex_length(unsigned long nbr);
int   ft_print_reversed_str(char *str)

#endif
