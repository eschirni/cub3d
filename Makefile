# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/10 15:43:54 by eschirni          #+#    #+#              #
#    Updated: 2022/07/28 10:14:01 by eschirni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# FLAGS
CFLAGS = -Wall -Wextra -Werror -fsanitize=address		
MLX = -lglfw -L $$HOME/.brew/Cellar/glfw/3.3.7/lib MLX42/libmlx42.a

# COLORS
Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[36m"
X = "\033[0m"

# EXECUTABLE
NAME = ./cub3D

# PATHS
SRC_PATH = ./src/
OBJ_PATH = ./obj/
GNL_PATH = get_next_line/
UTILS_PATH = ./src/utils/
DRAW_PATH = ./src/draw_functions/
PARSE_PATH = ./src/parser/

# SOURCES
SRC =	$(SRC_PATH)main.c $(SRC_PATH)init_map.c \
		$(SRC_PATH)char_direction.c $(SRC_PATH)hooks.c \
		$(SRC_PATH)ray.c $(SRC_PATH)init_textures.c \
		$(UTILS_PATH)ft_error.c $(UTILS_PATH)utils.c \
		$(UTILS_PATH)free_exit.c $(UTILS_PATH)hooks_utils.c \
		$(DRAW_PATH)draw_game.c $(DRAW_PATH)draw_3d.c \
		$(GNL_PATH)get_next_line.c $(GNL_PATH)get_next_line_utils.c \
		$(PARSE_PATH)parser.c $(PARSE_PATH)split.c \
		$(PARSE_PATH)parse_utils.c $(PARSE_PATH)get_config.c \

# OBJECTS
OBJ = $(patsubst $(SRC_PATH)%.c, $(OBJ_PATH)%.o, $(SRC))

# RULES
all: $(NAME)
	@echo $(B)
	@echo "███████╗██╗   ██╗ ██████╗██╗  ██╗███████╗"
	@echo "██╔════╝██║   ██║██╔════╝██║ ██╔╝██╔════╝"
	@echo "███████╗██║   ██║██║     █████╔╝ ███████╗"
	@echo "╚════██║██║   ██║██║     ██╔═██╗ ╚════██║"
	@echo "███████║╚██████╔╝╚██████╗██║  ██╗███████║"
	@echo "╚══════╝ ╚═════╝  ╚═════╝╚═╝  ╚═╝╚══════╝"
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
