#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void replace_spaces(char *str, int truesize, int size){
	char *writer = str + size-1;
	char *reader = str + truesize-1;
	while(writer > reader){
		if(*reader == ' '){
			*writer = '0';
			writer--;
			*writer = '2';
			writer--;
			*writer = '%';
		}
		else{
			*writer = *reader;
		}
		writer--;
		reader--;

    printf("%s \n", str);
	}
}

int main(){
  char str[13] = "abcde fghij  ";
  replace_spaces(str, 11, 13);

  char str1[52] = "the brown fox jumped over the i forgot              ";
  replace_spaces(str1, 38, 52);

  return 0;
}
