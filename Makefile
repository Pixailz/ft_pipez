# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/23 01:36:34 by brda-sil          #+#    #+#              #
#    Updated: 2022/04/23 20:03:35 by brda-sil         ###   ########.fr        #
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
CFLAGS			:= -Wall -Wextra -Werror -O3
NAME			:= pipex
RM				:= rm -rf
CC				:= gcc
PADDING			:= 25
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

all:			call_logo create_dir $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c

	@printf "$(font_color)[$(green)+$(font_color)] Creation of $(bold)$<"
	@printf "%0.s " $(shell seq 1 $(shell dc -e "$(PADDING) $(shell printf "$<" | wc -c) - p"))
	@printf "$(blinking)$(font_color)-> $(reset)$(bold)$@ $(reset)\n"
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME):		$(OBJ)
	@printf "$(font_color)[$(green)+$(font_color)] Creation of $(bold)$(NAME)$(reset)\n"
	@$(CC) -o $(NAME) $(OBJ)


so: 			$(OBJ_ASM)
	$(CC) -c -fPIC $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o $(LIBSHARE) $(OBJ) $(OBJ_ASM)

clean:
	@printf "$(font_color)[$(red)-$(font_color)] Deleting $(bold)object folder$(reset)\n"
	@$(RM) $(OBJ_DIR)
	@$(RM) $(LIBSHARE)

fclean:			clean
	@printf "$(font_color)[$(red)-$(font_color)] Deleting $(bold)$(NAME)$(reset)\n"
	@$(RM) $(NAME) $(LIBSHARE)

re:				call_logo fclean create_dir $(NAME)

call_logo:
	$(call print_ascii)

create_dir:
	@if [ ! -d ./obj ];\
	then printf "$(font_color)[$(green)+$(font_color)] Creation of $(bold)obj dir$(reset)\n";\
	mkdir -p $(OBJ_DIR);\
	printf "$(reset)";\
	fi

.PHONY:			all clean fclean re

# **************************************************************************** #
