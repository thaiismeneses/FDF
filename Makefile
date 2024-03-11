# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thfranco <thfranco@student.42.rio>        +#+  +:+       +#+          #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/16 18:02:59 by thfranco         #+#    #+#               #
#    Updated: 2024/03/11 11:47:34 by thfranco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        	:= fdf

CC		:= cc

FLAGS		:= -Wall -Wextra -Werror -g 

INCLUDE		:= -I libft/ minilibx-linux/fdf.h

LIBS		:= libft/libft.a minilibx-linux/libmlx.a -L/usr/X11/lib  -lX11 -lXext -lbsd -lm

SRCS        	:=	fdf.c\
			check_file.c\
			read_file.c\
			draw.c\
			config.c\
			key_settings.c\
			
                          
OBJS        := $(SRCS:.c=.o)

RM		    := rm -rf

AR			:= ar rcs

LEAK = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s

all: $(NAME)

minilibx:
	wget https://cdn.intra.42.fr/document/document/22074/minilibx-linux.tgz
	tar -xvzf minilibx-linux.tgz
	rm minilibx-linux.tgz
	
$(NAME): $(OBJS)
					@echo "Compilation of $(NAME) ..."
					@make -s -C libft/
					@make -s -C minilibx-linux/
					@$(CC) $(FLAGS) $(SRCS) $(LIBS) -o $(NAME)
					@echo "$(NAME) created✔️"

clean:
					@echo "Deleting $(NAME) objs ✔️"
					@make -s clean -C libft/
					@$(RM) $(OBJS)

fclean: clean
					@echo "Deleting $(NAME) ✔️"
					@make -s fclean -C libft/
					@make -s clean -C minilibx-linux/
					@$(RM) $(NAME)			
					@$(RM) $(LIBFT)


re:			fclean all 

leak:
				$(LEAK) ./fdf 42.fdf

norma:
				norminette $(SRCS) fdf.h ./libft

.PHONY:				all clean fclean re leak
