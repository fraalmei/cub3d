# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 13:09:37 by fraalmei          #+#    #+#              #
#    Updated: 2024/03/16 18:53:31 by cagonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#comments

VECTOR2 = matrix2_utils.c vector2_utils.c vector2_utils2.c
VECTOR3 = matrix3_utils.c vector3_utils.c vector3_utils2.c
VECTOR4 = matrix4_utils.c vector4_utils.c vector4_utils2.c

SRC_VECTOR2 = $(addprefix vector2/, $(VECTOR2))
SRC_VECTOR3 = $(addprefix vector3/, $(VECTOR3))
SRC_VECTOR4 = $(addprefix vector4/, $(VECTOR4))

SRC_VECTOR =	$(addprefix vector/, $(SRC_VECTOR2)) \
				$(addprefix vector/, $(SRC_VECTOR3)) \
				$(addprefix vector/, $(SRC_VECTOR4))


BIN_DIR		= bin

SRCS		= $(SRC_VECTOR)

OBJS		= $(SRCS:%.c=$(BIN_DIR)/%.o)

#	file's name
NAME = libft.a

#	flags
FLAGS = -Wall -Werror -Wextra #-fsanitize=address

MAIN = main

#	options to create the library
AR = ar -rc

#	options to force the remove
RM = rm -f

#	compilation
CC = gcc

all: $(NAME)

#	execute make
#$(NAME): $(MANDATORY_OBJS) $(OBJS_BONUS) $(OBJS_EXTRA)
$(NAME): $(OBJS)
		@$(AR) $@ $?

#%.o: %.c
#	@$(CC) $(FLAGS) -c $< -o $@
#	@$(COMPILE.c) -c $< -o $@

$(OBJS): $(BIN_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@$(RM) -r $(BIN_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
