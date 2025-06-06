CFLAGS = -Wall

input.o : input.c
	gcc $(CFLAGS) -c input.c
	
output.o : output.c
	gcc $(CFLAGS) -c output.c
	
main.o : main.c
	gcc $(CFLAGS) -c main.c
	
main : input.o output.o main.o
	gcc -o main input.o output.o main.o
	
clean : .FORCE
	rm -f main
	rm -f *.o
	
.FORCE : 
