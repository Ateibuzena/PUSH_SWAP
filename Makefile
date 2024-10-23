# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = /home/azubieta/sgoinfre/azubieta/utils/libft
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
		$(SRC_DIR)/handle/ft_prints.c\

OBJ_DIR = ./objs
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

NAME = push_swap

OBJ_DIR_BONUS = ./objs_bonus
BONUS_DIR = ./src
BONUS_SRCS = $(BONUS_DIR)/bonus/checker.c\
			$(BONUS_DIR)/utils/ft_math.c\
			$(BONUS_DIR)/utils/ft_check_args.c\
			$(BONUS_DIR)/handle/ft_inits.c\
			$(BONUS_DIR)/moves/ft_push.c $(BONUS_DIR)/moves/ft_swap.c $(BONUS_DIR)/moves/ft_rotate.c $(BONUS_DIR)/moves/ft_reverse.c\
			$(BONUS_DIR)/utils/ft_min_max.c\
			$(BONUS_DIR)/steps/ft_intermediate_steps.c\
			$(BONUS_DIR)/utils/ft_immediate_predecessor.c\
			$(BONUS_DIR)/utils/ft_free.c\
			$(BONUS_DIR)/utils/ft_join.c\
			$(BONUS_DIR)/utils/ft_sort_arrays.c\
			$(BONUS_DIR)/handle/ft_stacks.c\
			$(BONUS_DIR)/utils/ft_isordered.c\
			$(BONUS_DIR)/handle/ft_prints.c\

BONUS_OBJS = $(BONUS_SRCS:$(BONUS_DIR)/%.c=$(OBJ_DIR_BONUS)/%.o)
#BONUS_OBJS = $(BONUS_SRCS:./%.c=$(OBJ_DIR)/%.o)

BONUS_NAME = checker  # Cambia el nombre del programa de bonificación según sea necesario
# Excluir la carpeta bonus
# SRCS := $(filter-out $(SRC_DIR)/bonus/%.c, $(SRCS))



# Reglas
all: $(OBJ_DIR) $(NAME)

bonus: $(LIBFT) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)

$(NAME): $(LIBFT)  $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

# Crea los directorios necesarios para archivos del proyecto principal
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)   # Crea el subdirectorio si no existe
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR_BONUS)/%.o: $(BONUS_DIR)/%.c | $(OBJ_DIR_BONUS)
	@mkdir -p $(dir $@)   # Crea el subdirectorio si no existe
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Regla para crear el directorio de objetos
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR_BONUS):
	@mkdir -p $(OBJ_DIR_BONUS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

clean:
	rm -rf $(OBJ_DIR) $(OBJ_DIR_BONUS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re
