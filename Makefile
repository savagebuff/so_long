NAME_LIB		=	libft.a

HEADER_NAME		=	so_long.h
NAME_SL			=	so_long

INC_DIR			=	./includes/
INC_LIB			=	./libft/
SRC_DIR			=	./sources/
OBJ_DIR			=	./obj/

SRC_NAME_SL		=	so_long.c	get_next_line.c	get_next_line_utils.c	checker.c\
					helper.c	imgs.c			print_img.c

HEADER			=	$(addprefix $(INC_DIR), $(HEADER_NAME))

SRC_SL			=	$(addprefix $(SRC_DIR), $(SRC_NAME_SL))
OBJ_SL			=	$(addprefix $(OBJ_DIR), $(SRC_NAME_SL:.c=.o))

CC				=	gcc
FLAGS			=	-Wall -Wextra -Werror
FLAGSMLX		=	-lmlx -framework OpenGL -framework AppKit
GCC_LIBFT		=	-L ./libft/ -l ft

all: $(NAME_SL)

$(NAME_SL): $(OBJ_DIR) $(OBJ_SL) $(NAME_LIB) $(HEADER)
	@$(CC) $(GCC_LIBFT) $(addprefix -I, $(INC_DIR)) $(OBJ_SL) $(FLAGSMLX) libmlx.dylib -o $(NAME_SL)

$(OBJ_DIR):
	@mkdir -p obj

$(NAME_LIB):
	@make -C libft/

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	$(CC) -c -I $(INC_DIR) -I $(INC_LIB_FT) $(FLAGS) $< -o $@

clean:
	@/bin/rm -rf $(OBJ_DIR)
	@make clean -C libft/

fclean: clean
	@/bin/rm -f $(NAME_SL)
	@make fclean -C libft/

re: fclean all