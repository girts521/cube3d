CC = cc
CFLAGS = -Wall -Wextra -Werror -Isrc -O3 -g
MLX_FLAGS = -Iinclude -ldl -lglfw -pthread -lm

SRC = main.c \
		clean.c

OBJ = $(SRC:.c=.o)

NAME = cube3d

LIBFT_PATH = libft

LIBFT = $(LIBFT_PATH)/libft.a

MLX = .MLX42/build/libmlx42.a

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	@cp $(LIBFT) libft.a
	@cp $(MLX) libmlx42.a
	@$(CC) $(CFLAGS) $(OBJ) libft.a libmlx42.a $(MLX_FLAGS) -o $(NAME)
	@echo "/* Build $(NAME) */"

$(LIBFT):
	@make -C $(LIBFT_PATH) all --no-print-directory

$(MLX):
	@cmake MLX42 -B  MLX42/build > /dev/null 2>&1
	@make -C $ MLX42/build -j4 > /dev/null 2>&1

clean:
	@rm -rf MLX42/build
	@rm -f $(OBJ) libft.a libmlx42.a
	@echo "/* Removed o-files $(NAME) */"
	@make -C $(LIBFT_PATH) clean --no-print-directory

fclean: clean
	@rm -f $(NAME)
	@echo "/* Removed $(NAME) */"
	@make -C $(LIBFT_PATH) fclean --no-print-directory

re: fclean all

test: $(NAME)
	@echo ""
	@./$(NAME)

.PHONY: all re fclean clean bonus
