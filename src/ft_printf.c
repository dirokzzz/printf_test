#include "../includes/ft_printf.h"

void ft_head(va_list *ap, const char *format, t_flags *t)
{
    t->step++;
    reset_struct(t);
    ft_analysis(format, t, ap);
}

int ft_format(va_list *ap, const char *format, t_flags *t)
{
    while (format[t->step] != '\0')
    {
        if (format[t->step] != '%' && format[t->step])
            ft_text(format, t);
        else if(format[t->step] == '%' && ft_strchr(ALLSYMBOLS, format[t->step + 1]))
            ft_head(ap, format, t);
        else
            return(1);
        t->step++;
        
    }
    return (0);
}

int ft_printf(const char *format, ...)
{
    t_flags *t;
    va_list ap;

    if(!(t = malloc(sizeof(t))))
        return(-1);
    bzero_struct(t);
    va_start(ap, format);
    ft_format(&ap, format, t);
    va_end(ap);
    return (t->pf_return);
}