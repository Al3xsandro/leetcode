# Variáveis usadas para compilar os programas.
CFLAGS = -std=c99 -Wall -Werror -Wvla -g  # flags de compilação
LDFLAGS = -lm                             # flags de linkagem

# Marca essas duas receitas como alvos especiais, que
# não precisam existir como arquivos.
.PHONY: all clean

# `make all` compila todos os programas.
all: drama cpf auau

# `make clean` remove os arquivos gerados pela compilação.
clean:
	rm -f drama cpf auau

# As regras de compilação para cada programa.
# A sintaxe `$(VAR)` substitui o valor da variável VAR no comando.
drama: drama.c
	gcc $(CFLAGS) drama.c -o drama $(LDFLAGS)
cpf: cpf.c
	gcc $(CFLAGS) cpf.c -o cpf $(LDFLAGS)
auau: auau.c
	gcc $(CFLAGS) auau.c -o auau $(LDFLAGS)
