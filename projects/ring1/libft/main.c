/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:20:49 by escura            #+#    #+#             */
/*   Updated: 2023/11/20 16:46:30 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
# include <assert.h>
# include <ctype.h>
# include <stdio.h>
# include <string.h>
# include <time.h>

/* COLORS */

void blue(void)
{
	printf("\x1B[34m");
}

void gray(void)
{
	printf("\033[30;1m");
}

void green(void)
{
	printf("\x1B[32m");
}

void red(void)
{
	printf("\x1B[31m");
}

void yellow(void)
{
	printf("\x1B[33m");
}

void cyan(void)
{
	printf("\x1B[36m");
}

void reset(void)
{
	printf("\x1B[0m");
}

void hello(void)
{
	yellow();
	printf("\nLibft tester - https://github.com/emsa001/libft\n\n");
}

/* EXERCISES */

int check_ft_atoi(void)
{
	int response = 1;

	yellow();
	printf("==========[ FT_ATOI ]==========\n");
	char *str_atoi[] = {
		"12123",
		"   19212 123 123",
		"42as 1asd2 a3",
		"-12389          48",
		"2147483647",
		"-2147483648",
		"2147483648",
		"21474--83648",
		"++2483648",
		"-+214836+4-8",
		"     -     213123123",
		"   12998833 ----3",
		"    "};
	int length = sizeof(str_atoi) / sizeof(str_atoi[0]);
	for (int i = 0; i < length; i++)
	{
		int expected = atoi(str_atoi[i]);
		int result = ft_atoi(str_atoi[i]);
		if (expected == result)
		{
			green();
			printf("✅  ");
		}
		else
		{
			red();
			printf("❌  ");
			response = 0;
		}
		printf("Test %2d. ", i);
		gray();
		printf("expected: %-12d", expected);
		yellow();
		printf(" | ");
		gray();
		printf("received: %-12d\n", result);
	}
	printf("\n");

	return response;
}

int check_ft_bzero(void)
{
	int response = 1;
	yellow();
	printf("=========[ FT_BZERO ]=========\n");
	for (int i = 0; i < 5; i++)
	{
		char ft_bzero_1[i];
		char bzero_1[i];
		ft_bzero(ft_bzero_1, sizeof(ft_bzero_1));
		bzero(bzero_1, sizeof(bzero_1));
		int result = memcmp(ft_bzero_1, bzero_1, sizeof(ft_bzero_1));

		if (result == 0)
		{
			green();
			printf("✅  ");
		}
		else
		{
			red();
			printf("❌  ");
			response = 0;
		}
		printf("Test %2d. ", i);
		gray();
		printf("expected: %-12d\n", result);
	}

	printf("\n");
	return response;
}

int check_ft_calloc(void)
{
	int response = 1;
	yellow();
	printf("=========[ FT_CALLOC ]=========\n");
	printf("\n");

	return response;
}

int check_ft_issomething(char *name, int (*f1)(int), int (*f2)(int))
{
	int response = 1;

	yellow();
	printf("=========[ %s ]=========\n", name);
	for (int i = 0; i <= 127; i++)
	{
		int expected = f1(i);
		int result = f2(i);
		if (expected != result)
		{
			red();
			printf("❌  ");
			response = 0;

			printf("Test %2d. ", i);
			gray();
			printf("expected: %-12d", expected);
			yellow();
			printf(" | ");
			gray();
			printf("received: %-12d (%d)\n", result, i);
		}	
	}
	if(response){
		green();
		printf("✅  ");
		printf("All tests passed");
	}

	printf("\n\n");
	return response;
}

int check_ft_memchr()
{
	yellow();
	printf("=========[ FT_MEMCHR ]=========\n");
	int response = 1;
	char *strs[] = {"Hello World!", "This is test", "0123456789"};
	char c[] = {'W', 's', '5'};
	size_t n[] = {13, 10, 5};

	int length = sizeof(strs) / sizeof(strs[0]);
	for (int i = 0; i < length; i++)
	{
		void *result = ft_memchr(strs[i], c[i], n[i]);
		void *expected = memchr(strs[i], c[i], n[i]);
		if ((result == expected || (result && expected && memcmp(result, expected, (unsigned long)n) == 0)))
		{
			green();
			printf("✅  ");
		}
		else
		{
			red();
			printf("❌  ");
			response = 0;
		}
		printf("Test %2d. ", i);
		gray();
		printf("expected: %-12s", expected);
		yellow();
		printf(" | ");
		gray();
		printf("received: %-12s (%s)\n", result, strs[i]);
	}

	printf("\n");
	return response;
}

