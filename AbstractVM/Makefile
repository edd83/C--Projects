##
## Makefile for Makefile in /home/lardet_e/rendu/cpp_abstractvm
## 
## Made by lardet
## Login   <lardet_e@epitech.net>
## 
## Started on  Sat Mar  1 22:06:41 2014 lardet
## Last update Sat Mar  1 22:06:42 2014 lardet
##

NAME =	Abstract_VM

SRC =	Chipset.cpp \
	OperandCreator.cpp \
	Cpu.cpp \
	Memory.cpp \
	avm_error.cpp \
	Machine.cpp \
	main.cpp

CXXFLAGS = -W -Wall -Wextra -lm

CC =	g++

OBJS =	$(SRC:.cpp=.o)

RM =	rm -rf

$(NAME):  $(OBJS)
	  $(CC) $(OBJS) -o $(NAME) $(CFLAGS)

all:	$(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all
