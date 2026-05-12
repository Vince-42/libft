#include "libft.h"
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

#ifndef TEST_GREEN
# define TEST_GREEN "\033[32m"
#endif

#ifndef TEST_RED
# define TEST_RED "\033[31m"
#endif

#ifndef TEST_YELLOW
# define TEST_YELLOW "\033[33m"
#endif

#ifndef TEST_RESET
# define TEST_RESET "\033[0m"
#endif

/* ************************************************************************** */
/*                               ft_split tests                                */
/* ************************************************************************** */

static void	free_split_result(char **result)
{
	int	i;

	if (!result)
		return ;
	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
}

static int	count_split_result(char **result)
{
	int	i;

	if (!result)
		return (-1);
	i = 0;
	while (result[i])
		i++;
	return (i);
}

static int	compare_split_result(char **result, char **expected)
{
	int	i;

	if (!result)
		return (0);
	i = 0;
	while (expected[i])
	{
		if (!result[i])
			return (0);
		if (strcmp(result[i], expected[i]) != 0)
			return (0);
		i++;
	}
	if (result[i] != NULL)
		return (0);
	return (1);
}

static void	print_split_array(char **array)
{
	int	i;

	if (!array)
	{
		printf("NULL");
		return ;
	}
	printf("[");
	i = 0;
	while (array[i])
	{
		printf("\"%s\"", array[i]);
		if (array[i + 1])
			printf(", ");
		i++;
	}
	printf("]");
}

static void	split_result(int ok, int *pass, int *fail)
{
	if (ok)
	{
		printf(TEST_GREEN "Status:   PASS\n\n" TEST_RESET);
		(*pass)++;
	}
	else
	{
		printf(TEST_RED "Status:   FAIL\n\n" TEST_RESET);
		(*fail)++;
	}
}

static void	check_split(int n, char const *s, char c,
		char **expected, int *pass, int *fail)
{
	char	**result;
	int		ok;

	result = ft_split(s, c);
	ok = compare_split_result(result, expected);

	printf("Test %02d: ft_split(\"%s\", '%c')\n", n, s, c);
	printf("Expected: ");
	print_split_array(expected);
	printf("\n");
	printf("Result:   ");
	print_split_array(result);
	printf("\n");
	printf("Count:    %d\n", count_split_result(result));

	split_result(ok, pass, fail);
	free_split_result(result);
}

static void	test_ft_split_extra(void)
{
	int		pass;
	int		fail;
	char	*e1[] = {"hello", "world", NULL};
	char	*e2[] = {"hello", NULL};
	char	*e3[] = {"hello", NULL};
	char	*e4[] = {"hello", NULL};
	char	*e5[] = {NULL};
	char	*e6[] = {NULL};
	char	*e7[] = {"a", "b", "c", NULL};
	char	*e8[] = {"a", "b", "c", NULL};
	char	*e9[] = {"tripouille", "42", NULL};
	char	*e10[] = {"tripouille", NULL};
	char	*e11[] = {"42", NULL};
	char	*e12[] = {"one", "two", "three", NULL};
	char	*e13[] = {"one", "two", "three", NULL};
	char	*e14[] = {"abc", NULL};
	char	*e15[] = {"abc", NULL};
	char	*e16[] = {"a", NULL};
	char	*e17[] = {"a", NULL};
	char	*e18[] = {"a", NULL};
	char	*e19[] = {"split", "this", "string", NULL};
	char	*e20[] = {"lots", "of", "spaces", NULL};
	char	*e21[] = {"tabs", "are", "here", NULL};
	char	*e22[] = {"new", "lines", "here", NULL};
	char	*e23[] = {"abc", "def", "ghi", NULL};
	char	*e24[] = {"abc", "def", "ghi", NULL};
	char	*e25[] = {"no delimiter", NULL};
	char	*e26[] = {"", NULL};

	pass = 0;
	fail = 0;
	printf(TEST_YELLOW "\n========== ft_split extra tests ==========\n\n" TEST_RESET);

	check_split(1, "hello world", ' ', e1, &pass, &fail);
	check_split(2, "hello", ' ', e2, &pass, &fail);
	check_split(3, " hello", ' ', e3, &pass, &fail);
	check_split(4, "hello ", ' ', e4, &pass, &fail);
	check_split(5, "", ' ', e5, &pass, &fail);
	check_split(6, "     ", ' ', e6, &pass, &fail);

	check_split(7, "a b c", ' ', e7, &pass, &fail);
	check_split(8, "  a   b   c  ", ' ', e8, &pass, &fail);
	check_split(9, "tripouille 42", ' ', e9, &pass, &fail);
	check_split(10, "   tripouille   ", ' ', e10, &pass, &fail);
	check_split(11, "   42", ' ', e11, &pass, &fail);

	check_split(12, "one,two,three", ',', e12, &pass, &fail);
	check_split(13, ",one,,two,,,three,", ',', e13, &pass, &fail);
	check_split(14, "abc", ',', e14, &pass, &fail);
	check_split(15, ",,,abc,,,", ',', e15, &pass, &fail);

	check_split(16, "a", ' ', e16, &pass, &fail);
	check_split(17, "a ", ' ', e17, &pass, &fail);
	check_split(18, " a", ' ', e18, &pass, &fail);

	check_split(19, "split:this:string", ':', e19, &pass, &fail);
	check_split(20, "lots    of      spaces", ' ', e20, &pass, &fail);
	check_split(21, "tabs\tare\there", '\t', e21, &pass, &fail);
	check_split(22, "new\nlines\nhere", '\n', e22, &pass, &fail);

	check_split(23, "abc--def--ghi", '-', e23, &pass, &fail);
	check_split(24, "--abc--def--ghi--", '-', e24, &pass, &fail);
	check_split(25, "no delimiter", ',', e25, &pass, &fail);
	check_split(26, "", '\0', e26, &pass, &fail);

	printf(TEST_YELLOW "============== ft_split summary ==============\n" TEST_RESET);
	printf(TEST_GREEN "Passed: %d\n" TEST_RESET, pass);
	printf(TEST_RED "Failed: %d\n" TEST_RESET, fail);
	printf("Total:  %d\n\n", pass + fail);
}


