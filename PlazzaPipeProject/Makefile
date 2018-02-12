##
## Makefile for Makefile in /home/bonnet_v/programs/projects/cpp_pool/rush3
## 
## Made by Bonnet Vivien
## Login   <bonnet_v@epitech.net>
## 
## Started on  Sat Jan 25 10:44:17 2014 Bonnet Vivien
## Last Update Sun Apr 27 18:00:15 2014 Bonnet Vivien
##

CC=	g++

RM=	rm -f


ABSTRACTIONS_DIR=	abstractions
ABSTRACTIONS_SRCS=	$(ABSTRACTIONS_DIR)/CondVar.cpp	\
			$(ABSTRACTIONS_DIR)/Fifo.cpp	\
			$(ABSTRACTIONS_DIR)/Mutex.cpp	\
			$(ABSTRACTIONS_DIR)/Time.cpp

CORE_DIR=		core
CORE_SRCS=		$(CORE_DIR)/Cook.cpp		\
			$(CORE_DIR)/Kitchen.cpp		\
			$(CORE_DIR)/KitchenData.cpp	\
			$(CORE_DIR)/Pizza.cpp		\
			$(CORE_DIR)/Plazza.cpp		\
			$(CORE_DIR)/Recipes.cpp		\
			$(CORE_DIR)/Reserve.cpp		\
			$(CORE_DIR)/Schmidt.cpp		\
			$(CORE_DIR)/main.cpp

EXCEPTIONS_DIR=		exceptions
EXCEPTIONS_SRCS=	$(EXCEPTIONS_DIR)/ArgsException.cpp	\
			$(EXCEPTIONS_DIR)/FifoException.cpp	\
			$(EXCEPTIONS_DIR)/ParserException.cpp	\
			$(EXCEPTIONS_DIR)/PlazzaException.cpp	\
			$(EXCEPTIONS_DIR)/ProcessException.cpp	\
			$(EXCEPTIONS_DIR)/StringException.cpp	\
			$(EXCEPTIONS_DIR)/TimeException.cpp

GRAPHIC_DIR=		graphic
GRAPHIC_SRCS=		$(GRAPHIC_DIR)/GraphicModule.cpp	\
			$(GRAPHIC_DIR)/KitchenGraphic.cpp	\
			$(GRAPHIC_DIR)/Register.cpp		\
			$(GRAPHIC_DIR)/PlazzaWindow.cpp		\
			$(GRAPHIC_DIR)/Prompt.cpp

NCURSES_DIR=		ncursesxx
NCURSES_SRCS=		$(NCURSES_DIR)/Application.cpp		\
			$(NCURSES_DIR)/Color.cpp		\
			$(NCURSES_DIR)/NcursesException.cpp	\
			$(NCURSES_DIR)/Window.cpp

NETWORK_DIR=		network
NETWORK_SRCS=		$(NETWORK_DIR)/Error.cpp	\
			$(NETWORK_DIR)/Select.cpp	\
			$(NETWORK_DIR)/Server.cpp	\
			$(NETWORK_DIR)/Socket.cpp

PARSER_DIR=		parser
PARSER_SRCS=		$(PARSER_DIR)/Lexer.cpp		\
			$(PARSER_DIR)/PackFactory.cpp	\
			$(PARSER_DIR)/Parser.cpp	\
			$(PARSER_DIR)/PizzaString.cpp

NAME=			plazza

SRCS=			$(ABSTRACTIONS_SRCS)	\
			$(CORE_SRCS)		\
			$(EXCEPTIONS_SRCS)	\
			$(GRAPHIC_SRCS)		\
			$(NCURSES_SRCS)		\
			$(NETWORK_SRCS)		\
			$(PARSER_SRCS)

OBJS=			$(SRCS:.cpp=.o)


NCURSESXX_DIR=		ncursesxx
LIB_DIR=		libs

LIBS=			-lncurses	\
			-lpthread

CXXFLAGS=		-Wall -Werror -Wextra	\
			-I $(ABSTRACTIONS_DIR)	\
			-I $(CORE_DIR)		\
			-I $(EXCEPTIONS_DIR)	\
			-I $(GRAPHIC_DIR)	\
			-I $(NCURSES_DIR)	\
			-I $(NETWORK_DIR)	\
			-I $(PARSER_DIR)

LDFLAGS=		-o $(NAME)		\
			$(LIBS)



$(NAME):	$(OBJS)
		$(CC) $(OBJS) $(LDFLAGS)

all:		$(NAME)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
