CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RMCMD = rm
RMFLAGS = -f
NAME = fdf
SRCS = fdf.c fdf_readmap.c fdf_cleanup.c fdf_parsemap.c fdf_parseutils.c
OBJS = $(SRCS:.c=.o)
LIBFTPATH = libft
LIBFTNAME = libft.a

default: all

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFTPATH)
#$(MAKE) -C mlx
	$(CC) $(CFLAGS) -o $@ $(OBJS) ./$(LIBFTPATH)/$(LIBFTNAME) ./mlx/libmlx.a -lXext -lX11 -lm

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	$(MAKE) -C $(LIBFTPATH) clean
#$(MAKE) -C mlx clean
	$(RMCMD) $(RMFLAGS) $(OBJS)

fclean: clean
	$(RMCMD) $(RMFLAGS) $(NAME)
	$(MAKE) -C $(LIBFTPATH) fclean

re: fclean all

.PHONY: all clean fclean re default