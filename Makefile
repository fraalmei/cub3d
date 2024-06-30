# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/15 09:09:48 by cagonzal          #+#    #+#              #
#    Updated: 2024/06/30 09:42:15 by fraalmei         ###   ########.fr        #
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


#MLX_DIR		= minilibx/minilibx_mms_20200219
#MLX_DIR		= minilibx/minilibx_opengl_20191021
MLX_DIR		= minilibx/minilibx-linux
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lmlx_Linux -lXext -lX11 -lm -lz
INCLUDES	= -I$(INCLUDE_DIR) \
				-I$(LIBFT_DIR) \
				-I$(VECTOR_DIR) \
				-I$(MLX_DIR) \
				-I/usr/include
LIBS		= -L$(LIBFT_DIR) -lft \
				-L$(VECTOR_DIR) -lvector\
				-L/usr/lib


# Directories
BIN_DIR		= bin
SRC_DIR		= srcs
SRCS		= main.c $(ENGINE) $(PARSE) $(UTILS) $(STRUCTS)

ENGINE		= engine/src/color.c engine/src/end_program.c engine/src/engine.c engine/src/misc_functions.c \
			engine/src/player_data.c engine/src/ray_utils.c engine/src/ray.c engine/src/screen_frame.c \
			engine/keys.c

PARSE		= parse/check_scene.c parse/check_element.c \
			parse/check_image.c parse/check_map.c

STRUCTS		= structs/global_data.c structs/textures.c

UTILS		= utils/set_utils.c utils/file_utils.c utils/free.c utils/node_utils.c \
			utils/print_things.c utils/read_utils.c


INCLUDE_DIR	= include			# path to headers
ASSETS_DIR	= assets			# path to assets

MLX 		= lmlx
MLX_RULE	= $(MLX_DIR)/libmlx.a
MLX_LIB		= $(MLX_DIR)/libmlx.a

LIBFT 		= libft
LIBFT_DIR 	= libft
LIBFT_RULE	= libft/libft.a
LIBFT_LIB	= $(LIBFT_DIR)/$(LIBFT).a

VECTOR		= libvector
VECTOR_DIR	= vector
VECTOR_RULE	= vector/libvector.a
VECTOR_LIB	= $(VECTOR_DIR)/$(VECTOR).a

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

$(MLX_RULE):
	echo make $(MLX_RULE)
	@make -C $(MLX_DIR)
	$(info CREATED $@)

$(VECTOR_RULE):
	echo make $(VECTOR_RULE)
	@make -C $(VECTOR_DIR)
	$(info CREATED $@)

$(LIBFT_RULE):
	echo make $(LIBFT_RULE)
	@make -C $(LIBFT_DIR)
	$(info CREATED $@)


#	Libraries compile
libs: $(LIBFT_RULE) $(VECTOR_RULE) $(MLX_RULE)

re: fclean all

leaks: $(OBJS)
	$(CC) $(CFLAGS) $(LEAK_FLAGS) $(OBJS) $(INCLUDES) $(LIBS) $(MLX_FLAGS) -o $(NAME)

cbuild:
	$(RM) -r $(BIN_DIR)

clean:
	@echo "\033[0;31mCleaning mlx..."
	make clean -C $(MLX_DIR)
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
	@printf "UNAME		: $(UNAME)\n"
	@printf "NAME		: $(NAME)\n"
	@printf "CC  		: $(CC)\n"
	@printf "CFLAGS		: $(CFLAGS)\n"
	@printf "MLX_FLAGS	: $(MLX_FLAGS)\n"
	@printf "SRCS		: $(SRC)\n"
	@printf "OBJS		: $(OBJS)\n"

.PHONY: $(LIBFT) all clean fclean re
