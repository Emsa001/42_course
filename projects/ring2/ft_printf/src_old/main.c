/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:54:49 by escura            #+#    #+#             */
/*   Updated: 2023/11/23 12:36:15 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../../../libraries/lib.h"
#include <stdio.h>
#include <string.h>
#include <limits.h>

void a_putchar(char c){
    write(1,&c,1);
}

void write_test(int nb){
    cyan();
    a_putchar('[');
    a_putchar(nb + '0');
    a_putchar(']');
    reset();
}

void test_s(char *str){
    yellow();
    printf("\n[ TESTING FOR STRING: |%s| ]\n\n",str);

    write_test(1);
    int return_ft = ft_printf(" FT test_s: %s|",str);
    printf(" (%d)\n",return_ft);
    write_test(1);
    int return_og = printf(" OG test_s: %s|",str);
    printf(" (%d)\n\n",return_og);

    write_test(2);
    return_ft = ft_printf(" FT test_s: %50s|",str);
    printf(" (%d)\n",return_ft);
    write_test(2);
    return_og = printf(" OG test_s: %50s|",str);
    printf(" (%d)\n\n",return_og);

    write_test(3);
    return_ft = ft_printf(" FT test_s: %-50s|",str);
    printf(" (%d)\n",return_ft);
    write_test(3);
    return_og = printf(" OG test_s: %-50s|",str);
    printf(" (%d)\n\n",return_og);

    write_test(4);
    return_ft = ft_printf(" FT test_s: %050s|",str);
    printf(" (%d)\n",return_ft);
    write_test(4);
    return_og = printf(" OG test_s: %050s|",str);
    printf(" (%d)\n\n",return_og);

    write_test(5);
    return_ft = ft_printf(" FT test_s: %0s|",str);
    printf(" (%d)\n",return_ft);
    write_test(5);
    return_og = printf(" OG test_s: %0s|",str);
    printf(" (%d)\n\n",return_og);
}


void test_d(int nb){
    int return_ft = ft_printf("FT test_d: %12d| %d",nb,nb);
    printf(" (%d)\n",return_ft);
    int return_og = printf("OG test_d: %12d| %d",nb,nb);
    printf(" (%d)\n\n",return_og);
}

void test_i(int nb){
    int return_ft = ft_printf("FT test_i: %12i| %d",nb,nb);
    printf(" (%d)\n",return_ft);
    int return_og = printf("OG test_i: %12i| %d",nb,nb);
    printf(" (%d)\n\n",return_og);
}

void test_u(long int nb){
    int return_ft = ft_printf("FT test_u: %12u| %d",nb,nb);
    printf(" (%d)\n",return_ft);
    int return_og = printf("OG test_u: %12u| %d",nb,nb);
    printf(" (%d)\n\n",return_og);
}

void test_p(long int nb){
    int return_ft = ft_printf("FT test_p: %050p| %d",nb,nb);
    printf(" (%d)\n",return_ft);
    int return_og = printf("OG test_p: %050p| %d",nb,nb);
    printf(" (%d)\n\n",return_og);
}

void test_x(long int nb){
    int return_ft = ft_printf("FT test_x: %050x| %d",nb,nb);
    printf(" (%d)\n",return_ft);
    int return_og = printf("OG test_x: %050x| %d",nb,nb);
    printf(" (%d)\n\n",return_og);
}

void test_X(long int nb){
    int return_ft = ft_printf("FT test_X: %050X| %d",nb,nb);
    printf(" (%d)\n",return_ft);
    int return_og = printf("OG test_X: %050X| %d",nb,nb);
    printf(" (%d)\n\n",return_og);
}

void test_mix(){

    int nb = 42;

    int return_ft = ft_printf("FT test_mix: Test%%%% %c %d %d %s %p %50d | %010s %-10s|\n",'a',-1123,11200,"Hello World",&nb,123,"Hello", "World");
    printf(" (%d)\n",return_ft);
    int return_og = printf("OG test_mix: Test%%%% %c %d %d %s %p %50d | %010s %-10s|\n",'a',-1123,11200,"Hello World",&nb,123,"Hello","World");
    printf(" (%d)\n\n",return_og);
}

int main()
{
    int return_ft;
    int return_og;
    


    // int integerNumber = 42;
    // float floatNumber = 3.14159;
    // char *str = "Hello";

    // // Using zero flag and field minimum width
    // return_ft = ft_printf("FT Integer: %-6d %12s %-12s", integerNumber,str,str);
    // printf(" (%d)\n",return_ft);
    // return_og = printf("OG Integer: %-6d %12s %-12s", integerNumber,str,str);
    // printf(" (%d)\n",return_og);

    // ft_printf("FT: |%012p|\n",12);
    // printf("OG: |%012p|\n",12);



    // return_ft = ft_printf("FT: Test%%%% %c %d %d %s %p\n",'a',-1123,11200,"Hello World",ptr);
    // return_og =    printf("OG: Test%%%% %c %d %d %s %p\n",'a',-1123,11200,"Hello World",ptr);
    // printf("\n\n%d == %d\n\n",return_ft,return_og);

    // return_ft = ft_printf("FT: %s\0%s","Hello","World");
    // printf(" (%d)\n",return_ft);
    // return_og =    printf("OG: %s\0%s","Hello","World");
    // printf(" (%d)\n",return_og);

    // return_ft = ft_printf(" NULL %s NULL \n", NULL);
    // return_og = printf(" NULL %s NULL \n", NULL);

    // return_ft = ft_printf(" %8p %8p\n", ptr, 0);
    // return_og = printf(" %p %p\n", ptr, 0);
    
    // int decimalNum = 42;
    // int hexNum = 0x2A;
    // int octalNum = 052;

    // ft_printf("Decimal using %%i: %i\n", decimalNum);
    // printf("Decimal using %%i: %i\n\n", decimalNum);

    // ft_printf("Hexadecimal using %%i: %i\n", hexNum);
    // printf("Hexadecimal using %%i: %i\n\n", hexNum);

    // ft_printf("Hexadecimal using %%i: %i\n", hexNum);
    // printf("Octal using %%i: %i\n", octalNum);


    int test_cases[] = {0,-1,1,9,10,11,15,16,17,99,100,101,-9,-10,-11,-14,-15,-16,-99};

    for (size_t i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++) {
        // test_d(test_cases[i]);
        // test_i(test_cases[i]);
        // test_u(test_cases[i]);
        // test_p(test_cases[i]);
        // test_x(test_cases[i]);
        // test_X(test_cases[i]);
    }

    // test_mix();

    char *test_cases_s[] = {"Hello Worldasdadad pls work", "", "\0"};
    for (size_t i = 0; i < sizeof(test_cases_s) / sizeof(test_cases_s[0]); i++) {
        test_s(test_cases_s[i]);
    }
}

