#include "../includes/ft_printf.h"

void	ft_unsigned_n(t_flags *t, va_list *ap)
{
	char *s;

	s = NULL;
	if (t->h == 1)
	s = ft_itoa_unsigned((unsigned short)va_arg(*ap, unsigned int));
	else if (t->hh == 1)
		s = ft_itoa_unsigned((unsigned char)va_arg(*ap, unsigned int));
	else if (t->l == 1)
		s = ft_itoa_unsigned(va_arg(*ap, unsigned long));
	else if (t->ll == 1)
		s = ft_itoa_unsigned(va_arg(*ap, unsigned long long));
	else
		s = ft_itoa_unsigned(va_arg(*ap, unsigned int)); 
	ft_output(s, t);
}