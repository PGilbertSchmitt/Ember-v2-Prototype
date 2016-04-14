# This is my working make file.
#
# Assumes the following directory structure:
# Project/			-> Root project folder
#	src/			-> For all .cpp files
#	include/		-> For all .h files
#	obj/		-> For all native .o files
#	THIS_MAKEFILE
.SUFFIXES:
.SUFFIXES: .cpp .o

CFLAGS	= -Wall -std=c++11
SRCDIR	= src
IPATH	= -I include
LIBPATH	= -lsfml-window -lsfml-system

# Set compiler specific options

CC		= g++
OBJDIR	= obj
TARGET	= main

objects	= $(addprefix $(OBJDIR)/, main.o inputs.o)
# Note to future self, figure out how to automagically list the files

main : $(objects)
	$(CC) $(CFLAGS) $(objects) -o $(TARGET) $(LIBPATH)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) $(IPATH) -c $< -o $@

.PHONY : clean
clean :
	rm -f obj/* $(TARGET)
