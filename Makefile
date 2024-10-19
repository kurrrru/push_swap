NAME		=	push_swap
DEQUE_SRCS	=	deque_basic.c		deque_access.c		deque_push_pop.c	deque_rotate.c		deque_swap.c \
				deque_lower_bound.c	deque_find.c
OP_SRCS		=	op.c
OPT_SRCS	=	optimizer_add.c		optimizer_free.c	optimizer_init.c	optimizer_print.c
IS_SRCS		=	is_duplicated.c		is_empty_array.c	is_valid_string.c
UTIL_SRCS	=	error.c				compress.c			lis.c				lower_bound.c
SRCS		=	main.c 				push_swap.c 		sort.c				sort_push_to_a.c	sort_push_to_b.c \
				pos_to_insert.c \
				$(DEQUE_SRCS)		$(OP_SRCS)			$(OPT_SRCS)			$(IS_SRCS)			$(UTIL_SRCS)
OBJS		= 	$(SRCS:.c=.o)
LIBDIR		=	libft
LIB			=	libft.a
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -fsanitize=address

.DEFAULT_GOAL = all

$(NAME): $(OBJS) $(LIBDIR)/$(LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIBDIR)/$(LIB) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBDIR)/$(LIB):
	make -C $(LIBDIR)

clean:
	make -C $(LIBDIR) fclean
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

all: $(NAME)

.PHONY: all clean fclean re
