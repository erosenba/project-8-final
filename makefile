CFLAGS=-Wall -Werror -Wfatal-errors
#CFLAGS=-Wall -Werror

all: encrypt decrypt

encrypt: encrypt.o readWrite.o matrix.o eMatrix.o
	g++ -o encrypt encrypt.o readWrite.o matrix.o eMatrix.o

decrypt: decrypt.o readWrite.o matrix.o eMatrix.o
	g++ -o decrypt decrypt.o readWrite.o matrix.o eMatrix.o

encrypt.o: encrypt.cpp readWrite.h matrix.h eMatrix.h
	g++ -c $(CFLAGS) encrypt.cpp

decrypt.o: decrypt.cpp readWrite.h matrix.h eMatrix.h
		g++ -c $(CFLAGS) decrypt.cpp

readWrite.o: readWrite.cpp readWrite.h
	g++ -c $(CFLAGS) readWrite.cpp

matrix.o: matrix.cpp matrix.h
	g++ -c $(CFLAGS) matrix.cpp

eMatrix.o: eMatrix.cpp eMatrix.h matrix.h
	g++ -c $(CFLAGS) eMatrix.cpp

clean:
	rm -f *.o encrypt decrypt
