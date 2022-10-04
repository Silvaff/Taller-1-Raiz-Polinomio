salida: main.o Monomio.o Utils.o
	g++ main.o Monomio.o Utils.o -o salida

main.o: main.cpp
	g++ -c main.cpp
	
Monomio.o: Monomio.cpp Monomio.h
	g++ -c Monomio.cpp
	
Utils.o: Utils.cpp Utils.h
	g++ -c Utils.cpp
	
clean:
	rm *.o salida
