
tablice: tablice.c
	gcc tablice.c -o tablice

run: tablice
	./tablice

clean:
	rm tablice