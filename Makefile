# Lawrence Scroggs -- 10/08/20 -- Makefile
# Crediting Bart Massey Lecture 4 video since he built in class

CPP = g++
CPPFLAGS = -Wall -g
LIBS = -lncurses

conway: conway.cpp
	$(CPP) $(CPPFLAGS) -o conway conway.cpp $(LIBS)

clean: 
	-rm -f conway

