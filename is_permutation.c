#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
bool isPermutation(char *str1, int size1, char *str2, int size2){
	if(size1 != size2){
		return false;
	}
	int char_counter[128] = {0}; //128 is number of ascii characters
	for(int i = 0; i<size1; i++){
		int index = (int)(str1[i]);
		char_counter[index]++;
	}
	for(int j = 0; j<size2; j++){
		int index = (int)(str2[j]);
		char_counter[index]--;
		if(char_counter[index] < 0){
      return false;
    }
	}
	return true;
}

int main(){
  int x;
  x = isPermutation("flabbergasted", 13, "gatoraded", 9);
  printf(x ? "true \n" : "false \n");
  x = isPermutation("salami", 6, "lsaaim", 6);
  printf(x ? "true \n" : "false \n");
  x = isPermutation("bushdid911", 10, "obamaid119", 10);
  printf(x ? "true \n" : "false \n");
  return 1;
}