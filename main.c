#include "incs/ft_printf.h"
#include "stdio.h"

int main(void)
{
	int ret;
	char test_simple_mix;

	test_simple_mix = 0;
	ret = ft_printf("s: %s, p: %p, d:%d", "a string", &test_simple_mix, 42);
	printf("\n%d\n", ret);
	ret = printf("s: %s, p: %p, d:%d", "a string", &test_simple_mix, 42);
	    printf("\n%d\n", ret);
	return 0;
}
