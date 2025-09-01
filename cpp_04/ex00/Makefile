# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/01 19:00:00 by ertrigna          #+#    #+#              #
#    Updated: 2025/09/01 18:25:05 by ertrigna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors for pretty output
RED		= \033[31m
GREEN	= \033[32m
YELLOW	= \033[33m
BLUE	= \033[34m
CYAN	= \033[36m
WHITE	= \033[37m
RESET	= \033[0m

# Project settings
NAME		= Polymorphism
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
RM			= rm -rf

# Source files
SRCDIR		= .
SOURCES		= main.cpp \
			  Animal.cpp \
			  Cat.cpp \
			  Dog.cpp \
			  WrongAnimal.cpp \
			  WrongCat.cpp

# Object files
OBJDIR		= obj
OBJECTS		= $(SOURCES:%.cpp=$(OBJDIR)/%.o)

# Header files
HEADERS		= Animal.hpp \
			  Cat.hpp \
			  Dog.hpp \
			  WrongAnimal.hpp \
			  WrongCat.hpp

# Rules
.PHONY: all clean fclean re bonus help

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo "$(CYAN)🔗 Linking $(NAME)...$(RESET)"
	@$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(NAME)
	@echo "$(GREEN)✅ $(NAME) compiled successfully!$(RESET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(HEADERS) | $(OBJDIR)
	@echo "$(YELLOW)⚙️  Compiling $<...$(RESET)"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)
	@echo "$(BLUE)📁 Created object directory$(RESET)"

clean:
	@echo "$(RED)🧹 Cleaning object files...$(RESET)"
	@$(RM) $(OBJDIR)

fclean: clean
	@echo "$(RED)🗑️  Removing $(NAME)...$(RESET)"
	@$(RM) $(NAME)

re: fclean all
	@echo "$(GREEN)🔄 Full rebuild complete!$(RESET)"

run: all
	@echo "$(CYAN)🚀 Running $(NAME)...$(RESET)"
	@./$(NAME)

debug: CXXFLAGS += -g -fsanitize=address
debug: re
	@echo "$(YELLOW)🐛 Debug version compiled$(RESET)"

help:
	@echo "$(WHITE)Available targets:$(RESET)"
	@echo "  $(GREEN)all$(RESET)     - Build the project"
	@echo "  $(YELLOW)clean$(RESET)   - Remove object files"
	@echo "  $(RED)fclean$(RESET)  - Remove object files and executable"
	@echo "  $(CYAN)re$(RESET)      - Clean and rebuild"
	@echo "  $(BLUE)run$(RESET)     - Build and run the program"
	@echo "  $(YELLOW)debug$(RESET)   - Build with debug flags"
	@echo "  $(WHITE)help$(RESET)    - Show this help message"
