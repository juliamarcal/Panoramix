##
## EPITECH PROJECT, 2024
## Network
## File description:
## My_ftp
##

NAME = panoramix

CC = gcc

RM = rm -f

CFLAGS += -W -Wall -Wextra -Werror -std=gnu99 -I./libs

LDFLAGS += -fopenmp

SRCS = src/druid/druid_init.c \
		src/druid/druid_message.c \
		src/villager/villager_init.c \
		src/villager/villager_messages.c \
		src/main.c

OBJS =	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
