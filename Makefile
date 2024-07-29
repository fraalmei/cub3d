# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/15 09:09:48 by cagonzal          #+#    #+#              #
#    Updated: 2024/07/29 16:29:32 by fraalmei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##Colors #
#RED		= @echo "\033[0;31m"
#GREEN	= @echo "\033[0;32m"
#BLUE	= @echo "\033[0;33m"
#PURPLE	= @echo "\033[0;34m"
#CYAN	= @echo "\033[0;35m"

RESET		= 	@echo '\033[1;0m'
NC			=	@echo '\033[0m'
TITLE		=	@echo '\033[38;5;33m'
DEFAULT		=	@echo '\033[0;39m'
GRAY		=	@echo '\033[2;37m'
RED			=	@echo '\033[0;91m'
GREEN		=	@echo '\033[32m'
YELLOW		=	@echo '\033[33m'
BLUE		=	@echo '\033[0;94m'
LRED		=	@echo '\033[1;31m'
LGREEN		=	@echo '\033[1;32m'
LBLUE		=	@echo '\033[1;34m'
MAGENTA		=	@echo '\033[0;95m'
CYAN		=	@echo '\033[0;96m'
WHITE		=	@echo '\033[0;97m'
CURSIVE		=	@echo '\033[3m'

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
#MLX_DIR		= minilibx/minilibx-linux
MLX_DIR		= minilibx/mlx_Linux
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
SRCS		= main.c $(PARSE) $(UTILS) $(STRUCTS) #$(ENGINE)

ENGINE		= engine/src/color.c engine/src/end_program.c engine/src/engine.c engine/src/misc_functions.c \
			engine/src/player_data.c engine/src/ray_utils.c engine/src/ray.c engine/src/screen_frame.c \
			engine/keys.c

PARSE		= parse/check_scene.c parse/check_element.c \
			parse/check_image.c parse/check_map.c parse/check_player.c

STRUCTS		= structs/global_data.c structs/textures.c structs/player.c structs/map.c

UTILS		= utils/set_utils.c utils/file_utils.c utils/free.c utils/array_utils.c \
			utils/print_things.c utils/read_utils.c utils/matrix_utils.c


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
	make -C $(MLX_DIR)
	$(info CREATED $@)

$(VECTOR_RULE):
	echo make $(VECTOR_RULE)
	make -C $(VECTOR_DIR)
	$(info CREATED $@)

$(LIBFT_RULE):
	echo make $(LIBFT_RULE)
	make -C $(LIBFT_DIR)
	$(info CREATED $@)


#	Libraries compile
libs: $(LIBFT_RULE) $(MLX_RULE) $(VECTOR_RULE)

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
