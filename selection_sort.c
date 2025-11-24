#include<stdio.h>
#include<stdint.h>
void selection_sort(int A[],int n){
	int b[n];
	for(int i=0;i<n;i++){//We iterate through the array with index i (0 to n-2), treating the elements before i as sorted and elements from i onward as unsorted.
		int min=A[0],min_ind=0;
		for(int j=1;j<n;j++){
			if(min>A[j]){
				min=A[j];
				min_ind=j;
			}
		}
		b[i]=min;
		A[min_ind]=WINT_MAX;// WINT_MAX -->stdint.h
	}
	for(int i=0;i<n;i++) printf("%d ", b[i]);
}
int main(){
	int n;
	scanf("%d", &n);
	int A[n];
	for(int i=0;i<n;i++) scanf("%d", &A[i]);
	selection_sort(A,n);
}
//time complicity o(n^2) and space is o(n)
//4
//4 3 2 1--->1 2 3 4
//Selection Sort is a simple sorting algorithm. It selects the smallest element from the unsorted part of the array and swaps it with the first unsorted element.