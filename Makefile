# Makefile for MPI stubs library

# Syntax:
#   make                 # build lib as libsmpi.a
#   make clean           # remove *.o and lib files

# edit System-specific settings as needed for your platform

SHELL = /bin/sh
.IGNORE:

# Files

SRC =		mpi.c
INC =		mpi.h

# Definitions

EXE =		libsmpi.a
OBJ = 		$(SRC:.c=.o)

# System-specific settings

CC =		g++
CCFLAGS =	-O -fPIC
ARCHIVE =	ar
ARCHFLAG =	rs

# Targets

lib:	$(OBJ)
	$(ARCHIVE) $(ARCHFLAG) $(EXE) $(OBJ)

clean:
	rm -f *.o libsmpi.a

# Compilation rules

.c.o:
	$(CC) $(CCFLAGS) -c $<

# Individual dependencies

$(OBJ):	$(INC)
