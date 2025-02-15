#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/* Formatted output */
typedef struct s_fmt
{
	va_list		ap;
	size_t		ret;
	const char	*format;
}	t_fmt;
int	ft_printf(const char *format, ...);
void	parse_format(t_fmt *data);
void	handle_conversion(t_fmt *data);
void	ft_putchar(t_fmt *data, char c);
void	ft_putstr(t_fmt *data, char *s);
void	ft_putnbr(t_fmt *data, int n);
void	ft_putunbr(t_fmt *data, unsigned int n);
void	ft_puthex(t_fmt *data, unsigned int n, char specifier);
void	ft_putptr(t_fmt *data, unsigned long long ptr);

/* Dynamic memory allocation */
void	*ft_calloc(size_t nmemb, size_t size);

/* Process termination and conversion */
int	ft_atoi(const char *nptr);

/* String operations */
size_t	ft_strlen(const char *s);
int	ft_strncmp(const char *s1, const char *s2);

/* Character search */
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);

/* Memory operations */
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);

/* Character classification */
int	ft_isalpha(int c);
int	ft_isdigit(int c);
int	ft_isalnum(int c);
int	ft_isascii(int c);
int     ft_isprint(int c);

/* Character conversion */
int	ft_toupper(int c);
int	ft_tolower(int c);

/* On some systems, you might need <bsd/string.h> */
size_t	ft_strlcpy(char *dst, const char *src, size_t siz);
size_t	ft_strlcat(char *dst, const char *src, size_t siz);

/* Sets the first n bytes of the memory area pointed to by s to the constant byte c */
void	*ft_memset(void *s, int c, size_t n);

/* Searches for the first occurrence of the byte c (converted to an unsigned char)
   in the first n bytes of the memory area pointed to by s */
void	*ft_memchr(const void *s, int c, size_t n);

/* Compares the first n bytes of the memory areas s1 and s2.
   Returns an integer less than, equal to, or greater than zero if s1 is found,
   respectively, to be less than, to match, or be greater than s2. */
int	ft_memcmp(const void *s1, const void *s2, size_t n);

/* Allocates memory for an array of nmemb elements of size bytes each and returns a
   pointer to the allocated memory. The memory is set to zero. */
void	*ft_calloc(size_t nmemb, size_t size);

/* Returns a pointer to a new string which is a duplicate of the string s.
   Memory for the new string is obtained with malloc, and can be freed with free(). */
char	*ft_strdup(const char *s);

/* Clears (sets to zero) n bytes of memory starting at the pointer s.
   Note: bzero is considered obsolete in favor of memset. */
void	ft_bzero(void *s, size_t n);

/* Locates the first occurrence of the null-terminated string needle in the string haystack,
   where not more than len characters are searched. Returns a pointer to the first occurrence,
   or NULL if the needle is not found. */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

/* Funciones adicionales */
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/* bonus */
typedef struct	s_list
{
	void		*content;
	struct s_list	*next;
}			t_list;
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int	ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

char	*get_next_line(int fd);
char	*read_and_store(int fd, char *stash);
char	*extract_line(char *stash);
char	*save_remaining(char *stash);

#endif
