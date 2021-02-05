CC =			clang

FLAGS =			-Wall -Wextra -Werror

RM =			rm -rf

DIR_HEADERS =	./includes/

DIR_SRCS =		./srcs/

DIR_OBJS =		./

MLX_DIR = 		./
				# /usr/local/lib/

MLX_HEADER = 	./includes/
				# /usr/local/include/

MLX_FLAGS =		-lmlx -framework OpenGL -framework AppKit
# LIBMLX =		libmlx.dylib \
				libmlx.a

LIBFT =			libft.a

#SAVE =			-fsanitize=address

SRC =			gnl/get_next_line_utils.c \
				gnl/get_next_line.c \
				\
				parser/parse_scene.c \
				parser/parse_shapes.c \
				parser/parser.c \
				\
				vectors/init.c \
				vectors/operations.c \
				vectors/products.c \
				vectors/rotation.c \
				\
				intersect/intersect.c \
				intersect/intersect_cy.c \
				intersect/intersect_pl.c \
				intersect/intersect_sp.c \
				intersect/intersect_sq.c \
				intersect/intersect_tr.c \
				intersect/ray.c \
				\
				light/light.c \
				light/shadows.c \
				light/colors.c \
				\
				display/display.c \
				display/save.c \
				\
				error.c \
				\
				main.c

SRCS =			$(addprefix $(DIR_SRCS), $(SRC))

COMPIL =		$(FLAGS) #$(SAVE)

OBJS =			$(SRCS:.c=.o)

NAME =			miniRT

all:			$(NAME)

$(NAME) :		$(OBJS)
				$(CC) $(COMPIL) -I $(DIR_HEADERS) -I $(MLX_HEADER) -L $(MLX_DIR) $(MLX_FLAGS) $(LIBFT) $(OBJS) -o $(NAME)

%.o: %.c
				@$(MAKE) bonus -C ./libft
				@cp ./libft/libft.a libft.a
				@$(MAKE) -C ./mlx
				@cp ./mlx/libmlx.a $(MLX_DIR)libmlx.a && cp ./mlx/mlx.h $(MLX_HEADER)mlx.h
				@$(CC) $(FLAGS) -I $(DIR_HEADERS) -c $< -o $@
				@echo "Compiled "$<" successfully!"
		
bonus:

norme:
				norminette $(DIR_SRCS)
				norminette $(DIR_HEADERS)

clean:
				$(MAKE) clean -C ./libft
				$(MAKE) clean -C ./mlx
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(LIBFT)
				$(RM) $(MLX_DIR)libmlx.a
				$(RM) $(MLX_HEADER)mlx.h
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all, clean, fclean, re, bonus, norme