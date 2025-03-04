# File name
NAME = push_swap
BONUS = checker

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -Iinclude
NODIR = --no-print-directory

# temp
TEMP = .messages

# Directories
SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libft
APPS_DIR = apps

# Source and object files
FILES = calculates.c circular_list.c end.c get_moves_utils.c init_structs.c \
        moves_rotate.c moves_simple.c moves_specials.c parse_args.c sort.c sort_utils.c \
        stack.c stats.c turkish.c turkish_utils.c utils.c
SRCS = $(addprefix $(SRC_DIR)/, $(FILES))
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# App source files
MAIN_SRC = $(APPS_DIR)/main.c
CHECKER_SRC = $(APPS_DIR)/checker.c
MAIN_OBJ = $(MAIN_SRC:$(APPS_DIR)/%.c=$(OBJ_DIR)/$(APPS_DIR)/%.o)
CHECKER_OBJ = $(CHECKER_SRC:$(APPS_DIR)/%.c=$(OBJ_DIR)/$(APPS_DIR)/%.o)

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
RESET = \033[0m

# targets
all: $(OBJ_DIR) $(NAME)

bonus: $(OBJ_DIR) $(BONUS)

$(NAME): $(OBJS) $(MAIN_OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MAIN_OBJ) -L$(LIBFT_DIR) -lft
	@echo "$(GREEN)Done! $(NAME) compiled successfully.$(RESET)"

$(BONUS): $(OBJS) $(CHECKER_OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) -o $(BONUS) $(OBJS) $(CHECKER_OBJ) -L$(LIBFT_DIR) -lft
	@echo "$(GREEN)Done! $(BONUS) compiled successfully.$(RESET)"

$(LIBFT):
	@echo "$(CYAN)Building libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) $(NODIR) > $(TEMP) 2>&1 || TRUE
	@rm -f $(TEMP)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/$(APPS_DIR)
	@echo "$(CYAN)Building Objs...$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/$(APPS_DIR)/%.o: $(APPS_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Cleaning up object files...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR) $(NODIR) > $(TEMP) 2>&1 || TRUE
	@rm -f $(TEMP)

fclean: clean
	@echo "$(RED)Removing binaries...$(RESET)"
	@rm -f $(NAME) $(BONUS)
	@make fclean -C $(LIBFT_DIR) $(NODIR) > $(TEMP) 2>&1 || TRUE
	@rm -f $(TEMP)

test: $(NAME)
	./push_swap 34 24 76 16 74 2 29 9 19 14

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

test5:	$(NAME)	
	$(eval ARG = $(shell shuf -i 0-100 -n 5))

	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l


test10:	$(NAME)	
	$(eval ARG = $(shell shuf -i 0-100 -n 10))

	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

test50:	$(NAME)	
	$(eval ARG = $(shell shuf -i 0-100 -n 50))

	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

test100: $(NAME)	
	$(eval ARG = $(shell shuf -i 0-1000 -n 100))

	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

test500: $(NAME)	
	$(eval ARG = $(shell shuf -i 0-1000 -n 500))

	./push_swap $(ARG) | ./checker $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

test5000: $(NAME)	
	$(eval ARG = $(shell shuf -i 0-1000000 -n 5000))

	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

valgrind: $(NAME)
	$(eval ARG = $(shell shuf -i 0-100 -n $(SIZE)))
	@valgrind --leak-check=full --show-leak-kinds=all ./push_swap $(ARG)

re: fclean all

.PHONY: all clean fclean re
