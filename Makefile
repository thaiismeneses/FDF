# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thfranco <thfranco@student.42.rio>        +#+  +:+       +#+          #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/16 18:02:59 by thfranco         #+#    #+#               #
#    Updated: 2024/03/08 15:24:23 by thfranco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        	:= fdf

CC		:= gcc

FLAGS		:= -Wall -Wextra -Werror -g 
#-fsanitize=address

INCLUDE		:= -I libft/ minilibx-linux/fdf.h

LIBS		:= libft/libft.a minilibx-linux/libmlx.a -L/usr/X11/lib  -lX11 -lXext -lbsd -lm

SRCS        	:=	fdf.c\
			read_file.c\
			draw.c\
			config.c\
			key_settings.c\
			
                          
OBJS        := $(SRCS:.c=.o)

RM		    := rm -rf

AR			:= ar rcs

LEAK = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s

all: $(NAME)

$(NAME): $(OBJS)
					@echo "Compilation of $(NAME) ..."
					@make -C libft/
					@make -C minilibx-linux/
					$(CC) $(FLAGS) $(SRCS) $(LIBS) -o $(NAME)
					@echo "$(NAME) created✔️"

clean:
					@ echo "Deleting $(NAME) objs ✔️"
					@make clean -C libft/
					@$(RM) $(OBJS)

fclean: clean
					@ echo "Deleting $(NAME) ✔️"
					@ make fclean -C libft/
					@ make clean -C minilibx-linux/
					@ $(RM) $(NAME)			
					@ $(RM) $(LIBFT)


re:			fclean all 

leak:
				$(LEAK) ./fdf 42.fdf

norma:
				norminette $(SRCS) fdf.h ./libft

.PHONY:				all clean fclean re leak
