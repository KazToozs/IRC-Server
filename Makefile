
CC	=	gcc

RM	=	rm -f

SRCSER	=	src/server/server.c		\
		src/server/get_next_line.c	\
		src/server/main.c

SRCCLI	=	

OBJSER	=	$(SRCSER:.c=.o)

OBJCLI	=	$(SRCCLI:.c=.o)

SER	=	server

CLI	=	client

CFLAGS	=	-W -Wall -Wextra -I./include


all:	$(SER) $(CLI)

$(SER):	$(OBJSER)
	$(CC) -o $(SER) $(OBJSER) $(CFLAGS)

$(CLI):	$(OBJCLI)
	$(CC) -o $(CLI) $(OBJCLI) $(CFLAGS)

clean:
	$(RM) $(OBJSER)
	$(RM) $(OBJCLI)

fclean: clean
	$(RM) $(SER)
	$(RM) $(CLI)

re: fclean all
