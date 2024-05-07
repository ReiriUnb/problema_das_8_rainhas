CC=g++
CFLAGS=-Wall -Wextra -std=c++11 -g -O0
LDFLAGS=
GCOV_FLAGS=-fprofile-arcs -ftest-coverage
OBJ=rainhas.o testa_rainhas.o
EXEC=verifica_rainhas
TEST_EXEC=run_tests

all: $(EXEC)

# Compila o programa principal
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) -o $@ $^ $(LDFLAGS)

# Compila os objetos
%.o: %.cpp
	$(CC) $(CFLAGS) $(GCOV_FLAGS) -c -o $@ $<

# Compila e executa os testes
test: $(TEST_EXEC)

$(TEST_EXEC): $(OBJ)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) -o $@ $^ $(LDFLAGS)
	./$(TEST_EXEC)

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

.PHONY: all clean test cppcheck cpplint doc
