CC = gcc
CLFLAGS = -Wall 
DEPS = linked_list.h

ODIR = obj
EXECDIR = exec

# ------------- File Rules -------------  
_OBJ = linked_list.o
OBJ = $(patsubst %, $(ODIR)/%, $(_OBJ))

# make object files inside object directory with .c and .h files as dependencies
$(ODIR)/%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -g -c -o $@ $<

#_EXEC = linked_list.exe
#EXEC = $(patsubst %, $(EXECDIR)%, $(_EXEC))

#$(EXECDIR)/%.exe: $(ODIR)/%.o

# ------------- Compilation Rules -------------  

# make rule for linked list file
linked_list: $(OBJ)
	$(CC) $(CFLAGS) -g -o $@ $^

binary_tree: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# ------------- Clean Up Rules -------------  
.PHONY: clean

clean:
	rm -f $(ODIR)/*.o
