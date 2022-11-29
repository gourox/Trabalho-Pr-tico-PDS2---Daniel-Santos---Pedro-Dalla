all:
	g++ -std=c++17 main.cpp pesquisa.cpp -lstdc++ && ./a.out && rm a.out

clean:
	$(RM) -r *.o *.out $(TARGET)

testar:
	g++ -std=c++17 pesquisa_teste.cpp pesquisa.cpp  doctest.h -lstdc++ && ./a.out && rm a.out && rm doctest.h.gch