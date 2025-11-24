// printing subseq in a array
#include<stdio.h>
void printsubseq(int A[], int idx, int n, int B[]){
	//base case
	if(idx>=n){
		for(int i=0;i<n;i++){
			if(B[i]!=0) printf("%d ", B[i]);
		}
		printf("\n");
		return;
	}
	//pick call
	B[idx]=A[idx];
	printsubseq(A,idx+1,n,B);
	B[idx]=0;
	//non pick
	printsubseq(A,idx+1,n,B);
}
int main(){
	int n;
	scanf("%d", &n);
	int A[n];
	int B[n];
	for(int i=0;i<n;i++) scanf("%d", &A[i]);
	printsubseq(A,0,n,B);
}
//4
//1 2 3 4-->2^n=16 , but give 15 and another one is null no.