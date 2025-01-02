NAME = libftprintf.a

LIB_PATH = libft/

GNL_PATH = get_next_line/

GNL_SRCS = $(addprefix $(GNL_PATH), get_next_line_bonus.c get_next_line_utils_bonus.c)

MY_SRCS = 	ft_printf.c \
			basic/ft_checkarg.c \
			basic/ft_putnbr_base.c \
			basic/ft_putnbr_count.c \
			basic/ft_putchar_count.c \
			basic/ft_putstr_count.c \
			basic/ft_putptr_count.c \
			ft_setflags.c \
			ft_setflags_utils.c

MY_OBJS = $(MY_SRCS:.c=.o)

GNL_OBJS = $(GNL_SRCS:.c=.o)

B_SRCS = ft_printf.c \
			bonus/ft_checkarg_bonus.c \
			bonus/ft_putnbr_bonus.c \
			bonus/ft_putnbr_base_bonus.c \
			bonus/ft_putchar_bonus.c \
			bonus/ft_putstr_bonus.c \
			bonus/ft_putptr_bonus.c \
			bonus/ft_utils_bonus.c \
			ft_setflags.c \
			ft_setflags_utils.c

B_OBJS = $(B_SRCS:.c=.o)

ALL_OBJS = $(MY_OBJS) $(B_OBJS) $(GNL_OBJS)

CFLAGS = -Werror -Wextra -Wall

all : $(NAME)

$(NAME) : $(MY_OBJS) $(GNL_OBJS)
	@cd $(LIB_PATH) && make -s
	@ar rcs $(NAME) $(LIB_PATH)*.o $(GNL_OBJS) $(MY_OBJS)
	
	
bonus : $(B_OBJS)
	@rm -f $(NAME)
	@cd $(LIB_PATH) && make -s
	@ar rcs $(NAME) $(LIB_PATH)*.o $(B_OBJS) 

clean :
	@cd $(LIB_PATH) && make -s clean
	@rm -f $(ALL_OBJS)

fclean : clean
	@cd $(LIB_PATH) && make -s fclean
	@rm -f $(NAME)

re : fclean all 

.SILENT : $(MY_OBJS) $(GNL_OBJS)

.PHONY : all compile bonus clean fclean test re 