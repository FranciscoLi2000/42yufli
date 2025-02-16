#include "libft.h"

int	main(int argc, char **argv)
{
	char	*line;
	int		fd;

	if (argc != 2)
	{
		ft_printf("Usage: %s <filename>\n", argv[0]);
		return (2);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error opening file");
		return (2);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ft_printf("%s", line);
		free(line);
	}
	close(fd);
	if (line)
		free(line);
	return (0);
}
