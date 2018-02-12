##
## Makefile for Makefile in /home/lardet_e/rendu/PSU_2013_myftp
## 
## Made by lardet
## Login   <lardet_e@epitech.net>
## 
## Started on  Sun Apr 13 23:04:51 2014 lardet
## Last Update Sun Apr 27 18:33:01 2014 Bonnet Vivien
##

CC		=	g++
RM		=	rm -f
CXXFLAGS	+=	-W -Wall -Werror

####################################################
## CLIENT
####################################################

CLT_NAME	=	client
CLT_OBJS	=	$(CLT_SRCS:.cpp=.o)

CLT_SRCS	=	Client.cpp		\
			Error.cpp		\
			Socket.cpp		\
			Select.cpp

####################################################
## RULES
####################################################

$(CLT_NAME)	:	$(CLT_OBJS)
		$(CC) -o $(CLT_NAME) $(CLT_OBJS) $(CXXFLAGS)

all		:	$(CLT_NAME)

clean		:
		$(RM) $(CLT_OBJS)

fclean		:	clean
		$(RM) $(CLT_NAME)

re		:	fclean all
