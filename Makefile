SRC_DIR	:= srcs/
OBJ_DIR	:= obj/

checker = checker
utils = utils
inst = instructions

OBJ_DIRS = $(addprefix $(OBJ_DIR), $(checker) $(utils) $(inst))

PRE_SRCS	=	$(checker)/checker $(checker)/exit $(checker)/display \
				$(utils)/utils_nb $(utils)/lst_nbr $(utils)/lst_nbr2 $(utils)/lst_inst $(utils)/utils_sort $(utils)/utils_instructions \
				$(inst)/swap_push $(inst)/rotate $(inst)/reverse_rotate $(inst)/instructions

SRCS = $(addsuffix .c, $(addprefix $(SRC_DIR), $(PRE_SRCS)))
OBJS = $(addsuffix .o, $(addprefix $(OBJ_DIR), $(PRE_SRCS)))

LIBFTA = libft/libft.a

NAME = checker
CC = clang
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
# CFLAGS = -Wall -Wextra -Werror -g3
INC =	-I./includes -L./libft -lft

all:	libft $(NAME)

$(NAME): $(LIBFTA) $(OBJ_DIRS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INC) -o $(NAME) 
	@echo "----- \033[32m $@ created\033[0m  -----"

$(OBJ_DIRS):
	mkdir -p $(OBJ_DIRS)

$(OBJS) : includes/push_swap.h $(LIBFTA)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "$@ \033[32mcreated\033[0m"

$(LIBFTA):
	@$(MAKE) -C ./libft

libft:
	@$(MAKE) -C ./libft

clean:
	rm -rf $(OBJ_DIR)
	@$(MAKE) clean -C libft

fclean: 	clean
	@$(RM) libft/libft.a
	rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re libft
