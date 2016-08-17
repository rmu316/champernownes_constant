champernowne: champernowne.o
	gcc -o champernowne -g champernowne.o
champernowne.o: champernowne.c
	gcc -g -c -Wall champernowne.c
clean:
	rm -f *.o champernowne  
