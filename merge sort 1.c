//merge sort 1 
#include<stdio.h>
void merge(int A[],int start,int mid,int end,int n){
	int i=start;//1st part begin
	int j=mid+1;//2nd part begin
	int B[end-start+1];// Temporary array to store merged result
	int k=0;
	//beinging of merge
	while(i<=mid && j<=end){
		if(A[i]<A[j]){
		  B[k++]=A[i++];
		}else B[k++]=A[j++];
	}
	//adding the left over elements
	while(i<=mid) B[k++]=A[i++];// If any elements are left in the left half
	while(j<=end) B[k++]=A[j++];// If any elements are left in the right half
	k=0;
	//sort the elements to 'A' from B
	for(int i=start;i<=end;i++){ // Copy the sorted elements back to original array A[]
		A[i]=B[k++];
	}
}
void mergesort(int A[],int n,int start,int end){
	//base case
    if(start>=end) return;
    int mid=(start+end)/2;
    //break and perform recursion call
    mergesort(A,n,start,mid);
    mergesort(A,n,mid+1,end);
	//function call of merge sort
	merge(A,start,mid,end,n);
}
int main(){
	int n;
	scanf("%d", &n);
	int A[n];
	for(int i=0;i<n;i++) scanf("%d", &A[i]);
	mergesort(A,n,0,n-1);
	for(int i=0;i<n;i++) printf("%d ", A[i]);
}
//6
//5 4 1 2 6 3--> 1 2 3 4 5 6
//merge sort-->Useful for sorting huge datasets that don't fit in memory, as it can be implemented in a way that sorts data from disk efficiently.
//o(nlogn),o(n) time and space complicity of merge sort