NAME = fractol

FLAGS = -Wall -Wextra -Werror

SOURCE = main.c \
		key_option.c \
		draw_options.c \
		init.c \
		mandelbrot.c \
		julia.c \
		burning_ship.c \
		bresenham.c \
		triangle.c

OBJECTS = $(SOURCE:.c=.o)

LIB_DIR = ./libft/

LIB_INC = ./libft/libft.h

all: $(NAME)

%.o: %.c
	gcc -c $< -o $@ -I $(LIB_DIR) -I $(LIB_INC)

$(NAME): $(OBJECTS) $(LIB_DIR)libft.a
		cc -o $(NAME) $(SOURCE) $(LIB_DIR)*.o -lmlx -framework OpenGL -framework AppKit


$(LIB_DIR)libft.a:
	make -C $(LIB_DIR)././

clean:
	make clean -C $(LIB_DIR)
	rm -f $(OBJECTS)

fclean: clean
	make fclean -C $(LIB_DIR)
	rm -f $(NAME)

re: fclean all