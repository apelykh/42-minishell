#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apelykh <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/24 16:56:54 by apelykh           #+#    #+#              #
#    Updated: 2016/11/24 16:56:54 by apelykh          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a
FLAGS = -Wall -Werror -Wextra
CC = gcc $(FLAGS)
INCLUDE_DIR = includes/
SRC_DIR = src/
SRC_MEMORY_DIR = $(addprefix $(SRC_DIR), memory/)
SRC_STRINGS_DIR = $(addprefix $(SRC_DIR), strings/)
SRC_TRANSFORM_DIR = $(addprefix $(SRC_DIR), transform/)
SRC_CONTAINERS_DIR = $(addprefix $(SRC_DIR), containers/)
SRC_CONTAINERS_ARR_DIR = $(addprefix $(SRC_CONTAINERS_DIR), array/)
SRC_CONTAINERS_LIST_DIR = $(addprefix $(SRC_CONTAINERS_DIR), list/)

SRC_MEMORY =			ft_memset.c ft_memcpy.c ft_memccpy.c \
						ft_memmove.c ft_memchr.c ft_memcmp.c \
						ft_memalloc.c ft_memdel.c ft_memcalloc.c \

SRC_STRINGS =			ft_strlen.c ft_strdup.c ft_strcpy.c \
						ft_strncpy.c ft_strcat.c ft_strncat.c \
						ft_strlcat.c ft_strchr.c ft_strrchr.c \
						ft_strstr.c ft_strnstr.c ft_strcmp.c \
						ft_strncmp.c ft_strnew.c ft_strdel.c \
						ft_strclr.c ft_striter.c ft_striteri.c \
						ft_strmap.c ft_strmapi.c ft_strequ.c \
						ft_strnequ.c ft_strsub.c ft_strjoin.c \
						ft_strtrim.c ft_strsplit.c ft_strsafenjoin.c \
						ft_strjoindelim.c ft_strsplitspaceswithquotes.c \
						ft_strncpywoutquotes.c ft_strndup.c ft_strreplfirst.c \
						ft_strnjoin.c \

SRC_TRANSFORM =			ft_atoi.c ft_itoa.c \

SRC_CONTAINERS_LIST = 	ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
				  		ft_lstadd.c ft_lstiter.c ft_lstmap.c \
				  		ft_lstaddback.c ft_lstlen.c \

SRC_CONTAINERS_ARR =	ft_arrlen.c ft_arrprint.c ft_arrnew.c \
						ft_arrcpy.c ft_arrcpyextra.c ft_arrcpyexcept.c \
						ft_arrfree.c \

SRC_GENERAL =			ft_pow.c ft_bzero.c ft_putchar.c \
						ft_putstr.c ft_putendl.c ft_putnbr.c \
						ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
						ft_putnbr_fd.c ft_isalpha.c ft_isdigit.c \
						ft_isalnum.c ft_isascii.c ft_isprint.c \
						ft_toupper.c ft_tolower.c ft_isspace.c \
						get_next_line.c ft_abs.c \

SRC = $(addprefix $(SRC_DIR), $(SRC_GENERAL)) \
	  $(addprefix $(SRC_MEMORY_DIR), $(SRC_MEMORY)) \
	  $(addprefix $(SRC_STRINGS_DIR), $(SRC_STRINGS)) \
	  $(addprefix $(SRC_TRANSFORM_DIR), $(SRC_TRANSFORM)) \
	  $(addprefix $(SRC_CONTAINERS_ARR_DIR), $(SRC_CONTAINERS_ARR)) \
	  $(addprefix $(SRC_CONTAINERS_LIST_DIR), $(SRC_CONTAINERS_LIST))
OBJ = $(SRC:.c=.o)

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

.PHONY: all clean fclean re

all: $(NAME)

.c.o: $(SRC)
	@ $(CC) -I $(INCLUDE_DIR) -c $< -o $@

$(NAME): $(OBJ)
	@ ar rc $(NAME) $(OBJ)
	@ ranlib $(NAME)
	@ echo "[+] $(LOG_VIOLET)[$(NAME)]$(LOG_NOCOLOR) compiled"

clean:
	@ /bin/rm -f $(OBJ)
	@ echo "[+] $(LOG_VIOLET)[$(NAME)]$(LOG_NOCOLOR) .o files deleted"

fclean: clean
	@ /bin/rm -f $(NAME)
	@ echo "[+] $(LOG_VIOLET)[$(NAME)]$(LOG_NOCOLOR) binary file deleted"

re: fclean all
