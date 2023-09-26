#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
void Generate() {
	srand(time(NULL));
	char sym;
	const int size = 500;
	FILE* file;
	fopen_s(&file, "test.txt", "w");
	for (int i = 1; i <= size; ++i) {
		sym = (char)(rand() % 95 + 32);
		//printf("%c\n", sym);
		fwrite(&sym, sizeof(char), 1, file);
	}
	fclose(file);
}