# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: p <p@student.42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/26 10:38:51 by cagonzal          #+#    #+#              #
#    Updated: 2024/08/30 14:01:56 by p                ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##Colors #
#RED		= @echo "\033[0;31m"
#GREEN		= @echo "\033[0;32m"
#BLUE		= @echo "\033[0;33m"
#PURPLE		= @echo "\033[0;34m"
#CYAN		= @echo "\033[0;35m"

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

# Directories
SRC_DIR		= srcs
INCDIR		= include
BIN_DIR		= bin

VECTOR_DIR	= vector

# Libraries
LIBMLX = libs/MLX42
LIBFT = libs/libft
VECTOR = vector
LIB_BREW = /Users/${USER}/.brew/Cellar/glfw/3.4/lib

# Header files
HEADERS	= -I $(INCDIR) -I $(LIBMLX)/include -I $(VECTOR_DIR)

# Library flags
LIBFT_FLAGS = -L$(LIBFT) -lft
LMX_FLAGS = -L$(LIBMLX)/build -L$(LIB_BREW) -lmlx42 -lm -lglfw -lrt -ldl -pthread 
VECTOR_FLAGS = -L$(VECTOR_DIR) -lvector
LIBS_FLAGS = $(LIBFT_FLAGS) $(LMX_FLAGS) $(VECTOR_FLAGS)

# Directories


SRCS		= main.c $(PARSE) $(UTILS) $(STRUCTS) $(ENGINE)
SRCS_BONUS	= main_bonus.c $(PARSE) $(UTILS) $(STRUCTS) $(ENGINE)
SRCS_CHECK	= main_check.c $(PARSE) $(UTILS) $(STRUCTS) $(ENGINE) $(PACO_ENGINE)

PACO_ENGINE	= paco_engine/engine.c

ENGINE		= engine/src/color.c engine/src/engine.c

# ENGINE		= engine/src/color.c engine/src/end_program.c engine/src/engine.c engine/src/misc_functions.c \
# 			engine/src/player_data.c engine/src/ray_utils.c engine/src/ray.c engine/src/screen_frame.c \
# 			engine/keys.c

PARSE		= parse/check_scene.c parse/check_element.c \
			parse/check_image.c parse/check_map.c parse/check_player.c

STRUCTS		= structs/global_data.c structs/textures.c structs/player.c structs/map.c

UTILS		= utils/set_utils.c utils/file_utils.c utils/free.c utils/array_utils.c \
			utils/print_things.c utils/read_utils.c utils/matrix_utils.c


ASSETS_DIR	= assets			# path to assets

# Convert source files to binary
OBJS		= $(SRCS:%.c=$(BIN_DIR)/%.o)
OBJS_CHECK	= $(SRCS_CHECK:%.c=$(BIN_DIR)/%.o)
OBJS_BONUS	= $(SRCS_BONUS:%.c=$(BIN_DIR)/%.o)

all: clone_mlx42 $(NAME)

$(NAME): $(OBJS)
	@echo "\033[0;32mCompiling cub3D..."
	@cmake $(LIBMLX) -B $(LIBMLX)/build
	@make -C $(LIBMLX)/build -j4
	@make -C $(LIBFT)
	@make -C $(VECTOR_DIR)
	$(CC) $(OBJS) $(CFLAGS) $(LIBS_FLAGS) $(HEADERS) -o $(NAME)
	@echo "\n\033[0mDone !"

#	Objects construction
$(OBJS): $(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@printf "\033[0;33mGenerating cub3D objects... %-33.33s\r" $@
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(OBJS_CHECK): $(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@printf "\033[0;33mGenerating cub3D objects... %-33.33s\r" $@
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(OBJS_BONUS): $(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@printf "\033[0;33mGenerating cub3D objects... %-33.33s\r" $@
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

# Clone the external repo if not already cloned
clone_mlx42:
	@if [ ! -d "$(LIBMLX)" ]; then \
		echo "$(COLOR)Cloning MLX42 repository...$(RESET_COLOR)"; \
		git clone https://github.com/codam-coding-college/MLX42.git $(LIBMLX); \
	fi

re: fclean all

recheck: fclean check

rebonus: fclean bonus

check: $(OBJS_CHECK)
	@echo "\033[0;32mCompiling cub3D..."
	@cmake $(LIBMLX) -B $(LIBMLX)/build
	@make -C $(LIBMLX)/build -j4
	@make -C $(LIBFT)
	@make -C $(VECTOR_DIR)
	$(CC) $(OBJS_CHECK) $(CFLAGS) $(LIBS_FLAGS) $(HEADERS) -o $(NAME)
	@echo "\n\033[0mDone !"

bonus: $(OBJS_BONUS)
	@echo "\033[0;32mCompiling cub3D..."
	@cmake $(LIBMLX) -B $(LIBMLX)/build
	@make -C $(LIBMLX)/build -j4
	@make -C $(LIBFT)
	@make -C $(VECTOR_DIR)
	$(CC) $(OBJS_BONUS) $(CFLAGS) $(LIBS_FLAGS) $(HEADERS) -o $(NAME)
	@echo "\n\033[0mDone !"

leaks: $(OBJS)
	@echo "\033[0;32mCompiling cub3D..."
	@cmake $(LIBMLX) -B $(LIBMLX)/build
	@make -C $(LIBMLX)/build -j4
	@make -C $(LIBFT)
	$(CC) $(OBJS) $(CFLAGS) $(LEAK_FLAGS) $(LIBS_FLAGS) $(HEADERS) -o $(NAME)
	@echo "\n\033[0mDone !"

bleaks: $(OBJS_BONUS)
	@echo "\033[0;32mCompiling cub3D..."
	@cmake $(LIBMLX) -B $(LIBMLX)/build
	@make -C $(LIBMLX)/build -j4
	@make -C $(LIBFT)
	$(CC) $(OBJS_BONUS) $(CFLAGS) $(LEAK_FLAGS) $(LIBS_FLAGS) $(HEADERS) -o $(NAME)
	@echo "\n\033[0mDone !"

clean:
	@echo "\033[0;31mCleaning mlx..."
#	@rm -rf $(LIBMLX)/build
	@echo "\033[0;31mCleaning libft..."
	@make -C $(LIBFT) clean
	@echo "\033[0;31mCleaning vectorlib..."
	@make clean -C $(VECTOR_DIR)
	@echo "\nRemoving binaries..."
	@$(RM) $(OBJS)
	@$(RM) $(OBJS_CHECK)
	@$(RM) $(OBJS_BONUS)
	@$(RM) -r $(BIN_DIR)
	@echo "\033[0m"

fclean: clean
	@echo "\033[0;31mFcleaning libft..."
	@make -C $(LIBFT) fclean
	@echo "\033[0;311mFcleaning mlx..."
#	@rm -rf $(LIBMLX)
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
	@printf "MLX_FLAGS	: $(LMX_FLAGS)\n"
	@printf "SRCS		: $(SRCS)\n"
	@printf "OBJS		: $(OBJS)\n"

.PHONY: $(LIBFT) all clean fclean re