NAME			=	push_swap

BLACK			=	\033[0;30m
RED				=	\033[0;31m
GREEN			=	\033[0;32m
ORANGE			=	\033[0;33m
BLUE			=	\033[0;34m
PURPLE			=	\033[0;35m
CYAN			=	\033[0;36m
LIGHT_GRAY		=	\033[0;37m
DARK_GRAY		=	\033[1;30m
LIGHT_RED		=	\033[1;31m
LIGHT_GREEN		=	\033[1;32m
YELLOW			=	\033[1;33m
LIGHT_BLUE		=	\033[1;34m
LIGHT_PURPLE	=	\033[1;35m
LIGHT_CYAN		=	\033[1;36m
WHITE			=	\033[1;37m
NO_COLOR		=	\033[0m

-include sources.mk
-include includes.mk

INCLUDES_PATH	=	./incs
LIBFT_PATH		=	./my_libft

GCC				=	gcc
FLAGS			=	-Wall -Wextra -Werror #-g3 -fsanitize=address
OBJECTS			=	$(SOURCES:.c=.o)
RM				=	rm -f

all:	$(NAME)

$(LIBFT_PATH)/libft.a:
	@$(MAKE) -C $(LIBFT_PATH) all

%.o:	%.c $(LIBFT_PATH)/libft.a $(INCLUDES)
	@$(GCC) $(FLAGS) -I $(INCLUDES_PATH) -c $< -o $@
	@printf "\033[2K\r$(BLUE)$(NAME)$(RESET)$(BLUE): $(PURPLE)$<$(RESET)"

$(NAME):	$(LIBFT_PATH)/libft.a $(INCLUDES) $(OBJECTS)
	@$(GCC) $(LIBFT_PATH)/libft.a $(FLAGS) -I $(INCLUDES_PATH) $(OBJECTS) -o $(NAME)
	@printf "\033[2K\r$(BLUE)$(NAME)$(RESET)$(BLUE): $(GREEN)Compiled [√]$(RESET)\n"

oclean:
	@printf "$(BLUE)$(NAME): $(LIGHT_RED)Cleaning all .o in project.\n$(RESET)"
	@$(RM) $(OBJECTS)

clean: oclean
	@$(MAKE) -C $(LIBFT_PATH) clean

fclean:
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@printf "$(BLUE)$(NAME): $(RED)Cleaning compiled program $(NAME).\n$(RESET)"
	@$(RM) $(NAME)

re:	fclean all

gmk:
	@printf "$(BLUE)$(NAME): $(GREEN)Generating Makefile includes.\n$(RESET)"
	@find srcs -name '*.c' | sed 's/^/SOURCES += /' > sources.mk
	@find incs -name '*.h' | sed 's/^/INCLUDES += /' > includes.mk

norminette: oclean
	@printf "$(BLUE)$(NAME): $(GREEN)norminette -> sources\n$(RESET)"
	@norminette srcs
	@echo " "
	@printf "$(BLUE)$(NAME): $(GREEN)norminette -> includes\n$(RESET)"
	@norminette incs

end:
	@make fclean
	@make gmk
	@make all
	@make norminette
	@make fclean
	@printf "$(BLUE)$(NAME): $(LIGHT_CYAN)Prepared to be pushed.\n$(RESET)"

.PHONY:	all oclean clean fclean re gmk norminette end