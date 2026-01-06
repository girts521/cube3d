CC = cc
CFLAGS = -Wall -Wextra -Werror -Isrc -O3 -g
MLX_FLAGS = -Iinclude -ldl -lglfw -pthread -lm

SRC = main.c \

OBJ = $(SRC:.c=.o)

NAME = cube3d

MLX = .MLX42/build/libmlx42.a

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	@cp $(MLX) libmlx42.a
	@$(CC) $(CFLAGS) $(OBJ) libmlx42.a $(MLX_FLAGS) -o $(NAME)
	@echo "/* Build $(NAME) */"

$(MLX):
	@cmake MLX42 -B  MLX42/build > /dev/null 2>&1
	@make -C $ MLX42/build -j4 > /dev/null 2>&1

clean:
	@rm -rf MLX42/build
	@rm -f $(OBJ) libmlx42.a
	@echo "/* Removed o-files $(NAME) */"

fclean: clean
	@rm -f $(NAME)
	@echo "/* Removed $(NAME) */"

re: fclean all

test: $(NAME)
	@echo ""
	@./$(NAME)

.PHONY: all re fclean clean bonus
