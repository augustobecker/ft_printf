#include "ft_printf.h"

static int	ft_putchar_bw(char c)
{
	write(1, &c, sizeof(char));
	return (1);
}

static	char	*ft_rev_str(char *str)
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

static char ft_hexa_converter(char digit, char type)
{
	int capitalize;

	capitalize = 0;
	if (type == 'X')
		capitalize = 32;
	if (digit > 9)
	{
		if (digit == 10)
			return ('a' - capitalize);
		if (digit == 11)
			return ('b' - capitalize);
		if (digit == 12)
			return ('c' - capitalize);
		if (digit == 13)
			return ('d' - capitalize);
		if (digit == 14)
			return ('e' - capitalize);
		if (digit == 15)
			return ('f' - capitalize);
	}
	else
		return (digit + '0');
	return (0);
}

int ft_arguments_x(unsigned long int nbr, char type)
{
	unsigned long int	aux;
	int 				size;
	char				*num;
	int					i;

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
	ft_rev_str(num);
	ft_putstr_fd(num, 1);
	i = ft_strlen(num);
	ft_free_ptr(&num);
	return (i);
}
