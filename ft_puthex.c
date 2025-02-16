#include "libft.h"

void	ft_puthex(t_fmt *data, unsigned int n, char specifier)
{
	char	c;
	int		remainder;

	if (n == 0)
	{
		ft_putchar(data, '0');
		return ;
	}
	if (n >= 16)
		ft_puthex(data, n / 16, specifier);
	remainder = n % 16;
	if (remainder < 10)
		c = remainder + '0';
	else
	{
		if (specifier == 'x')
			c = remainder - 10 + 'a';
		else
			c = remainder - 10 + 'A';
	}
	ft_putchar(data, c);
}
