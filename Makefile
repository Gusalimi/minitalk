CNAME	= client
SNAME	= server
CSRCS	= client.c
SSRCS	= server.c
COBJS	= $(CSRCS:.c=.o)
SOBJS	= $(SSRCS:.c=.o)
CSRCSB	= client_bonus.c
SSRCSB	= server_bonus.c
COBJSB	= $(CSRCSB:.c=.o)
SOBJSB	= $(SSRCSB:.c=.o)
LIB		= ft_printf/libftprintf.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf

.c.o:
	$(CC) -c $< $(CFLAGS) -o $(<:.c=.o)

all: $(CNAME) $(SNAME)

$(CNAME): $(COBJS) $(LIB)
	$(CC) $(CFLAGS) $(COBJS) $(LIB) -o $(CNAME)

$(SNAME): $(SOBJS) $(LIB)
	$(CC) $(CFLAGS) $(SOBJS) $(LIB) -o $(SNAME)

bonus: $(SOBJSB) $(COBJSB) $(LIB)
	$(CC) $(CFLAGS) $(COBJSB) $(LIB) -o $(CNAME)
	$(CC) $(CFLAGS) $(SOBJSB) $(LIB) -o $(SNAME)

$(LIB):
	$(MAKE) -C ft_printf

clean:
	$(RM) $(COBJS) $(COBJSB) $(SOBJS) $(SOBJSB)
	$(MAKE) clean -C ft_printf

fclean: clean
	$(RM) $(CNAME) $(SNAME)
	$(MAKE) fclean -C ft_printf

re:	fclean all

.PHONY: all debug clean fclean
