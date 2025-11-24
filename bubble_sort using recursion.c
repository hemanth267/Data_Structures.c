// bubble sort using recursion
// 4
// 23 24 25 22---> 22 23 24 25
#include<stdio.h>
void bubble_sort(int A[], int i, int j, int n){//0 4
	//base case if all passes are done
	if(i>=n) return;
	//for eaxh pass
	if(j>=n-1) return;
	if(j<n-1 && A[j]>A[j+1]){// 3 4
		int temp=A[j];
		A[j]=A[j+1];
		A[j+1]=temp;
	}
	bubble_sort(A,i,j+1,n);//0 4
	bubble_sort(A,i+1,0,n);//1 0
}
int main(){
	int n;
	scanf("%d", &n);
	int A[n];
	for(int i=0;i<n;i++) scanf("%d", &A[i]);
	int i=0,j=0;
	bubble_sort(A,i,j,n);
	for(int i=0;i<n;i++) printf("%d ", A[i]);
}