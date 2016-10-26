randtest: randomfile.c
	gcc randomfile.c
run: randtest
	./a.out
clean:
	rm randfile.txt
