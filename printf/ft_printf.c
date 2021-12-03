#include "ft_printf.h"

int ft_printf(const char *str, ...)
{
	va_list argptr;
	int i;
	int bytes_writed;

	i = 0;
	bytes_writed = 0;
	va_start(argptr, str);
	while (str[i])
	{
		if (str[i] == '%')
        {
			if (str[i + 1] == '%')
				bytes_writed += ft_argument_percent();
			if (str[i + 1] == 'c')
				bytes_writed += ft_argument_c(va_arg(argptr, int));
			if (str[i + 1] == 's')
				bytes_writed += ft_argument_s(va_arg(argptr, char *));
			if (str[i + 1] == 'p')
				bytes_writed += ft_argument_p(va_arg(argptr, int));
			if (str[i + 1] == 'd' || str[i + 1] == 'i')
				bytes_writed += ft_arguments_d_i(va_arg(argptr, int));
			if (str[i + 1] == 'u')
				bytes_writed += ft_argument_u(va_arg(argptr, int));
			if (str[i + 1] == 'x' || str[i + 1] == 'X')
				bytes_writed += ft_arguments_x(va_arg(argptr, int), str[i + 1]);
			i++;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			bytes_writed++;
		}
		i++;
	}
	va_end(argptr);
	return (bytes_writed);
}
