#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char* str){
	int size = 0;
	char curr = str[0];
	while(curr != '\0'){
		size++;
		curr = str[size];
	}
	for(int i = 0; i<size/2; i++){
		int temp = str[i];
		str[i] = str[size-i-1]; 
		str[size-i-1] = temp;
	}
}

int main(){
  char str[5] = {'b', 'i', 't', 'h', '\0'};
  reverse(str);
  printf("%s \n", str);

  char str1[7] = {'d', 'i', 'n', 'g', 'u', 's', '\0'};
  reverse(str1);
  printf("%s \n", str1);
}