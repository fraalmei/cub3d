# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: p <p@student.42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/15 09:09:48 by cagonzal          #+#    #+#              #
#    Updated: 2024/06/12 17:29:31 by p                ###   ########.fr        #
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
NAME	= cub3d

#	compilation
CC		= gcc

#	options to force the remove
RM		= /bin/rm -f

#	flags
CFLAGS	= -Wall -Werror -Wextra

LEAK_FLAGS	= -fsanitize=address -g3

MLX_DIR1		= minilibx/minilibx_opengl_20191021
MLX_DIR2		= minilibx/minilibx_mms_20200219
#MLX_DIR3		= minilibx/minilibx-linux
MLX_FLAGS	= -L$(MLX_DIR1) -L$(MLX_DIR2) \
				-Imlx_Linux -Lmlx_Linux -lXext -lX11 -lm -lGL #-lglfw 
INCLUDES	= -I$(INCLUDE_DIR) \
				-I$(LIBFT_DIR) \
				-I$(VECTOR_DIR) \
				-I$(MLX_DIR1) \
				-I$(MLX_DIR2) \
				-I/usr/include
LIBS		= -L$(LIBFT_DIR) -lft \
				-L/usr/lib \
				-L$(VECTOR_DIR) -lvector

# Directories
BIN_DIR		= bin
SRC_DIR		= srcs
SRCS		= main.c $(PARSE) $(UTILS) #$(WINDOW)
#SRCS		= main.c $(ENGINE) $(UTILS)
ENGINE		= engine/engine.c engine/end_program.c engine/map_generator.c
PARSE		= parse/scene/check_scene.c parse/elements/check_element.c \
			parse/elements/check_image.c parse/elements/check_textures.c
			

UTILS		= utils/free.c utils/file_utils.c utils/utils.c #utils/global_data.c

#WINDOW		= window/window.c

INCLUDE_DIR	= include			# path to headers
ASSETS_DIR	= assets			# path to assets

VECTOR		= vector
VECTOR_DIR	= vector
VECTOR_RULE	= vector/vector.a
VECTOR_LIB	= $(VECTOR_DIR)/$(VECTOR).a

LIBFT_DIR 	= libft
LIBFT_RULE	= libft/libft.a

# Convert source files to binary
OBJS = $(SRCS:%.c=$(BIN_DIR)/%.o)

all: $(NAME)

$(NAME): $(BIN) $(OBJS) | libs
	@echo "\033[0;32mCompiling cub3D..."
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(MLX_FLAGS) -o $(NAME)
	@echo "\n\033[0mDone !"

#	Objects construction
$(OBJS): $(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@printf "\033[0;33mGenerating cub3D objects... %-33.33s\r" $@
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(VECTOR_RULE):
	echo make $(VECTOR_RULE)
	@make -C $(VECTOR_DIR)
	$(info CREATED $@)

$(MLX_RULE):
	echo make $(MLX_RULE)
	@make -C $(MLX_DIR1)
	@make -C $(MLX_DIR2)
	$(info CREATED $@)

$(LIBFT_RULE):
	echo make $(LIBFT_RULE)
	@make -C $(LIBFT_DIR)
	$(info CREATED $@)


#	Libraries compile
libs: $(LIBFT_RULE) $(VECTOR_RULE) $(MLX_RULE)

re: fclean all

leaks: $(BIN) $(OBJS) | libs
	@echo "\033[0;32mCompiling cub3D..."
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(MLX_FLAGS) $(MLX_FLAGS) -o $(NAME)
	@echo "\n\033[0mDone !"

cbuild:
	$(RM) -r $(BIN_DIR)

clean:
	@echo "\033[0;31mCleaning mlx..."
	@make clean -C $(MLX_DIR1)
	@make clean -C $(MLX_DIR2)
	@echo "\033[0;31mCleaning libft..."
	make clean -C $(LIBFT_DIR)
	@echo "\033[0;31mCleaning vectorlib..."
	make clean -C $(VECTOR_DIR)
	@echo "\nRemoving binaries..."
	@$(RM) $(OBJS)
	@$(RM) -r $(BIN_DIR)
	@echo "\033[0m"

fclean: clean
	@echo "\033[0;31mFcleaning libft..."
	@make fclean -C $(LIBFT_DIR)
	@echo "\033[0;31mFcleaning vectorlib..."
	@make fclean -C $(VECTOR_DIR)
	@echo "\nDeleting executable..."
	@$(RM) $(NAME)
	@echo "\033[0m"


show:
	@printf "NAME		: $(NAME)\n"
	@printf "CC  		: $(CC)\n"
	@printf "CFLAGS		: $(CFLAGS)\n"
	@printf "MLX_FLAGS	: $(MLX_FLAGS)\n"
	@printf "SRCS		: $(SRCS)\n"
	@printf "OBJS		: $(OBJS)\n"
	
.PHONY: $(LIBFT) all clean fclean re