static void	strtrim_result(int ok, int *pass, int *fail)
{
	if (ok)
	{
		printf(TEST_GREEN "Status:   PASS\n\n" TEST_RESET);
		(*pass)++;
	}
	else
	{
		printf(TEST_RED "Status:   FAIL\n\n" TEST_RESET);
		(*fail)++;
	}
}

static void	check_strtrim(int n, char const *s1, char const *set,
		char const *expected, int *pass, int *fail)
{
	char	*result;
	int		ok;

	result = ft_strtrim(s1, set);
	ok = (result != NULL && strcmp(result, expected) == 0);

	printf("Test %02d: ft_strtrim(\"%s\", \"%s\")\n", n, s1, set);
	printf("Expected: \"%s\"\n", expected);
	if (result)
		printf("Result:   \"%s\"\n", result);
	else
		printf("Result:   NULL");
	printf("\n");

	strtrim_result(ok, pass, fail);
	free(result);
}

static void	test_ft_strtrim_extra(void)
{
	int	pass;
	int	fail;

	pass = 0;
	fail = 0;
	printf(TEST_YELLOW "\n========== ft_strtrim extra tests ==========\n\n" TEST_RESET);

	check_strtrim(1, "   hello   ", " ", "hello", &pass, &fail);
	check_strtrim(2, "\t\n hello \n\t", " \n\t", "hello", &pass, &fail);
	check_strtrim(3, "xxhelxloxx", "x", "helxlo", &pass, &fail);
	check_strtrim(4, "xyxhelloxyx", "xy", "hello", &pass, &fail);
	check_strtrim(5, "abcHelloabc", "abc", "Hello", &pass, &fail);

	check_strtrim(6, "hello", " ", "hello", &pass, &fail);
	check_strtrim(7, "hello", "", "hello", &pass, &fail);
	check_strtrim(8, "", " ", "", &pass, &fail);
	check_strtrim(9, "", "", "", &pass, &fail);

	check_strtrim(10, "aaaa", "a", "", &pass, &fail);
	check_strtrim(11, "ababab", "ab", "", &pass, &fail);
	check_strtrim(12, "   ", " ", "", &pass, &fail);
	check_strtrim(13, "\t\n ", " \n\t", "", &pass, &fail);

	check_strtrim(14, "  hello", " ", "hello", &pass, &fail);
	check_strtrim(15, "hello  ", " ", "hello", &pass, &fail);
	check_strtrim(16, "xxhello", "x", "hello", &pass, &fail);
	check_strtrim(17, "helloxx", "x", "hello", &pass, &fail);

	check_strtrim(18, "123hello321", "123", "hello", &pass, &fail);
	check_strtrim(19, "123hello456", "123456", "hello", &pass, &fail);
	check_strtrim(20, "!!hello!!", "!", "hello", &pass, &fail);
	check_strtrim(21, "...hello...", ".", "hello", &pass, &fail);

	check_strtrim(22, "libft", "lt", "ibf", &pass, &fail);
	check_strtrim(23, "tripouille", "te", "ripouill", &pass, &fail);
	check_strtrim(24, "zzzzabczzzz", "z", "abc", &pass, &fail);
	check_strtrim(25, "abc", "abc", "", &pass, &fail);

	printf(TEST_YELLOW "============== ft_strtrim summary ==============\n" TEST_RESET);
	printf(TEST_GREEN "Passed: %d\n" TEST_RESET, pass);
	printf(TEST_RED "Failed: %d\n" TEST_RESET, fail);
	printf("Total:  %d\n\n", pass + fail);
}

static void	print_test_result(int ok, int *pass, int *fail)
{
	if (ok)
	{
		printf(TEST_GREEN "Status:   PASS\n\n" TEST_RESET);
		(*pass)++;
	}
	else
	{
		printf(TEST_RED "Status:   FAIL\n\n" TEST_RESET);
		(*fail)++;
	}
}

