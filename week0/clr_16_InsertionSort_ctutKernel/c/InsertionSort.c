#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void charswap(int from,int to,char* args);
void insertionSort(int* A,int n);
int num2str(char* args);
int* randArray(int n);
int* randMatrix(int argc,int limit);
int main(int argc,char *args[]){
	//get input
	int n=0;
	clock_t begin,end;
	if(argc<2){
		puts("Too less input");
		return 1;
	}else{
		n = num2str(args[1]);
	}
	begin = clock();
	int* A = randMatrix(n,n*n);
	end = clock();
	double time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
	//InsertionSort
	insertionSort(A,n);
	puts("SORTED");
	for(int i=0;i<n;i++){
		printf("index %d : %d\n",i,A[i]);
	}
	//RECORD
	FILE* fout = fopen("cResult.txt","a");
	fprintf(fout,"input size : %10d , time %10f\n",n,time_spent);
	fclose(fout);
}
void charswap(int from,int to,char* args){
	char key = args[from];
	args[from] = args[to];
	args[to] = key;
}
void insertionSort(int* A,int n){
	for(int i=1;i<n;i++){
		int key = A[i];
		int j = i-1;
		while(j>=0&&A[j]>key){
			A[j+1] = A[j--];
		}
		A[j+1] = key;
	}
}
int num2str(char* args){
	int num = 0;
	int tmp = 0;
	while(args[tmp++]!='\0');
	for(int i=0;i<(tmp-1)/2;i++){
		charswap(i,tmp-2-i,args);
	}
	int size = tmp;
	tmp = 1;
	for(int i=0;i<size-1;i++){
		num += tmp*(args[i]-'0');
		tmp *= 10;
	}
	return num;
}
int* randMatrix(int argc,int limit){
	srand(time(NULL));
	int* arr = (int*)malloc(sizeof(int)*argc);
	int index[argc];
	for(int i=0;i<argc;i++){
		index[i] = 0;
		arr[i] = 0;
	}
	for(int i=0;i<argc;i++){
		int val = rand()%limit;
		int tmp = val%argc;
		while(index[tmp]!=0){
			if(val = arr[tmp]){
				i--;
				break;
			}
			tmp++;
		}
		index[tmp] = 1;
		arr[tmp] = val;
	}	
	for(int i=0;i<argc;i++){
		//printf("index %d : %d\n",i,arr[i]);
	}
	return arr;
}
