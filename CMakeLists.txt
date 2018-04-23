cmake_minimum_required(VERSION 3.6)

project(fdf2)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lmlx -framework OpenGL -framework AppKit")

add_executable(fr42
        lib_function/ft_bzero.c
        lib_function/ft_itoa.c
        lib_function/ft_memset.c
        lib_function/ft_strlen.c
        burning_ship.c
        draw_options.c
        fractol.h
        julia.c
        key_option.c
        main.c
        mandelbrot.c)
