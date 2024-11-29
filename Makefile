CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RMCMD = rm
RMFLAGS = -f
NAME = fdf
SRCS = fdf.c fdf_utils.c fdf_map_parser.c fdf_map_parser1.c fdf_list.c fdf_graphic.c fdf_calculation.c
OBJS = $(SRCS:.c=.o)
LIBFTPATH = libft
LIBFTNAME = libft.a

default: all

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFTPATH)
	$(CC) $(CFLAGS) -o $@ $(OBJS) ./$(LIBFTPATH)/$(LIBFTNAME) ./libmlx_Linux.a -lXext -lX11 -lm

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	$(MAKE) -C $(LIBFTPATH) clean
	$(RMCMD) $(RMFLAGS) $(OBJS)

fclean: clean
	$(RMCMD) $(RMFLAGS) $(NAME)
	$(MAKE) -C $(LIBFTPATH) fclean

re: fclean all

.PHONY: all clean fclean re default