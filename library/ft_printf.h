/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 19:28:57 by acesar-l          #+#    #+#             */
/*   Updated: 2021/12/14 19:30:14 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_argument_c(char c);
int		ft_arguments_d_i(int c);
int		ft_argument_p(unsigned long long int address);
int		ft_argument_percent(void);
int		ft_argument_s(char *str);
int		ft_argument_u(unsigned int nbr);
int		ft_arguments_x(unsigned int nbr, char type);
int		ft_is_argument(char a);
int		ft_nbrlen(long int nbr);
void	ft_free_ptr(char **ptr);
int		ft_putchar_bw(char c);
char	*ft_revstr(char *str);
char	ft_hexa_converter(char digit, char type);

#endif
