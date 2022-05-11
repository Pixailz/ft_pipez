# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/23 01:36:34 by brda-sil          #+#    #+#              #
#    Updated: 2022/05/11 17:40:53 by brda-sil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# config

CFLAGS			:= -Wall -Wextra #-Werror -g
NAME			:= pipex
BONUS			:= pipex_bonus
RM				:= rm -rf
CC				:= gcc
PADDING			:= 27

# DIR
BIN_DIR			:= bin
SRC_DIR			:= src
INC_DIR			:= includes
OBJ_DIR			:= obj

# SRC
SRC_BASE		:= ft_calloc.c \
				   ft_checkparams.c \
				   ft_error.c \
				   ft_get_words.c \
				   ft_memchr.c \
				   ft_memjoin.c \
				   ft_memset.c \
				   ft_parse.c \
				   ft_printf.c \
				   ft_put_addr.c \
				   ft_putchar.c \
				   ft_puthex.c \
				   ft_putnbr.c \
				   ft_putnbr_u.c \
				   ft_putstr.c \
				   ft_sel_params.c \
				   ft_split.c \
				   ft_strcat.c \
				   ft_strchr.c \
				   ft_strcpy.c \
				   ft_strcspn.c \
				   ft_strdup.c \
				   ft_strjoin.c \
				   ft_strlen.c \
				   ft_strncmp.c \
				   ft_strspn.c \
				   ft_strtok.c \
				   get_next_line.c

SRC_C			:= $(SRC_BASE) \
				   pipex.c \
				   pipex_child.c \
				   pipex_cmd.c \
				   pipex_free.c \
				   pipex_init.c

SRC_BONUS		:= $(SRC_BASE) \
				   pipex_bonus.c \
				   pipex_child_bonus.c \
				   pipex_cmd_bonus.c \
				   pipex_free_bonus.c \
				   pipex_init_bonus.c \

SRC_C			:= $(addprefix $(SRC_DIR)/,$(SRC_C))
SRC_BONUS		:= $(addprefix $(SRC_DIR)/,$(SRC_BONUS))

# OBJ
OBJ_C			:= $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SRC_C:%.c=%.o))
OBJ_BONUS		:= $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SRC_BONUS:%.c=%.o))

# LIB DIR
CFLAGS			+= -I$(INC_DIR)

#  Bash Color
green			:= \033[38;5;82m
blue			:= \033[38;5;75m
red				:= \033[38;5;196m
yellow			:= \033[38;5;226m

blinking		:= \033[5m
reset			:= \033[0m

font_color		:= $(blue)
bold			:= $(green)
ascii_color		:= $(bold)

# **************************************************************************** #

# **************************************************************************** #
# utils

define ascii_art
   ▄███████▄  ▄█     ▄███████▄    ▄████████  ▄███████▄
  ███    ███ ███    ███    ███   ███    ███ ██▀     ▄██
  ███    ███ ███▌   ███    ███   ███    █▀        ▄███▀
  ███    ███ ███▌   ███    ███  ▄███▄▄▄      ▀█▀▄███▀▄▄
▀█████████▀  ███▌ ▀█████████▀  ▀▀███▀▀▀       ▄███▀   ▀
  ███        ███    ███          ███    █▄  ▄███▀
  ███        ███    ███          ███    ███ ███▄     ▄█
 ▄████▀      █▀    ▄████▀        ██████████  ▀████████▀
$(reset)
endef
export ascii_art

# **************************************************************************** #


# **************************************************************************** #
# Rules

all:			setup $(NAME)

$(OBJ_DIR)/%.o: 		$(SRC_DIR)/%.c
	@printf "  $(font_color)[$(green)+$(font_color)] Creation of $(bold)$<"
	$(eval OBJ_LEN := $(shell printf $^ | wc -c))
	$(eval PAD_LEN := $(shell expr $(PADDING) - $(OBJ_LEN)))
	@printf "%-$(PAD_LEN)s" " "
	@printf "$(blinking)$(font_color)-> $(reset)$(bold)$@ $(reset)"
	@printf "\n"
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME):			$(OBJ_C)
	@printf "$(font_color)[$(green)+$(font_color)] Creation of $(bold)$(NAME)$(reset)\n"
	@$(CC) -o $(NAME) $(OBJ_C)

$(BONUS):			$(OBJ_BONUS)
	@printf "$(font_color)[$(green)+$(font_color)] Creation of $(bold)$(BONUS)$(reset)\n"
	@$(CC) -o $(BONUS) $(OBJ_BONUS)

bonus:				setup $(BONUS)

setup:					call_logo $(OBJ_DIR)

call_logo:
	@printf "$(ascii_color)$$ascii_art"

$(OBJ_DIR):
	@printf "$(font_color)[$(green)+$(font_color)] Creation of $(bold)$(OBJ_DIR)$(reset)\n"
	@mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	@printf "$(font_color)[$(green)+$(font_color)] Creation of $(bold)$(BIN_DIR)$(reset)\n"
	@mkdir -p $(BIN_DIR)

clean:
	@printf "$(font_color)[$(red)-$(font_color)] Deleting $(bold)$(OBJ_DIR)$(reset)\n"
	@$(RM) $(OBJ_DIR)

fclean:					clean
	@printf "$(font_color)[$(red)-$(font_color)] Deleting $(bold)$(NAME)$(reset)\n"
	@$(RM) $(NAME) $(LIBSHARE)
	@printf "$(font_color)[$(red)-$(font_color)] Deleting $(bold)$(BIN_DIR)$(reset)\n"
	@$(RM) $(BIN_DIR)

re:						call_logo fclean $(OBJ_DIR) $(NAME)

$(TEST_DIR):
	@printf "$(font_color)[$(green)+$(font_color)] Creation of $(bold)$(TEST_DIR)$(reset)\n"
	@mkdir -p $(TEST_DIR)

.PHONY:					all clean fclean re setup lib call_logo so

# **************************************************************************** #
#run "data.txt" "cat -e" "sed -nE 's|[0-9]*(.*)|\1|p'" "outfile.txt"
