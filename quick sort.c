#include<stdio.h>
int partision(int A[],int key,int start,int end){
	int s = start;//starting index
	int e = end;//ending index;
	int temp;
	while(s<e){
	//use to find the index
		while(A[s]<=key){//find out which numbers are smaller or equal to given number 
			s++;
		}
		while(A[e]>key){//find out which numbers are greater than given number 
			e--;
		}
		//exchange
		if(s<e){ //during checking any smaller number is in greater side it will swap
			temp = A[s];
			A[s] = A[e];
			A[e] = temp;
		}
	}
	temp = A[e];// swap the greater number with the partision number
	A[e] = key;
	A[start] = temp;
	return e;// Return the pivot index
}
void QuickSort(int A[],int n,int start,int end){
	if(start < end){
		int p = A[start];// take the element
		p  = partision(A,p,start,end);//use to find the index of that number
		QuickSort(A,n,start,p-1);//seperate into small function and calculates
		QuickSort(A,n,p+1,end);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	int A[n],i;
	for(i=0;i<n;i++) scanf("%d",&A[i]);
	QuickSort(A,n,0,n-1);
	for(i=0;i<n;i++) printf("%d ",A[i]);
}//quick sort is used as Selects the first element as the pivot.and Calls partision() to rearrange elements. and Recursively sorts the left and right partitions.
//5
//4 2 5 1 3
//1 2 3 4 5
