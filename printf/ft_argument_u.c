#include "ft_printf.h"

static void	ft_put_unsigned_nbr(unsigned int nb)
{
	if (nb < 10)
		ft_putchar_fd(nb + 48, 1);
	else
	{
		ft_put_unsigned_nbr(nb / 10);
		ft_put_unsigned_nbr(nb % 10);
	}	
}

int 	ft_argument_u(unsigned int nbr)
{
	ft_put_unsigned_nbr(nbr);
	return (ft_nbrlen(nbr));
}
