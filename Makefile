# Makefile for Marshrut project
# Yauheni Kazlouski

# Compiler and flags
CC = gcc
CFLAGS = -I./include -Wall -Wextra -std=c99

# Directories
SRCDIR = src
INCDIR = include
OBJDIR = obj
BINDIR = bin

# Files
SOURCES = $(SRCDIR)/main.c $(SRCDIR)/marshrut.c
OBJECTS = $(OBJDIR)/main.o $(OBJDIR)/marshrut.o
TARGET = $(BINDIR)/marshrut

# Default target
all: $(TARGET)

build: all

# Link object files to create executable
$(TARGET): $(OBJECTS) | $(BINDIR)
	$(CC) -o $@ $(OBJECTS)

# Compile main.c
$(OBJDIR)/main.o: $(SRCDIR)/main.c $(INCDIR)/marshrut.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Compile marshrut.c
$(OBJDIR)/marshrut.o: $(SRCDIR)/marshrut.c $(INCDIR)/marshrut.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create bin directory if it doesn't exist
$(BINDIR):
	mkdir -p $(BINDIR)

# Create obj directory if it doesn't exist
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Clean object files and executable
clean:
	rm -f $(OBJDIR)/*.o $(TARGET)
	rm -rf $(OBJDIR) $(BINDIR)

# Run target
run: all
	$(TARGET)