static void	check_substr(int n, char const *s, unsigned int start,
		size_t len, char const *expected, int *pass, int *fail)
{
	char	*result;
	int		ok;

	result = ft_substr(s, start, len);
	ok = (result != NULL && strcmp(result, expected) == 0);

	printf("Test %02d: ft_substr(\"%s\", %u, %zu)\n", n, s, start, len);
	printf("Expected: \"%s\"\n", expected);
	if (result)
		printf("Result:   \"%s\"\n", result);
	else
		printf("Result:   NULL");
	printf("\n");

	print_test_result(ok, pass, fail);
	free(result);
}

static void	check_strjoin_ex(int n, char const *s1, char const *s2,
		char const *expected, int *pass, int *fail)
{
	char	*result;
	int		ok;

	result = ft_strjoin(s1, s2);
	ok = (result != NULL && strcmp(result, expected) == 0);

	printf("Test %02d: ft_strjoin(\"%s\", \"%s\")\n", n, s1, s2);
	printf("Expected: \"%s\"\n", expected);
	if (result)
		printf("Result:   \"%s\"\n", result);
	else
		printf("Result:   NULL");
	printf("\n");

	print_test_result(ok, pass, fail);
	free(result);
}

static void	print_test_summary(char const *name, int pass, int fail)
{
	printf(TEST_YELLOW "============== %s summary ==============\n" TEST_RESET, name);
	printf(TEST_GREEN "Passed: %d\n" TEST_RESET, pass);
	printf(TEST_RED "Failed: %d\n" TEST_RESET, fail);
	printf("Total:  %d\n\n", pass + fail);
}

static void	test_ft_substr_extra(void)
{
	int	pass;
	int	fail;

	pass = 0;
	fail = 0;
	printf(TEST_YELLOW "\n========== ft_substr extra tests ==========\n\n" TEST_RESET);

	check_substr(1, "tripouille", 0, 42000, "tripouille", &pass, &fail);
	check_substr(2, "tripouille", 1, 1, "r", &pass, &fail);
	check_substr(3, "tripouille", 100, 1, "", &pass, &fail);
	check_substr(4, "tripouille", 0, 0, "", &pass, &fail);
	check_substr(5, "tripouille", 1, 0, "", &pass, &fail);

	check_substr(6, "tripouille", 0, 1, "t", &pass, &fail);
	check_substr(7, "tripouille", 1, 2, "ri", &pass, &fail);
	check_substr(8, "tripouille", 3, 4, "poui", &pass, &fail);
	check_substr(9, "tripouille", 9, 1, "e", &pass, &fail);
	check_substr(10, "tripouille", 10, 1, "", &pass, &fail);

	check_substr(11, "", 0, 0, "", &pass, &fail);
	check_substr(12, "", 0, 1, "", &pass, &fail);
	check_substr(13, "", 1, 1, "", &pass, &fail);

	check_substr(14, "Hello World", 0, 5, "Hello", &pass, &fail);
	check_substr(15, "Hello World", 6, 5, "World", &pass, &fail);
	check_substr(16, "Hello World", 6, 50, "World", &pass, &fail);
	check_substr(17, "Hello World", 11, 5, "", &pass, &fail);

	check_substr(18, "abc", 0, 10, "abc", &pass, &fail);
	check_substr(19, "abc", 1, 10, "bc", &pass, &fail);
	check_substr(20, "abc", 2, 10, "c", &pass, &fail);
	check_substr(21, "abc", 3, 10, "", &pass, &fail);
	check_substr(22, "abc", 4, 10, "", &pass, &fail);

	check_substr(23, "a", 0, 1, "a", &pass, &fail);
	check_substr(24, "a", 0, 2, "a", &pass, &fail);
	check_substr(25, "a", 1, 1, "", &pass, &fail);

	check_substr(26, "   spaces", 0, 3, "   ", &pass, &fail);
	check_substr(27, "   spaces", 3, 6, "spaces", &pass, &fail);
	check_substr(28, "libft-test", 6, 4, "test", &pass, &fail);

	print_test_summary("ft_substr", pass, fail);
}

static void	test_ft_strjoin_extra(void)
{
	int	pass;
	int	fail;

	pass = 0;
	fail = 0;
	printf(TEST_YELLOW "\n========== ft_strjoin extra tests ==========\n\n" TEST_RESET);

	check_strjoin_ex(1, "tripouille", "42", "tripouille42", &pass, &fail);
	check_strjoin_ex(2, "", "42", "42", &pass, &fail);
	check_strjoin_ex(3, "42", "", "42", &pass, &fail);
	check_strjoin_ex(4, "", "", "", &pass, &fail);

	check_strjoin_ex(5, "Hello", " World", "Hello World", &pass, &fail);
	check_strjoin_ex(6, "abc", "def", "abcdef", &pass, &fail);
	check_strjoin_ex(7, "123", "456", "123456", &pass, &fail);
	check_strjoin_ex(8, " ", " ", "  ", &pass, &fail);
	check_strjoin_ex(9, "libft", " is cool", "libft is cool", &pass, &fail);

	check_strjoin_ex(10, "a", "b", "ab", &pass, &fail);
	check_strjoin_ex(11, "a", "", "a", &pass, &fail);
	check_strjoin_ex(12, "", "a", "a", &pass, &fail);
	check_strjoin_ex(13, "longer string ", "joined here",
		"longer string joined here", &pass, &fail);
	check_strjoin_ex(14, "symbols: ", "!@#$%^&*()", "symbols: !@#$%^&*()",
		&pass, &fail);

	print_test_summary("ft_strjoin", pass, fail);
}


