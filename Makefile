##
## Makefile for Makefile in /home/mathon_j/rendu/208chevillettes
## 
## Made by Jérémy MATHON
## Login   <mathon_j@epitech.net>
## 
## Started on  Thu May 28 15:44:41 2015 Jérémy MATHON
## Last update Sat May 30 10:22:20 2015 Jérémy MATHON
##

NAME			=	209sondage

SRC			=	main.cpp	\
				calcul.cpp

OBJ			=	$(SRC:.cpp=.o)

RM			=	rm -rf

CXX			=	clang++

CXXFLAGS		=	-W -Wall -Wextra -g

all			:	$(NAME)

$(NAME)			:	$(OBJ)
				$(CXX) -o $(NAME) $(OBJ)

clean			:
				$(RM) $(OBJ)

fclean			:	clean
				$(RM) $(NAME)

re			:	fclean all
