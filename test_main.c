#include <unistd.h>
#include <stdio.h>

int main(void)
{
	int c_std;
	int c_ft;

	printf("1 PRINTF VS. 2.FT_PRINTF\n");
	printf("\n1. No args and %%\n");
	c_std = printf(" hola123 \n");
	c_ft = ft_printf(" hola123 \n");
	printf("Printed: %d vs. %d\n", c_std, c_ft);

	printf("\n2. No args but some %% without flag\n");
	c_std = printf(" hola123 \n");
	c_ft = ft_printf(" hola123 \n");
	printf("Printed: %d vs. %d\n", c_std, c_ft);

	printf("\n3. Some %% without args\n");
	c_std = printf(" hola123 \n");
	c_ft = ft_printf(" hola123 \n");
	printf("Printed: %d vs. %d\n", c_std, c_ft);

	printf("\n4. Percentage, 'A' char %%c and 'Hola123' string %%s\n");
	c_std = printf(" hola123 \n");
	c_ft = ft_printf(" hola123 \n");
	printf("Printed: %d vs. %d\n", c_std, c_ft);

	printf("\n5. Integer with %%d and %%i\n");
	c_std = printf(" hola123 \n");
	c_ft = ft_printf(" hola123 \n");
	printf("Printed: %d vs. %d\n", c_std, c_ft);

	printf("\n6. Unsigned integer %%u\n");
	c_std = printf(" hola123 \n");
	c_ft = ft_printf(" hola123 \n");
	printf("Printed: %d vs. %d\n", c_std, c_ft);

	printf("\n7. Pointer %%p\n");
	c_std = printf(" hola123 \n");
	c_ft = ft_printf(" hola123 \n");
	printf("Printed: %d vs. %d\n", c_std, c_ft);

	printf("\n8. Hexa upper %%X and lower %%x\n");
	c_std = printf(" hola123 \n");
	c_ft = ft_printf(" hola123 \n");
	printf("Printed: %d vs. %d\n", c_std, c_ft);
	
	printf("\nEND\n");
	return (0);
}