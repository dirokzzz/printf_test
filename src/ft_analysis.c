#include "../includes/ft_printf.h"

void ft_conversions(const char *format, t_flags *t, va_list *ap)
{
    if(format[t->step] == 'd' || format[t->step] == 'i')
        ft_int(t, ap);
    if(format[t->step] == 'c' || format[t->step] == 'C')
        ft_char(t, ap);
    if(format[t->step] == 's' || format[t->step] == '%')
        ft_string(t, ap, format);
    if(format[t->step] == 'u')
        ft_unsigned_n(t, ap);
}

void ft_modifers(const char *format, t_flags *t)
{
    while(!ft_strchr(TYPE, format[t->step]))
    {
        if (ft_strchr(NUMBERS, format[t->step]))
            ft_numbers(format, t);
        else if (format[t->step] == 'h' || format[t->step] == 'l' || format[t->step] == 'L')
            len_analysis(format, t);
        else if (format[t->step] == '+' || format[t->step] == '-')
            ft_plus_minus(format,t);
        else if (format[t->step] == '.' && ft_strchr(NUMBERS, format[t->step + 1]))
            t->step++;
        else if (format[t->step] == '.' && !ft_strchr(NUMBERS, format[t->step + 1]))
        {
            t->step++;
            t->dot++;
        }
        else if(format[t->step] == ' ')
        {
            t->space++;
            t->step++;
        }
        //if(format[t->step] == '#')
    }
}

void ft_analysis(const char *format, t_flags *t, va_list *ap)
{
    if(ft_strchr(FLAGS, format[t->step]))
        ft_modifers(format, t);
    if(ft_strchr(TYPE, format[t->step]))
        ft_conversions(format, t, ap);
}