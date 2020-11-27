CC = gcc
CLFLAGS = -Wall
DEPS = linked_list.h

ODIR = obj
EXECDIR = exec

_OBJ = linked_list.o
OBJ = $(patsubst %, $(ODIR)/%, $(_OBJ))

_EXEC = linked_list.exe
EXEC = $(patsubst %, $(EXECDIR)%, $(_EXEC))

# make object files inside object directory with .c and .h files as dependencies
$(ODIR)/%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(EXECDIR)/%.exe: $(ODIR)/%.o

# make rule for linked list file
linked_list: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

binary_tree: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o
