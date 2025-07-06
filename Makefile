# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_SRCS := $(shell find $(LIBFT_DIR) -name '*.c' -o -name '*.h')

INCLUDES = -I$(LIBFT_DIR)

SRC_DIR = ./src
SRCS = $(SRC_DIR)/main.c\
		$(SRC_DIR)/core/alignment.c $(SRC_DIR)/core/costs.c $(SRC_DIR)/core/init_steps.c $(SRC_DIR)/core/logic.c $(SRC_DIR)/core/sort_three.c\
		$(SRC_DIR)/data/init.c $(SRC_DIR)/data/print.c $(SRC_DIR)/data/stacks.c\
		$(SRC_DIR)/input/check_args.c $(SRC_DIR)/input/free.c\
		$(SRC_DIR)/moves/push.c $(SRC_DIR)/moves/reverse.c $(SRC_DIR)/moves/rotate.c $(SRC_DIR)/moves/swap.c $(SRC_DIR)/moves/sync.c\
		$(SRC_DIR)/utils/isordered.c $(SRC_DIR)/utils/join.c $(SRC_DIR)/utils/math.c $(SRC_DIR)/utils/min_max.c $(SRC_DIR)/utils/predecessor.c $(SRC_DIR)/utils/sort_arrays.c\

OBJ_DIR = ./objs
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

NAME = push_swap

OBJ_DIR_BONUS = ./objs_bonus
BONUS_DIR = ./src
BONUS_SRCS = $(BONUS_DIR)/bonus/checker.c\
			$(BONUS_DIR)/core/alignment.c $(BONUS_DIR)/core/costs.c $(BONUS_DIR)/core/init_steps.c $(BONUS_DIR)/core/logic.c $(BONUS_DIR)/core/sort_three.c\
			$(BONUS_DIR)/data/init.c $(BONUS_DIR)/data/print.c $(BONUS_DIR)/data/stacks.c\
			$(BONUS_DIR)/input/check_args.c $(BONUS_DIR)/input/free.c\
			$(BONUS_DIR)/moves/push.c $(BONUS_DIR)/moves/reverse.c $(BONUS_DIR)/moves/rotate.c $(BONUS_DIR)/moves/swap.c $(BONUS_DIR)/moves/sync.c\
			$(BONUS_DIR)/utils/isordered.c $(BONUS_DIR)/utils/join.c $(BONUS_DIR)/utils/math.c $(BONUS_DIR)/utils/min_max.c $(BONUS_DIR)/utils/predecessor.c $(BONUS_DIR)/utils/sort_arrays.c\

BONUS_OBJS = $(BONUS_SRCS:$(BONUS_DIR)/%.c=$(OBJ_DIR_BONUS)/%.o)

BONUS_NAME = checker

# 🎨 Colors
RED      = \033[0;31m
GREEN    = \033[0;32m
YELLOW   = \033[0;33m
MAGENTA  = \033[0;35m
PINK = \033[38;2;255;105;180m
CYAN     = \033[0;36m
WHITE    = \033[0;37m
RESET    = \033[0m

all: $(OBJ_DIR) $(NAME)

bonus: $(OBJ_DIR_BONUS) $(BONUS_NAME)

$(BONUS_NAME): $(LIBFT) $(BONUS_OBJS)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)
	@echo "$(YELLOW)✅ Bonus executable '$(BONUS_NAME)' created successfully.$(RESET)"

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(YELLOW)✅ Executable '$(NAME)' created successfully.$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@echo "$(CYAN)🔹 Compiling$(MAGENTA) $<$(CYAN) ->$(PINK) $@$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR_BONUS)/%.o: $(BONUS_DIR)/%.c | $(OBJ_DIR_BONUS)
	@mkdir -p $(dir $@)
	@echo "$(CYAN)🔹 Compiling$(MAGENTA) bonus $<$(CYAN) ->$(PINK) $@$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)✅ Object directory $(OBJ_DIR) ready.$(RESET)"

$(OBJ_DIR_BONUS):
	@mkdir -p $(OBJ_DIR_BONUS)
	@echo "$(YELLOW)✅ Bonus object directory $(OBJ_DIR_BONUS) ready.$(RESET)"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	@echo "$(GREEN)🗑️  Removing object directories...$(RESET)"
	@rm -rf $(OBJ_DIR) $(OBJ_DIR_BONUS)
	@echo "$(YELLOW)✅ Object directories removed.$(RESET)"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(GREEN)🚮 Removing $(NAME)...$(RESET)";
	@rm -f $(NAME) $(BONUS_NAME)
	@echo "$(YELLOW)✅ $(NAME) removed.$(RESET)";

re: fclean all	

.PHONY: all clean fclean re bonus
