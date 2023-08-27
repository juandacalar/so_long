NAME = so_long

CC = gcc
CFLAGS  -Wall -Wextra -Werror

SRC_DIR = srcs/
OBJ_DIR = obj/
LIBFT = libs/libft/
MINILIBX = libs/minilibx/

SRC_FILES = $(wildcard $(SRC_DIR)*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC_FILES))

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c 
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(LIBFT) -I $(MINILIBX) -c $< -o $@

$(NAME): $(OBJ_FILE)
	$(MAKE) -C $(LIBFT)
	$(MAKE) -C $(MINILIBX)
	$(CC) $(CFLAGS) $(OBJ_FILES) -L $(LIBFT) -lft -L $(MINILIBX) -lmlx -o $(NAME)

clean: 
	rm -f $(OBJ_DIR)
	$(MAKE) clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re