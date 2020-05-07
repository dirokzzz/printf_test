#include "../includes/ft_printf.h"

void ft_int(t_flags *t, va_list *ap)
{
    char *s;

    s = ft_itoa(va_arg(*ap, int));
    ft_output(s, t);
}