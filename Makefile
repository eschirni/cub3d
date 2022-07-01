# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/10 15:43:54 by eschirni          #+#    #+#              #
#    Updated: 2022/07/01 13:02:11 by btenzlin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# FLAGS
CFLAGS = -Wall -Wextra -Werror
MLX = -lglfw -L $$HOME/.brew/Cellar/glfw/3.3.7/lib MLX42/libmlx42.a

# COLORS
Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[36m"
X = "\033[0m"

# EXECUTABLE
NAME = ./cub3d

# PATHS
SRC_PATH = ./src/
OBJ_PATH = ./obj/
GNL_PATH = get_next_line/
UTILS_PATH = ./src/utils/
DRAW_PATH = ./src/draw_functions/
MAIN_MENU_PATH = ./src/main_menu/

# SOURCES
SRC =	$(SRC_PATH)main.c $(SRC_PATH)init_map.c \
		$(UTILS_PATH)ft_error.c $(UTILS_PATH)utils.c \
		$(UTILS_PATH)free_exit.c \
		$(SRC_PATH)char_direction.c $(SRC_PATH)hooks.c \
		$(SRC_PATH)ray.c \
		$(DRAW_PATH)draw_game.c $(DRAW_PATH)draw_crosshair.c \
		$(DRAW_PATH)draw_map.c $(DRAW_PATH)draw.c \
		$(DRAW_PATH)draw_chars.c \
		$(GNL_PATH)get_next_line.c $(GNL_PATH)get_next_line_utils.c \
		$(MAIN_MENU_PATH)main_menu.c $(MAIN_MENU_PATH)hooks.c \
		$(MAIN_MENU_PATH)settings.c $(SRC_PATH)generate_map.c \

# OBJECTS
OBJ = $(patsubst $(SRC_PATH)%.c, $(OBJ_PATH)%.o, $(SRC))

# RULES
all: $(NAME)
	@echo $(B)
	@echo "                       _|         _|_|_|     _|_|_|  "
	@echo "   _|_|_|   _|    _|   _|_|_|           _|   _|    _|"
	@echo " _|         _|    _|   _|    _|     _|_|     _|    _|"
	@echo " _|         _|    _|   _|    _|         _|   _|    _|"
	@echo "   _|_|_|     _|_|_|   _|_|_|     _|_|_|     _|_|_|  "
	@echo $(X)

$(OBJ_PATH)%.o :$(SRC_PATH)%.c
	@echo $(Y)Compiling [$@]...$(X)
	@mkdir -p $(dir $@)
	@gcc $(CFLAGS) -c -o $@ $<
	@echo $(G)Finished [$@]$(X)

$(NAME): $(OBJ)
	@echo $(Y)Compiling [$(SRC)]
	@echo into [$(NAME)]...$(X)
	@gcc $(CFLAGS) $(MLX) $(OBJ) -o $(NAME)
	@echo $(G)Finished [$(NAME)]$(X)

clean:
	@if [ -d "$(OBJ_PATH)" ]; then \
			rm -f -r $(OBJ_PATH); \
			echo $(R)Cleaning" "[$(OBJ) $(OBJ_PATH)]...$(X); else \
			echo "No objects to remove."; \
	fi;

fclean: clean
	@if [ -f "$(NAME)" ]; then \
			rm -f $(NAME); \
			echo $(R)Cleaning" "[$(NAME)]...$(X);else \
			echo "No executable to remove."; \
	fi;

re: fclean all

# ADDITIONAL RULES

norm:
	@echo $(G)Checking Norminette...$(X)
	@norminette src/* get_next_line/* | grep Error | egrep --color '.*Error!|$$' || true
	@echo $(G)Done$(X)

.PHONY: all, clean, fclean, re, norm
