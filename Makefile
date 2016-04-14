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

# Set compiler specific options

CC		= g++
OBJDIR	= obj
TARGET	= main

objects	= $(addprefix $(OBJDIR)/, main.o buttons.o)
# Note to future self, figure out how to automagically list the files

main : $(objects)
	$(CC) $(CFLAGS) -o $(TARGET) $(objects)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) $(IPATH) -c $< -o $@

.PHONY : clean
clean :
	rm -f obj/* $(TARGET)