int check_ft_memcmp()
{
	yellow();
	printf("=========[ FT_MEMCMP ]=========\n");
	int response = 1;
	char *strs1[] = {"Hello World!", "This is test", "0123456789"};
	char *strs2[] = {"Hello World!", "This ist", "01345679"};
	size_t n[] = {13, 10, 5};

	int length = sizeof(strs1) / sizeof(strs1[0]);
	for (int i = 0; i < length; i++)
	{
		int result = ft_memcmp(strs1[i], strs2[i], n[i]);
		int expected = memcmp(strs1[i], strs2[i], n[i]);
		if (result == expected)
		{
			green();
			printf("✅  ");
		}
		else
		{
			red();
			printf("❌  ");
			response = 0;
		}
		printf("Test %2d. ", i);
		gray();
		printf("expected: %-12d", expected);
		yellow();
		printf(" | ");
		gray();
		printf("received: %d (%s)\n", result, strs1[i]);
	}

	printf("\n");
	return response;
}

int check_ft_memcpy()
{
	yellow();
	printf("=========[ FT_MEMCPY ]=========\n");
	int response = 1;
	char *src[] = {"Hello World!", "This is test", "0123456789"};
	char dest[50];
	size_t n[] = {13, 10, 5};

	int length = sizeof(src) / sizeof(src[0]);
	for (int i = 0; i < length; i++)
	{
		void *result = ft_memcpy(dest, src[i], n[i]);
		dest[n[i]] = '\0'; // Ensure null-termination
		void *expected = memcpy(dest, src[i], n[i]);
		if (result == expected || (result && expected && memcmp(result, expected, n[i]) == 0))
		{
			green();
			printf("✅  ");
		}
		else
		{
			red();
			printf("❌  ");
			response = 0;
		}
		printf("Test %2d. ", i);
		gray();
		printf("expected: %-12s", (char *)expected);
		yellow();
		printf(" | ");
		gray();
		printf("received: %-12s (%s)\n", (char *)result, src[i]);
	}

	printf("\n");
	return response;
}

int check_ft_memmove()
{
	yellow();
	printf("=========[ FT_MEMMOVE ]=========\n");
	int response = 1;
	char *strs[] = {"Hello World!", "This is test", "0123456789"};
	char dest_ft[50] = "asd";
	char dest_og[50] = "asd";
	size_t n[] = {1, 10, 5};

	int length = sizeof(strs) / sizeof(strs[0]);
	for (int i = 0; i < length; i++)
	{
		void *result = ft_memmove(dest_ft, strs[i], n[i]);
		void *expected = memmove(dest_og, strs[i], n[i]);

		if (strcmp(result, expected) == 0 && (memcmp(result, expected, n[i]) == 0))
		{
			green();
			printf("✅  ");
		}
		else
		{
			red();
			printf("❌  ");
			response = 0;
		}
		printf("Test %2d. ", i);
		gray();
		printf("expected: %-12s (%s)", (char *)expected, dest_og);
		yellow();
		printf(" | ");
		gray();
		printf("received: %-12s (%s)\n", (char *)result, dest_ft);
	}

	printf("\n");
	return response;
}

int check_ft_memset()
{
	yellow();
	printf("=========[ FT_MEMSET ]=========\n");
	int response = 1;
	char dest[50];
	char expected[50];
	size_t n[] = {10, 11, 8};
	int c[] = {'*', 'A', '5'};

	int length = sizeof(n) / sizeof(n[0]);
	for (int i = 0; i < length; i++)
	{
		void *result = ft_memset(dest, c[i], n[i]);
		void *standard = memset(expected, c[i], n[i]);
		dest[n[i]] = '\0';
		expected[n[i]] = '\0';

		if (result == dest || (result && memcmp(result, expected, n[i]) == 0))
		{
			green();
			printf("✅  ");
		}
		else
		{
			red();
			printf("❌  ");
			response = 0;
		}
		printf("Test %2d. ", i);
		gray();
		printf("expected: %-12s", (char *)standard);
		yellow();
		printf(" | ");
		gray();
		printf("received: %s\n", (char *)result);
	}

	printf("\n");
	return response;
}

int check_ft_strchr()
{
	yellow();
	printf("=========[ FT_STRCHR ]=========\n");
	int response = 1;
	char *strs[] = {"Hello World!", "This is test", "0123456789"};
	char c[] = {'W', 's', '5'};

	int length = sizeof(strs) / sizeof(strs[0]);
	for (int i = 0; i < length; i++)
	{
		void *result = ft_strchr(strs[i], c[i]);
		void *expected = strchr(strs[i], c[i]);

		if (result == expected)
		{
			green();
			printf("✅  ");
		}
		else
		{
			red();
			printf("❌  ");
			response = 0;
		}
		printf("Test %2d. ", i);
		gray();
		printf("expected: %-12s", (char *)expected);
		yellow();
		printf(" | ");
		gray();
		printf("received: %s\n", (char *)result);
	}

	printf("\n");
	return response;
}

