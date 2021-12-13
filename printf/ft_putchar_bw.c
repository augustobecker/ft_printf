#include "ft_printf.h"

int	ft_putchar_bw(char c)
{
	write(1, &c, sizeof(char));
	return (1);
}
