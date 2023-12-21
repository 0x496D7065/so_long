# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpetit <lpetit@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/22 12:46:17 by lpetit            #+#    #+#              #
#    Updated: 2023/12/21 17:44:54 by lpetit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= so_long.out

UNAME = $(shell uname)

INCLUDES = -L./includes

SRCS_DIR = ./srcs/

SRCS= $(SRCS_DIR)ft_split.c $(SRCS_DIR)ft_strncmp.c $(SRCS_DIR)ft_strlen.c \
	$(SRCS_DIR)ft_strdup.c $(SRCS_DIR)map_check.c $(SRCS_DIR)is_valid.c \
	$(SRCS_DIR)find_player.c $(SRCS_DIR)exit_msg.c $(SRCS_DIR)display.c \
	$(SRCS_DIR)move.c $(SRCS_DIR)img_init.c $(SRCS_DIR)on_exit.c \
	$(SRCS_DIR)main.c \

OBJS= $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra -I./includes

MLX_DIR = ./mlx
MLX_LIB = $(MLX_DIR)/libmlx_$(UNAME).a

ifeq ($(shell uname), Linux)
	MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
else
	MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
endif
.PHONY: all clean fclean re

all: $(MLX_LIB) $(NAME)
 
.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)
 
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS) $(INCLUDES) -lftprintf
 
$(MLX_LIB):
	@make -C $(MLX_DIR)

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)



