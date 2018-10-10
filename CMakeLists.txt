cmake_minimum_required(VERSION 3.9)
project(fdf)
find_library(MLX mlx)
set(CMAKE_C_STANDARD 99)
set(SOURCE_FILES
        src/draw.c
        src/key.c
        src/main.c
        src/fract.c
        src/lib_function/ft_bzero.c
        src/lib_function/ft_itoa.c
        src/lib_function/ft_memset.c
        src/lib_function/ft_strlen.c src/init.c)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${MLX} -framework OpenGL -framework AppKit")
add_executable(fdf ${SOURCE_FILES})
