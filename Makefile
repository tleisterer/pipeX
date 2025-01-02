NAME  = pipex

MY_SRCS = main.c utils.c

MY_OBJS = $(MY_SRCS:.c=.o)

BOLD=\033[1m
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
BLUE=\033[0;34m
END=\033[0m

all: $(NAME)

$(NAME): $(MY_OBJS)
	@printf "Compiling libft..."
	@make -s -C libft
	@printf "$(GREEN) Done\n$(END)"
	@printf "Compiling $(NAME)..."
	@cc $(MY_OBJS) libft/libftprintf.a -o $(NAME)
	@printf "$(GREEN) Done\n$(END)"

clean:
	@printf "$(YELLOW)$(BOLD)Removing all object files\n$(END)"
	@rm -f $(MY_OBJS)
	@make clean -C libft

fclean: clean
	@printf "$(YELLOW)$(BOLD)Removing all created files\n$(END)"
	@rm -f $(NAME)
	@make fclean -C libft

re: fclean all

.SILENT: $(MY_OBJS)
