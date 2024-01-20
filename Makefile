# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahsalam <ahsalam@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/16 12:29:08 by ahsalam           #+#    #+#              #
#    Updated: 2023/07/26 10:43:31 by ahsalam          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LDFLAGS = -Lminilibx_macos -lmlx -framework OpenGL -framework AppKit

INC = -Iincludes/ -Ilibft/

LIBS = -Lprevious_projects/libft -lft

SRCS = FDF_code/main.c FDF_code/utils.c FDF_code/read_file.c FDF_code/map_drawing.c FDF_code/key.c \
		./previous_projects/get_next_line/get_next_line.c ./previous_projects/get_next_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):	$(OBJS)
			$(MAKE) -sC previous_projects/libft
			$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -sC previous_projects/libft clean
	rm -f $(OBJS)

fclean: 
	$(MAKE) -sC previous_projects/libft fclean
	rm -f $(OBJS) $(NAME)

re: fclean all

.PHONY: all clean fclean re