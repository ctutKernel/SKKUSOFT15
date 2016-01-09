#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef struct{
	int col,row;
	int* arr;
}matrix;

int* randArray(int n);
int num2str(char* str);
matrix* multiply(matrix A, matrix B);
int main(int argc, char *args[]){
	srand(time(NULL));
	int n = num2str(args[1]);
	matrix A = {.col = n, .row = n, .arr = randArray(n*n)};
	matrix B = {.col = n, .row = n, .arr = randArray(n*n)};
	matrix* C = multiply(A,B);
	for(int i=0;i<C->row;i++){
		for(int j=0;j<C->col;j++){
			printf("%d ",C->arr[i*C->col+j]);
		}
		puts("");
	}	
	return 0;
}
int* randArray(int n){
	int *arr =(int*)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++){
		arr[i] = rand()%(n*n);
		printf("val : %d\n",arr[i]);
	}
	puts("");
	return arr;
}
int num2str(char* str){
	int len = strlen(str);
	int tmp = 1,val = 0;
	for(int i=len-1;i>=0;i--){
		val+=(str[i]-'0')*tmp;
		tmp*=10;
	}
	return val;
}
matrix* multiply(matrix A, matrix B){
	if(A.col != B.row){
		return NULL;
	}else{
		int n = A.col;
		int* arr = (int*)malloc(sizeof(int)*A.row*B.col);
		for(int i=0;i<A.row;i++){
			for(int j=0;j<B.col;j++){
				for(int k=0;k<n;k++){
					arr[i*n+j] += A.arr[i*A.col+k]*B.arr[k*B.col+j];
				}
			}
		}		
		matrix* C = (matrix*)malloc(sizeof(matrix));
		C->row = A.row;
		C->col = B.col;
		C->arr = arr;
	}
}