int check_ft_substr(void)
{
    int response = 1;

    yellow();
    printf("=========[ FT_SUBSTR ]=========\n");

    typedef struct s_testcase {
        char *str;
        int start;
        int len;
        char *expected;
    } t_param;

    t_param cases[] = {
        {"Lorem ipsum", 2, 4, "rem "},
        {"Hello World", 6, 7, "World"},
        {"Coding is fun", 3, 7, "ing is "},
        {"not really", 2, 8, "t really"},
        {"Lorem ipsum dolor sit amet", 3, 4, "em i"},
        {"Pls work", 4, 5, "work"},
        {"test123456789", 0, 11, "test1234567"},
        {"tripouille", 10, 1, ""}
    };

    for (int i = 0; i < sizeof(cases) / sizeof(cases[0]); i++)
    {
        t_param *current_case = &cases[i];
        char *result = ft_substr(current_case->str, current_case->start, current_case->len);

        if (strcmp(current_case->expected, result) == 0)
        {
            green();
            printf("✅  ");
        }
        else
        {
            red();
            printf("❌  ");
            response = 0;
        }

        printf("Test %2d. ", i);
        gray();
        printf("expected: %-12s", current_case->expected);
        yellow();
        printf(" | ");
        gray();
        printf("received: %-12s\n", result);
        free(result);
    }

    printf("\n");

    return response;
}


int check_ft_strdup()
{
	yellow();
	printf("=========[ FT_STRDUP ]=========\n");
	int response = 1;
	char *strs[] = {"Hello World!", "This is test", "0123456789"};

	int length = sizeof(strs) / sizeof(strs[0]);
	for (int i = 0; i < length; i++)
	{
		void *result = ft_strdup(strs[i]);
		void *expected = strdup(strs[i]);

		if (result && expected && strcmp(result, expected) == 0)
		{
			green();
			printf("✅  ");
		}
		else
		{
			red();
			printf("❌  ");
			response = 0;
		}
		printf("Test %2d. ", i);
		gray();
		printf("expected: %-12s", (char *)expected);
		yellow();
		printf(" | ");
		gray();
		printf("received: %s\n", (char *)result);

		free(result);
		free(expected);
	}

	printf("\n");
	return response;
}

int check_ft_strjoin(void)
{
	int response = 1;
	int length;
	char *expected;
	char *result;

	yellow();
	printf("=========[ FT_STRJOIN ]=========\n");
	char *s1[] = {
		"Lorem",
		"Hello ",
		"Cod",
		"not ",
		"Pls ",
		"test",
	};
	char *s2[] = {
		" ipsum",
		"World",
		"ing",
		"really",
		"work",
		"",
	};
	char *expected_strs[] = {
		"Lorem ipsum",
		"Hello World",
		"Coding",
		"not really",
		"Pls work",
		"test",
	};
	length = sizeof(s1) / sizeof(s1[0]);
	for (int i = 0; i < length; i++)
	{
		expected = expected_strs[i];
		result = ft_strjoin(s1[i], s2[i]);
		if (strcmp(expected, result) == 0)
		{
			green();
			printf("✅  ");
		}
		else
		{
			red();
			printf("❌  ");
			response = 0;
		}
		printf("Test %2d. ", i);
		gray();
		printf("expected: %-12s", expected);
		yellow();
		printf(" | ");
		gray();
		printf("received: %-12s\n", result);
		free(result);
	}

	printf("\n");
	return response;
}

size_t check_ft_strlx(const char *name, size_t (*ft_function)(char *, const char *, size_t), size_t (*original_function)(char *, const char *, size_t))
{
	yellow();
	printf("=========[ %s ]=========\n", name);
	int response = 1;
	char dest_ft[1000];
	char dest_og[1000];
	char *src[] = {"World!", "test", "6789", "", "","second is empty",};
	char *dests[] = {"Hello ", "This is ", "12345", "", "",""};

	size_t dest_size[] = {6, 15, 10, 0, 10,100};

	int length = sizeof(src) / sizeof(src[0]);
	size_t total_diff = 0;

	for (int i = 0; i < length; i++)
	{
		strncpy(dest_ft, dests[i], dest_size[i]);
		strncpy(dest_og, dests[i], dest_size[i]);
		dest_ft[dest_size[i] - 1] = '\0';
		dest_og[dest_size[i] - 1] = '\0';

		size_t result_ft = ft_function(dest_ft, src[i], dest_size[i]);
		size_t result_original = original_function(dest_og, src[i], dest_size[i]);

		size_t diff = result_ft - result_original;
		total_diff += diff;

		if (result_ft == result_original && strcmp(dest_ft, dest_og) == 0)
		{
			green();
			printf("✅  ");
		}
		else
		{
			red();
			printf("❌  ");
			response = 0;
		}
		printf("Test %2d. ", i);
		gray();
		printf("expected: %-16s (%zu)", dest_og, result_original);
		yellow();
		printf(" | ");
		gray();
		printf("received: %-16s (%zu)\n", dest_ft, result_ft);
	}

	reset();
	printf("\n");
	return response;
}

