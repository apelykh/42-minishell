#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apelykh <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/29 16:29:12 by apelykh           #+#    #+#              #
#    Updated: 2017/06/29 16:29:13 by apelykh          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

FLAGS = -g -Wall -Werror -Wextra
CC = gcc $(FLAGS)
NAME = minishell
LIB_DIR = libft/
LIB = $(addprefix $(LIB_DIR), libft.a)
SRC_DIR = src/
SRC_FILES = env_utils.c \
			dir_utils.c \
			exec_utils.c \
			echo_utils.c \
			process_args.c \
			parse_input.c \
			get_line.c \
			signals.c \
			main.c \

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(SRC:.c=.o)
INCLUDE_DIR = includes

LOG_CLEAR		= \033[2K
LOG_UP 			= \033[A
LOG_NOCOLOR		= \033[0m
LOG_BLACK		= \033[1;30m
LOG_RED			= \033[1;31m
LOG_GREEN		= \033[1;32m
LOG_YELLOW		= \033[1;33m
LOG_BLUE		= \033[1;34m
LOG_VIOLET		= \033[1;35m
LOG_CYAN		= \033[1;36m
LOG_WHITE		= \033[1;37m

.PHONY: all

all: $(NAME)
	
makelib:
	@ make -C $(LIB_DIR)

libclean:
	@ make -C $(LIB_DIR) clean

libfclean:
	@ make -C $(LIB_DIR) fclean

$(NAME): $(OBJ) makelib
	@ $(CC) $(OBJ) -L$(LIB_DIR) -lft -o $@
	@ echo "[+] $(LOG_YELLOW)[$(NAME)]$(LOG_NOCOLOR) compiled"

.c.o: $(SRC)
	@ $(CC) -I $(LIB_DIR)/includes -I includes -c $^ -o $@

clean: libclean
	@ /bin/rm -f $(OBJ)
	@ echo "[+] $(LOG_YELLOW)[$(NAME)]$(LOG_NOCOLOR) .o files deleted"

fclean: clean
	@ /bin/rm -f $(NAME)
	@ echo "[+] $(LOG_YELLOW)[$(NAME)]$(LOG_NOCOLOR) binary file deleted"

re: fclean all