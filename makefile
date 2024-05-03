NAME = get_next_line
CFLAGS = -Wall -Wextra -Werror 
SRC=src/get_next_line.c src/get_next_line_utils.c
OBJS = $(SRC:%.c=%.o)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -D BUFFER_SIZE=32 -I get_next_line.h -c $< -o $@

.PHONY: all
all: $(NAME)

.PHONY: clean
clean:
	rm -f $(OBJS)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all


.PHONY: test
test: 
	$(CC) $(CFLAGS) -D BUFFER_SIZE=100000 -I  get_next_line.h $ -o main *.c
