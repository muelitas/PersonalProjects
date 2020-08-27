#include <stdio.h>

void transpose(int rows, int cols, int mat[rows][cols], int matT[cols][rows]){
	int i, j;
	for(i=0; i<rows; i++){
		for(j=0; j<cols; j++){
			matT[j][i] = mat[i][j];
		}
	}
}

void read_matrix(int r, int c, int m[r][c]){
	printf("Please enter the values of your matrix:\n");
	int i, j;
	for(i=0; i<r; i++){
		for(j=0; j<c; j++){
			scanf("%d", &m[i][j]);
		}
	}
}

void print_matrix(int r, int c, int m[r][c]){
	int i, j;
	for(i=0; i<r; i++){
		for(j=0; j<c; j++){
			printf("%4d", m[i][j]);
		}
		printf("\n");
	}
}

int main(){
	int rows, cols;
	printf("How many rows will your matrix have? ");
	scanf("%d", &rows);
	printf("How many cols will your matrix have? ");
	scanf("%d", &cols);

	int mat[rows][cols];
	int matT[cols][rows];
	read_matrix(rows, cols, mat);
	printf("These are the values of your matrix:\n");
	print_matrix(rows, cols, mat);

	transpose(rows, cols, mat, matT);
	printf("These are the values of your transposed matrix:\n");
	print_matrix(cols, rows, matT);

	return 0;
}
