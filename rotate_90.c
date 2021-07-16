#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rotate_pixel(int **image, int size, int i, int j){
	size = size-1; //indexes go from 0 to size-1
	int curr; //holds pixel to be moved
	int temp; //holds pixel that was displaced

	curr = image[i][j];
	temp = image[j][size-i];
	image[j][size-i] = curr;
	curr = temp;
	temp = image[size-i][size-j];
	image[size-i][size-j] = curr;
	curr = temp;
	temp = image[size-j][i];
	image[size-j][i] = curr;
	curr = temp;
	image[i][j] = curr;
}

void rotate_ninety(int **image, int n){
	for(int i = 0; i<n/2; i++){
		for(int j = 0; j<(n+1)/2; j++){
			rotate_pixel(image, n, i, j);
		}
	}
}		

void print_matrix(int **image, int size){
  for(int i = 0; i<size; i++){
    for(int j = 0; j<size; j++){
      printf("%d ", image[i][j]);
    }
    printf("\n");
  }
	printf("\n");
}

int main(){
  int size = 5;
	int num = 1;
  int **image = malloc(sizeof(int*)*size);
	for(int i = 0; i<size; i++){
		image[i] = malloc(sizeof(int)*size);
	}
	for(int i = 0; i<size; i++){
		for(int j = 0; j<size; j++){
			image[i][j] = num;
			num++;
		}
	}
  print_matrix(image, size);
  rotate_ninety(image, size);
  print_matrix(image, size);
  return 1;
}
