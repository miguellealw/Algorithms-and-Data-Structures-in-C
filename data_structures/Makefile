CC = gcc
CLFLAGS = -Wall -Wl
DEPS = linked_list.h stack.h

ODIR = obj
EXECDIR = exec

# ------------- File Rules -------------  
_OBJ = main.o linked_list.o stack.o
OBJ = $(patsubst %, $(ODIR)/%, $(_OBJ))

# make object files inside object directory with .c and .h files as dependencies
$(ODIR)/%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -g -c -o $@ $<

#_EXEC = linked_list.exe
#EXEC = $(patsubst %, $(EXECDIR)%, $(_EXEC))

#$(EXECDIR)/%.exe: $(ODIR)/%.o

# ------------- Compilation Rules -------------  

main: $(OBJ)
	$(CC) $(CFLAGS) -g -o $@.out $^

# make rule for linked list file
linked_list: $(OBJ)
	$(CC) $(CFLAGS) -g -o $@.out $^

stack: $(OBJ)
	$(CC) $(CFLAGS) -g -o $@.out $^

binary_tree: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# ------------- Clean Up Rules -------------  
.PHONY: clean

clean:
	rm -f $(ODIR)/*.o