int check_ft_strlen()
{
	yellow();
	printf("=========[ FT_STRLEN ]=========\n");
	int response = 1;
	char *strs[] = {"Hello World!", "This is test", "0123456789"};

	int length = sizeof(strs) / sizeof(strs[0]);
	for (int i = 0; i < length; i++)
	{
		int result = ft_strlen(strs[i]);
		int expected = strlen(strs[i]);

		if (result == expected)
		{
			green();
			printf("✅  ");
		}
		else
		{
			red();
			printf("❌  ");
			response = 0;
		}
		printf("Test %2d. ", i);
		gray();
		printf("expected: %d", expected);
		yellow();
		printf(" | ");
		gray();
		printf("received: %d\n", result);
	}

	printf("\n");
	return response;
}

int check_ft_strncmp()
{
	yellow();
	printf("=========[ FT_STRNCMP ]=========\n");
	int response = 1;
	char *s1[] = {"Hello World!", "This is a test", "12345","test\200"};
	char *s2[] = {"Hello Earth!", "This is test", "12","test\0"};

	size_t n[] = {13, 12, 5,6};

	int length = sizeof(s1) / sizeof(s1[0]);
	for (int i = 0; i < length; i++)
	{
		int result = ft_strncmp(s1[i], s2[i], n[i]);
		int expected = strncmp(s1[i], s2[i], n[i]);

		if (result == expected)
		{
			green();
			printf("✅  ");
		}
		else
		{
			red();
			printf("❌  ");
			response = 0;
		}
		printf("Test %2d. ", i);
		gray();
		printf("expected: %-4d", expected);
		yellow();
		printf(" | ");
		gray();
		printf("received: %-4d\n", result);
	}

	printf("\n");
	return response;
}

int check_ft_strnstr()
{
	yellow();
	printf("=========[ FT_STRNSTR ]=========\n");
	int response = 1;
	char *haystack[] = {"Hello World!", "This is a test", "0123456789", " ", "test"};
	char *needle[] = {"World", "test", "567", "   ", ""};

	size_t len[] = {13, 15, 10};

	int length = sizeof(haystack) / sizeof(haystack[0]);
	for (int i = 0; i < length; i++)
	{
		void *result = ft_strnstr(haystack[i], needle[i], len[i]);
		void *expected = strnstr(haystack[i], needle[i], len[i]);

		if (result == expected)
		{
			green();
			printf("✅  ");
		}
		else
		{
			red();
			printf("❌  ");
			response = 0;
		}
		printf("Test %2d. ", i);
		gray();
		printf("expected: %-12s", (char *)expected);
		yellow();
		printf(" | ");
		gray();
		printf("received: %-12s\n", (char *)result);
	}

	printf("\n");
	return response;
}

int check_ft_strrchr()
{
	yellow();
	printf("=========[ FT_STRRCHR ]=========\n");
	int response = 1;
	char *strs[] = {"Hello World!", "This is a test", "0123456789"};
	char c[] = {'o', 't', '5'};

	int length = sizeof(strs) / sizeof(strs[0]);
	for (int i = 0; i < length; i++)
	{
		void *result = ft_strrchr(strs[i], c[i]);
		void *expected = strrchr(strs[i], c[i]);

		if (result == expected)
		{
			green();
			printf("✅  ");
		}
		else
		{
			red();
			printf("❌  ");
			response = 0;
		}
		printf("Test %2d. ", i);
		gray();
		printf("expected: %-12s", (char *)expected);
		yellow();
		printf(" | ");
		gray();
		printf("received: %-12s\n", (char *)result);
	}

	printf("\n");
	return response;
}

int check_ft_toupper_tolower(const char *name, int (*ft_function)(int), int (*original_function)(int))
{
	yellow();
	printf("=========[ %s ]=========\n", name);
	int response = 1;
	char chars[] = {'A', 'b', '3', ' ', '$', 'z', 'Z', '0'};

	int length = sizeof(chars) / sizeof(chars[0]);
	for (int i = 0; i < length; i++)
	{
		int result_ft = ft_function(chars[i]);
		int result_original = original_function(chars[i]);

		if (result_ft == result_original)
		{
			green();
			printf("✅  ");
		}
		else
		{
			red();
			printf("❌  ");
			response = 0;
		}
		printf("Test %2d. ", i);
		gray();
		printf("expected: %-4d (%c)", result_original, result_original);
		yellow();
		printf(" | ");
		gray();
		printf("received: %-4d (%c)\n", result_ft, result_ft);
	}

	printf("\n");
	return response;
}

