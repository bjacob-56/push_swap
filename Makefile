SRC_DIR	:= srcs/
OBJ_DIR	:= obj/

common = common
utils = utils
inst = instructions
sort = sort

OBJ_DIRS = $(addprefix $(OBJ_DIR), $(common) $(utils) $(inst) $(mains) $(sort))

PRE_SRCS	=	$(common)/init $(common)/exit $(common)/display $(common)/clear_objects \
				$(utils)/utils_nb $(utils)/lst_nbr $(utils)/lst_nbr2 $(utils)/lst_inst $(utils)/lst_utils $(utils)/utils_sort_check $(utils)/utils_sort_modif $(utils)/utils_sort_array $(utils)/utils_instructions \
				$(inst)/swap_push $(inst)/rotate $(inst)/reverse_rotate $(inst)/instructions \
				$(sort)/sort_medium_and_high_numbers $(sort)/sort_very_high_numbers

OBJS = $(addsuffix .o, $(addprefix $(OBJ_DIR), $(PRE_SRCS)))

OBJ_PUSH =  obj/push_swap.o
OBJ_CHECKER = obj/checker.o

LIBFTA = libft/libft.a

NAME = push_swap
CHECKER = checker
CC = clang
RM = rm -f
# CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
CFLAGS = -Wall -Wextra -Werror -g3
INC =	-I./includes -L./libft -lft

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "$@ \033[32mcreated\033[0m"

all:	libft $(NAME) $(CHECKER)

$(CHECKER):	$(OBJ_DIRS) $(LIBFTA) $(OBJS) $(OBJ_CHECKER)
	$(CC) $(CFLAGS) $(OBJS) $(OBJ_CHECKER) $(INC) -o $(CHECKER) 
	@echo "----- \033[32m $@ created\033[0m  -----"

$(NAME):	$(OBJ_DIRS) $(LIBFTA) $(OBJS) $(OBJ_PUSH)
	$(CC) $(CFLAGS) $(OBJS) $(OBJ_PUSH) $(INC) -o $(NAME) 
	@echo "----- \033[32m $@ created\033[0m  -----"

$(OBJ_DIRS):
	mkdir -p $(OBJ_DIRS)

$(OBJS) : includes/push_swap.h
$(OBJ_PUSH) : includes/push_swap.h
$(OBJ_CHECKER) : includes/push_swap.h

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
	rm -f $(CHECKER)

re:		fclean all

.PHONY: all clean fclean re libft
