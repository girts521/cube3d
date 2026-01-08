# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afruhauf <afruhauf@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 13:22:28 by afruhauf          #+#    #+#              #
#    Updated: 2025/01/06 17:45:13 by afruhauf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

CONVERSION_SRC = conversion/ft_atoi.c conversion/ft_itoa.c \
					conversion/ft_atoi_err.c

FILE_SRC = file/ft_putchar_fd.c file/ft_putendl_fd.c file/ft_putnbr_fd.c \
			file/ft_putstr_fd.c file/get_next_line/get_next_line.c \
			file/get_next_line/get_next_line_utils.c

IS_CHAR_SRC = is_char/ft_checkchar.c is_char/ft_isalnum.c \
				is_char/ft_isalpha.c is_char/ft_isascii.c \
				is_char/ft_isbinary.c is_char/ft_ischars.c \
				is_char/ft_isdigit.c is_char/ft_ishex.c \
				is_char/ft_islow.c is_char/ft_isprint.c \
				is_char/ft_isspace.c is_char/ft_isup.c

LIST_SRC = list/ft_lstadd_back.c list/ft_lstadd_front.c list/ft_lstclear.c \
			list/ft_lstdelone.c list/ft_lstiter.c list/ft_lstlast.c \
			list/ft_lstmap.c list/ft_lstnew.c list/ft_lstsize.c

MATH_SRC = math/ft_fnext_prime.c math/ft_is_prime.c math/ft_pow.c \
			math/ft_sqrt.c

MEMORY_SRC = memory/ft_bzero.c memory/ft_calloc.c memory/ft_memchr.c \
				memory/ft_memcmp.c memory/ft_memcpy.c memory/ft_memmove.c \
				memory/ft_memset.c

MY_STRING_SRC = my_string/ft_split.c my_string/ft_strdup.c \
					my_string/ft_strjoin.c my_string/ft_strlcpy.c \
					my_string/ft_strmapi.c my_string/ft_strnstr.c \
					my_string/ft_strremc.c my_string/ft_substr.c \
					my_string/ft_toupper.c my_string/ft_strchr.c  \
					my_string/ft_striteri.c my_string/ft_strlcat.c \
					my_string/ft_strlen.c my_string/ft_strncmp.c \
					my_string/ft_strrchr.c my_string/ft_strtrim.c \
					my_string/ft_tolower.c

PRINT_SRC = print/ft_putbase.c print/ft_putbase_uns.c print/ft_putchar.c \
			print/ft_putnbr.c print/ft_putnbr_uns.c print/ft_putnstr.c \
			print/ft_putpointer.c print/ft_putstr.c \
			print/ft_printf/flags.c print/ft_printf/ft_print_hex.c \
			print/ft_printf/ft_print_num.c print/ft_printf/ft_print_p.c \
			print/ft_printf/ft_printf.c  rint/ft_printf/padding.c \
			print/ft_printf/stringchar.c print/ft_printf/utils.c


UTILS_SRC = utils/ft_max.c utils/ft_min.c utils/ft_n_d_hex.c  \
			utils/ft_n_d_uns.c utils/ft_n_digits.c utils/ft_shift_d.c \
			utils/ft_n_bits.c

SRC = $(CONVERSION_SRC) $(FILE_SRC) $(IS_CHAR_SRC) $(LIST_SRC) $(MATH_SRC) \
		$(MEMORY_SRC) $(MY_STRING_SRC) $(PRINT_SRC) $(UTILS_SRC)

OBJ = $(patsubst %.c, %.o, $(notdir $(SRC)))

NAME = libft.a

TEST = dev_dump/main

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@printf "/* Build $(NAME) */\n"

VPATH = $(shell find memory is_char list file my_string conversion utils \
			math print -type d)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) $(TEST).out
	@printf "/* Removed o-files (libft) */\n"

fclean: clean
	@rm -f $(NAME)
	@printf "/* Removed $(NAME) */\n"

re: fclean all

test: $(NAME) $(TEST).c
	$(CC) $(CFLAGS) $(TEST).c $(NAME) -o $(TEST).out
	./$(TEST).out

.PHONY: all re fclean clean test
