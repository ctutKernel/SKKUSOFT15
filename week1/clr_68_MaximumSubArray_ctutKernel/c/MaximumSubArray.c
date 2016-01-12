#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
typedef struct{
	int st,en;
}tuple;

int* randArray(int n);
int str2num(char* str,int size);
tuple* msa(int* change, int st,int en);
int main(int argc,char *args[]){
	if(argc < 2){
		return 0;
	}
	int n= str2num(args[1],strlen(args[1]));
	puts("PRICE");
	int* price = randArray(n);
	puts("CHANGE");
	int change[n-1];
	for(int i=0;i<n-1;i++){
		change[i] = price[i+1] - price[i];
		printf("index %d : val %d\n",i,change[i]);
	}
	tuple* maxSub = msa(change,0,n-2);
	printf("%d,%d MAX : %d\n",maxSub->st,maxSub->en+1,price[maxSub->en+1]-price[maxSub->st]);
}

int* randArray(int n){
	int hash = n*n;
	srand(time(NULL));
	bool index[n];
	for(int i=0;i<n;i++)
		index[i] = false;
	int* arr = (int*)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++){
		int val = rand()%hash;
		int tmp = val%n;
		while(index[tmp%n] != false){
			if(arr[tmp%n] == val)
				break;
			tmp++;	
		}
		arr[tmp%n] = val;
		index[tmp%n] = true;
	}
	for(int i=0;i<n;i++){
		printf("index %d : val %d\n",i,arr[i]);
	}
	return arr;
}

int str2num(char* str,int size){
	int returnVal=0;
	//check if input is all number
	for(int i=0;i<size;i++){
		if(str[i]>'9'||str[i]<'0')
			return 0;
	}
	for(int i=size-1, tmp=1;i>=0;i--){
		returnVal+=tmp*(str[i]-'0');
		tmp*=10;
	}
	return returnVal;
}

tuple* msa(int* change, int st,int en){
	if(en-st>0){
		//divide step
		tuple* lMax =  msa(change,st,(st+en)/2);
		tuple* rMax = msa(change,(st+en)/2+1,en);
		int rMaxVal=0,lMaxVal=0;
		
		//from st-en == 1
		if(lMax == NULL){
			lMax = (tuple*)malloc(sizeof(tuple));
			lMax->st = st;
			lMax->en = st;
		}
		if(rMax == NULL){
			rMax = (tuple*)malloc(sizeof(tuple));
			rMax->st = en;
			rMax->en = en;
		}

		//get right Max and left Max
		for(int i=rMax->st;i<=rMax->en;i++){
			rMaxVal += change[i];
		}
		for(int i=lMax->st;i<=lMax->en;i++){
			lMaxVal += change[i];
		}

		
		//get Max which include mid point
		int lSt,rEn,max,tmp;
		lSt = rEn = (st+en)/2;
		max = tmp = change[(st+en)/2];
		for(int i = (st+en)/2-1;i>=st;i--){
			tmp= tmp +  change[i];
			if(tmp > max){
				lSt = i;
				max = tmp;
			}
		}
		tmp = max;
		for(int i= (st+en)/2+1;i<=en;i++){
			tmp= tmp +  change[i];
			if(tmp>max){
				rEn = i;
				max = tmp;
			}
		}

		tuple* midMax = (tuple*)malloc(sizeof(tuple));
		midMax->st = lSt;
		midMax->en = rEn;
		//cmp with lMax,rMax,midMax
		if(max >= rMaxVal && max >= lMaxVal){
			free(rMax);
			free(lMax);
			return midMax;
		}else if(rMaxVal >= max && rMaxVal >= lMaxVal){
			free(midMax);
			free(lMax);
			return rMax;
		}else{
			free(midMax);
			free(rMax);
			return lMax;
		}

	}else{
		return NULL;
	}
	return NULL;
}

	