int check_ft_strtrim()
{
	yellow();
	printf("=========[ FT_STRTRIM ]=========\n");
	int response = 1;

    typedef struct s_testcase {
        char *str;
        char *set;
        char *expected;
    } t_param;

    t_param cases[] = {
        {"   Hello World!   ", " ",  "Hello World!"},
		{"lorem \t ipsum \t dolor \t sit \t amet"," ","lorem \t ipsum \t dolor \t sit \t amet"}
    };

    for (int i = 0; i < sizeof(cases) / sizeof(cases[0]); i++)
    {
        t_param *current_case = &cases[i];
		char *result = ft_strtrim(current_case->str, current_case->set);
        if (strcmp(result, current_case->expected) == 0)
		{
			green();
			printf("✅  ");
		}
		else
		{
			red();
			printf("❌  ");
			response = 0;
		}
		printf("Test %2d. ", i);
		gray();
		printf("expected: %-20s", current_case->expected);
		yellow();
		printf(" | ");
		gray();
		printf("received: %-20s\n", result);

		free(result);
    }

	printf("\n");
	return response;
}

int check_ft_split() {
    int response = 1;

    yellow();
    printf("=========[ FT_SPLIT ]=========\n");

    typedef struct s_testcase {
        char *s;
        char c;
        char *expected[1024];
    } t_param;

    t_param cases[] = {
        { "    Hello,            World!    ", ' ', {"Hello,", "World!"} },
		{ "1,2,3,4,5,6,7,8,9,10", ',', {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"} },
        {NULL, '\0', NULL}
    };

    t_param *tc = cases;
    while (tc->s != NULL)
    {
        char **result = ft_split(tc->s, tc->c);
		yellow();
		printf("Recived: |");
		gray();
		printf("%s",tc->s);
		yellow();
		printf("| split at: |");
		gray();
		printf("%c",tc->c);
		yellow();
		printf("|\n");
        for (int i = 0; tc->expected[i] != NULL; i++)
        {
            if (strcmp(result[i], tc->expected[i]) != 0) {
				red();
				printf("❌ Test %2d. ", i);
				gray();
				printf("expected: |%s|", tc->expected[i]);
				yellow();
				printf(" | ");
				gray();
				printf("received: |%s|\n", result[i]);
                response = 0;
            }
			yellow();
			printf("> ");
			gray();
			printf(" |%s|\n",result[i]);
        }
        tc++;
    }

	if(response){
		green();
		printf("✅  ");
		printf("All tests passed");
	}
	printf("\n\n");
    return response;
}

int check_ft_itoa() {
    int response = 1;

    yellow();
    printf("=========[ FT_ITOA ]=========\n");

	srand(time(NULL));
    for(int i = 0; i <= 1000; i++){
        int nb = rand();
		if(atoi(ft_itoa(nb)) != nb){
			red();
			printf("❌ Test %2d. ", i);
			gray();
			printf("expected: %-20d", nb);
			yellow();
			printf(" | ");
			gray();
			printf("received: %-20s\n", ft_itoa(nb));
			response = 0;
		}
    }

	for(int i = 0; i <= 1000; i++){
		int nb = -rand();
		if(atoi(ft_itoa(nb)) != nb){
			red();
			printf("❌ Test %2d. ", i);
			gray();
			printf("expected: %-20d", nb);
			yellow();
			printf(" | ");
			gray();
			printf("received: %-20s\n", ft_itoa(nb));
			response = 0;
		}
    }

	if(response){
		green();
		printf("✅  ");
		printf("All tests passed");
	}
	printf("\n\n");
    return response;
}

char ft_strmapi_1(unsigned int i, char c)
{
	return ft_toupper(c);
}

char ft_strmapi_2(unsigned int i, char c)
{
	return ft_tolower(c);
}

char ft_strmapi_3(unsigned int i, char c)
{
	return i + '0';
}

int check_ft_strmapi() {
    int response = 1;

    yellow();
    printf("=========[ FT_STRMAPI ]=========\n");


	typedef struct s_testcase {
		char *s;
		char (*f)(unsigned int, char);
		char *expected[1024];
	} t_param;

	t_param cases[] = {
		{ "hello world", ft_strmapi_1, "HELLO WORLD"},
		{ "HELLO WORLD", ft_strmapi_2, "hello world"},
		{ "hello", ft_strmapi_3, "01234"},
		{NULL,ft_strmapi_1, NULL}
	};

    t_param *tc = cases;
    while (tc->s != NULL)
    {
		char *result = ft_strmapi(tc->s, tc->f);
        
        for (int i = 0; result != NULL && tc->expected[i] != NULL; i++)
        {
            if (strcmp(result, tc->expected[i]) != 0) {
				red();
				printf("❌ Test %2d. ", i);
				gray();
				printf("expected: %-20s", tc->expected[i]);
				yellow();
				printf(" | ");
				gray();
				printf("received: %-20s\n", result);
                response = 0;
            }
        }
        tc++;
    }

	if(response){
		green();
		printf("✅  ");
		printf("All tests passed");
	}
	printf("\n\n");
    return response;
}


void increment_char(unsigned int i, char *c) {
	*c = *c + 1;
}

int check_ft_striteri() {
    int response = 1;

    yellow();
    printf("=========[ FT_STRITERI ]=========\n");

    typedef struct s_testcase {
        char s[42];
        void (*f)(unsigned int, char *);
        char *expected[1024];
    } t_param;

    t_param cases[] = {
        {"abc", increment_char, "bcd"},
		{"eee", increment_char, "fff"},
		{"123", increment_char, "234"},
		{"\0",increment_char, "\0"}
    };

    t_param *tc = cases;
	int i = 0;
    while (tc->s[0] != '\0')
    {
		ft_striteri(&tc->s[i], tc->f);
		
		if (strcmp(tc->s, tc->expected[i]) != 0) {
			red();
			printf("❌ Test %2d. ", i);
			gray();
			printf("expected: %-20s", tc->expected[i]);
			yellow();
			printf(" | ");
			gray();
			printf("received: %-20s\n", &tc->s[i]);
			response = 0;
		}
        tc++;
    }

    if (response) {
        green();
        printf("✅  ");
        printf("All tests passed");
    }
    printf("\n\n");
    return response;
}


char *check_ft_putx(int temp_fd) {
    temp_fd = open("temp_file.txt", O_RDONLY);

    if (temp_fd == -1) {
        perror("Error opening file for reading");
        return NULL;
    }

    char buffer[1024];
    ssize_t bytesRead = read(temp_fd, buffer, sizeof(buffer));

    close(temp_fd);

    if (remove("temp_file.txt") != 0) {
        perror("Error deleting file");
        return NULL;
    }

    buffer[bytesRead] = '\0';
    return strdup(buffer);
}

int check_ft_putnbr_fd() {
	int response = 1;
	yellow();
    printf("=========[ FT_PUTNBR_FD ]=========\n");

    typedef struct s_testcase {
        int nb;
        char *expected;
    } t_param;

    t_param cases[] = {
        {42, "42"},
        {-312, "-312"},
		{-2147483648, "-2147483648"},
        {0, NULL} 
    };

    t_param *tc = cases;
    int i = 0;
   	while (tc->expected != NULL) {
		int temp_fd = open("temp_file.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);

		if (temp_fd == -1) {
			perror("Error creating file");
			return 0;
		}

		ft_putnbr_fd(tc->nb, temp_fd);
		close(temp_fd);
		char *result = check_ft_putx(temp_fd);
		if (result == NULL) {
			red();
			printf("❌ Test %d. ", i);
			gray();
			printf("Expected: |%s|", tc->expected);
			yellow();
			printf(" | ");
			gray();
			printf("Received: NULL\n");
			response = 0;
		} else if (strcmp(result, tc->expected) != 0) {
			red();
			printf("❌ Test %d. ", i);
			gray();
			printf("Expected: |%s|", tc->expected);
			yellow();
			printf(" | ");
			gray();
			printf("Received: |%s|\n", result);
			response = 0;
		} else {
			printf("✅ Test %d passed\n", i);
		}

		free(result);

		tc++;
		i++;
	}
	printf("\n");
	return response;
}

int check_ft_putchar_fd() {
	int response = 1;
	
	yellow();
    printf("=========[ FT_PUTCHAR_FD ]=========\n");

    typedef struct s_testcase {
        char nb;
        char *expected;
    } t_param;

    t_param cases[] = {
        {'1', "1"},
        {'a', "a"},
		{'\n', "\n"},
        {0, NULL} 
    };

    t_param *tc = cases;
    int i = 0;
   	while (tc->expected != NULL) {
		int temp_fd = open("temp_file.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);

		if (temp_fd == -1) {
			perror("Error creating file");
			return 0;
		}

		ft_putchar_fd(tc->nb, temp_fd);
		close(temp_fd);

		char *result = check_ft_putx(temp_fd);
		if (result == NULL) {
			red();
			printf("❌ Test %d. ", i);
			gray();
			printf("Expected: |%s|", tc->expected);
			yellow();
			printf(" | ");
			gray();
			printf("Received: NULL\n");
			response = 0;
		} else if (strcmp(result, tc->expected) != 0) {
			red();
			printf("❌ Test %d. ", i);
			gray();
			printf("Expected: |%s|", tc->expected);
			yellow();
			printf(" | ");
			gray();
			printf("Received: |%s|\n", result);
			response = 0;
		} else {
			printf("✅ Test %d passed\n", i);
		}

		free(result);

		tc++;
		i++;
	}
	printf("\n");
	return response;
}

int check_ft_putstr_fd() {
	int response = 1;
	
	yellow();
    printf("=========[ FT_PUTSTR_FD ]=========\n");

    typedef struct s_testcase {
        char *expected;
    } t_param;

    t_param cases[] = {
        {"Hello World"},
		{"42Wolfsburg"},
		{"Bueons dias my friend"},
		{"Abra kadabra"},
        {NULL} 
    };

    t_param *tc = cases;
    int i = 0;
   	while (tc->expected != NULL) {
		int temp_fd = open("temp_file.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);

		if (temp_fd == -1) {
			perror("Error creating file");
			return 0;
		}

		ft_putstr_fd(tc->expected, temp_fd);
		close(temp_fd);

		char *result = check_ft_putx(temp_fd);
		if (result == NULL) {
			red();
			printf("❌ Test %d. ", i);
			gray();
			printf("Expected: |%s|", tc->expected);
			yellow();
			printf(" | ");
			gray();
			printf("Received: NULL\n");
			response = 0;
		} else if (strcmp(result, tc->expected) != 0) {
			red();
			printf("❌ Test %d. ", i);
			gray();
			printf("Expected: |%s|", tc->expected);
			yellow();
			printf(" | ");
			gray();
			printf("Received: |%s|\n", result);
			response = 0;
		} else {
			printf("✅ Test %d passed\n", i);
		}

		free(result);

		tc++;
		i++;
	}
	printf("\n");
	return response;
}

int check_ft_putendl_fd() {
	int response = 1;
	
	yellow();
    printf("=========[ FT_PUTENDL_FD ]=========\n");

    typedef struct s_testcase {
		char *s;
        char *expected;
    } t_param;

    t_param cases[] = {
        {"Hello World","Hello World\n"},
		{"42Wolfsburg","42Wolfsburg\n"},
		{"Bueons dias my friend","Bueons dias my friend\n"},
		{"Abra kadabra","Abra kadabra\n"},
        {NULL} 
    };

    t_param *tc = cases;
    int i = 0;
   	while (tc->expected != NULL) {
		int temp_fd = open("temp_file.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);

		if (temp_fd == -1) {
			perror("Error creating file");
			return 0;
		}

		ft_putendl_fd(tc->s, temp_fd);
		close(temp_fd);

		char *result = check_ft_putx(temp_fd);
		if (result == NULL) {
			red();
			printf("❌ Test %d. ", i);
			gray();
			printf("Expected: |%s|", tc->expected);
			yellow();
			printf(" | ");
			gray();
			printf("Received: NULL\n");
			response = 0;
		} else if (strcmp(result, tc->expected) != 0) {
			red();
			printf("❌ Test %d. ", i);
			gray();
			printf("Expected: |%s|", tc->expected);
			yellow();
			printf(" | ");
			gray();
			printf("Received: |%s|\n", result);
			response = 0;
		} else {
			printf("✅ Test %d passed\n", i);
		}

		free(result);

		tc++;
		i++;
	}
	printf("\n");
	return response;
}

int check_lst(t_list *lst, int expected_size, char *expected_content[])
{
    int size = ft_lstsize(lst);
    if (size != expected_size)
    {
        printf("Error: Unexpected list size. Expected %d, got %d.\n", expected_size, size);
        return 0;
    }

    t_list *current = lst;
    for (int i = 0; i < expected_size; i++)
    {
        if (current == NULL || current->content != expected_content[i])
        {
            printf("Error: Unexpected content at position %d.\n", i);
            return 0;
        }
        current = current->next;
    }

    printf("List check passed.\n");
    return 1;
}

void test_ft_lstlast()
{
    // Test 1: Empty list
    t_list *emptyList = NULL;
    t_list *result1 = ft_lstlast(emptyList);
    if (result1 == NULL)
        printf("Test 1 passed (empty list).\n");
    else
        printf("Test 1 failed (empty list).\n");

    // Test 2: List with one element
    t_list *listWithOne = ft_lstnew("Element 1");
    t_list *result2 = ft_lstlast(listWithOne);
    if (result2 == listWithOne)
        printf("Test 2 passed (list with one element).\n");
    else
        printf("Test 2 failed (list with one element).\n");

    // Test 3: List with multiple elements
    t_list *myList = NULL;
    ft_lstadd_front(&myList, ft_lstnew("Element 3"));
    ft_lstadd_front(&myList, ft_lstnew("Element 2"));
    ft_lstadd_front(&myList, ft_lstnew("Element 1"));
    t_list *result3 = ft_lstlast(myList);
    if (result3 != NULL && strcmp(result3->content,"Element 3") == 0)
        printf("Test 3 passed (list with multiple elements).\n");
    else
        printf("Test 3 failed (list with multiple elements).\n");

	// Test 4: List with multiple elements from first to last
    t_list *myList2 = NULL;
    ft_lstadd_back(&myList2, ft_lstnew("Element 1"));
    ft_lstadd_back(&myList2, ft_lstnew("Element 2"));
    ft_lstadd_back(&myList2, ft_lstnew("Element 3"));
    t_list *result4 = ft_lstlast(myList2);
    if (result4 != NULL && strcmp(result4->content,"Element 3") == 0)
        printf("Test 3 passed (list with multiple elements).\n");
    else
        printf("Test 3 failed (list with multiple elements).\n");
}

void delete_content(void *content)
{
    free(content);
}

void *double_content(void *content)
{
    int *value = (int *)content;
    int *result = (int *)malloc(sizeof(int));
    if (!result)
        return NULL;

    *result = (*value) * 2;
    return result;
}

void print_list(t_list *lst)
{
    while (lst)
    {
        printf("%d -> ", *((int *)lst->content));
        lst = lst->next;
    }
    printf("NULL\n");
}

void test_ft_lstmap()
{
    t_list *original_list = NULL;

    // Create a sample linked list: 1 -> 2 -> 3
    for (int i = 1; i <= 3; ++i)
    {
        t_list *new_node = ft_lstnew((void *)malloc(sizeof(int)));
        *((int *)new_node->content) = i;
        ft_lstadd_back(&original_list, new_node);
    }

    // Print original list
    printf("Original List: ");
    print_list(original_list);

    // Apply ft_lstmap
    t_list *mapped_list = ft_lstmap(original_list, &double_content, &delete_content);

    // Print mapped list
    printf("Mapped List: ");
    print_list(mapped_list);

    // Clean up memory
    ft_lstclear(&original_list, &delete_content);
    ft_lstclear(&mapped_list, &delete_content);
}

int main(void)
{

	char failed_functions[1024];

	hello();

	// !check_ft_atoi() && strcat(failed_functions, "ft_atoi ");
	// !check_ft_bzero() && strcat(failed_functions, "ft_bzero ");
	// // !check_ft_calloc() && strcat(failed_functions, "ft_calloc ");
	// !check_ft_issomething("FT_ISALNUM", ft_isalnum, isalnum) && strcat(failed_functions, "ft_isalnum ");
	// !check_ft_issomething("FT_ISALPHA", ft_isalpha, isalpha) && strcat(failed_functions, "ft_isalpha ");
	// !check_ft_issomething("FT_ISASCII", ft_isascii, isascii) && strcat(failed_functions, "ft_isascii ");
	// !check_ft_issomething("FT_ISDIGIT", ft_isdigit, isdigit) && strcat(failed_functions, "ft_isalnum ");
	// !check_ft_issomething("FT_ISPRINT", ft_isprint, isprint) && strcat(failed_functions, "ft_isprint ");
	// !check_ft_memchr() && strcat(failed_functions, "ft_memchr");
	// !check_ft_memcmp() && strcat(failed_functions, "ft_memcmp");
	// !check_ft_memcpy() && strcat(failed_functions, "ft_memcpy");
	// !check_ft_memmove() && strcat(failed_functions, "ft_memmove");
	// !check_ft_memset() && strcat(failed_functions, "ft_memset");
	// !check_ft_strchr() && strcat(failed_functions, "ft_strchr");
	// !check_ft_strdup() && strcat(failed_functions, "ft_strdup");
	// !check_ft_strlx("FT_STRLCAT",ft_strlcat,strlcat) && strcat(failed_functions, "ft_strlcat");
	// !check_ft_strlx("FT_STRLCPY",ft_strlcpy, strlcpy) && strcat(failed_functions, "ft_strlcpy");
	// !check_ft_strlen() && strcat(failed_functions, "ft_strlen");
	// !check_ft_strncmp() && strcat(failed_functions, "ft_strncmp"); 
	// !check_ft_strnstr() && strcat(failed_functions, "ft_strnstr");
	// !check_ft_strrchr() && strcat(failed_functions, "ft_strrchr");
	// !check_ft_toupper_tolower("FT_TOUPPER", ft_toupper, toupper) && strcat(failed_functions, "ft_tolower");
	// !check_ft_toupper_tolower("FT_TOLOWER", ft_tolower, tolower) && strcat(failed_functions, "ft_tolower");

	// !check_ft_substr() && strcat(failed_functions, "ft_substr");
	// !check_ft_strjoin() && strcat(failed_functions, "ft_strjoin");
	// !check_ft_strtrim() && strcat(failed_functions, "ft_strtrim");
	!check_ft_split() && strcat(failed_functions, "ft_split");
	// !check_ft_itoa() && strcat(failed_functions, "ft_itoa");
	// !check_ft_strmapi() && strcat(failed_functions, "ft_strmapi");
	// !check_ft_striteri() && strcat(failed_functions, "ft_striteri");

	// check_ft_putchar_fd();
	// check_ft_putnbr_fd();
	// check_ft_putstr_fd();
	// check_ft_putendl_fd();


	/*  BONUS */

	// t_list *myList = NULL;

    // // Add elements to the list
    // ft_lstadd_front(&myList, ft_lstnew("Element 3"));
    // ft_lstadd_front(&myList, ft_lstnew("Element 2"));
    // ft_lstadd_front(&myList, ft_lstnew("Element 1"));

    // // Check the list
    // int result = check_lst(myList, 3, (char *[]){"Element 1", "Element 2", "Element 3"});
	// test_ft_lstlast();
	// test_ft_lstmap();
	
	red();
	printf("\nFailed functions: [ %s ]\n\n", failed_functions);
	reset();
}
