LIB		= liblist.a
LIB-SRC		= list.c \
	 	  modifier.c \
		  iterator.c
LIB-OBJS	= $(LIB-SRC:.c=.o)

CFLAGS		= -W -Wall
CC		= cc
RM		= rm -rf

all		: $(LIB)

$(LIB)		: $(LIB-OBJS)
		  ar -r $(LIB) $(LIB-OBJS)
		  ranlib $(LIB)
		  $(CC) -o test main.c -L. -llist

clean		:
		  $(RM) *~
		  $(RM) $(OBJ)
		  $(RM) $(LIB-OBJS)

fclean		: clean
		  $(RM) $(NAME)
		  $(RM) $(LIB)

re		: fclean all