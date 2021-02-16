CC =			clang

FLAGS =			-Wall -Wextra -Werror -g

RM =			rm -rf

DIR_HEADERS =	./includes/

DIR_SRCS =		./srcs/

MLX_DIR = 		./

MLX_HEADER = 	/usr/local/include/

MLX_LIB = 		/usr/local/lib/

MLX_FLAGS	=	-lmlx

MACOS_FLAGS =	-framework OpenGL -framework AppKit

LINUX_FLAGS =	-lX11 -lXext -lm

LIBMLX =		libmlx.a

LIBFT =			libft.a

FSAN =			-fsanitize=address

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
				vectors/utils.c \
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

COMPIL =		$(FLAGS)# $(FSAN)

OBJS =			$(SRCS:.c=.o)

NAME =			miniRT

UNAME := 		$(shell uname)

ifeq ($(UNAME),Darwin)
	MLX_DIR = ./mlx
	MLX_FLAGS += $(MACOS_FLAGS)
	COMPIL += -Lmlx -lmlx $(MACOS_FLAGS)
	FLAGS += -I$(DIR_HEADERS) -Imlx
	OS = -D MACOS
endif

ifeq ($(UNAME),Linux)
	MLX_DIR = ./mlx_linux
	MLX_FLAGS = -Lmlx -lmlx -L$(MLX_LIB) -Imlx_linux $(LINUX_FLAGS)
	FLAGS += -I$(DIR_HEADERS) -I$(MLX_HEADER) -Imlx_linux
	OS = -D LINUX
endif

all:			$(NAME)
				@echo "Compiled "$(NAME)" successfully!"

$(NAME) :		$(OBJS)
				@$(MAKE) -C ./libft bonus
				@cp ./libft/$(LIBFT) $(LIBFT) && cp ./libft/libft.h $(DIR_HEADERS)/libft.h
				@cp $(MLX_DIR)/*.h $(MLX_HEADER)
				@$(MAKE) CFLAGS="-w" -C $(MLX_DIR)
				@cp $(MLX_DIR)/$(LIBMLX) $(MLX_LIB)
				@$(CC) $(COMPIL) $(OS) $(OBJS) $(MLX_FLAGS) -L $(LIB)libft -lft -o $(NAME)

%.o: %.c
				@$(CC) $(FLAGS) $(OS) -c $< -o $@
				@echo "Compiled "$<" successfully!"
		
norme:
				norminette $(DIR_SRCS)
				norminette $(DIR_HEADERS)

clean:
				$(MAKE) -C ./libft clean
				$(MAKE) -C $(MLX_DIR) clean
				$(RM) $(OBJS)

fclean:			clean
				$(MAKE) -C ./libft fclean
				$(RM) $(LIBFT)
				$(RM) $(LIBMLX)
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all, clean, fclean, re, norme
