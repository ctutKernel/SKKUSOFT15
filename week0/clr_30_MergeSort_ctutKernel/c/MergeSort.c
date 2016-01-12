#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

void MergeSort(int* A, int st, int en);
void Merge(int* A,int st, int mid, int en);
int num2str(char* args);
void charswap(int from,int to,char* args);
int* randArray(int* par,int argc,int limit);
int main(int argc, char *args[]){
	//get input
	if(argc < 2){
		puts("Too less input");
		return 1;
	}
	//invert input to num
	int n = num2str(args[1]);
	//get random Array
	int par[1] = {n};
	int *A = randArray(par,1,n*2);
	MergeSort(A,0,n-1);
	puts("");
	for(int i=0;i<n;i++){
		printf("index: %10d val: %10d\n",i,A[i]);
	}
}
void MergeSort(int* A, int st, int en){
	if(en > st&&A!=NULL){
		//divide A into two sequences
		MergeSort(A,st,(st+en)/2);
		MergeSort(A,(st+en)/2+1,en);
		//Merge and sort
		Merge(A,st,(st+en)/2,en);
	}
}
void Merge(int* A,int st, int mid, int en){
	int L[mid-st+2];
	int R[en-mid+1];
	for(int i=0;i<mid-st+1;i++){
		L[i] = A[i+st];
	}
	L[mid-st+1] = INT_MAX;
	for(int i=0;i<en-mid;i++){
		R[i] = A[i+mid+1];
	}
	R[en-mid] = INT_MAX;
	for(int i=0,j=0,k=st;k<en+1;k++){
		if(L[i] < R[j]){
			A[k] = L[i++];
		}else if(L[i] > R[j]){
			A[k] = R[j++];
		}
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
void charswap(int from,int to,char* args){
	char key = args[from];
	args[from] = args[to];
	args[to] = key;
}
int* randArray(int* par,int argc,int limit){
	srand(time(NULL));
	int n = 1;
	for(int i=0;i<argc;i++){
		n *= par[i];
	}
	if(limit < n){
		puts("Too small limit");
		return NULL;
	}
	int* arr = (int*)malloc(sizeof(int)*n);
	int index[n];
	for(int i=0;i<n;i++){
		index[i] = 0;
	}
	for(int i=0;i<n;i++){
		int val = rand()%limit;
		int tmp = val%n;
		while(index[tmp%10]!=0){
			if(val == arr[tmp%10]){
				i--;
				break;
			}
			tmp++;
		}
		index[tmp%10] = 1;
		arr[tmp%10] = val;
	}
	puts("");
	for(int i=0;i<n;i++){
		printf("index: %10d val: %10d\n",i,arr[i]);
	}
	return arr;
}
