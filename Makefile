# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = /home/azubieta/sgoinfre/azubieta/libft
LIBFT = $(LIBFT_DIR)/libft.a


INCLUDES = -I$(LIBFT_DIR)

SRC_DIR = ./src
SRCS = $(SRC_DIR)/push_swap.c\
		$(SRC_DIR)/handle/ft_inits.c $(SRC_DIR)/handle/ft_stacks.c\
		$(SRC_DIR)/moves/ft_push.c $(SRC_DIR)/moves/ft_swap.c $(SRC_DIR)/moves/ft_rotate.c $(SRC_DIR)/moves/ft_reverse.c\
		$(SRC_DIR)/utils/ft_isordered.c $(SRC_DIR)/utils/ft_min_max.c $(SRC_DIR)/utils/ft_immediate_predecessor.c\
		$(SRC_DIR)/utils/ft_join.c $(SRC_DIR)/utils/ft_free.c $(SRC_DIR)/utils/ft_sort_arrays.c $(SRC_DIR)/utils/ft_check_args.c\
		$(SRC_DIR)/steps/ft_steps.c $(SRC_DIR)/steps/ft_intermediate_steps.c\
		$(SRC_DIR)/utils/ft_math.c\

OBJ_DIR = ./objs
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

NAME = push_swap

# Reglas
all: $(NAME)

$(NAME): $(LIBFT)  $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

# Crea los directorios necesarios dentro de OBJ_DIR
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)   # Crea el subdirectorio si no existe
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Regla para crear el directorio de objetos
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
