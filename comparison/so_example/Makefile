test:
	gcc -c main.c
	g++ -fPIC -shared -o cppfile.so cppfile.cpp
	gcc -o exec main.o cppfile.so

clean:
	rm -f exec *.so *.o *~
