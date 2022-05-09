# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkim3 <mkim3@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/09 16:26:27 by mkim3             #+#    #+#              #
#    Updated: 2022/05/09 19:03:59 by mkim3            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=so_long
GCC=gcc
FLAG=-Werror -Wall -Wextra

# SOLONG=solong
SRCS=./so_long.c ./read_map.c ./get_next_line.c ./exception.c
OBJS=$(SRCS:.c=.o)

LIBFT=libft.a
LIBFT_PATH=./libft
LIBFT_MAKE_CLEAN=make -C $(LIBFT_PATH) clean

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	$(GCC) $(FLAG) -I $(LIBFT_PATH) $(OBJS) ./libft/libft.a -o $@	
.c.o:
	$(CC) $(CFLAGS) -I $(LIBFT_PATH) -c $< -o $@

# $(SOLONG) : $(OBJS) 	
	
$(LIBFT) : 
	make -C $(LIBFT_PATH) all

clean:
	$(LIBFT_MAKE_CLEAN)
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) ./libft/libft.a

re: fclean all

.PHONY: re all fclean clean

