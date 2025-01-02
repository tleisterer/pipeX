NAME  = pipex

MY_SRCS = main.c

MY_OBJS = $(MY_SRCS:.c=.o)

all:

$(NAME): $(MY_OBJS)
	make -C libft.a
	cc $(MY_OBJS) libft/libftprintf.a -o $(NAME)

clean:
	rm -f