# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thafranco <thfranco@student.42.rio>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/16 18:02:59 by thafranco         #+#    #+#              #
#    Updated: 2024/02/20 11:13:25 by thafranco        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := fdf

CC			:= gcc

FLAGS		:= -Wall -Wextra -Werror 

INCLUDE		:= -I libft/ minilibx/ fdf.h

LIBS		:= libft/libft.a minilibx/libmlx.a -L/usr/X11/lib -lmlx -lX11 -lXext -lbsd

SRCS        :=			  main.c\
						  key_settings.c\
						  read_file.c\
                          
OBJS        := $(SRCS:.c=.o)

RM		    := rm -rf

AR			:= ar rcs


all: $(NAME)

$(NAME): $(OBJS)
					@echo "Compilation of $(NAME) ..."
					@make -C libft
					@make -C minilibx
					$(CC) $(FLAGS) $(SRCS) $(LIBS) -o $(NAME)
					@echo "$(NAME) created✔️"

clean:
					@ echo "Deleting $(NAME) objs ✔️"
					@make clean -C libft
					@$(RM) $(OBJS)

fclean: clean
					@ echo "Deleting $(NAME) ✔️"
					@ make fclean -C libft/
					@ make clean -C minilibx/
					@ $(RM) $(NAME)			
					@ $(RM) $(LIBFT)


re:			fclean all 

.PHONY:				all clean fclean re
