all:
	gcc -g main.c -o main


clean:
	rm -f server 

run:
	./main
