#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

# define TYPE           "cspdiouxXfyb%"
# define FLAGS 			"#-+ .*0123456789hljz"
# define ALLSYMBOLS 	"cspdiouxXfyb#-+% .*0123456789hLljz"
# define NUMBERS		"1234567890"

typedef struct  s_flags
{
    int             pf_return;
    int             step;
    int             percent;
	int				dot;
    unsigned char	minus;
	unsigned char	plus;
	unsigned char	zero;
	unsigned char	space;
	unsigned char	hash;
	size_t				width;
	size_t				precision;
	char			type;
	int				h;
	int				hh;
	int				l;
	int				ll;
	int				l_cap;
	int				error;

}               t_flags;

void    ft_percent(t_flags *t);
void	reset_struct(t_flags *t);
void    ft_plus_minus(const char *format, t_flags *t);
void	ft_numbers(const char *format, t_flags *t);
void	len_analysis(const char *s, t_flags *t);
void	ft_string(t_flags *t, va_list *ap, const char *format);
void	ft_char(t_flags *t, va_list *ap);
int		ft_printf(const char *format, ...);
void	bzero_struct(t_flags *t);
void	ft_text(const char *format, t_flags *t);
void	ft_analysis(const char *format, t_flags *t, va_list *ap);
void	ft_int(t_flags *t, va_list *ap);
void	ft_conversions(const char *format, t_flags *t, va_list *ap);
void	ft_modifers(const char *format, t_flags *t);
void	ft_output(const char *s, t_flags *t);
void	ft_head(va_list *ap, const char *format, t_flags *t);
int		ft_format(va_list *ap, const char *format, t_flags *t);
void	ft_unsigned_n(t_flags *t, va_list *ap);

#endif
