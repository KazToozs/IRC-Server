
CC	=	gcc

RM	=	rm -f

SRCSER	=	src/server/server.c		\
		src/server/get_next_line.c	\
		src/server/read_commands.c	\
		src/server/list.c		\
		src/server/channels.c		\
		src/server/my.c			\
		src/server/my_str_tab.c		\
		src/server/handle_clients.c	\
		src/server/commands/c_join.c	\
		src/server/commands/c_list.c	\
		src/server/commands/c_names.c	\
		src/server/commands/c_msg.c	\
		src/server/commands/c_nick.c	\
		src/server/commands/c_part.c	\
		src/server/commands/c_users.c	\
		src/server/commands/c_user.c	\
		src/server/commands/c_quit.c	\
		src/server/main.c

SRCCLI	=	src/client/main.c

OBJSER	=	$(SRCSER:.c=.o)

OBJCLI	=	$(SRCCLI:.c=.o)

SER	=	server

CLI	=	client

CFLAGS	=	-W -Wall -Wextra -I./include -g -g3


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
