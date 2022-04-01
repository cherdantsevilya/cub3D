# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pkari <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/01 18:43:57 by pkari             #+#    #+#              #
#    Updated: 2022/04/01 18:44:00 by pkari            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= cub3D

SRC_DIR			= srcs
OBJ_DIR			= objs

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -g
FRAME			= -framework AppKit -framework OpenGL

LIB				= libft/libft.a
MLX				= mlx/libmlx.a

HDR				= includes/cub3D.h
INCFLAGS		= -I./includes -I./libft -I./mlx

SRC				=	srcs/main.c \
					srcs/init.c \
					srcs/pars.c \
					srcs/pars_check_NSWE.c \
					srcs/pars_check_FC.c \
					srcs/pars_map.c \
					srcs/draw.c \
					srcs/draw_raycasting.c \
					srcs/textures.c \
					srcs/hook.c \
					srcs/utils.c \
					gnl/get_next_line.c \
					gnl/get_next_line_utils.c

OBJ				= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

all				: $(NAME)

$(NAME)			: $(OBJ)
				make -C mlx/
				make -C libft/
				$(CC) $(CFLAGS) $(OBJ) $(MLX) $(LIB) $(INCFLAGS) $(FRAME) -o $(NAME)

$(OBJ_DIR)/%.o	: $(SRC_DIR)/%.c $(HDR)
				mkdir -p $(OBJ_DIR)
				$(CC) $(CFLAGS) -c $< -o $@

clean			:
				make -C mlx/ clean
				make -C libft/ clean
				rm -rf $(OBJ_DIR)

fclean			: clean
				make -C mlx/ fclean
				make -C libft/ fclean
				rm -f $(NAME)

re				: fclean all

.PHONY			: all clean fclean re
