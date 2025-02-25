# File name
NAME = push_swap

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -Iinclude

# Directories
SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libft

# Source and object files
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
LIBFT = $(LIBFT_DIR)/libft.a

# Text Colors
BLACK = \033[30m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
WHITE = \033[37m

# targets
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR) $(LIBFT_DIR)/obj
	@echo "Object files removed."

fclean: clean
	@rm -f $(NAME) $(LIBFT)
	@echo "fcleaned"

test2:	$(NAME)	
	$(eval ARG = $(shell shuf -i 0-100 -n 2))

	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

test3:	$(NAME)	
	$(eval ARG = $(shell shuf -i 0-100 -n 3))

	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

test4:	$(NAME)	
	$(eval ARG = $(shell shuf -i 0-100 -n 4))

	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

test10:	$(NAME)	
	$(eval ARG = $(shell shuf -i 0-100 -n 10))

	./push_swap $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

test50:	$(NAME)	
	$(eval ARG = $(shell shuf -i 0-100 -n 50))

	./push_swap $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

re: fclean all

.PHONY: all clean fclean re
