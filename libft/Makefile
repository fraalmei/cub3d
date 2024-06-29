# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 13:30:04 by cagonzal          #+#    #+#              #
#    Updated: 2024/06/29 19:13:12 by fraalmei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Binaries variables
BIN			=	bin# Bin location
SRC			=	src# Source location
INCLUDE_L	=	include# Include location

# Compiler options
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
INCLUDE		=	-I./$(INCLUDE_L)
COMPILE		=	$(CC) $(FLAGS) $(INCLUDE)
NAME		=	libft.a
HEADER		=	libft.h

# Color
NC			=	'\033[0m'
TITLE		=	'\033[38;5;33m'
DEFAULT		=	'\033[0;39m'
GRAY		=	'\033[2;37m'
RED			=	'\033[0;91m'
GREEN		=	'\033[32m'
YELLOW		=	'\033[33m'
BLUE		=	'\033[0;94m'
LRED		=	'\033[1;31m'
LGREEN		=	'\033[1;32m'
LBLUE		=	'\033[1;34m'
MAGENTA		=	'\033[0;95m'
CYAN		=	'\033[0;96m'
WHITE		=	'\033[0;97m'
CURSIVE		=	'\033[3m'

#	files
FILE		=	ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putchar_fd.c get_next_line.c

LIST		=	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
				ft_lstduplicate.c ft_lstiter.c ft_lstlast.c ft_lstnew.c ft_lstsize.c

MEM			=	ft_memset.c ft_bzero.c ft_calloc.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
				ft_memcpy.c ft_memmove.c ft_freetable.c

NBR			=	ft_abs.c ft_atoi_base.c ft_atoi.c ft_itoa.c ft_atoll.c

OTHERS		=	ft_arraybi_size.c ft_error.c ft_isalnum.c ft_isalpha.c \
				ft_isascii.c ft_isdigit.c ft_isprint.c ft_printf.c ft_printf_fd.c ft_swap.c

STR			=	ft_split.c ft_strchr.c ft_strcmp.c ft_strcpy.c ft_strdup.c ft_strichr.c \
				ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
				ft_strncmp.c ft_strndup.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_strtrim.c \
				ft_substr.c ft_tolower.c ft_toupper.c ft_chrjoin.c ft_arrayjoin.c

LIBFT_SRC	=	$(FILE:%=file/%) \
				$(LIST:%=list/%) \
				$(MEM:%=mem/%) \
				$(NBR:%=nbr/%) \
				$(OTHERS:%=others/%) \
				$(STR:%=str/%)

SOURCE		=	$(LIBFT_SRC) # Libft files

SRC_CODE	=	$(SOURCE:%=$(SRC)/%)
OBJ			=	$(SRC_CODE:$(SRC)/%.c=$(BIN)/%.o)

#	Execute make
all: $(NAME)

$(NAME): $(OBJ)
	@echo ${TITLE}"Compiling "$(RED)"libft	\c"$(NC)
	@ar -rcs $(NAME) $(OBJ)
	@echo ${LGREEN}"	[OK]\n"$(NC)

$(BIN)/%.o: $(SRC)/%.c
	@mkdir -p ${dir $@}
	@$(COMPILE) -c $< -o $@

# Clean logic
.PHONY: all clean fclean re

re: fclean all

fclean: clean
	@echo ${CURSIVE}${GRAY}"  - Removing $(NAME)..." ${NC}
	@rm -f $(NAME)
	@echo ${CURSIVE}${GRAY}"  - Project Libft clean" ${NC}

clean:
	@echo ${CURSIVE}${GRAY}"  - Removing $(NAME) binaries..." ${NC}
	@rm -rf $(BIN)
