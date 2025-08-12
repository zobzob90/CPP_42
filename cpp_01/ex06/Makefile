# Variables
NAME = harl
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

# Source files
SRCS = main.cpp \
       Harl.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Header files
HEADERS = Harl.hpp

# Colors and Emojis
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
BOLD = \033[1m
NC = \033[0m

# Harl Emojis
HARL = 😤
DEBUG = 🐛
INFO = ℹ️
WARNING = ⚠️
ERROR = ⛔
CHECKMARK = ✅
TRASH = 🗑️
ROCKET = 🚀
STAR = ⭐

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(CYAN)$(BOLD)$(ROCKET) Building Harl complainer...$(NC)"
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(BOLD)$(CHECKMARK) $(NAME) compiled successfully! $(HARL)$(NC)"
	@echo "$(MAGENTA)$(BOLD)Usage: ./$(NAME) to hear Harl complain! $(STAR)$(NC)"

%.o: %.cpp $(HEADERS)
	@echo "$(YELLOW)📄 Compiling $<...$(NC)"
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
	@echo "$(MAGENTA)$(BOLD)🔄 Project rebuilt successfully!$(NC)"

test: $(NAME)
	@echo "$(CYAN)$(BOLD)$(HARL) Running Harl complaint test...$(NC)"
	@echo "$(GREEN)$(BOLD)======= HARL COMPLAINT SYSTEM =======$(NC)"
	@./$(NAME)
	@echo "$(GREEN)$(BOLD)====================================$(NC)"

debug: $(NAME)
	@echo "$(YELLOW)$(DEBUG) Testing DEBUG level only:$(NC)"
	@echo 'DEBUG' | xargs -I {} ./$(NAME) {}

info: $(NAME)
	@echo "$(BLUE)$(INFO) Testing INFO level only:$(NC)"
	@echo 'INFO' | xargs -I {} ./$(NAME) {}

warning: $(NAME)
	@echo "$(YELLOW)$(WARNING) Testing WARNING level only:$(NC)"
	@echo 'WARNING' | xargs -I {} ./$(NAME) {}

error: $(NAME)
	@echo "$(RED)$(ERROR) Testing ERROR level only:$(NC)"
	@echo 'ERROR' | xargs -I {} ./$(NAME) {}

help:
	@echo "$(CYAN)$(BOLD)$(STAR) Available commands:$(NC)"
	@echo "$(GREEN)  make$(NC)        - Compile Harl"
	@echo "$(GREEN)  make test$(NC)   - Run all complaint tests $(HARL)"
	@echo "$(GREEN)  make debug$(NC)  - Test DEBUG level $(DEBUG)"
	@echo "$(GREEN)  make info$(NC)   - Test INFO level $(INFO)"
	@echo "$(GREEN)  make warning$(NC)- Test WARNING level $(WARNING)"
	@echo "$(GREEN)  make error$(NC)  - Test ERROR level $(ERROR)"
	@echo "$(GREEN)  make clean$(NC)  - Remove object files $(TRASH)"
	@echo "$(GREEN)  make fclean$(NC) - Remove all generated files"
	@echo "$(GREEN)  make re$(NC)     - Rebuild the project"
	@echo "$(GREEN)  make help$(NC)   - Show this help"

.PHONY: all clean fclean re test debug info warning error help