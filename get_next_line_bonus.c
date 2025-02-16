#include "libft.h"

static char	*read_line(int fd, char *left_c, char *buffer)
{
	/* ssize_t type works the same way as siyze_t type, but it can be
	 * a negative number, something that size_t can't do.
	 * Since most of the system function we'll be using return -1 to
	 * signify errors, it could be useful to be able to store
	 * negative numbers */
	ssize_t	bytes_read;
	char	*temp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		/* if b_read is -1, it means there was an error reading
		 * the file descriptor, so we free left_c and return NULL. */
		if (bytes_read == -1)
		{
			free(left_c);
			return (NULL);
		}
		/* if b_read is 0, this surely means we read the whole
		 * file so there-s no need to stay in the loop */
		else if (bytes_read == 0)
			/* if we didn't read anything, we can break out of the loop */
			break ;
		/* don't forget to set the last character of the buffer
		 * to 0 to NUL-terminate the string */
		buffer[bytes_read] = 0;
		/* there we check if the left_c static char * is empty
		 * because if it's empty, we can't use ft_strjoin on it */
		if (left_c == NULL)
			left_c = ft_strdup("");
		temp = left_c;
		/* once we set left_c to be empty, if it was NUL
		 * or just that something was left in it from the
		 * last time we called get_next_line
		 * we can join the buffer we just read to left_c */
		left_c = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		/* we search in the buffer we just read if we read a \n or not
		 * if yes, we can break out of the loop
		 * if not, we go in the loop once again to read more from the file. */
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	/* at the end of this function, we return the left_c string
	 * it will contain everything we read and ensure there's is 
	 * either a \0 or a \n within it. */
	return (left_c);
}

static char	*extract_line(char *line_buffer)
{
	char	*left_c;
	ssize_t	i;

	i = 0;
	/* This loop let's us find the end of the line
	 * either when we encounter a \n or a \0 */
	while (line_buffer[i] != '\0' && line_buffer[i] != '\n')
		i++;
	/* here we check if the current or next character is a \0
	 * if this is the case, this means that the line is empty so
	 * we return NULL, this is what the subject asks us, send NULL
	 * if there is no next line */
	if (line_buffer[i] == 0 || line_buffer[1] == 0)
		return (NULL);
	/* here we take a substring from the end of the line to the end
	 * of the whole line_buffer, that's what's left from our line */
	left_c = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i);
	if (*left_c == 0)
	{
		free(left_c);
		left_c = NULL;
	}
	/* don't forget to set the last character to \0 to NUL-terminate the line */
	line_buffer[i + 1] = 0;
	return (left_c);
}

char	*get_next_line_bonus(int fd)
{
	/* There's only a minimal difference to make the bonus work
	 * It's basically transforming our static char * variable to an array of char *
	 * as you can see I set the number of elements of the array to 
	 * the constant MAX_FD (see get_next_line.h to see what it is) */
	static char	*left_c[MAX_FD];
	char		*line;
	char		*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	/* fd < 0 : this means the file descriptor is invalid
	 * BUFFER_SIZE <= 0 : we'll read BUFFER_SIZE characters at a time,
	 * we can't read 0 or less character
	 * read(fd, 0, 0) < 0 : this check lets us see if the file exists and
	 * that it has some content to read from, or event that the file is 
	 * openable to read, maybe the file descriptor is more than 0, but it
	 * was open in 'modify only', that means we can't read it. */
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		/* as we changed our static char * to an array
		 * we have to specify wich index we wanna work on
		 * the easier thing to do is to set it to fd */
		free(left_c[fd]);
		free(buffer);
		left_c[fd] = NULL;
		buffer = NULL;
		return (0);
	}
	if (!buffer)
		return (NULL);
	/* again here, we want to store the left characters in 
	 * the array at the index of the fd, so if we have another fd
	 * we won't be overwriting what was left from the other fd
	 * 	 	 	 */
	line = read_line(fd, left_c[fd], buffer);
	/* We have to free the buffer variable here since we'll not be using
	 * it later in the function, freeing it prevents memory leaks. */
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	/* and here again, we have to switch from left_c to left_c[fd]
	 * that's the last thing we have to change, all the other place
	 * we use left_c (in all other functions), we use it as a string
	 * therefore, because we are passing left_c[fd] as parameter
	 * we basically are passing strings as parameter
	 * so no problem there, and nothing to change */
	left_c[fd] = extract_line(line);
	return (line);
}
