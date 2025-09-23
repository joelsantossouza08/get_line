PROGRAM=getline

CC=cc
FLAGS=-Wall -Wextra -Werror -g
SRCS=tests/main.c srcs/utils.c srcs/get_line.c
OBJS=$(SRCS:.c=.o)
HEADERS=includes/get_line.h

all: $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(CC) $^ -o $@

%.o: %.c $(HEADERS)
	$(CC) $(FLAGS) -c $< -o $@ -I includes

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(PROGRAM)
