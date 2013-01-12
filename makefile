CC = gcc
Objects = test.o mfload.o mmethod.o
Lib = 
MFLOAD = mfload.h mstruct.h mfload.c
MMETHOD = mmethod.h mstruct.h mmethod.c
TEST = mfload.h mmethod.h mstruct.h test.c

test: $(Objects)
	$(CC) -o test $(Objects) $(Lib)

mfload.o: $(MFLOAD)
	$(CC) -c mfload.c

mmethod.o: $(MMETHOD)
	$(CC) -c mmethod.c

test.o: $(TEST)
	$(CC) -c test.c

clean:
	rm *.o
