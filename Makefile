NAME = fractol


SOURCE = src/main.c \
		src/key_option.c \
		src/draw_options.c \
		src/fract.c \
		src/lib_function/ft_bzero.c \
		src/lib_function/ft_itoa.c \
		src/lib_function/ft_strlen.c \
		src/lib_function/ft_memset.c \

OBJECTS = $(SOURCE:.c=.o)

all: $(NAME)

%.o: %.c
	@gcc -c $< -o $@ -I $(LIB_DIR) -I $(LIB_INC)

$(NAME): $(OBJECTS) 
		@cc -o $(NAME) $(SOURCE) -lmlx -framework OpenGL -framework AppKit
		 @echo "\033[33mFract'ol is ready!\033[0m"


clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all