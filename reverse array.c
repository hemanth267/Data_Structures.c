//reverse an array using recursion

#include<stdio.h>
void rev(int arr[],int i,int j){
	if(i>=j) return ;
	int temp=arr[j];
	arr[j]=arr[i];
	arr[i]=temp;
	rev(arr,i+1,j-1);
}
int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	rev(arr,0,n-1);
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
}
//5
//5 4 3 2 1-->1 2 3 4 5