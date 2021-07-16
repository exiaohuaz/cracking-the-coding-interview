#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool uniqueChars(char* s, int size){
	bool seen[128] = {false};
	for(int i = 0; i<size; i++){
    printf("Char: %c ", s[i]);
		int index = (int)(s[i]);
    printf(" Index: %d \n", index);
		if(seen[index]){
			return false;
		}
		else{
			seen[index] = true;
		}
	}
	return true;
}

int main(){
  int x;
  x = uniqueChars("hubad", 5);
  printf(x ? "true \n" : "false \n");
  x = uniqueChars("hubbadubba", 10);
  printf(x ? "true \n" : "false \n");
  return 1;
}