# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/16 15:40:00 by ertrigna          #+#    #+#              #
#    Updated: 2025/09/16 16:08:49 by ertrigna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors for pretty output
RED		= \033[0;31m
GREEN	= \033[0;32m
YELLOW	= \033[0;33m
BLUE	= \033[0;34m
MAGENTA	= \033[0;35m
CYAN	= \033[0;36m
WHITE	= \033[0;37m
RESET	= \033[0m

# Program name
NAME		= scalar

# Compiler and flags
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

# Source files
SRCDIR		= .
SRCS		= main.cpp Scalar.cpp
OBJS		= $(SRCS:.cpp=.o)

# Header files
HEADERS		= Scalar.hpp

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(CYAN)Linking $(NAME)...$(RESET)"
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) compiled successfully!$(RESET)"

%.o: %.cpp $(HEADERS)
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -f $(OBJS)
	@echo "$(GREEN)✓ Object files cleaned!$(RESET)"

fclean: clean
	@echo "$(RED)Cleaning $(NAME)...$(RESET)"
	@rm -f $(NAME)
	@echo "$(GREEN)✓ $(NAME) cleaned!$(RESET)"

re: fclean all

# Test targets
test: $(NAME)
	@echo "$(MAGENTA)Running basic tests...$(RESET)"
	@echo "$(CYAN)Testing char: 'c'$(RESET)"
	@./$(NAME) 'c'
	@echo "\n$(CYAN)Testing int: 42$(RESET)"
	@./$(NAME) 42
	@echo "\n$(CYAN)Testing float: 42.5f$(RESET)"
	@./$(NAME) 42.5f
	@echo "\n$(CYAN)Testing double: 3.14159$(RESET)"
	@./$(NAME) 3.14159
	@echo "\n$(CYAN)Testing nan: nan$(RESET)"
	@./$(NAME) nan

# Full test suite
fulltest: $(NAME)
	@chmod +x test.sh
	@./test.sh

.PHONY: all clean fclean re test fulltest