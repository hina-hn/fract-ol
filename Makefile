NAME = fractol

LIBFT = libft/libft.a
MLX = mlx/libmlx_Linux.a
SRC_DIR = SRC_DIROBJ_DIR obj

CC = cc
CFLAG = -Wall -Wextra -Werror

INC 	:= -I inc -I ibft/includes -I mlx
MLXFLAG = -Llibft -Lmlx -lmlx -lft -Imlx -lXext -lX11 -lm -Ofast

SRC = src/main.c \
      src/init.c \
	  src/render.c \
	  src/math_utils.c \
	  src/events.c \
	  src/string_utils.c
OBJ		:= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	$(CC) $(OBJ) $(CFLAG) $(INC) $(MLXFLAG) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAG) -c -o $@ $<

$(LIBFT):
	make -C libft

$(MLX):
	make -C mlx

clean: 
		make -C libft clean
		make -C mlx clean
		$(RM) $(OBJ_DIR)

fclean: clean
		make -C libft fclean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re