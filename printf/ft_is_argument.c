#include "ft_printf.h"

int ft_is_argument(char a)
{
    return (a == 'c' || a == 'd' || a == 'i' || a == 'p'
        || a == 'f' || a == 's' || a == 'x' || a == 'X' || a == 'u' || a == '%');
}
