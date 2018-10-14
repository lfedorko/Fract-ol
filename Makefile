NAME = fractol

SOURCE = src/main.c \
		src/key.c \
		src/draw.c \
		src/fract.c \
		src/init.c \
		src/lib_functions.c \
		src/mouse.c 

OBJECTS = $(SOURCE:.c=.o)

FLAGS = -Wall -Wextra -Werror
all: $(NAME)

%.o: %.c
	@gcc -c $< -o $@ -I fractol.h

$(NAME): $(OBJECTS) 
		@cc -o $(NAME) $(SOURCE) $(FLAGS) -lmlx -framework OpenGL -framework AppKit
		 @echo "\033[33mFract'ol is ready!\033[0m"


clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all