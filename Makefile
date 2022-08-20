# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/23 01:36:34 by brda-sil          #+#    #+#              #
#    Updated: 2022/08/21 00:49:35 by brda-sil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# config
CFLAGS			:= -Wall -Wextra
TARGET			:= pipex
RM				:= rm -rf
CC				:= gcc
MAKE			:= make -C
VERSION			:= 1.2.3
$(eval export MAIN=1)

ifneq ($(PADDING),30)
PADDING			:= 30
endif

ifeq ($(DEBUG),)
CFLAGS			+= -Werror
else
CFLAGS			+= -g3
endif

# DIR
BIN_DIR			:= bin
SRC_DIR			:= src
LIB_DIR			:= lib
OBJ_DIR			:= obj
INC_DIR			:= -Iincludes

TARGET			:= $(addprefix $(BIN_DIR)/,$(TARGET))

# SRC
SRC_C			:= src/ft_strchr.c \
				   src/ft_memchr.c \
				   src/ft_puthex.c \
				   src/ft_parse.c \
				   src/ft_strcpy.c \
				   src/ft_checkparams.c \
				   src/get_next_line.c \
				   src/ft_memjoin.c \
				   src/pipex_init.c \
				   src/ft_putstr.c \
				   src/ft_get_words.c \
				   src/ft_calloc.c \
				   src/ft_strcspn.c \
				   src/ft_strspn.c \
				   src/ft_put_addr.c \
				   src/ft_strdup.c \
				   src/pipex_cmd.c \
				   src/ft_sel_params.c \
				   src/pipex.c \
				   src/pipex_free.c \
				   src/ft_strlen.c \
				   src/ft_error.c \
				   src/ft_memset.c \
				   src/ft_strtok.c \
				   src/pipex_child.c \
				   src/ft_putnbr_u.c \
				   src/ft_printf.c \
				   src/ft_putnbr.c \
				   src/ft_strjoin.c \
				   src/ft_strncmp.c \
				   src/ft_split.c \
				   src/ft_putchar.c \
				   src/ft_strcat.c

# OBJ
OBJ_C			:= $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SRC_C:%.c=%.o))

# LIB DIR
CFLAGS			+= $(INC_DIR)

#  Bash Color / unicode char

#get_random		= $(shell seq 0 256 | shuf | head -n1)
green			:= \033[38;5;82m
blue			:= \033[38;5;75m
red				:= \033[38;5;196m
orange			:= \033[38;5;214m

blinking		:= \033[5m
reset			:= \033[0m

font_color		:= $(blue)
bold			:= $(green)
ascii_color		:= $(bold)

green_plus		:= $(font_color)[$(green)+$(font_color)]
red_minus		:= $(font_color)[$(red)-$(font_color)]
orange_star		:= $(font_color)[$(orange)*$(font_color)]
blinking_arrow	:= $(blinking)$(font_color)->
#font_color		:= \033[38;5;$(get_random)m
#bold			:= \033[38;5;$(get_random)m
#ascii_color		:= \033[38;5;$(get_random)m

UL="\xe2\x95\x94"
HO="\xe2\x95\x90"
UR="\xe2\x95\x97"
VE="\xe2\x95\x91"
LL="\xe2\x95\x9a"
LR="\xe2\x95\x9d"

# **************************************************************************** #

# **************************************************************************** #
# utils

define ascii_art
██████╗ ██╗██████╗ ███████╗███████╗
██╔══██╗██║██╔══██╗██╔════╝╚══███╔╝
██████╔╝██║██████╔╝█████╗    ███╔╝
██╔═══╝ ██║██╔═══╝ ██╔══╝   ███╔╝
██║     ██║██║     ███████╗███████╗
╚═╝     ╚═╝╚═╝     ╚══════╝╚══════╝
$(reset)
endef
export ascii_art

define print_padded
	@printf '   $(orange_star) $(font_color)Creation of $(bold)$1'
	$(eval OBJ_LEN := $(shell printf $1 | wc -c))
	$(eval PAD_LEN := $(shell expr $(PADDING) - $(OBJ_LEN)))
	@printf '%-$(PAD_LEN)s' ' '
	@printf '$(blinking_arrow) $(reset)$(bold)$2 $(reset)'
	@printf '\n'
endef

define usage
$(orange_star) $(bold)INFO$(font_color):

    ./$(TARGET) <$(bold)infile$(font_color)> <$(bold)cmd1$(font_color)> $(font_color)<$(bold)cmd2$(font_color)> \
$(font_color)<$(bold)outfile$(font_color)>
        $(bold)cmd$(font_color): should have $(bold)2$(font_color) command.
        $(bold)infile$(font_color): the infile.
        $(bold)outfile$(font_color): the outfile.

$(font_color)Version: $(bold)$(VERSION)$(reset)

endef
export usage
# **************************************************************************** #

# **************************************************************************** #
# Rules

all:			setup $(TARGET)
	@printf "$$usage"

$(OBJ_DIR)/%.o: 		$(SRC_DIR)/%.c
	$(call print_padded,$^,$@)
	@$(CC) $(CFLAGS) -o $@ -c $<

$(TARGET):				$(OBJ_C)
	@printf "$(green_plus) $(font_color)Creation of $(bold)$@$(reset)\n"
	@$(CC) $(CFLAGS) -o $@ $(OBJ_C)

setup:					call_logo $(OBJ_DIR) $(BIN_DIR)

call_logo:
	@printf "$(ascii_color)$$ascii_art"

print_usage:
	@printf "$$usage"

$(OBJ_DIR):
	@printf "$(green_plus) $(font_color)Creation of $(bold)$(OBJ_DIR)$(reset)\n"
	@mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	@printf "$(green_plus) $(font_color)Creation of $(bold)$(BIN_DIR)$(reset)\n"
	@mkdir -p $(BIN_DIR)

clean:
	@printf "$(red_minus) $(font_color)Deleting $(bold)$(OBJ_DIR)$(reset)\n"
	@$(RM) $(OBJ_DIR)

fclean:					clean
	@printf "$(red_minus) $(font_color)Deleting $(bold)$(TARGET)$(reset)\n"
	@$(RM) $(TARGET)
	@printf "$(red_minus) $(font_color)Deleting $(bold)$(BIN_DIR)$(reset)\n"
	@$(RM) -rf $(BIN_DIR)

re:						fclean all

.PHONY:					all clean fclean re setup lib call_logo

# **************************************************************************** #
