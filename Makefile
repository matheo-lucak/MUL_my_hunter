##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## rtfm
##

CC			=	gcc

SRC			=	menu/menu.c				 	\
				menu/launcher_disp.c	 	\
				menu/launcher_destroy.c	 	\
				menu/launcher_event.c	 	\
				menu/launcher_set.c		 	\
				menu/launcher_set_bg.c	 	\
				menu/launcher_button.c	 	\
				menu/main.c				 	\
				menu/set_highscore.c	 	\
				src/set_lvl.c			 	\
				src/event.c				 	\
				src/event_ammo.c		 	\
				src/event_collision.c	 	\
				src/event_entity.c		 	\
				src/anime_cursor.c		 	\
				src/anime_bot_cursor.c	 	\
				src/anime_cannon.c		 	\
				src/anime_cannon_color.c	\
				src/anime_carrot.c		 	\
				src/anime_duck.c		 	\
				src/anime_bird.c		 	\
				src/anime_seed.c		 	\
				src/set_text.c			 	\
				src/set_heart_bar.c		 	\
				src/set_ammo_bar.c		 	\
				src/set_cursor.c		 	\
				src/set_bg.c			 	\
				src/set_music.c			 	\
				src/set_cannon.c		 	\
				src/set_carrot_arr.c	 	\
				src/set_carrot.c		 	\
				src/set_duck.c			 	\
				src/set_bird.c			 	\
				src/set_seed_arr.c		 	\
				src/set_seed.c			 	\
				src/set_window.c			\
				src/manage_obj.c			\
				src/destroy_ammo.c			\
				src/destroy_cannon.c		\
				src/destroy_entity.c		\
				src/destroy_window.c		\
				src/game.c					\

OBJ			=	$(SRC:.c=.o)

NAME		=	my_hunter

CPPFLAGS	=	-I./include/

LDFLAGS		=	-L./lib

LDLIBS		=	-lmy -lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system -lm

LIB			=	./lib/libmy.a

ASSET		=	music/		\
				sound/		\
				sprite/		\
				font/		\


$(NAME):	 $(LIB) $(OBJ) $(ASSET)
	$(CC) $(OBJ) -o $(NAME) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

all:	$(NAME)

debug:	fclean $(LIB) $(OBJ) $(ASSET)
	$(CC) $(SRC) -o $(NAME) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) -W -Wall -Wextra -g

$(LIB):
	make -C ./lib/my/

$(ASSET):
	tar -xzf asset.tar.gz

clean:
	rm -f $(OBJ)
	make clean -C ./lib/my/

fclean: clean
	rm -f $(NAME)
	rm -rf $(ASSET)
	make fclean -C ./lib/my

re:	fclean all

.PHONY:	$(NAME) all clean fclean
