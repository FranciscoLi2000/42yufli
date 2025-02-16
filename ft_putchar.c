#include "libft.h"

void	ft_putchar(t_fmt *data, char c)
{
	write(1, &c, 1);
	data->ret++;
}
