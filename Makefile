# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brda-sil <brda-sil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/23 01:36:34 by brda-sil          #+#    #+#              #
#    Updated: 2022/04/28 20:05:48 by brda-sil         ###   ########.fr        #
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

define print_ascii
	@printf "$(ascii_color)"
	@printf "   ▄███████▄  ▄█     ▄███████▄    ▄████████  ▄███████▄  \n"
	@printf "  ███    ███ ███    ███    ███   ███    ███ ██▀     ▄██ \n"
	@printf "  ███    ███ ███▌   ███    ███   ███    █▀        ▄███▀\n"
	@printf "  ███    ███ ███▌   ███    ███  ▄███▄▄▄      ▀█▀▄███▀▄▄\n"
	@printf "▀█████████▀  ███▌ ▀█████████▀  ▀▀███▀▀▀       ▄███▀   ▀\n"
	@printf "  ███        ███    ███          ███    █▄  ▄███▀\n"
	@printf "  ███        ███    ███          ███    ███ ███▄     ▄█\n"
	@printf " ▄████▀      █▀    ▄████▀        ██████████  ▀████████▀\n"
	@printf "                                                                \n"
	@printf "$(reset)"
endef

# **************************************************************************** #

# **************************************************************************** #
# config
CFLAGS			:= -Wall -Wextra -g #-Werror
NAME			:= pipex
RM				:= rm -rf
CC				:= gcc
PADDING			:= 10

# SRC
SRC_DIR			:= src
SRC				:= $(wildcard $(SRC_DIR)/*.c)

SRC				:= $(sort $(SRC))

# OBJ
OBJ_DIR			:= obj
OBJ				:= $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SRC:%.c=%.o))

# LIB DIR
LIB_DIR			:= lib
CFLAGS			+= -I$(LIB_DIR)

# **************************************************************************** #

# **************************************************************************** #
# Building rules

all:			setup $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@printf "  $(font_color)[$(green)+$(font_color)] Creation of $(bold)$<"
	$(eval OBJ_LEN := $(shell printf $^ | wc -c))
	$(eval PAD_LEN := $(shell expr $(PADDING) - $(OBJ_LEN)))
	@printf "%-$(PAD_LEN)s" " "
	@printf "$(blinking)$(font_color)-> $(reset)$(bold)$@ $(reset)"
	@printf "%-30s" " "
	@printf "\r"
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME):		$(OBJ)
	@printf "$(font_color)[$(green)+$(font_color)] Creation of $(bold)$(NAME)$(reset)\n"
	@$(CC) -o $(NAME) $(OBJ)

setup:				call_logo $(OBJ_DIR)

$(OBJ_DIR):
	@printf "$(font_color)[$(green)+$(font_color)] Creation of $(bold)obj dir$(reset)\n"
	@mkdir -p $(OBJ_DIR)

lib:			setup $(OBJ)
	@printf "$(font_color)[$(green)+$(font_color)] Creation of $(bold)pipex.a$(reset)\n"
	ar rcs pipex.a $(OBJ)

clean:
	@printf "$(font_color)[$(red)-$(font_color)] Deleting $(bold)object folder$(reset)\n"
	@$(RM) $(OBJ_DIR)
	@$(RM) $(LIBSHARE)

fclean:				clean
	@printf "$(font_color)[$(red)-$(font_color)] Deleting $(bold)$(NAME)$(reset)\n"
	@$(RM) $(NAME) $(LIBSHARE)

re:					call_logo fclean $(OBJ_DIR) $(NAME)

call_logo:
	$(call print_ascii)

.PHONY:			all clean fclean re setup lib

# **************************************************************************** #
