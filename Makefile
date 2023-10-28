 
Monedas.o: monedas.h monedas.cpp
	g++ -c monedas.cpp

testCambio: testCambio.cpp monedas.o
	g++ -c testCambio.cpp
	g++ -o testCambio testCambio.o monedas.o
