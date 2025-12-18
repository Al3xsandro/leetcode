🔹 Tipos numéricos

%d → inteiro decimal (int)

%i → inteiro decimal, octal ou hexadecimal (int)

%u → inteiro sem sinal (unsigned int)

%ld → inteiro longo (long int)

%lu → inteiro longo sem sinal (unsigned long int)

%hd → inteiro curto (short int)

%hu → inteiro curto sem sinal (unsigned short int)

🔹 Tipos de ponto flutuante

%f → número real (float)

%lf → número real duplo (double)

%Lf → número real longo (long double)
(atenção: no printf, %f e %lf são equivalentes, mas no scanf não são!)

🔹 Caracteres e strings

%c → um único caractere (char)

%s → string (sequência de caracteres até espaço ou \n) (char[])

%[...] → conjunto de caracteres (ex: %[^\n] lê até a quebra de linha)

🔹 Ponteiros

%p → lê/mostra endereço de memória (um ponteiro).

🔹 Miscelânea

%o → inteiro em octal (int)

%x ou %X → inteiro em hexadecimal (int)

%% → o caractere % literal (não para entrada, mas útil no printf)
