CC = cc
#CFLAGS = -Wall -Wextra -Werror -Isrc -O3 -g
CFLAGS = -Isrc -O3 -g
MLX_FLAGS = -Iinclude -ldl -lglfw -pthread -lm

MLX_DIR = .MLX42
AUDIO_DIR = .miniaudio

SRC = main.c \
		clean.c \
		init/init.c \
		init/init_extra.c \
		game/game_loop.c \
		game/movement.c \
		game/rotation.c \
		game/key_handler.c \
		game/hud.c \
		game/audio.c \
		parser/parse_input.c \
		parser/parse_map.c \
		parser/parse_utils.c \
		parser/fill_map.c	\
		parser/add_rgb.c	\
		raycasting/raycasting.c \
		raycasting/fill_background.c \
		raycasting/render_vertical_line.c \
		raycasting/floor_ceiling.c \
		raycasting/utils.c \
		$(AUDIO_DIR)/miniaudio.c

OBJ = $(SRC:.c=.o)

NAME = cub3d

LIBFT_PATH = libft

LIBFT = $(LIBFT_PATH)/libft.a

MLX = .MLX42/build/libmlx42.a

%.o: %.c cub3d.h
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(AUDIO_DIR) $(OBJ)
	@cp $(LIBFT) libft.a
	@cp $(MLX) libmlx42.a
	@$(CC) $(CFLAGS) $(OBJ) libft.a libmlx42.a $(MLX_FLAGS) -o $(NAME)
	@echo "/* Build $(NAME) */"

$(LIBFT):
	@make -C $(LIBFT_PATH) all --no-print-directory

$(MLX_DIR):
	@echo "Downloading MLX42..."
	@git clone https://github.com/codam-coding-college/MLX42.git $(MLX_DIR)

$(AUDIO_DIR):
	@echo "Downloading miniaudio..."
	@git clone https://github.com/mackron/miniaudio $(AUDIO_DIR)

$(MLX): | $(MLX_DIR)
	@cmake $(MLX_DIR) -B  $(MLX_DIR)/build > /dev/null 2>&1
	@make -C $(MLX_DIR)/build -j4 > /dev/null 2>&1

clean:
	@rm -rf $(MLX_DIR)/build
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
	@./$(NAME) .test/working.cub

val: $(NAME)
	@echo ""
	@valgrind --leak-check=full --show-leak-kinds=definite --suppressions=mlx42.supp --track-origins=yes ./$(NAME) .test/working.cub

.PHONY: all re fclean clean test val

# download:
# 	git clone https://github.com/mackron/miniaudio .miniaudio
# 	git clone https://github.com/codam-coding-college/MLX42.git .MLX42

# download:
# 	@if [ ! -d ".miniaudio" ]; then \
# 		git clone https://github.com/mackron/miniaudio .miniaudio; \
# 	else \
# 		echo "miniaudio already installed"; \
# 	fi
# 	@if [ ! -d ".MLX42" ]; then \
# 		git clone https://github.com/codam-coding-college/MLX42.git .MLX42; \
# 	else \
# 		echo "MLX42 already installed"; \
# 	fi
