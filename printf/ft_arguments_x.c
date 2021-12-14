#include "ft_printf.h"

int ft_arguments_x(unsigned int nbr, char type)
{
	unsigned int	aux;
	int		size;
	char		*num;
	int		i;

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
		num[i] = ft_hexa_converter(nbr % 16, type);
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
