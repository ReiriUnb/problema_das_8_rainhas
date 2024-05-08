CC=g++
CFLAGS=-Wall -Wextra -std=c++11 -g -O0 -ftest-coverage -fprofile-arcs
LDFLAGS=
GCOV_FLAGS=-fprofile-arcs -ftest-coverage
OBJ=rainhas.o main.o testa_rainhas.o
EXEC=verifica_rainhas
TEST_EXEC=run_tests

# Compila o programa principal
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Compila os objetos
%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

# Compila e executa os testes
test: $(TEST_EXEC)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) -o $@ $^ $(LDFLAGS)
	./$(TEST_EXEC)

$(TEST_EXEC): testa_rainhas.o
	$(CC) $(CFLAGS) $(GCOV_FLAGS) -o $@ $^ $(LDFLAGS)

# Limpa os arquivos de compilação e cobertura
clean:
	rm -f $(OBJ) $(EXEC) $(TEST_EXEC)
	rm -f *.gcda *.gcno *.gcov

# Executa o cppcheck
cppcheck:
	cppcheck --enable=warning .

# Executa o cpplint
cpplint:
	python cpplint.py --extensions=c,h,cpp,hpp *.c *.h *.cpp *.hpp

# Gera a documentação com Doxygen
doc:
	doxygen Doxyfile

# Executa o gcov
gcov:
	gcov -r -b $(OBJ:.o=.cpp)

.PHONY: all clean test cppcheck cpplint doc gcov
