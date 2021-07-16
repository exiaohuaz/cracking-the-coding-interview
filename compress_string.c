#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *compress_string(char *str, int size){
	if(size < 2) return str; //compressing will not help
	
	char *compressed = malloc(size+1);
	compressed[0] = str[0];
	int index = 0; //index of current letter in compressed string
	int count = 1; //number of current letter in compressed string
	for(int i = 1; i<size; i++){
		if(str[i] == compressed[index]){ //if letter is same as current letter, inc count
			count++;
		}
		else{ //otherwise, write count to array and move to next letter
			compressed[index+1] = count + '0'; 
			index += 2;
			if(index+1 >= size-1){ //before writing to array, check that index is in bounds
				free(compressed);
				return str;
			}
			compressed[index] = str[i]; //add new letter to compressed string
			count = 1;
		}
	}
	compressed[index+1] = count + '0'; //writes the number for the last letter
	compressed[index+2] = '\0';
	return compressed;
}

int main(){
  char str1[14] = "flamindshdush"; //i think i'm writing my test cases wrong... 
	//behavior is correct but string prints weird
  printf("%s \n", str1);
  printf("%s \n\n", compress_string(str1, 13));

  char str2[15] = "aabbbccccddddd";
  printf("%s \n", str2);
  printf("%s \n\n", compress_string(str2, 14));
  return 1;
}