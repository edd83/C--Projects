##
## Makefile for Makefile in /home/lardet_e/TP/nibbler
## 
## Made by lardet
## Login   <lardet_e@epitech.net>
## 
## Started on  Tue Apr  1 10:29:25 2014 lardet
## Last update Sun Apr  6 22:11:37 2014 lardet
##

NAME=	nibbler

CXX=	g++ -g -Wall -Wextra -W -ldl

DIR_SRCS=	./srcs

SRC=	$(DIR_SRCS)/Collision.cpp	\
	$(DIR_SRCS)/Food.cpp		\
	$(DIR_SRCS)/Game.cpp		\
	$(DIR_SRCS)/GameException.cpp	\
	$(DIR_SRCS)/Hole.cpp		\
	$(DIR_SRCS)/Loader.cpp		\
	$(DIR_SRCS)/main.cpp		\
	$(DIR_SRCS)/Snake.cpp		\
	$(DIR_SRCS)/Strategie.cpp	\
	$(DIR_SRCS)/StratFact.cpp

OBJ=	$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) -o $(NAME)
	g++ -shared -lncurses -o lib_nibbler_ncurses.so ./ncurses/src/Display.cpp ./ncurses/src/ncursesManager.cpp ./srcs/GameException.cpp -fPIC
	g++ -shared -lSDL -o lib_nibbler_sdl.so ./sdl/src/Display.cpp ./srcs/GameException.cpp ./sdl/src/SDL_Manager.cpp -fPIC
	g++ -shared -lGL -lGLU -lSDL -o lib_nibbler_opengl.so opengl/srcs/Display.cpp  -fPIC

clean:	
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	rm -rf lib_nibbler_ncurses.so
	rm -rf lib_nibbler_sdl.so
	rm -rf lib_nibbler_opengl.so

re:	fclean all
