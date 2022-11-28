#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include "../include/libftprintf.h"

int main(void)
{
	int c_std;
	int c_ft;

	printf("1 PRINTF VS. 2.FT_PRINTF\n");

	printf("\n1. No args and %%\n");
	c_std = printf("> hola 123 <\n");
	c_ft = ft_printf("> hola 123 <\n");
	printf("Printed: %d vs. %d\n", c_std, c_ft);

/* ft_printf no controla argumentos
	printf("\n2. No args but some %% without flag\n");
	c_std = printf("ho%la %123\n");
	c_ft = ft_printf("ho%la %123\n");
	printf("Printed: %d vs. %d\n", c_std, c_ft);

	printf("\n3. Some %% without args\n");
//	c_std = printf("hola %d %s 123 \n");
	c_ft = ft_printf("hola %d %s 123\n");
	printf("Printed: %d vs. %d\n", c_std, c_ft);
*/

	printf("\n4. Percentage, 'A' char %%c and 'Hola123\\t?' string %%s\n");
	c_std = printf(">%%< / >'%c'< / >'%s'<\n", 'A', "Hola123\t?");
	c_ft = ft_printf(">%%< / >'%c'< / >'%s'<\n", 'A', "Hola123\t?");
	printf("Printed: %d vs. %d\n", c_std, c_ft);


	printf("\n5. MAX and MIN integer using %%d\n");
	c_std = printf("%d / %d\n", INT_MAX, INT_MIN);
	c_ft = ft_printf("%d / %d\n", INT_MAX, INT_MIN);
	printf("Printed: %d vs. %d\n", c_std, c_ft);

	printf("\n6. MAX and MIN integer using %%i\n");
	c_std = printf("%i / %i\n", INT_MAX, INT_MIN);
	c_ft = ft_printf("%i / %i\n", INT_MAX, INT_MIN);
	printf("Printed: %d vs. %d\n", c_std, c_ft);

	printf("\n7. MAX unsigned integer %%u\n");
	c_std = printf("%u\n", UINT_MAX);
	c_ft = ft_printf("%u\n", UINT_MAX);
	printf("Printed: %d vs. %d\n", c_std, c_ft);

	printf("\n8. Uninitialized pointer %%p\n");
	char *test = NULL;
	c_std = printf("%p\n", &test);
	c_ft = ft_printf("%p\n", &test);
	printf("Printed: %d vs. %d\n", c_std, c_ft);

	printf("\n9. Initialized pointer %%p\n");
	int test2 = 1;
	c_std = printf("%p\n", &test2);
	c_ft = ft_printf("%p\n", &test2);
	printf("Printed: %d vs. %d\n", c_std, c_ft);

	printf("\n10. Null pointer %%p\n");
	int *test3 = NULL;
	c_std = printf("%p\n", &test3);
	c_ft = ft_printf("%p\n", &test3);
	printf("Printed: %d vs. %d\n", c_std, c_ft);

	printf("\n11. MAX int (7FFFFFFF) hexa upper %%X and lower %%x\n");
	c_std = printf("%X / %x\n", INT_MAX, INT_MAX);
	c_ft = ft_printf("%X / %x\n", INT_MAX, INT_MAX);
	printf("Printed: %d vs. %d\n", c_std, c_ft);

	printf("\n12. MIN int (wrong value) hexa upper %%X and lower %%x\n");
	c_std = printf("%X / %x\n", INT_MIN, INT_MIN);
	c_ft = ft_printf("%X / %x\n", INT_MIN, INT_MIN);
	printf("Printed: %d vs. %d\n", c_std, c_ft);

	printf("\n13. empty string\n");
	c_std = printf("");
	write(1, "\n", 1);
	c_ft = ft_printf("");
	write(1, "\n", 1);
	printf("printed: %d vs. %d\n", c_std, c_ft);
	
	printf("\n14. null string using %%s\n");
	c_std = printf("%s", (char *)NULL);
	write(1, "\n", 1);
	c_ft = printf("%s", (char *)NULL);
	write(1, "\n", 1);
	printf("printed: %d vs. %d\n", c_std, c_ft);

	printf("\nEND\n");
	return (0);
}
