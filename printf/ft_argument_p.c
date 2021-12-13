#include "ft_printf.h"

static int ft_long_argument_p(unsigned long long int nbr)
{
	unsigned long long int		aux;
	int 						          size;
	char						          *num;
	int						          	i;

	aux = nbr;
	size = 0;
	i = 0;
	if (!nbr)
		return (ft_putchar_bw('0'));
	while (aux > 0)
	{
		aux /= 16;
		size++;
	}
	num = (char *) malloc((size + 1) * sizeof(char));
	while (nbr)
	{
		num[i] = ft_hexa_converter(nbr % 16, 'x');
		nbr /= 16;
		i++;
	}
	num[i] = '\0';
	ft_revstr(num);
	ft_putstr_fd(num, 1);
	i = ft_strlen(num);
	ft_free_ptr(&num);
	return (i);
}

int ft_argument_p(unsigned long long int address)
{
	int bytes;

	if (!address)
	{
		ft_putstr_fd("(nil)" , 1);
		bytes = 5;
		return (bytes);
	}
	ft_putstr_fd("0x" , 1);
	bytes = 2;
	bytes += ft_long_argument_p(address);
	return (bytes);
}
