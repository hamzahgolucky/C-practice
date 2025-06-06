CFLAGS = -Wall

hello.o : hello.c
	gcc $(CFLAGS) -c hello.c
	
hello: hello.o
	gcc $(CFLAGS) -o hello hello.o
	
clean : .FORCE
	rm -f hello
	rm -f hello.o
	
.FORCE : 
