# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/17 14:55:00 by ertrigna          #+#    #+#              #
#    Updated: 2025/09/17 14:52:18 by ertrigna         ###   ########.fr        #
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
NAME		= serialization

# Compiler and flags
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

# Source files
SRCDIR		= .
SRCS		= main.cpp Serialization.cpp
OBJS		= $(SRCS:.cpp=.o)

# Header files
HEADERS		= Serialization.hpp

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
	@echo "$(MAGENTA)Running serialization test...$(RESET)"
	@echo "$(CYAN)================================$(RESET)"
	@./$(NAME)
	@echo "$(CYAN)================================$(RESET)"

# Advanced test with multiple data structures
test_multiple: $(NAME)
	@echo "$(MAGENTA)Running multiple serialization tests...$(RESET)"
	@echo "$(CYAN)Test 1: Basic Data$(RESET)"
	@./$(NAME)
	@echo ""
	@echo "$(CYAN)Program completed. Check if addresses match!$(RESET)"

# Memory leak check (if valgrind is available)
valgrind: $(NAME)
	@echo "$(MAGENTA)Running memory leak check...$(RESET)"
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

# Debug build
debug: CXXFLAGS += -g -DDEBUG
debug: re

.PHONY: all clean fclean re test test_multiple valgrind debug