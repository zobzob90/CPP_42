# Executable name
NAME		= PmergeMe

# Compiler and flags
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

# Directories
SRCDIR		= .
OBJDIR		= obj
INCDIR		= .

# Source files
SOURCES		= 	main.cpp \
				PmergeMe.cpp

# Object files
OBJECTS		= $(SOURCES:%.cpp=$(OBJDIR)/%.o)

# Header files
HEADERS		=	PmergeMe.hpp

# Colors for pretty output
GREEN		= \033[0;32m
YELLOW		= \033[0;33m
RED			= \033[0;31m
NC			= \033[0m

# Main rule
all: $(NAME)

# Create executable
$(NAME): $(OBJECTS)
	@echo "$(YELLOW)Linking $(NAME)...$(NC)"
	@$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) compiled successfully!$(NC)"

# Compile object files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(HEADERS) | $(OBJDIR)
	@echo "$(YELLOW)Compiling $<...$(NC)"
	@$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

# Create obj directory
$(OBJDIR):
	@mkdir -p $(OBJDIR)
	@echo "$(GREEN)Created obj directory$(NC)"

# Clean object files
clean:
	@if [ -d "$(OBJDIR)" ]; then \
		rm -rf $(OBJDIR); \
		echo "$(RED)✓ Object files cleaned$(NC)"; \
	fi

# Clean everything
fclean: clean
	@if [ -f "$(NAME)" ]; then \
		rm -f $(NAME); \
		echo "$(RED)✓ $(NAME) removed$(NC)"; \
	fi

# Rebuild everything
re: fclean all

# Run the program
run: $(NAME)
	@echo "$(GREEN)Running $(NAME):$(NC)"
	@./$(NAME)

# Debug build
debug: CXXFLAGS += -g -DDEBUG
debug: re

# Show help
help:
	@echo "$(GREEN)Available targets:$(NC)"
	@echo "  all     - Build the executable"
	@echo "  clean   - Remove object files"
	@echo "  fclean  - Remove object files and executable"
	@echo "  re      - Rebuild everything"
	@echo "  run     - Build and run the program"
	@echo "  debug   - Build with debug flags"
	@echo "  help    - Show this help message"

# Declare phony targets
.PHONY: all clean fclean re run debug help