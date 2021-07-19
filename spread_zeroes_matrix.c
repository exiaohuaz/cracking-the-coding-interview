#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fill_row_col(int **matrix, int numrows, int numcols, int row, int col, int fillnum){
	for(int i = 0; i<numrows; i++){
		matrix[i][col] = fillnum;
	}
	for(int j = 0; j<numcols; j++){
		matrix[row][j] = fillnum;
	}
}

void spread_zeroes(int **matrix, int numrows, int numcols){
	bool *rows = malloc(numrows);
	memset(rows, true, numrows);
	bool *cols = malloc(numcols);
	memset(cols, true, numcols);

	for(int row = 0; row<numrows; row++){
		for(int col = 0; col<numcols; col++){
			if(rows[row] && cols[col] && matrix[row][col] == 0){
				fill_row_col(matrix, numrows, numcols, row, col, 0);
				rows[row] = false;
				cols[col] = false;
			}
		}
	}
}

void generate_matrix(int **matrix, int m, int n){
	for(int i = 0; i<m; i++){
		for(int j = 0; j<n; j++){
			matrix[i][j] = rand() % 30;
		}
	}
}

void print_matrix(int **matrix, int m, int n){
	for(int i = 0; i<m; i++){
    for(int j = 0; j<n; j++){
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
	printf("\n");
}

int main(){
  int m = 6;
  int n = 9;
  int **matrix = malloc(sizeof(int*) * m);
	for(int i = 0; i<m; i++){
		matrix[i] = malloc(sizeof(int) * n);
	}

	generate_matrix(matrix, m, n);
	print_matrix(matrix, m, n);

	spread_zeroes(matrix, m, n);
	print_matrix(matrix, m, n);

	return 0;
}
