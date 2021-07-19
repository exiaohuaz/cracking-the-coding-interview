#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Checks if str2 is a substring of str1 */
bool isSubstring(char *str1, int size1, char *str2, int size2){
  if(size1 < size2) return false;
  
  for(int i = 0; i<size1-size2+1; i++){
    for(int j = 0; j<size2; j++){
      if(str1[i+j] != str2[j]){
        break;
      }
      if(j == size2-1){
        return true;
      }
    }
  }

  return false;
}

bool is_rotation(char *str1, int size1, char *str2, int size2){
	if(size1 != size2) return false;
	char *doublestr = malloc(sizeof(char) * size1 * 2);
	for(int i = 0; i<size1; i++){
		doublestr[i] = str1[i];
		doublestr[i+size1] = str1[i];
	}
	return isSubstring(doublestr, size1*2, str2, size2);
}

int main(){
  char str1[] = "shamalamadingdong";
  char str2[] = "dongshamalamading";
  int x = is_rotation(str1, 17, str2, 17);
  printf(x ? "true \n" : "false \n");
  char str3[] = "dongshamalamadine";
  x = is_rotation(str1, 17, str3, 17);
  printf(x ? "true \n" : "false \n");
}