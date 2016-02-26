# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmichelo <rmichelo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/09 10:49:51 by rmichelo          #+#    #+#              #
#*   Updated: 2016/02/26 13:31:36 by takiapo          ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

CC				=	gcc
NAME			=	fractol
SRC				=	srcs/main.c

OBJ				=	$(SRC:.c=.o)
INCLUDE			=	-I/usr/X11R6/include -I/opt/X11/include -Iincludes
CFLAGS			=	-Wextra -Wall -Werror -g -pg -Iincludes
RM				=	rm -rf
BEGIN_COMPIL	=	@echo " Compilation launched."
END_COMPIL		=	@echo " Compilation ended."
BEGIN_CLEAN		=	@echo " Clean launched."
END_CLEAN		=	@echo " Clean ended."
BEGIN_SAVE		=	@echo " Save launched."
END_SAVE		=	@echo " Save ended."
SAVE_NAME		=	save_wolf3d.tar.gz
SAVE_INC_NAME	=	fractol.h
SAVE			=	tar cfz $(SAVE_NAME) Makefile $(SAVE_INC_NAME) $(SRC)
MINILIBX		=	-L/usr/X11/lib -lmlx -lX11 -lXext
LIBMATHS		=	-lm
LIBFTDIR		=	libft/
LIBFTH			=	-I$(LIBFTDIR)
LIBFTFLAGS		=	-L$(LIBFTDIR) -lft

$(NAME):	 makelibft $(OBJ)
		$(CC) $(CFLAGS) $(MINILIBX) $(LIBMATHS) $(INCLUDE) -o $(NAME) $(OBJ) $(LIBFTH) $(LIBFTFLAGS) $(MINILIBX) $(LIBMATHS)

makelibft:
	make -C $(LIBFTDIR)

makerelibft:
	make -C $(LIBFTDIR) re

all:		$(NAME)

end_compil:
		@echo "\033[1;35m"
		$(END_COMPIL)
		@echo "\033[00m"
		@echo ""

echo_name:
		@echo "\033[1;32m"
		@echo ""
		@echo " ______   ______     ______     ______     ______   ______     __        "
		@echo "/\  ___\ /\  == \   /\  __ \   /\  ___\   /\__  _\ /\  __ \   /\ \       "
		@echo "\ \  __\ \ \  __<   \ \  __ \  \ \ \____  \/_/\ \/ \ \ \/\ \  \ \ \____  "
		@echo " \ \_\    \ \_\ \_\  \ \_\ \_\  \ \_____\    \ \_\  \ \_____\  \ \_____\ "
		@echo "  \/_/     \/_/ /_/   \/_/\/_/   \/_____/     \/_/   \/_____/   \/_____/ "
		@echo "\033[1;33m"


begin_compil:
		@echo ""
		@echo "\033[1;35m"
		$(BEGIN_COMPIL)
		@echo "\033[1;33m"

save:
		@echo "\033[1;35m"
		$(BEGIN_SAVE)
		@echo "\033[1;33m"

		$(RM) $(SAVE_NAME)
		$(SAVE)

		@echo "\033[1;35m"
		$(END_SAVE)
		@echo "\033[00m"

clean:
		@echo ""
		@echo "\033[1;35m"
		$(BEGIN_CLEAN)
		@echo "\033[1;33m"

		$(RM) $(OBJ)

		@echo "\033[1;35m"
		$(END_CLEAN)
		@echo "\033[00m"

fclean:
		@echo ""
		@echo "\033[1;35m"
		$(BEGIN_CLEAN)
		@echo "\033[1;33m"

		$(RM) $(OBJ)

		@echo "\033[1;35m"
		$(END_CLEAN)
		@echo "\033[1;33m"

		$(RM) $(NAME)

		@echo "\033[1;35m"
		@echo " Old binary deleted."
		@echo "\033[00m"

end:
		@echo "\033[1;32m"
		@echo " Installation successful."
		@echo "\033[00m"

re:		echo_name fclean makerelibft begin_compil all end_compil end

.PHONY:		all clean re echo_name begin_compil end_compil save end
