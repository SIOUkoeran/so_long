# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkim3 <mkim3@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/09 16:26:27 by mkim3             #+#    #+#              #
#    Updated: 2022/06/15 18:19:56 by mkim3            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=so_long
GCC=gcc
FLAG=-Werror -Wall -Wextra

SRCS=./so_long.c ./read_map.c ./get_next_line.c ./exception.c\
./move_character.c ./print_image.c ./read_map_util.c
OBJS=$(SRCS:.c=.o)

LIBFT=libft.a
LIBFT_PATH=./libft
LIBFT_MAKE_CLEAN=make -C $(LIBFT_PATH) clean

MLX=libmlx.a
MLX_PATH=./minilibx_opengl_20191021
MLX_MAKE_CLEAN=make -C $(MLX_PATH) clean

all : $(NAME)

$(NAME) : $(LIBFT) $(MLX) $(OBJS)
	$(GCC) $(FLAG) -I $(LIBFT_PATH) $(OBJS) ./libft/libft.a  -L ./minilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit -o $@
.c.o:
	$(CC) $(CFLAGS) -I $(LIBFT_PATH) -Imlx -c $< -o $@
$(LIBFT) : 
	make -C $(LIBFT_PATH) all

$(MLX) : 
	make -C $(MLX_PATH) all

clean:
	$(LIBFT_MAKE_CLEAN)
	$(MLX_MAKE_CLEAN)
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) ./libft/libft.a ./minilibx_opengl_20191021/libmlx.a

re: fclean all

.PHONY: re all fclean clean

