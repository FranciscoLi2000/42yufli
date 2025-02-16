#include "libft.h"

void	ft_putunbr(t_fmt *data, unsigned int n)
{
	if (n >= 10)
		ft_putunbr(data, n / 10);
	ft_putchar(data, (n % 10) + '0');
}
