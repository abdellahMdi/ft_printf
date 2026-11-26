#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

#define TEST(fmt, ...) do { \
	int ret_orig, ret_ft; \
	printf("ORIG: ["); \
	ret_orig = printf(fmt, ##__VA_ARGS__); \
	printf("] (ret: %d)\n", ret_orig); \
	printf("FT  : ["); \
	fflush(stdout); \
	ret_ft = ft_printf(fmt, ##__VA_ARGS__); \
	printf("] (ret: %d) -> %s\n\n", ret_ft, (ret_orig == ret_ft) ? "OK" : "KO"); \
} while (0)

int	main(void)
{
	int		x = 42;
	char	*null_str = NULL;
	void	*null_ptr = NULL;

	printf("========== GENERAL & EMPTY ==========\n");
	TEST("");
	TEST("Just a plain string.");
	TEST("%%");
	TEST("%%%%");
	TEST("100%% legit");

	printf("========== %%c ==========\n");
	TEST("%c", 'A');
	TEST("%c", '0');
	TEST("%c", '\0');
	TEST("%c%c%c", 'a', '\0', 'b');

	printf("========== %%s ==========\n");
	TEST("%s", "Hello 42");
	TEST("%s", "");
	TEST("%s", null_str);
	TEST("Before %s After", null_str);

	printf("========== %%p ==========\n");
	TEST("%p", &x);
	TEST("%p", null_ptr);
	TEST("%p", (void *)0);
	TEST("%p", (void *)ULONG_MAX);
	TEST("%p", (void *)LONG_MIN);

	printf("========== %%d & %%i ==========\n");
	TEST("%d", 0);
	TEST("%d", -1);
	TEST("%d", 42);
	TEST("%d", INT_MAX);
	TEST("%d", INT_MIN);
	TEST("%i", 0);
	TEST("%i", -42);
	TEST("%i", INT_MAX);
	TEST("%i", INT_MIN);

	printf("========== %%u ==========\n");
	TEST("%u", 0);
	TEST("%u", 1);
	TEST("%u", UINT_MAX);
	TEST("%u", -1);
	TEST("%u", INT_MIN);

	printf("========== %%x & %%X ==========\n");
	TEST("%x", 0);
	TEST("%x", 1);
	TEST("%x", 15);
	TEST("%x", 16);
	TEST("%x", 255);
	TEST("%x", -1);
	TEST("%x", UINT_MAX);
	TEST("%X", 0);
	TEST("%X", 15);
	TEST("%X", 16);
	TEST("%X", 255);
	TEST("%X", -1);
	TEST("%X", UINT_MAX);

	printf("========== BONUS: # FLAG ==========\n");
	TEST("%#x", 0);
	TEST("%#x", 1);
	TEST("%#x", 42);
	TEST("%#x", UINT_MAX);
	TEST("%#X", 0);
	TEST("%#X", 1);
	TEST("%#X", 42);
	TEST("%#X", UINT_MAX);

	printf("========== BONUS: + AND SPACE FLAGS ==========\n");
	TEST("%+d", 0);
	TEST("%+d", 42);
	TEST("%+d", -42);
	TEST("%+d", INT_MAX);
	TEST("%+d", INT_MIN);
	TEST("%+i", 42);
	TEST("%+i", -42);
	TEST("% d", 0);
	TEST("% d", 42);
	TEST("% d", -42);
	TEST("% d", INT_MAX);
	TEST("% d", INT_MIN);
	TEST("% i", 42);
	TEST("% i", -42);

	printf("========== MIXED ==========\n");
	TEST("%c | %s | %p | %+d | % i | %u | %#x | %#X | %%",
		'Z', "mix", &x, 42, 99, UINT_MAX, 0xbeef, 0xCAFE);

	printf("========== NULL FORMAT ==========\n");
	printf("ft_printf(NULL) ret: %d (expected: -1)\n", ft_printf(NULL));

	return (0);
}