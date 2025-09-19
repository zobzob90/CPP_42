# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/19 20:50:00 by ertrigna          #+#    #+#              #
#    Updated: 2025/09/19 20:47:50 by ertrigna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME		= array

# Compiler and flags
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

# Directories
SRCDIR		= .
OBJDIR		= obj
INCDIR		= .

# Source files
SRCS		= main.cpp

# Object files
OBJS		= $(SRCS:%.cpp=$(OBJDIR)/%.o)

# Include files
INCLUDES	= Array.hpp Array.tpp

# Colors for pretty output
RED			= \033[0;31m
GREEN		= \033[0;32m
YELLOW		= \033[0;33m
BLUE		= \033[0;34m
MAGENTA		= \033[0;35m
CYAN		= \033[0;36m
WHITE		= \033[0;37m
RESET		= \033[0m

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(CYAN)Linking $(NAME)...$(RESET)"
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) compiled successfully!$(RESET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(INCLUDES) | $(OBJDIR)
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)
	@echo "$(BLUE)📁 Created $(OBJDIR) directory$(RESET)"

clean:
	@if [ -d "$(OBJDIR)" ]; then \
		rm -rf $(OBJDIR); \
		echo "$(RED)🗑️  Removed object files$(RESET)"; \
	fi

fclean: clean
	@if [ -f "$(NAME)" ]; then \
		rm -f $(NAME); \
		echo "$(RED)🗑️  Removed $(NAME)$(RESET)"; \
	fi

re: fclean all

test: $(NAME)
	@echo "$(MAGENTA)🧪 Running tests...$(RESET)"
	@./$(NAME)

.PHONY: all clean fclean re test

