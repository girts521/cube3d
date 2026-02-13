CC = cc
CFLAGS = -Wall -Wextra -Werror -Isrc -O3
CFLAGS_M = -Isrc -O3
MLX_FLAGS = -Iinclude -ldl -lglfw -pthread -lm

MLX_DIR = .MLX42
AUDIO_DIR = .miniaudio
AUDIO_FILE = $(AUDIO_DIR)/miniaudio.c

SRC_M = main.c \
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
		$(AUDIO_FILE)

SRC = no_sound_files/main.c \
		no_sound_files/clean.c \
		init/init.c \
		no_sound_files/init_extra.c \
		no_sound_files/game_loop.c \
		game/movement.c \
		game/rotation.c \
		no_sound_files/key_handler.c \
		game/hud.c \
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

OBJ = $(SRC:.c=.o)
OBJ_PROPER = $(SRC_M:.c=.p.o)

NAME = cub3d

LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a

MLX = .MLX42/build/libmlx42.a

%.o: %.c cub3d.h
	@$(CC) $(CFLAGS) -c $< -o $@

%.p.o: %.c cub3d.h
	@$(CC) $(CFLAGS_M) -c $< -o $@

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	@cp $(LIBFT) libft.a
	@cp $(MLX) libmlx42.a
	@$(CC) $(CFLAGS) $(OBJ) libft.a libmlx42.a $(MLX_FLAGS) -o $(NAME)
	@echo "/* Build $(NAME) (Standard) */"

proper: $(AUDIO_FILE) $(LIBFT) $(MLX) $(OBJ_PROPER) 
	@cp $(LIBFT) libft.a
	@cp $(MLX) libmlx42.a
	@$(CC) $(CFLAGS_M) $(OBJ_PROPER) libft.a libmlx42.a $(MLX_FLAGS) -o $(NAME)
	@echo "/* Build $(NAME) (Proper) */"

$(LIBFT):
	@make -C $(LIBFT_PATH) all --no-print-directory

$(MLX_DIR):
	@echo "Downloading MLX42..."
	@git clone https://github.com/codam-coding-college/MLX42.git $(MLX_DIR)

# $(AUDIO_DIR):
# 	@echo "Downloading miniaudio..."
# 	@git clone https://github.com/mackron/miniaudio $(AUDIO_DIR)

$(AUDIO_FILE):
	@if [ ! -d "$(AUDIO_DIR)" ]; then \
		echo "Downloading miniaudio..."; \
		git clone https://github.com/mackron/miniaudio $(AUDIO_DIR); \
	fi

$(MLX): | $(MLX_DIR)
	@cmake $(MLX_DIR) -B  $(MLX_DIR)/build > /dev/null 2>&1
	@make -C $(MLX_DIR)/build -j4 > /dev/null 2>&1

clean:
	@rm -rf $(MLX_DIR)/build
	@rm -f $(OBJ) $(OBJ_PROPER) libft.a libmlx42.a
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

.PHONY: all re fclean clean test val proper

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
