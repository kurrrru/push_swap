NAME		=	push_swap
DEQUE_SRCS	=	deque_basic.c		deque_access.c		deque_push_pop.c	deque_rotate.c		deque_swap.c \
				deque_find.c
OP_SRCS		=	op.c
OPT_SRCS	=	optimizer_add.c		optimizer_free.c	optimizer_init.c	optimizer_print.c
IS_SRCS		=	is_duplicated.c		is_empty_array.c	is_valid_string.c
UTIL_SRCS	=	error.c				compress.c			lis.c				lower_bound.c
SRCS		=	main.c 				push_swap.c 		sort.c				sort_push_to_a.c	sort_push_to_b.c \
				pos_to_insert.c		sort_small_case.c	multiple_rotate.c \
				$(DEQUE_SRCS)		$(OP_SRCS)			$(OPT_SRCS)			$(IS_SRCS)			$(UTIL_SRCS)
OBJS		= 	$(SRCS:.c=.o)
BONUS_SRCS	=	ch_check_instruction_bonus.c			ch_checker_bonus.c \
				ch_compress_bonus.c						ch_deque_access_bonus.c \
				ch_deque_basic_bonus.c					ch_deque_find_bonus.c \
				ch_deque_push_pop_bonus.c				ch_deque_rotate_bonus.c \
				ch_deque_swap_bonus.c					ch_empty_array_bonus.c \
				ch_error_bonus.c						ch_is_duplicated_bonus.c \
				ch_is_empty_array_bonus.c				ch_is_valid_string_bonus.c \
				ch_main_bonus.c							ch_op_bonus.c \
				ch_lower_bound_bonus.c
BONUS_OBJS	=	$(BONUS_SRCS:.c=.o)
BONUS_NAME	=	checker
LIBDIR		=	libft
LIB			=	libft.a
CC			=	cc
# あとで消す
CFLAGS		=	-Wall -Wextra -Werror -fsanitize=address

.DEFAULT_GOAL = all

$(NAME): $(OBJS) $(LIBDIR)/$(LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIBDIR)/$(LIB) -o $(NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(LIBDIR)/$(LIB)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBDIR)/$(LIB) -o $(BONUS_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBDIR)/$(LIB):
	make -C $(LIBDIR)

clean:
	make -C $(LIBDIR) fclean
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

all: $(NAME)

bonus: $(BONUS_NAME)

.PHONY: all clean fclean re
