#include "../includes/ft_printf.h"

char *b_space(char *string, int width)
{
    int i;
    
    i = 0;
    while(i < width)
    {
        string[i] = ' ';
        i++;
    }
    string[i] = '\0';
    return (string);
}

char *ft_str_right_cpy(char *string, char *s, size_t precision, t_flags *t)
{
    size_t i;
    size_t j;
    
    if(!t->dot)
    {
        i = precision < ft_strlen(s) ? ft_strlen(string) - precision : ft_strlen(string) - ft_strlen(s);
        j = 0;
        while(j < precision && string[i] && s[j])
            string[i++] = s[j++];
    }
    return(string);
}

char *ft_str_left_cpy(char *string, char *s, int precision, t_flags *t)
{
    int i;

	i = 0;
    printf("###\n");
    if (!t->dot)
    {
	    while (i < precision && s[i])
	    {
		    string[i] = s[i];
		    i++;
	    }
    }
	return (string);
}

void ft_char(t_flags *t, va_list *ap)
{
    ft_putchar((char)va_arg(*ap, int));
    t->pf_return++;
}

void ft_string(t_flags *t, va_list *ap, const char *format)
{
    char *s;
    char *string;
    size_t width;
    size_t precision;

    if(format[t->step] == '%')
    {
        printf("minus1=%d\n", t->minus);
        s = ft_strdup("%");
        printf("minus2=%d\n", t->minus);
    }
    else
        s = (char*)va_arg(*ap, char*);
    
    printf("width == %zu, precision == %zu, minus == %d\n", t->width, t->precision, t->minus);
    if (!t->width && !t->precision && !t->dot)
        string = ft_strdup(s);
    else
    {
        if (t->width > 0)
            width = t->width > 0 && t->width > ft_strlen(s) ? t->width : ft_strlen(s);
        else
            width = t->precision < ft_strlen(s) ? t->precision : ft_strlen(s);
        precision = t->precision > 0 ? t->precision : INT16_MAX;
        if (!(string = (char*)malloc(sizeof(char) *  width + 1)))
            return;
        string = b_space(string, width);
        printf("minus1=%d\n", t->minus);
        if(t->minus)
            string = ft_str_left_cpy(string, s, precision, t);
        else
            string = ft_str_right_cpy(string, s, precision, t);
    }
    ft_putstr(string);
    t->pf_return += ft_strlen(string);
    free(string);
}