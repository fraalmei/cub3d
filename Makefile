# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/15 09:09:48 by cagonzal          #+#    #+#              #
#    Updated: 2024/03/15 10:25:29 by cagonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##Colors #
RED		= @echo "\033[0;31m"
GREEN	= @echo "\033[0;32m"
BLUE	= @echo "\033[0;33m"
PURPLE	= @echo "\033[0;34m"
CYAN	= @echo "\033[0;35m"
RESET	= "\033[1;0m"

#	file's name
NAME	= so_long

#	compilation
CC		= gcc

#	options to force the remove
RM		= /bin/rm -f

#	flags
CFLAGS	= #-Wall -Werror -Wextra

LEAK_FLAGS	= -fsanitize=address -g3

#	Compile a mlx for linux or mac
UNAME = $(shell uname -s)
ifeq ($(UNAME), Linux)
#	MLX_DIR		= minilibx/minilibx-linux
	MLX_DIR		= minilibx/mlx_Linux
	MLX_FLAGS	= -Imlx_Linux -Lmlx_Linux -lmlx_Linux -lXext -lX11 -lm -lz
	INCLUDES	= -I$(INCLUDE_DIR) \
				  -I$(LIBFT_DIR) \
				  -I$(MLX_DIR) \
				  -I/usr/include
	LIBS		= -L$(LIBFT_DIR) -lft \
				  -L/usr/lib
endif

ifeq ($(UNAME), Darwin)
#	MLX_DIR		= minilibx/minilibx_opengl_20191021
#	MLX_DIR		= minilibx/minilibx_mms_20200219
	MLX_DIR		= mlx
	MLX_FLAGS	= -L$(MLX_DIR) -lmlx \
				  -framework OpenGL \
				  -framework AppKit \
				  -lm
	INCLUDES	= -I$(INCLUDE_DIR) \
				  -I$(LIBFT_DIR) \
				  -I$(MLX_DIR)
	LIBS		= -L$(LIBFT_DIR) -lft
endif

# Directories
BIN_DIR		= bin
SRC_DIR		= srcs
LIBFT_DIR 	= libft				# path to libft library
INCLUDE_DIR	= include			# path to headers
ASSETS_DIR	= assets			# path to assets

VECTOR2 = matrix2_utils.c vector2_utils.c vector2_utils2.c
VECTOR3 = matrix3_utils.c vector3_utils.c vector3_utils2.c
VECTOR4 = matrix_utils.c vector_utils.c vector_utils2.c

SRC_VECTOR2 = $(addprefix vector2/, $(VECTOR2))
SRC_VECTOR3 = $(addprefix vector3/, $(VECTOR3))
SRC_VECTOR4 = $(addprefix vector4/, $(VECTOR4))

SRC_VECTOR =	$(addprefix vector/, $(SRC_VECTOR2)) \
				$(addprefix vector/, $(SRC_VECTOR3)) \
				$(addprefix vector/, $(SRC_VECTOR4))

MAIN_SRC = main.c
 
SRC = $(MAIN_SRC) $(SRC_VECTOR)


# Convert source files to binary
OBJ = $(SRC:%.c=$(BIN_DIR)/%.o)

all: $(NAME)

$(NAME): $(BIN) $(OBJS) | libs
	@echo "\033[0;32mCompiling so_long..."
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(MLX_FLAGS) -o $(NAME)
	@echo "\n\033[0mDone !"

#	Objects construction
$(OBJS): $(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@printf "\033[0;33mGenerating so_long objects... %-33.33s\r" $@
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

#	Libraries compile
libs:
#	make -C $(LIBFT_DIR)
	make -C $(MLX_DIR)

re: fclean all

leaks: $(OBJS)
	$(CC) $(CFLAGS) $(LEAK_FLAGS) $(OBJS) $(INCLUDES) $(LIBS) $(MLX_FLAGS) -o $(NAME)

cbuild:
	$(RM) -r $(BIN_DIR)

clean:
	@echo "\033[0;31mCleaning libft..."
	make clean -C $(LIBFT_DIR)
	@echo "\033[0;31mCleaning mlx..."
	make clean -C $(MLX_DIR)
	@echo "\nRemoving binaries..."
	@$(RM) $(OBJS)
	@$(RM) -r $(BIN_DIR)
	@echo "\033[0m"

fclean: clean
	@echo "\033[0;31mFcleaning libft..."
	@make fclean -C $(LIBFT_DIR)
	@echo "\033[0;31mFcleaning mlx..."
	@make fclean -C $(MLX_DIR)
	@echo "\nDeleting executable..."
	@$(RM) $(NAME)
	@echo "\033[0m"


show:
	@printf "UNAME		: $(UNAME)\n"
	@printf "NAME		: $(NAME)\n"
	@printf "CC  		: $(CC)\n"
	@printf "CFLAGS		: $(CFLAGS)\n"
	@printf "MLX_FLAGS	: $(MLX_FLAGS)\n"
	@printf "SRCS		: $(SRC)\n"
	@printf "OBJS		: $(OBJS)\n"

.PHONY: $(LIBFT) all clean fclean re