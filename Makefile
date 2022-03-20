NAME = push_swap

NAME_BONUS = checker

CC = @cc

FLAGS = -Wall -Wextra -Werror

RM = @rm -f

C_FILES = 	push_swap.c \
			./algorithms/medium_sort.c \
			./algorithms/simple_sort.c \
			./algorithms/complex_sort.c \
			./algorithms/complex_sort_1.c \
			./operations/push_rotate.c \
			./operations/rrotate.c \
			./operations/swap.c\
			./operations/operations.c \
			./stack/index_stack.c \
			./stack/stack.c \
			./stack/parsing.c \
			./utils/ft_printf.c \
			./utils/ft_atoi.c \
			./utils/ft_split.c 

B_FILES = 	./operations/push_rotate.c \
			./operations/rrotate.c \
			./operations/swap.c\
			./operations/operations.c \
			./utils/ft_printf.c \
			./utils/ft_atoi.c \
			./utils/ft_split.c \
			./stack/index_stack.c \
			./stack/stack.c \
			./stack/parsing.c \
			./checker_files/checker.c \
			./checker_files/get_next_line.c \
			./checker_files/get_next_line_utils.c \
			./checker_files/apply_op.c \

N_FLAG = -o

#  colors

C_PURPLE = \033[1;31m
C_GREEN = \033[1;32m
C_L_BLUE = \033[1;34m
C_RES = \033[0m

all : $(NAME)

$(NAME) : $(C_FILES) 
	@echo "$(C_GREEN)["push_swap" CREATED]$(C_RES)"
	$(CC) $(FLAGS) $(C_FILES) $(N_FLAG) $(NAME)

bonus : $(B_FILES)
	@echo "$(C_GREEN)["checker" CREATED]$(C_RES)"
	$(CC) $(FLAGS) $(B_FILES) $(N_FLAG) $(NAME_BONUS)

clean :
	@echo "$(C_PURPLE)["push_swap" REMOVED]$(C_RES)"
	$(RM) $(NAME)

fclean : clean
	@echo "$(C_PURPLE)["checker" REMOVED]$(C_RES)"
	$(RM) $(NAME_BONUS)

re : fclean all