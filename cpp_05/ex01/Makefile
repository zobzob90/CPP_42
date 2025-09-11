# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/09 14:30:00 by ertrigna          #+#    #+#              #
#    Updated: 2025/09/11 15:48:31 by ertrigna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME		= Form

# Compiler and flags
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

# Source files
SRCDIR		= .
SOURCES		= main.cpp \
				Bureaucrat.cpp \
				Form.cpp 

OBJECTS		= $(SOURCES:.cpp=.o)

# Header files
HEADERS		= Bureaucrat.hpp \
				Form.hpp 

# Colors for output
GREEN		= \033[0;32m
RED			= \033[0;31m
BLUE		= \033[0;34m
YELLOW		= \033[1;33m
NC			= \033[0m # No Color

# Rules
all: $(NAME)

$(NAME): $(OBJECTS)
	@echo "$(BLUE)Linking $(NAME)...$(NC)"
	@$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) compiled successfully!$(NC)"

%.o: %.cpp $(HEADERS)
	@echo "$(YELLOW)Compiling $<...$(NC)"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Cleaning object files...$(NC)"
	@rm -f $(OBJECTS)
	@echo "$(GREEN)✓ Object files cleaned!$(NC)"

fclean: clean
	@echo "$(RED)Cleaning executable...$(NC)"
	@rm -f $(NAME)
	@echo "$(GREEN)✓ Executable cleaned!$(NC)"

re: fclean all

# Test rule
test: $(NAME)
	@echo "$(BLUE)Running tests...$(NC)"
	@./$(NAME)

# Debug version
debug: CXXFLAGS += -g3 -fsanitize=address
debug: $(NAME)

.PHONY: all clean fclean re test debug
