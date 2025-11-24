#include<stdio.h>
void insertion_sort(int A[],int n){
	//insert the 1st element form unsorted to sorted array
	//how to separate 1st half and 2nd half
	//[0 1 2 3 ...n]
	//i-->0 to i-1 sorted and i to n is unsorted
	//pick 1st element from unsorted i
	//0 1 2    3
	//1 5 5    7
	//j        i
	//temp=3
	for(int i=1;i<n;i++){
		//i 1st element in unsorted
		int j=i-1;//last element of sorted array
		int temp=A[i];
		while(j>=0 && A[j]>temp){
			A[j+1]=A[j];
			j--;//Since j-- moves j back when shifting elements, the correct insertion point is j + 1.
		}
		A[j+1]=temp;
	}
}
int main(){
	int n;
	scanf("%d", &n);
	int A[n];
	for(int i=0;i<n;i++){
		scanf("%d", &A[i]);
	}
	insertion_sort(A,n);
	for(int i=0;i<n;i++){
		printf("%d ",A[i]);
	}
}
// 4
// 27 25 23 22 ---> 22 23 25 27
//time complicity is o(n^2) and space is o(1) for buuble sort and insertion sort
// insertion sort is used as Nearly sorted data: Performs well when the array is almost sorted.