//in radix sort elements are not swapped they sagregated and erearranged
#include<stdio.h>
void radix_sort(int arr[],int n){
	int bucket[10][n],max=arr[0]; //declaration of bucket 2d array
	for(int i=1;i<n;i++){  //to find out max element
		if(max<arr[i]) max=arr[i];
	}
	int size_of_max=log10(max)+1,e=1; //find out the size of maximum element in the array
	while(size_of_max--){   //run the loop for number of digits in maximum element
		int cnt[10]={0}; //indicates the number of elements in buckets and position 
		for(int i=0;i<n;i++){ //segregation of array elements into buckets
			int pos=(arr[i]/e)%10; //using a integer valiable to know in which bucket the element has to be placed
			bucket[pos][cnt[pos]]=arr[i]; //arranging elements in array to buckets
			cnt[pos]++; //increasing cnt as to know how many elements are present in bucket 
		}
		int k=0; //variable used to place elements in bucket to the arrray
		for(int i=0;i<10;i++){ //upto rows of bucket 2d array
			for(int j=0;j<cnt[i];j++){ //upto last column in the array
				arr[k]=bucket[i][j];//rearranging elements into array from bucket 
				k++;
			}
		}
		e*=10; //increment of e to obtain unit digit in first pass and ten's digit in the second pass
	}
}
int main(){
	int n;
	scanf("%d",&n); //read size of array
	int i,A[n]; //declare array of size n
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);//read n elements
	}
	radix_sort(A,n); //caling radixsort function
	for(int i=0;i<n;i++){
		printf("%d ",A[i]);
	}
}//5
//170 45 75 90 802-->45 75 90 170 802

