NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

REMOVE = rm -f
SRC_DIR = src/
INC_DIR = inc/

SRCS = \
	$(SRC_DIR)push_swap.c \
	$(SRC_DIR)handle_errors.c \
	$(SRC_DIR)handle_stack.c \
	$(SRC_DIR)init_nodes_a.c \
	$(SRC_DIR)init_nodes_b.c \
	$(SRC_DIR)sort_stack.c \
	$(SRC_DIR)sort_stack_utils.c \
	$(SRC_DIR)init_stack.c \
	$(SRC_DIR)push.c \
	$(SRC_DIR)swap.c \
	$(SRC_DIR)rotate.c \
	$(SRC_DIR)reverse_rotate.c \

OBJS = $(SRCS:.c=.o)

# Colors
GREEN = \033[0;32m
YELLOW = \033[0;33m
CYAN = \033[0;36m
RESET = \033[0m

all: $(LIBFT) $(NAME)
	@echo "$(GREEN)Compilation completed!$(RESET)"

$(LIBFT):
	@echo "$(YELLOW)Compiling libft...$(RESET)"
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	@echo "$(CYAN)Linking push_swap...$(RESET)"
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)push_swap executable created successfully!$(RESET)"

%.o: %.c
	@echo "$(CYAN)Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	@echo "$(YELLOW)Cleaning object files...$(RESET)"
	$(REMOVE) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@echo "$(YELLOW)Cleaning push_swap executable...$(RESET)"
	$(REMOVE) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

# test:
	# cc -Wall -Wextra -Werror src/*.c -Llibft -lft -Ilibft -o push_swap
