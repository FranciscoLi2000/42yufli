#include "libft.h"

void	ft_putnbr(t_fmt *data, int n)
{
	if (n == -2147483648)
	{
		ft_putstr(data, "-2147483648");
		return ;
	}
	if (n < 0)
	{
		ft_putchar(data, '-');
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(data, n / 10);
	ft_putchar(data, (n % 10) + '0');
}
