# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/23 01:36:34 by brda-sil          #+#    #+#              #
#    Updated: 2022/05/02 01:44:58 by brda-sil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
# config
CFLAGS			:= -Wall -Wextra -Werror -g
NAME			:= pipex
RM				:= rm -rf
CC				:= gcc
PADDING			:= 27

# DIR
BIN_DIR			:= bin
SRC_DIR			:= src
INC_DIR			:= includes
OBJ_DIR			:= obj

# SRC
SRC_C			:= $(wildcard $(SRC_DIR)/*.c)

# OBJ
OBJ_C			:= $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SRC_C:%.c=%.o))

# LIB DIR
CFLAGS			+= -I$(INC_DIR)

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

$(NAME):				$(OBJ_C) $(BIN_DIR)
	@printf "$(font_color)[$(green)+$(font_color)] Creation of $(bold)$(BIN_DIR)/$(NAME)$(reset)\n"
	@$(CC) -o $(BIN_DIR)/$(NAME) $(OBJ_C)

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

.PHONY:					all clean fclean re setup lib call_logo so test

# **************************************************************************** #
#run "data.txt" "cat -e" "sed -nE 's|[0-9]*(.*)|\1|p'" "outfile.txt"
