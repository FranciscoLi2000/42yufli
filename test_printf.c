#include "libft.h"

int	main()
{
	int	x;
	int	y;

	x = 1157;
	y = 1215;
	ft_printf(" I love the mang%c, que se llama %s \n", 'A', "Detective Conan");
	ft_printf("Officially the serie ya tiene %i episodios (%d)\n%p\n%p\n", x, y, &x, &y);
	ft_printf("This number %u and %u in base 16 is %x and %X \n", 1157, 1215, x, y);
	return (0);
}
