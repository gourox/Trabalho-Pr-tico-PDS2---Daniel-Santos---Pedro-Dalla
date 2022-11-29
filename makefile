./maquina_busca: pesquisa.o main.o
	c++ -o ./maquina_busca pesquisa.o main.o
./maquina_busca.o: jpesquisa.h pesquisa.cpp
	c++ -c pesquisa.cpp -o pesquisa.o
./main.o: pesquisa.h main.cpp
	c++ -c main.cpp
clean:
	rm *.o
execution:
	./maquina_busca
	