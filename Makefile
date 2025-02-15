# Makefile
CC      = cc
CFLAGS  = -Wall -Werror -Wextra
AR      = ar rcs

NAME    = libft.a

SRCS    = $(wildcard *.c)

OBJS    = $(SRCS:.c=.o)

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(B_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
