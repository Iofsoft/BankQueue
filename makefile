CC = gcc
CFLAGS = -Wall -Wextra -g

SRCS = BankQueue.c CircularQueue.c List.c Main.c
OBJS = $(SRCS:.c=.o)
TARGET = BankQueue

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(TARGET)
