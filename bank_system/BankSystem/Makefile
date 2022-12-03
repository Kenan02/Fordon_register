bank: Bank.o Functions.o
	gcc Bank.c Functions.c -o bank

Bank.o: Bank.c
	gcc -c Bank.c

Functions.o: Functions.c
	gcc -c Functions.c


clean:
	rm *.o bank