# Build greeting library and main output.

out: main.c libgreeting.a
	gcc -o $@ $< -L. -lgreeting

libgreeting.a: hello.o bubye.o
	ar cr $@ $^ 

hello.o: hello.c
	gcc -c hello.c

bubye.o: bubye.c
	gcc -c bubye.c

clean: 
	rm -rf *.o out libgreeting.a

