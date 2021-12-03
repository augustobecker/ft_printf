#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>

int	 	ft_printf(const char *str, ...);
int		ft_argument_c(char c);
int 	ft_arguments_d_i(int c);
int 	ft_argument_p(unsigned long int address);
int 	ft_argument_percent(void);
int 	ft_argument_s(char *str);
int 	ft_argument_u(unsigned int nbr);
int		ft_arguments_x(unsigned long int nbr, char type);
int		ft_is_argument(char a);
int		ft_nbrlen(long int nbr);

#endif
