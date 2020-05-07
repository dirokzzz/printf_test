#include <stdio.h>
#include "../includes/ft_printf.h"

#define LLONG_MAX  __LONG_LONG_MAX__

int main()
{
    t_flags *t;
    int i;
    char c = '#';
    char *s = "ANDREW";
    /*i = printf("1==asd%d = %c = %s = %u\n", 2, c, s, 112);
    printf("%d\n", i);
    i = ft_printf("1==asd%d = %c = %s = %u\n", 2, c, s, 112);
    printf("%d", i);
    printf("%2.5d|%-1.5d|%+1.5d|% 1.5d|%01.5d\n", 1, 0, 0, 0, 1);
    i = ft_printf("%-+hhi|%- hhi|%-0hhi|%+ hhi|%+0hhi|% 0hhi|%-+ 0hhi\n", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX);
    printf("%d\n", i);
    i = printf("%-+hhi|%- hhi|%-0hhi|%+ hhi|%+0hhi|% 0hhi|%-+ 0hhi\n", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX);
    printf("%d\n", i);*/
   // ft_printf("test12345678\n");
    /*i = printf("origin=%-7s", "test");
    printf("\n");
    printf("origin=%d\n", i);*/
    ft_printf("%5s\n", "q");
    //printf("\n");
   // printf("govno=%d\n", i);
   // printf("%5%");
   // printf("\n");
   // printf("govno2=%d\n", i);
   // i = ft_printf("1govno= %10.1s", "test12345678tvn\n");
   // printf("2govno=%d\n", i);
}



/*  для отладки

printf("width == %d, precision == %d, minus == %d\n", t->width, t->precision, t->minus);




*/