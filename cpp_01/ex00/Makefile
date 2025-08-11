# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/11 15:30:00 by ertrigna          #+#    #+#              #
#    Updated: 2025/08/11 15:05:40 by ertrigna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom de l'exécutable
NAME = zombie

# Compilateur et flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp \
       Zombie.cpp \
       newZombie.cpp \
       randomChump.cpp

# Fichiers objets
OBJS = $(SRCS:.cpp=.o)

# Règle par défaut
all: $(NAME)

# Compilation de l'exécutable
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

# Compilation des fichiers objets
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Nettoyage des fichiers objets
clean:
	rm -f $(OBJS)

# Nettoyage complet
fclean: clean
	rm -f $(NAME)

# Recompilation complète
re: fclean all

.PHONY: all clean fclean re