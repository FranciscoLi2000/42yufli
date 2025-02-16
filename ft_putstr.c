#include "libft.h"

void	ft_putstr(t_fmt *data, char *s)
{
	size_t	len;

	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	write(1, s, len);
	data->ret += len;
}
