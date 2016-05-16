
CC	=	gcc

RM	=	rm -f

SRCSER	=	

SRCCLI	=	

OBJSER	=	$(SRCSER:.c=.o)

OBJCLI	=	$(SRCCLI:.c=.o)

SER	=	server

CLI	=	client

CFLAGS	=	-W -Wall -Wextra

INC	=	-I./include


all:	$(SER) $(CLI)

$(SER):	$(OBJSER)
	$(CC) -o $(SER) $(SRCSER) $(CFLAGS) $(INC)

$(SER):	$(OBJCLI)
	$(CC) -o $(CLI) $(SRCCLI) $(CFLAGS) $(INC)

clean:
	$(RM) $(OBJSER)
	$(RM) $(OBJCLI)

fclean: clean
	$(RM) $(SER)
	$(RM) $(CLI)

re: fclean all
