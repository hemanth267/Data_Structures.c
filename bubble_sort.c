// 4
// 25 24 23 22---> 22 23 24 25
#include<stdio.h>
void bubble_sort(int A[],int n){
	for(int i=0;i<n;i++){//Each iteration represents one pass through the array to "bubble up" the largest unsorted element to the correct position at the end of the array.
		for(int j=0;j<n-i-1;j++){//elements move to the end with each pass of the outer loop, the range of the inner loop shrinks (n - i - 1), because the elements after n - i - 1 are already sorted.
			if(A[j]>A[j+1]){
				int temp=A[j];
				A[j]=A[j+1];
				A[j+1]=temp;// totally The swapping process is done using a temporary variable (temp). This ensures that the larger element "bubbles" up to the end of the array during each iteration of the inner
				                //loop
			}
		}
	}
}
int main(){
	int n;
	scanf("%d", &n);
	int A[n];
	for(int i=0;i<n;i++) scanf("%d", &A[i]);
	bubble_sort(A,n);
	for(int i=0;i<n;i++) printf("%d ", A[i]);
}
//bubble sort is used as to adapted to detect whether a list is already sorted.