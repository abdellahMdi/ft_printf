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

	printf("=== %%c (Character) ===\n");
	TEST("%c", 'A');
	TEST("%c", '0');
	TEST("%c", '\0');

	printf("=== %%s (String) ===\n");
	TEST("%s", "Hello, 42!");
	TEST("%s", "");
	TEST("%s", null_str);

	printf("=== %%p (Pointer) ===\n");
	TEST("%p", &x);
	TEST("%p", null_ptr);
	TEST("%p", (void *)LONG_MAX);

	printf("=== %%d and %%i (Signed Decimal) ===\n");
	TEST("%d", 0);
	TEST("%d", -42);
	TEST("%d", INT_MAX);
	TEST("%d", INT_MIN);
	TEST("%i", 0);
	TEST("%i", -2147483648);
	TEST("%i", 2147483647);

	printf("=== %%u (Unsigned Decimal) ===\n");
	TEST("%u", 0);
	TEST("%u", 42);
	TEST("%u", UINT_MAX);
	TEST("%u", -1);

	printf("=== %%x and %%X (Hexadecimal) ===\n");
	TEST("%x", 0);
	TEST("%x", 255);
	TEST("%x", -1);
	TEST("%x", UINT_MAX);
	TEST("%X", 0);
	TEST("%X", 255);
	TEST("%X", -1);
	TEST("%X", UINT_MAX);

	printf("=== %%%% (Percent) ===\n");
	TEST("%%");
	TEST("100%%");

	printf("=== Mixed ===\n");
	TEST("Char: %c | Str: %s | Ptr: %p | Dec: %d | Hex: %x | %%",
		'Z', "test", &x, -123, 0xdeadbeef);

	return (0);
}