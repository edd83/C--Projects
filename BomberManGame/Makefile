##
## Makefile for cpp_bomberman in /home/ovoyan_s/rendu/cpp_bomberman/Core
## 
## Made by ovoyan_s
## Login   <ovoyan_s@epitech.net>
## 
## Started on  Mon May 26 16:12:13 2014 ovoyan_s
## Last update Sun Jun 15 21:21:33 2014 ovoyan_s
##

SRC_LIBRARY		=	my_cpp_libraries

SRC_SOURCES		=	sources

SRC_SOUNDS		=	Sounds

SRC			=	$(SRC_LIBRARY)/AStar.cpp		\
				$(SRC_LIBRARY)/Containers.cpp		\
				$(SRC_LIBRARY)/MyException.cpp		\
				$(SRC_LIBRARY)/Random.cpp		\
				$(SRC_LIBRARY)/Node.cpp			\
				$(SRC_LIBRARY)/Time.cpp			\
				$(SRC_SOURCES)/Bombe.cpp		\
				$(SRC_SOURCES)/BombermanAI.cpp		\
				$(SRC_SOURCES)/Bonus.cpp		\
				$(SRC_SOURCES)/Button.cpp		\
				$(SRC_SOURCES)/Entity.cpp		\
				$(SRC_SOURCES)/Event.cpp		\
				$(SRC_SOURCES)/GModel.cpp		\
				$(SRC_SOURCES)/GPlayer.cpp		\
				$(SRC_SOURCES)/GeneratorMap.cpp		\
				$(SRC_SOURCES)/GraphParsing.cpp		\
				$(SRC_SOURCES)/InputAction.cpp		\
				$(SRC_SOURCES)/main_graphic_client.cpp	\
				$(SRC_SOURCES)/Map.cpp			\
				$(SRC_SOURCES)/ModelManager.cpp		\
				$(SRC_SOURCES)/MyGame.cpp		\
				$(SRC_SOURCES)/Pause.cpp		\
				$(SRC_SOURCES)/Player.cpp		\
				$(SRC_SOURCES)/PrincipalMenu.cpp	\
				$(SRC_SOURCES)/SaveMenu.cpp		\
				$(SRC_SOURCES)/Scene.cpp		\
				$(SRC_SOURCES)/Sound.cpp		\
				$(SRC_SOURCES)/SoundManager.cpp		\
				$(SRC_SOURCES)/Window.cpp

OBJ			=	$(SRC:.cpp=.o)

CC			=	g++

NAME			=	Bomberman

RM			=	rm -rf

LIBS			=	-Iheaders				\
				-I./library/includes	 		\
				-L./library/libs			\
				-lgdl_gl -lGL -lGLEW -ldl -lrt		\
				-lfbxsdk -lSDL2 -lpthread -ldl -lm	\
				-lfmodex64

CXXFLAGS		=	-Werror -Wextra -Wall -W $(LIBS)

all:			$(NAME)

$(NAME):		$(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(LIBS)
			export LD_PRELOAD=$(PWD)/../library/libs/libfbxsdk.so

clean:
			$(RM) $(OBJ)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all
