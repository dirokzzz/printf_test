#include "../includes/ft_printf.h"

void bzero_struct(t_flags *t)
{
    t->pf_return = 0;
    t->percent = 0;
    t->step = 0;
    t->ll = 0;
    t->width = 0;
    t->precision = 0;
    t->plus = 0;
    t->minus = 0;
    t->zero = 0;
    t->space = 0;
    t->hash = 0;
    t->l = 0;
    t->h = 0;
    t->hh = 0;
    t->l_cap = 0;
    t->dot = 0;
}

void reset_struct(t_flags *t)
{
    t->ll = 0;
    t->width = 0;
    t->precision = 0;
    t->plus = 0;
    t->minus = 0;
    t->zero = 0;
    t->space = 0;
    t->hash = 0;
    t->l = 0;
    t->h = 0;
    t->hh = 0;
    t->l_cap = 0;
    t->dot = 0;
}