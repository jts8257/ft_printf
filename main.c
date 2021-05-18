#include "printf.h"

int			main(void)
{

	int tmp = 10;
	int *ptr;
	ptr = &tmp;
	
	printf("====c====\n");
	printf("%c\n", 'c');
	ft_printf("%c\n", 'c');

	printf("====s====\n");
	printf("%s\n", "rororo");
	ft_printf("%s\n", "rororo");

	printf("====p====\n");
	printf("%p\n", ptr);
	ft_printf("%p\n", ptr);

	printf("====d====\n");
	printf("%d\n", tmp);
	ft_printf("%d\n", tmp);

	printf("====i====\n");
	printf("%i\n", tmp);
	ft_printf("%i\n", tmp);

	printf("====u====\n");
	printf("%u\n", tmp * -1);
	ft_printf("%u\n", tmp * -1);

	printf("====x====\n");
	printf("%x\n", 31);
	ft_printf("%x\n", 31);


	printf("====X====\n");
	printf("%X\n", -100);
	ft_printf("%X\n", -100);

	printf("%%\n");
	ft_printf("%%\n");
}
