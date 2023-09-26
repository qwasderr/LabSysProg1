//#include <iostream>
//#include <set>
//#include <fstream>
//#include <string>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "set.h"
#include "Generator.cpp"
#define CLS 65
#define CLE 90
#define SLS 97
#define SLE 122
//using namespace std;
bool IsNum_Ascii(char a) {
	if ((((int)a >= CLS) && ((int)a <= CLE)) || (((int)a >= SLS) && ((int)a <= SLE))) return true;
	return false;
}
/*void SymSkip(ifstream& f) {
	char a=' ';
	while (!IsNum_Ascii(a)) f.get(a);
	f.seekg((long long)f.tellg() - 1, ios_base::beg);
}
void LettersSkip(ifstream& f) {
	char a = 'a';
	while (IsNum_Ascii(a)) f.get(a);
	f.seekg((long long)f.tellg() - 1, ios_base::beg);
}
char* GetWord(ifstream& f) {
	char* temp = new char[35];
	int letters = 1;
	f.get(temp[0]);
	while (letters <= 30 && IsNum_Ascii(temp[letters - 1])) {
		f.get(temp[letters]);
		++letters;
	}
	if (letters > 30) LettersSkip(f);
	temp[letters - 1] = 0;
	return temp;
}
bool Check(char* temp) {
	if (strlen(temp) > 26) return false;
	set<char> counter;
	for (int i = 0; i < strlen(temp); ++i) {
		if (counter.count(tolower(temp[i])) > 0) return false;
		counter.insert(tolower(temp[i]));
	}
	return true;
}*/ //C++ implementation
void SymSkip_c(FILE* f) {
	char a = ' ';
	while (!IsNum_Ascii(a) && !feof(f)) a = fgetc(f);
	if (feof(f)) return;
	fseek(f, -1, SEEK_CUR);
}
void LettersSkip_c(FILE* f) {
	char a = 'a';
	while (IsNum_Ascii(a)&&!feof(f)) a=fgetc(f);
	if (feof(f)) return;
	fseek(f,-1,SEEK_CUR);
}
char* GetWord_c(FILE* f) {
	char* temp;
	temp = (char*)malloc(35 * sizeof(char));
	int letters = 1;
	temp[0]=fgetc(f);
	while (letters <= 30 && IsNum_Ascii(temp[letters - 1])) {
		temp[letters]=fgetc(f);
		++letters;
	}
	if (letters > 30) LettersSkip_c(f);
	temp[letters - 1] = 0;
	if (!feof(f)) fseek(f, -1, SEEK_CUR);
	return temp;
}
int str_len(char* t) {
	return (strchr(t,0)-t)/sizeof(char);
}
bool Check_c(char* temp) {
	if (str_len(temp) > 26) return false;
	SimpleSet counter;
	set_init(&counter);
	for (int i = 0; i < str_len(temp); ++i) {
		char t = tolower(temp[i]);
		if (set_contains(&counter, &t) == SET_TRUE) return false;
		set_add(&counter, &t);
	}
	return true;
}
int main() {
	//set<char> letters{ 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	//set<char> sym{ ' ','.','/','[',']','{','}','+','-','*','\\','\'','"','#','%','$','@','!','^','&','(',')','_','=' };
	//ifstream file("test.txt");
	Generate();
	FILE* file;
	fopen_s(&file,"test.txt", "r");
	//char* buffer=new char;
	char* buffer;
	buffer = (char*)malloc(35 * sizeof(char));
	/*while (!file.eof()) {
		SymSkip(file);
		buffer = GetWord(file);
		if (Check(buffer)) cout << buffer << endl;
		delete buffer;
	}*/
	while (!feof(file)) {
		SymSkip_c(file);
		buffer = GetWord_c(file);
		if (Check_c(buffer)) printf("%s\n", buffer);
		free(buffer);
	}
	fclose(file);
}

