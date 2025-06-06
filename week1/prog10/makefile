CFLAGS = -Wall
	
OBJECTS = input.o output.o main.o
	
main : $(OBJECTS)
	gcc -o main $(OBJECTS)
	
clean : .FORCE
	rm -f main
	rm -f $(OBJECTS)
	
.FORCE : 
