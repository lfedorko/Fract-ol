cmake_minimum_required(VERSION 3.9)
project(fdf)
find_library(MLX mlx)
set(CMAKE_C_STANDARD 99)
set(SOURCE_FILES
        src/burning_ship.c
        src/draw_options.c
        src/key_option.c
        src/main.c
        src/mandelbrot.c
        src/burning_ship.c
        src/julia.c
        src/lib_function/ft_bzero.c
        src/lib_function/ft_itoa.c
        src/lib_function/ft_memset.c
        src/lib_function/ft_strlen.c)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${MLX} -framework OpenGL -framework AppKit")
add_executable(fdf ${SOURCE_FILES})