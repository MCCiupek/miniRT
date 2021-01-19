LINUX
gcc main.c srcs/*.c libft/*.c -I includes -I /usr/local/include/ -L /usr/local/lib/ -lmlx -lX11 -lXext -D BUFFER_SIZE=32 -lm

MAC
gcc main.c srcs/*.c libft/*.c -I includes -I /usr/local/include/ -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit -D BUFFER_SIZE=32
