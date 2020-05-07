#include "../includes/ft_printf.h"

void ft_output(const char *s, t_flags *t)
{
    int i;

    i = 0;
    while (s[i])
    {
        ft_putchar(s[i]);
        i++;
        t->pf_return++;
    }
}

void ft_text(const char *format, t_flags *t)
{
    ft_putchar(format[t->step]);
    t->pf_return++;
}

void    ft_percent(t_flags *t)
{
    ft_putchar('%');
    t->pf_return++;
}