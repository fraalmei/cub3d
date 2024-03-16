# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 13:09:37 by fraalmei          #+#    #+#              #
#    Updated: 2024/03/16 19:56:58 by cagonzal         ###   ########.fr        #
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
NAME		=	vector.a
HEADER		=	vector.h


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

VECTOR2 = matrix2_utils.c vector2_utils.c vector2_utils2.c
VECTOR3 = matrix3_utils.c vector3_utils.c vector3_utils2.c
VECTOR4 = matrix4_utils.c vector4_utils.c vector4_utils2.c

SRC_VECTOR2 = $(VECTOR2)
SRC_VECTOR3 = $(VECTOR3)
SRC_VECTOR4 = $(VECTOR4)

VEC_SRC =	$(VECTOR2:%=vector2/%) \
			$(VECTOR3:%=vector3/%) \
			$(VECTOR4:%=vector4/%)

SOURCE		=	$(VEC_SRC)

SRC_CODE	=	$(SOURCE:%=$(SRC)/%)
OBJ			=	$(VEC_SRC:%.c=$(BIN)/%.o)

#	Execute make
all: $(NAME)

$(NAME): $(OBJ)
	@echo ${TITLE}"Compiling "$(RED)"Vector lib	\c"$(NC)
	@ar -rcs $(NAME) $(OBJ)
	@echo ${LGREEN}"	[OK]\n"$(NC)

$(BIN)/%.o: $(SRC)/%.c
	@mkdir -p ${dir $@}
	@$(COMPILE) -c $< -o $@

# Clean logic
.PHONY: re fclean

re: fclean all

fclean: clean
	@echo ${CURSIVE}${GRAY}"  - Removing $(NAME)..." ${NC}
	@rm -f $(NAME)
	@echo ${CURSIVE}${GRAY}"  - Vector lib cleaned" ${NC}

clean:
	@echo ${CURSIVE}${GRAY}"  - Removing $(NAME) binaries..." ${NC}
	@rm -rf $(BIN)
