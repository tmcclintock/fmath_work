lol:
	gcc -c thec.c
	g++ -fPIC -shared comp.cpp -O2 -o comp.so
	gcc -o exec thec.o comp.so

clean:
	rm -f *.so exec *.o
