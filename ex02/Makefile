NAME = Bureacraut_Fancy_Forms
CC = g++ -o -g
CFLAGZ = -Wall -Wextra -Werror -std=c++98 -Iinclude
SRCS = 	main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp  ShrubberyCreationForm.cpp
CREATED_FILES = *_shrubbery

OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CC) $(CFLAGZ) -g -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC)	$(CFLAGZ)	-o	$(NAME)	$(OBJS) 

clean:
	rm -f $(OBJS)
	rm -f $(CREATED_FILES)

fclean: clean
	rm -f $(NAME)
	
re: fclean all