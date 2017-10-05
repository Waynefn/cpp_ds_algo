
CC		=	g++
SRCS	=	main.cpp	\
			array.cpp	\
			list.cpp	\
			doubly_list.cpp	\
			tree.cpp	\
			graph.cpp	\
			sort.cpp

OBJS	=	$(SRCS:.cpp=.o)
EXES	=	exe

start:	$(OBJS)
	$(CC) -o $(EXES) $(OBJS)
.cpp.o:
	$(CC) -o $@ -c $<

clean:
	rm -rf $(OBJS)
	rm -rf $(EXES)
	rm -rf *stackdump
