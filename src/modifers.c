#include "../includes/ft_printf.h"

void    ft_plus_minus(const char *format, t_flags *t)
{
    if(format[t->step] == '+')
    {
        t->plus = 1;
        t->step++;
    }
    else
    {
        t->minus = 1;
        t->step++;
    }
}

void    ft_numbers(const char *format, t_flags *t)
{
    int num;
    int dot;
    
    if(format[t->step] == '0')
    {
        t->zero++;
        t->step++;
    }
    else
    {
        dot = (format[t->step - 1] == '.') ? 1 : 0; 
        num = ft_atoi(&format[t->step]);
        while(ft_strchr(NUMBERS, format[t->step]))
            t->step++;
        if(dot)
            t->precision = num;
        else
            t->width = num;
    }
}

void	len_analysis(const char *s, t_flags *t)
{
	if (s[t->step] == 'h')
	{
		t->step++;
        if (s[t->step] == 'h')
            t->hh = 1;
        else
            t->h = 1;
	}
	else if (s[t->step] == 'l')
	{
		t->step++;
        if (s[t->step] == 'l')
            {
                t->ll = 1;
                t->step++;
            }
        else
            t->l = 1;
	}
	else if (s[t->step] == 'L')
		{
            t->l_cap = 1;
            t->step++;
        }
}

