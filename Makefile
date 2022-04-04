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
TMP_DIR			= cub3D.dSYM

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -g
FRAME			= -framework AppKit -framework OpenGL

LIB				= libft/libft.a
MLX				= mlx/libmlx.a

HDR				= includes/cub3d.h

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
					srcs/get_next_line.c \
					srcs/get_next_line_utils.c

OBJ				= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

all				: $(NAME)

$(NAME)			: $(OBJ) $(LIB) $(MLX)
				$(CC) $(CFLAGS) $(OBJ) $(LIB) $(MLX) $(FRAME) -o $(NAME)
				printf "\x1b[1m\x1b[35m 👾 cub3D 👾 \x1b[22m\n"

$(LIB)			:
				make -C libft/

$(MLX)			:
				make -C mlx/

$(OBJ_DIR)/%.o	: $(SRC_DIR)/%.c $(HDR)
				mkdir -p $(OBJ_DIR)
				$(CC) $(CFLAGS) -c $< -o $@

clean			:
				make -C mlx/ clean
				make -C libft/ clean
				rm -rf $(TMP_DIR)
				rm -rf $(OBJ_DIR)

fclean			: clean
				make -C libft/ fclean
				rm -f $(NAME)

re				: fclean all

.PHONY			: all clean fclean re
