#make the binary (gcc args interception for linker: lib should be found in current didectory) :
binary: main.o libmatr.so
	gcc -o binary main.o -L. -lmatr -Wl,-rpath,.

#make the main ELF (compile only):
main.o: main.c
	gcc -c main.c

#construct the shared lib 'libmatr.so':
libmatr.so: matr.o
	gcc -shared -o libmatr.so matr.o

#make the matr.o ELF (compile only). Position-independent code is required:
matr.o: matr.c
	gcc -c -fPIC main.c

#clean build
clean:
	rm -f *.o *.so binary  
