#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	write(fd, s, len);
	write(fd, "\n", 1);
}
