# ******************************************# Header files
HEADERS		= AMateria.hpp \
			  ICharacter.hpp \
			  Character.hpp \
			  IMateriaSource.hpp \
			  MateriaSource.hpp \
			  Ice.hpp \
			  Cure.hpp \
			  Fire.hpp \
			  Prison.hpp \
			  Salade.hpp************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/08 15:00:00 by ertrigna          #+#    #+#              #
#    Updated: 2025/09/10 10:21:18 by ertrigna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors for pretty output
RED		= \033[31m
GREEN	= \033[32m
YELLOW	= \033[33m
BLUE	= \033[34m
CYAN	= \033[36m
WHITE	= \033[37m
PINK	= \033[35m
RESET	= \033[0m

# Project settings
NAME		= Materia
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
RM			= rm -rf

# Source files
SRCDIR		= .
SOURCES		= main.cpp \
			  AMateria.cpp \
			  Ice.cpp \
			  Cure.cpp \
			  Fire.cpp \
			  Prison.cpp \
			  Salade.cpp \
			  Character.cpp \
			  MateriaSource.cpp

# Object files
OBJDIR		= obj
OBJECTS		= $(SOURCES:%.cpp=$(OBJDIR)/%.o)

# Header files
HEADERS		= AMateria.hpp \
			  ICharacter.hpp \
			  Character.hpp \
			  IMateriaSource.hpp \
			  MateriaSource.hpp \
			  Ice.hpp \
			  Fire.hpp \
			  Salade.hpp \
			  Prison.hpp \
			  Color.hpp \
			  Cure.hpp

# Rules
.PHONY: all clean fclean re run debug help

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo "$(CYAN)🔗 Linking $(NAME)...$(RESET)"
	@$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(NAME)
	@echo "$(GREEN)✅ $(NAME) compiled successfully!$(RESET)"

obj/main.o: main.cpp $(HEADERS)
	@mkdir -p obj
	@echo "$(YELLOW)⚙️  Compiling main.cpp...$(RESET)"
	@$(CXX) $(CXXFLAGS) -c main.cpp -o obj/main.o

obj/AMateria.o: AMateria.cpp $(HEADERS)
	@mkdir -p obj
	@echo "$(YELLOW)⚙️  Compiling AMateria.cpp...$(RESET)"
	@$(CXX) $(CXXFLAGS) -c AMateria.cpp -o obj/AMateria.o

obj/Ice.o: Ice.cpp $(HEADERS)
	@mkdir -p obj
	@echo "$(YELLOW)⚙️  Compiling Ice.cpp...$(RESET)"
	@$(CXX) $(CXXFLAGS) -c Ice.cpp -o obj/Ice.o

obj/Fire.o: Fire.cpp $(HEADERS)
	@mkdir -p obj
	@echo "$(YELLOW)⚙️  Compiling Fire.cpp...$(RESET)"
	@$(CXX) $(CXXFLAGS) -c Fire.cpp -o obj/Fire.o

obj/Prison.o: Prison.cpp $(HEADERS)
	@mkdir -p obj
	@echo "$(YELLOW)⚙️  Compiling Prison.cpp...$(RESET)"
	@$(CXX) $(CXXFLAGS) -c Prison.cpp -o obj/Prison.o

obj/Cure.o: Cure.cpp $(HEADERS)
	@mkdir -p obj
	@echo "$(YELLOW)⚙️  Compiling Cure.cpp...$(RESET)"
	@$(CXX) $(CXXFLAGS) -c Cure.cpp -o obj/Cure.o

obj/Character.o: Character.cpp $(HEADERS)
	@mkdir -p obj
	@echo "$(YELLOW)⚙️  Compiling Character.cpp...$(RESET)"
	@$(CXX) $(CXXFLAGS) -c Character.cpp -o obj/Character.o

obj/MateriaSource.o: MateriaSource.cpp $(HEADERS)
	@mkdir -p obj
	@echo "$(YELLOW)⚙️  Compiling MateriaSource.cpp...$(RESET)"
	@$(CXX) $(CXXFLAGS) -c MateriaSource.cpp -o obj/MateriaSource.o

obj/Salade.o: Salade.cpp $(HEADERS)
	@mkdir -p obj
	@echo "$(YELLOW)⚙️  Compiling Salade.cpp...$(RESET)"
	@$(CXX) $(CXXFLAGS) -c Salade.cpp -o obj/Salade.o

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

valgrind: all
	@echo "$(PINK)🔍 Running with valgrind...$(RESET)"
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

test: all
	@echo "$(WHITE)🧪 Running tests...$(RESET)"
	@./$(NAME)
	@echo "$(GREEN)✅ Tests completed$(RESET)"

help:
	@echo "$(WHITE)Available targets:$(RESET)"
	@echo "  $(GREEN)all$(RESET)       - Build the project"
	@echo "  $(GREEN)clean$(RESET)     - Remove object files"
	@echo "  $(GREEN)fclean$(RESET)    - Remove object files and executable"
	@echo "  $(GREEN)re$(RESET)        - Full rebuild"
	@echo "  $(GREEN)run$(RESET)       - Compile and run"
	@echo "  $(GREEN)debug$(RESET)     - Compile with debug flags"
	@echo "  $(GREEN)valgrind$(RESET)  - Run with valgrind"
	@echo "  $(GREEN)test$(RESET)      - Run basic tests"
	@echo "  $(GREEN)help$(RESET)      - Show this help"