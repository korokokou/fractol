# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: takiapo <takiapo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 21:45:12 by takiapo           #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2016/03/02 13:20:06 by takiapo          ###   ########.fr        #
=======
#*   Updated: 2016/03/02 23:05:25 by takiapo          ###   ########.fr       *#
>>>>>>> array_pointers
#                                                                              #
# **************************************************************************** #

NAME = libxft.a

FLAGS = -Wall -Wextra -Werror

SRCDIR = srcs

OBJDIR = obj

SRC =	\
		srcs/itoc.c\
		srcs/ctoi.c\
		srcs/new_image.c\
		srcs/reset_image.c\
		srcs/add_point_int.c\
		srcs/add_point_t_color.c

OBJECTS = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

INCLUDE = includes/minilibxft.h

all : $(OBJECTS) $(NAME)

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@mkdir -p obj
	@gcc -c $(FLAGS) -Iincludes -c $< -o $@

$(NAME):
	@ar -rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

clean :
	@rm -rf $(OBJECTS)
	@rm -rf obj
	@echo 'clean'

fclean : clean
	@rm -rf $(NAME)
	@echo 'fclean'

re: fclean all
