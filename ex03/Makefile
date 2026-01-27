NAME = bureaucrat
SRC_DIR = src
OBJ_F = obj/

SRC = $(SRC_DIR)/main.cpp \
      $(SRC_DIR)/Bureaucrat.cpp \
      $(SRC_DIR)/AForm.cpp \
      $(SRC_DIR)/PresidentialPardonForm.cpp \
      $(SRC_DIR)/RobotomyRequestForm.cpp \
      $(SRC_DIR)/ShrubberyCreationForm.cpp \
	  $(SRC_DIR)/Intern.cpp

OBJ = $(addprefix $(OBJ_F), $(notdir $(SRC:.cpp=.o)))

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -Iincludes

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(CFLAGS) -o $(NAME)
	@echo "✅ $(NAME) compiled successfully!"

$(OBJ_F)%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_F)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled: $<"

clean:
	@rm -rf $(OBJ_F)

fclean: clean
	@rm -f $(NAME)

re: fclean all

run: all
	./$(NAME)

val: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

.PHONY: all clean fclean re run val