# Variables
NAME = replace
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

# Source files
SRCS = main.cpp \
       Replace.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Header files
HEADERS = Replace.hpp

# Colors and Emojis
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
BOLD = \033[1m
NC = \033[0m

# File Emojis
FILE = 📄
SEARCH = 🔍
REPLACE = 🔄
CHECKMARK = ✅
TRASH = 🗑️
ROCKET = 🚀
STAR = ⭐
COMPUTER = 💻

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(CYAN)$(BOLD)$(ROCKET) Building file replacer...$(NC)"
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(BOLD)$(CHECKMARK) $(NAME) compiled successfully! $(STAR)$(NC)"
	@echo "$(MAGENTA)$(BOLD)Usage: ./$(NAME) <filename> <s1> <s2> $(SEARCH)$(REPLACE)$(NC)"

%.o: %.cpp $(HEADERS)
	@echo "$(YELLOW)$(FILE) Compiling $<...$(NC)"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "$(RED)$(TRASH) Cleaning object files...$(NC)"
	@$(RM) $(OBJS)
	@echo "$(BLUE)Object files cleaned! $(CHECKMARK)$(NC)"

fclean: clean
	@echo "$(RED)$(BOLD)$(TRASH) Removing $(NAME)...$(NC)"
	@$(RM) $(NAME)
	@echo "$(BLUE)$(BOLD)Everything cleaned! $(STAR)$(NC)"

re: fclean all
	@echo "$(MAGENTA)$(BOLD)$(REPLACE) Project rebuilt successfully! $(ROCKET)$(NC)"

test: $(NAME)
	@echo "$(CYAN)$(BOLD)$(COMPUTER) Running test...$(NC)"
	@echo "Hello world, this is a test file!" > test.txt
	@echo "World peace for the world!" >> test.txt
	@echo "$(GREEN)Original file:$(NC)"
	@cat test.txt
	@echo "$(YELLOW)$(SEARCH) Replacing 'world' with 'universe'...$(NC)"
	@./$(NAME) test.txt "world" "universe"
	@echo "$(GREEN)Result file:$(NC)"
	@cat test.txt.replace
	@$(RM) test.txt test.txt.replace
	@echo "$(CHECKMARK) Test completed!"

install: $(NAME)
	@echo "$(MAGENTA)$(BOLD)$(ROCKET) Installing $(NAME) to /usr/local/bin...$(NC)"
	@sudo cp $(NAME) /usr/local/bin/
	@echo "$(GREEN)$(BOLD)$(CHECKMARK) $(NAME) installed successfully!$(NC)"

help:
	@echo "$(CYAN)$(BOLD)$(STAR) Available commands:$(NC)"
	@echo "$(GREEN)  make$(NC)        - Compile the project"
	@echo "$(GREEN)  make clean$(NC)  - Remove object files"
	@echo "$(GREEN)  make fclean$(NC) - Remove object files and executable"
	@echo "$(GREEN)  make re$(NC)     - Rebuild the project"
	@echo "$(GREEN)  make test$(NC)   - Run a quick test"
	@echo "$(GREEN)  make install$(NC)- Install to system"
	@echo "$(GREEN)  make help$(NC)   - Show this help"

.PHONY: all clean fclean re test install help