static int	g_pass = 0;
static int	g_fail = 0;

static void	check_strjoin(int test_num, char const *s1, char const *s2, char const *expected)
{
	char	*result;

	result = ft_strjoin(s1, s2);

	printf("Test %02d: ft_strjoin(\"%s\", \"%s\")\n", test_num, s1, s2);
	printf("Expected: \"%s\"\n", expected);

	if (result && strcmp(result, expected) == 0)
	{
		printf("Result:   \"%s\"\n", result);
		printf(GREEN "Status:   PASS\n\n" RESET);
		g_pass++;
	}
	else
	{
		if (result)
			printf("Result:   \"%s\"\n", result);
		else
			printf("Result:   NULL");
		printf("\n");
		printf(RED "Status:   FAIL\n\n" RESET);
		g_fail++;
	}

	free(result);
}

static void	test_ft_strjoin(void)
{
	printf(YELLOW "\n========== ft_strjoin tests ==========\n\n" RESET);

	check_strjoin(1, "tripouille", "42", "tripouille42");
	check_strjoin(2, "", "42", "42");
	check_strjoin(3, "42", "", "42");
	check_strjoin(4, "", "", "");
	check_strjoin(5, "Hello", " World", "Hello World");
	check_strjoin(6, "abc", "def", "abcdef");
	check_strjoin(7, "123", "456", "123456");
	check_strjoin(8, " ", " ", "  ");
	check_strjoin(9, "libft", " is cool", "libft is cool");

	printf(YELLOW "============== Summary ==============\n" RESET);
	printf(GREEN "Passed: %d\n" RESET, g_pass);
	printf(RED "Failed: %d\n" RESET, g_fail);
	printf("Total:  %d\n\n", g_pass + g_fail);
}

void	test_substr(void)
{
	char	*res;

	printf("\n--- ft_substr ---\n");

	res = ft_substr("tripouille", 0, 42000);
	printf("1: %s\n", strcmp(res, "tripouille") == 0 ? "OK" : "KO");
	free(res);

	res = ft_substr("tripouille", 1, 1);
	printf("2: %s\n", strcmp(res, "r") == 0 ? "OK" : "KO");
	free(res);

	res = ft_substr("tripouille", 100, 1);
	printf("3: %s\n", strcmp(res, "") == 0 ? "OK" : "KO");
	free(res);

	res = ft_substr("1", 42, 42000000);
	printf("4: %s\n", strcmp(res, "") == 0 ? "OK" : "KO");
	free(res);

	res = ft_substr("0123456789", 9, 10);
	printf("5: %s\n", strcmp(res, "9") == 0 ? "OK" : "KO");
	free(res);

	res = ft_substr("42", 0, 0);
	printf("6: %s\n", strcmp(res, "") == 0 ? "OK" : "KO");
	free(res);

	res = ft_substr("BONJOUR LES HARICOTS !", 8, 14);
	printf("7: %s\n", strcmp(res, "LES HARICOTS !") == 0 ? "OK" : "KO");
	free(res);

	res = ft_substr("test", 1, 2);
	printf("8: %s\n", strcmp(res, "es") == 0 ? "OK" : "KO");
	free(res);
}

static int  check_zero(void *ptr, size_t size)
{
    unsigned char   *bytes;
    size_t          i;

    bytes = (unsigned char *)ptr;
    i = 0;
    while (i < size)
    {
        if (bytes[i] != 0)
            return (0);
        i++;
    }
    return (1);
}

static void test_calloc_case(size_t count, size_t size, const char *name)
{
    void    *real;
    void    *mine;
    size_t  total;

    printf("\n--- %s ---\n", name);
    printf("count = %zu, size = %zu\n", count, size);

    real = calloc(count, size);
    mine = ft_calloc(count, size);

    printf("calloc    : %p\n", real);
    printf("ft_calloc : %p\n", mine);

    total = count * size;

    if (count != 0 && size != 0)
    {
        if (real == NULL)
            printf("calloc    : NULL\n");
        else if (check_zero(real, total))
            printf("calloc    : memory is zeroed ✅\n");
        else
            printf("calloc    : memory is NOT zeroed ❌\n");

        if (mine == NULL)
            printf("ft_calloc : NULL ❌\n");
        else if (check_zero(mine, total))
            printf("ft_calloc : memory is zeroed ✅\n");
        else
            printf("ft_calloc : memory is NOT zeroed ❌\n");
    }
    else
    {
        printf("zero-size allocation: NULL or non-NULL can both be valid\n");
    }

    free(real);
    free(mine);
}

