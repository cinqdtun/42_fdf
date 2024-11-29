CC = cc
CFLAGS = -Wall -Wextra -Werror
RMCMD = rm
RMFLAGS = -f
LIBCMD = ar
LIBFLAGS = rcs
INCLUDES = .
NAME = libft.a
SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcpy.c \
                 ft_memmove.c ft_memset.c ft_memcmp.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c \
                 ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c \
                 ft_toupper.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
				 ft_lstadd.c ft_lstfree.c ft_printf/ft_printf.c ft_printf/ft_utils.c ft_printf/ft_conversions.c ft_printf/ft_conversions1.c ft_strcmp.c\
				 gnl/get_next_line_utils.c gnl/get_next_line.c ft_atoi_base.c
OBJS = $(SRCS:.c=.o)

default: all

all: $(NAME)

$(NAME): $(OBJS)
	$(LIBCMD) $(LIBFLAGS) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

clean:
	$(RMCMD) $(RMFLAGS) $(OBJS)

fclean: clean
	$(RMCMD) $(RMFLAGS) $(NAME)

re: fclean all
	
.PHONY: all clean fclean re