static void test_calloc_overflow(size_t count, size_t size, const char *name)
{
    void    *mine;

    printf("\n--- %s ---\n", name);
    printf("count = %zu, size = %zu\n", count, size);

    mine = ft_calloc(count, size);

    printf("ft_calloc : %p\n", mine);

    if (mine == NULL)
        printf("overflow handled ✅\n");
    else
    {
        printf("overflow NOT handled ❌\n");
        free(mine);
    }
}

void    test_calloc(void)
{
    printf("\n*********** *********** calloc *********** ***********\n");

    test_calloc_case(5, sizeof(int), "normal int array");
    test_calloc_case(10, sizeof(char), "char array");
    test_calloc_case(3, sizeof(long), "long array");
    test_calloc_case(100, 1, "100 bytes");

    test_calloc_case(0, sizeof(int), "count is zero");
    test_calloc_case(5, 0, "size is zero");
    test_calloc_case(0, 0, "both are zero");

    test_calloc_overflow((size_t)-1, 2, "overflow: SIZE_MAX * 2");
    test_calloc_overflow(((size_t)-1 / 2) + 1, 2, "overflow: half max + 1 times 2");
}

int main(void)
{
    int i;
    int j;
    // test strlen
    printf("*********** *********** strlen *********** ***********\n");
    // test strlen
    const char *strlen_str[] = {"un", "deux", "trois", "quatres", "RaNd0M T3s*t", "", ".", "encore 3 ramdom elements", " ", "12345", "lA5t"};
    for (i = 0; i < (sizeof(strlen_str) / sizeof(strlen_str[0])); i++)
    {
        if (ft_strlen(strlen_str[i]) != strlen(strlen_str[i]))
        {
            printf("************ ERROR ERROR ERROR ************\n");
            printf("ft_strlen test | '%i'     >> ... %zu\n", i, ft_strlen(strlen_str[i]));
            printf("strlen test    | '%i'     >> ... %zu\n", i, strlen(strlen_str[i]));
            printf("************ ERROR ERROR ERROR ************\n");
        }
        else
            printf("test %i ******* OK ******* no-diff \n", i);
    }
    // test isalfa
    printf("****** *********** isalpha *********** ******\n");
    for (i = 89; i < 99; i++)
    {

        if(ft_isalpha(i) != isalpha(i))
        {
            printf("************ ERROR ERROR ERROR ************\n");
            printf("ft_isalpha test | '%i'     >> ... %i\n", i, ft_isalpha(i));
            printf("isalpha test    | '%i'     >> ... %i\n", i, isalpha(i));
            printf("************ ERROR ERROR ERROR ************\n");
        }
        else
            printf("test %i ******* OK ******* no-diff \n", i);
    }
    // test isalnum
    printf("****** *********** isalnum *********** ******\n");
    for (i = 40; i < 50; i++)
    {

        if(ft_isalnum(i) != isalnum(i))
        {
            printf("************ ERROR ERROR ERROR ************\n");
            printf("ft_isalnum test | '%i'     >> ... %i\n", i, ft_isalnum(i));
            printf("isalnum test    | '%i'     >> ... %i\n", i, isalnum(i));
            printf("************ ERROR ERROR ERROR ************\n");
        }
        else
            printf("test %i ******* OK ******* no-diff \n", i);
    }
    // test isAscii
    printf("****** *********** isAscii *********** ******\n");
    for (i = 89; i < 99 ; i++)
    {

        if(ft_isascii(i) != isascii(i))
        {
            printf("************ ERROR ERROR ERROR ************\n");
            printf("ft_isascii test | '%i'     >> ... %i\n",i, ft_isascii(i));
            printf("isascii test    | '%i'     >> ... %i\n",i ,isascii(i));
            printf("************ ERROR ERROR ERROR ************\n");
        }
        else
            printf("test %i ******* OK ******* no-diff \n", i);
    }
    // test isdigit
    printf("****** *********** isdigit *********** ******\n");
    for (i = 40; i < 50 ; i++)
    {

        if(ft_isdigit(i) != isdigit(i))
        {
            printf("************ ERROR ERROR ERROR ************\n");
            printf("ft_isdigit test | '%i'     >> ... %i\n",i, ft_isdigit(i));
            printf("isdigit test    | '%i'     >> ... %i\n",i ,isdigit(i));
            printf("************ ERROR ERROR ERROR ************\n");
        }
        else
            printf("test %i ******* OK ******* no-diff \n", i);
    }
    // test isprint
    printf("****** *********** isprint *********** ******\n");
    for (i = 25; i < 35 ; i++)
    {

        if(ft_isprint(i) != isprint(i))
        {
            printf("************ ERROR ERROR ERROR ************\n");
            printf("ft_isprint test | '%i'     >> ... %i\n",i, ft_isprint(i));
            printf("isprint test    | '%i'     >> ... %i\n",i ,isprint(i));
            printf("************ ERROR ERROR ERROR ************\n");
        }
        else
            printf("test %i ******* OK ******* no-diff \n", i);
    }
    // test memset
    printf("****** *********** memset *********** ******\n");
    char    str_mem[6] = "hello";
    char    str_test[6] = "hello";
    int     arr_mem[6] = {1,2,3,4,5,6};
    int     arr_test[6] = {1,2,3,4,5,6};

    memset(str_mem, '0', 4);
    memset(arr_mem, 0, 16);
    
    ft_memset(str_test, '0', 4);
    ft_memset(arr_test, 0, 16);

    for (i = 0; i < 6; i++)
    {
        if (str_mem[i] != str_test[i])
        {
            printf("************ ERROR ERROR ERROR ************\n");
            printf("ft_memset test | '%i'     >> ... %c\n",i, str_mem[i]);
            printf("memset test    | '%i'     >> ... %c\n",i ,str_test[i]);
            printf("************ ERROR ERROR ERROR ************\n");
        }
        else
            printf("#1 memtest %i ******* OK ******* no-diff \n", i);
    }

    for (i = 0; i < 6; i++)
    {
        if (arr_mem[i] != arr_test[i])
        {
            printf("************ ERROR ERROR ERROR ************\n");
            printf("ft_memset test | '%i'     >> ... %i\n", i, arr_mem[i]);
            printf("memset test    | '%i'     >> ... %i\n", i, arr_test[i]);
            printf("************ ERROR ERROR ERROR ************\n");
        }
        else
            printf("#2 memtest %i ******* OK ******* no-diff \n", i);
    }
    // test bzero
    printf("*********** *********** bzero *********** ***********\n");
    char    bze_str[10] = "hello amy";
    int     bze_arr[10] = {1,2,3,4,5,6,7,8,9,10};

    char    bze_str_official[10] = "hello amy";
    int     bze_arr_official[10] = {1,2,3,4,5,6,7,8,9,10};

    ft_bzero(bze_str, 1);
    ft_bzero(bze_arr, 4);

    bzero(bze_str_official, 1);
    bzero(bze_arr_official, 4);
    // until 10 because after it is undefined behavior
    for (i = 0; i < 10; i++)
    {
        if (bze_str[i] != bze_str_official[i])
        {
            printf("************ ERROR ERROR ERROR ************\n");
            printf("ft_bzero test  | '%i'     >> ... %c\n", i, bze_str[i]);
            printf("bzero  test    | '%i'     >> ... %c\n", i, bze_str_official[i]);
            printf("************ ERROR ERROR ERROR ************\n");
        }
        else
            printf("#1 bzero str %i ******* OK ******* no-diff \n", i);
    }
    // until 10 because after it is undefined behavior
    for (i = 0; i < 10; i++)
    {
        if (bze_arr[i] != bze_arr_official[i])
        {
            printf("************ ERROR ERROR ERROR ************\n");
            printf("ft_bzero test2  | '%i'     >> ... %i\n", i, bze_arr[i]);
            printf("bzero  test2    | '%i'     >> ... %i\n", i, bze_arr_official[i]);
            printf("************ ERROR ERROR ERROR ************\n");
        }
        else
            printf("#2 bzero int %i ******* OK ******* no-diff \n", i);
    }
    // test memcpy
    printf("*********** *********** memcpy *********** ***********\n");
    char    memcpy_src_str[10] = "hello amy";
    char    memcpy_dst_str[20] = "xxxxxxxxx";
    char    memcpy_src_str_official[10] = "hello amy";
    char    memcpy_dst_str_official[20] = "pppppppppppp";

    int     memcpy_src_arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int     memcpy_dst_arr[20] = {0,0,0,0,0,0,0,0,0,0,0,0};
    int     memcpy_src_arr_official[10] = {1,2,3,4,5,6,7,8,9,10};
    int     memcpy_dst_arr_official[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1};

    ft_memcpy(memcpy_dst_str, memcpy_src_str, 10);
    memcpy(memcpy_dst_str_official, memcpy_src_str_official, 10);
    for (i = 0; i < 10 ; i++)
    {
        if (memcpy_dst_str[i] != memcpy_dst_str_official[i])
        {
            printf("************ ERROR ERROR ERROR ************\n");
            printf("ft_memcpy test     | '%i'     >> ... %c\n", i, memcpy_dst_str[i]);
            printf("memcpy  test       | '%i'     >> ... %c\n", i, memcpy_dst_str_official[i]);
            printf("************ ERROR ERROR ERROR ************\n");
        }
        else
            printf("#1 memcpy str %i ******* OK ******* no-diff \n", i);
    }
    ft_memcpy(memcpy_dst_arr, memcpy_src_arr, sizeof(memcpy_src_arr));
//    printf("should be 4 bytes * 10 elements >>> %lu\n", sizeof(memcpy_src_arr));
    memcpy(memcpy_dst_arr_official, memcpy_src_arr_official, sizeof(memcpy_src_arr_official));

    for (i = 0; i < 10 ; i++)
    {
        if (memcpy_dst_arr[i] != memcpy_dst_arr_official[i])
        {
            printf("************ ERROR ERROR ERROR ************\n");
            printf("ft_memcpy test arr | '%i'     >> ... %i\n", i, memcpy_dst_arr[i]);
            printf("memcpy  test  arr  | '%i'     >> ... %i\n", i, memcpy_dst_arr_official[i]);
            printf("************ ERROR ERROR ERROR ************\n");
        }
        else
            printf("#2 memcpy int %i ******* OK ******* no-diff \n", i);
    }
    // test memmove
    printf("*********** *********** memmove *********** ***********\n");


    for (i = 0; i <= 5 ; i++)
    {
        char    dst_memmove[10] = "abcdefgh";
        char    src_memmove[10] = "abcdefgh";
        memmove(dst_memmove + 3, dst_memmove + i, i);
        ft_memmove(src_memmove + 3, src_memmove + i, i);
        for (j = 0; j < 10; j++)
        {
            if(dst_memmove[j] != src_memmove[j])
            {
                printf("************ ERROR ERROR ERROR ************\n");
                printf("ft_memmove test arr | i='%i'  j='%i'     >> ... %i\n",i, j, src_memmove[j]);
                printf("memmove  test  arr  | i='%i'  j='%i'     >> ... %i\n",i, j, dst_memmove[j]);
                printf("************ ERROR ERROR ERROR ************\n");
            }
            else
                printf("#1 memmove i:%i j:%i ******* OK ******* no-diff \n", i, j);
        }
    }
    // test strlcat
    printf("*********** *********** strlcat *********** ***********\n");
    char tst_strl[6] = "world";
    char dst_strl[11] = "hello\0";
    ft_strlcat(dst_strl, tst_strl, 11);
    printf("var: 'helloworld' result : '%s'\n", dst_strl);

    // test strncmp
    printf("*********** *********** strncmp *********** ***********\n");
    const char *strlen_str_cmp[] = {"uAn", "deBux", "trocis", "quatres", "RANd0M T3s*t", "", ".", "encore 3 ramdom elements", " ", "12345", "lA5t"};
    char tst_strncmp[6] = "world\0";
    char dst_tst_strncmp[6] = "hello\0";

    for (i = 0; i < 10; i++)
    {
        printf("strncmp   0 >> %i\n", strncmp(strlen_str_cmp[i], strlen_str_cmp[i+1], 0));
        printf("ftstrncmp 0 >> %i\n", ft_strncmp(strlen_str_cmp[i], strlen_str_cmp[i+1], 0));

        printf("strncmp   5 >> %i\n", strncmp(strlen_str_cmp[i], strlen_str_cmp[i+1], 5));
        printf("ftstrncmp 5 >> %i\n", ft_strncmp(strlen_str_cmp[i], strlen_str_cmp[i+1], 5));

        printf("strncmp   10 >> %i\n", strncmp(strlen_str_cmp[i], strlen_str_cmp[i+1], 10));
        printf("ftstrncmp 10 >> %i\n", ft_strncmp(strlen_str_cmp[i], strlen_str_cmp[i+1], 10));
    }
    printf("strncmp   0 >> %i\n", strncmp("abcdefgh", "abcdwxyz", 4));
    printf("ftstrncmp 0 >> %i\n", ft_strncmp("abcdefgh", "abcdwxyz", 4));



    // test memchr
    printf("*********** *********** memchr *********** ***********\n");
   // const char *strlen_str_cmp[] = {"un", "deux", "trois", "quatres", "RaNd0M T3s*t", "", ".", "encore 3 ramdom elements", " ", "12345", "lA5t"};

    for (i = 0; i < 10; i++)
    {
        printf("memchr   0 >> %p\n", memchr(strlen_str_cmp[i], 65 + i, 10));
        printf("ftmemchr 0 >> %p\n", ft_memchr(strlen_str_cmp[i], 65 + i, 10));
    }
    // test memcmp
    printf("*********** *********** memcmp *********** ***********\n");
    for (i = 0; i < 10; i++)
    {
        printf("memcmp    0 >> %i\n", memcmp(strlen_str_cmp[i], strlen_str_cmp[i+1], 0));
        printf("ft_memcmp 0 >> %i\n", ft_memcmp(strlen_str_cmp[i], strlen_str_cmp[i+1], 0));
        printf("memcmp    5 >> %i\n", memcmp(strlen_str_cmp[i], strlen_str_cmp[i+1], 5));
        printf("ft_memcmp 5 >> %i\n", ft_memcmp(strlen_str_cmp[i], strlen_str_cmp[i+1], 5));
        printf("memcmp    20 >> %i\n", memcmp(strlen_str_cmp[i], strlen_str_cmp[i+1], 20));
        printf("ft_memcmp 20 >> %i\n", ft_memcmp(strlen_str_cmp[i], strlen_str_cmp[i+1], 20));
    }
    printf("strncmp abcdefgh / abcdwxyz / 4 >> %i\n", memcmp("abcdefgh", "abcdwxyz", 4));
    printf("ftstrncmp abcdefgh / abcdwxyz / 4 >> %i\n", ft_memcmp("abcdefgh", "abcdwxyz", 4));
/*
    // test strnstr
    printf("*********** *********** strnstr *********** ***********\n");
    printf("'findme' in 'you should manage to find if you can findme.'\n");
    char findme[7] = "findme\0";
    char inhere[45] = "you should manage to find if you can findme.\0";

    for (i = 0; i < 50 ; i++)
    {
        if (strnstr(inhere, findme, i) != ft_strnstr(inhere, findme,i))
        {
            printf("i = %i\n", i);
            printf("strnstr : %s\n",strnstr(inhere, findme, i));
            printf("ft_strnstr : %s\n",ft_strnstr(inhere, findme,i));
        }
        else
            printf("strnstr %i ******* OK ******* no-diff \n", i);
    }
*/
    // test toupper && tolower
    printf("*********** *********** toupper / tolower *********** ***********\n");
    char tou = 'a';
    char pper = 'C';

    printf("toupper: '%c' then '%c'\n", tou, ft_toupper(tou));
    printf("tolower: '%c' then '%c'\n", tou, ft_tolower(tou));
    printf("toupper: '%c' then '%c'\n", pper, ft_toupper(pper));
    printf("tolower: '%c' then '%c'\n", pper, ft_tolower(pper));

    printf("OFFI ||toupper: '%c' then '%c'\n", tou, toupper(tou));
    printf("OFFI ||tolower: '%c' then '%c'\n", tou, tolower(tou));
    printf("OFFI ||toupper: '%c' then '%c'\n", pper, toupper(pper));
    printf("OFFI ||tolower: '%c' then '%c'\n", pper, tolower(pper));

    // test calloc
    printf("*********** *********** calloc *********** ***********\n");
    test_calloc();


    // test atoi
    printf("*********** *********** atoi *********** ***********\n");
    printf("ft_atoi        : '123' result : '%i'\n", ft_atoi("123"));
    printf("OFFI atoi      : '123' result : '%i'\n", atoi("123"));
    printf("ft_atoi        : '-123' result : '%i'\n", ft_atoi("-123"));
    printf("OFFI atoi      : '-123' result : '%i'\n", atoi("-123"));
    printf("ft_atoi        : '0' result : '%i'\n", ft_atoi("0"));
    printf("OFFI atoi      : '0' result : '%i'\n", atoi("0"));
    printf("ft_atoi        : '-0' result : '%i'\n", ft_atoi("-0"));
    printf("OFFI atoi      : '-0' result : '%i'\n", atoi("-0"));

    printf("ft_atoi        : '--12' result : '%i'\n", ft_atoi("--12"));
    printf("OFFI atoi      : '--12' result : '%i'\n", atoi("--12"));
    printf("ft_atoi        : '+12' result : '%i'\n", ft_atoi("+12"));
    printf("OFFI atoi      : '+12' result : '%i'\n", atoi("+12"));
    printf("ft_atoi        : '++12' result : '%i'\n", ft_atoi("++12"));
    printf("OFFI atoi      : '++12' result : '%i'\n", atoi("++12"));

    printf("ft_atoi        : '1+2' result : '%i'\n", ft_atoi("1+2"));
    printf("OFFI atoi      : '1+2' result : '%i'\n", atoi("1+2"));
    printf("ft_atoi        : '\t\n\r\v\f 469 \n' result : '%i'\n", ft_atoi("\t\n\r\v\f 469 \n"));
    printf("OFFI atoi      : '\t\n\r\v\f 469 \n' result : '%i'\n", atoi("\t\n\r\v\f 469 \n"));
    printf("ft_atoi        : '  12 42' result : '%i'\n", ft_atoi("  12 42"));
    printf("OFFI atoi      : '  12 42' result : '%i'\n", atoi("  12 42"));

    // test substr
    printf("*********** *********** substr *********** ***********\n");
    test_substr();
    test_ft_substr_extra();

    // test strjoin
    printf("*********** *********** strjoin *********** ***********\n");
    test_ft_strjoin();
    test_ft_strjoin_extra();

/* ************************************************************************** */
/*                              ft_strtrim tests                               */
/* ************************************************************************** */
    // test strtrim
    printf("*********** *********** strtrim *********** ***********\n");
    test_ft_strtrim_extra();

    // test ft_split
    printf("*********** *********** ft_split *********** ***********\n");
    test_ft_split_extra();

    ft_split("hello world france", ' ');

        // test itoa
    printf("*********** *********** itoa *********** ***********\n");

    printf(ft_itoa(123));
    printf("\n");
    printf(ft_itoa(-123));
        printf("\n");
    printf(ft_itoa(0));
    printf("\n");

     printf("*********** *********** strtrim *********** ***********\n");
    ft_strtrim("   xxx   xxx", " x");

}