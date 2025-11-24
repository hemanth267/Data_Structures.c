//find the 1st occurence of key in array
//[1,5,8,2,13,8,11] key =8--> output -->2

#include <stdio.h>
int first_occ(int a[],int n,int k){
	if (n==0) return -1;
	if (a[0]==k) return 0;
	int sub = first_occ(a+1,n-1,k);
	if (sub== -1) return -1;
	else return sub+1;
}
int main(){
	int n;
	scanf("%d",&n);
	int a[n];
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	int key;
	scanf("%d",&key);
	int ans = first_occ(a,n,key);
	printf("%d",ans);
	return 0;
}
//5 input
//1 2 3 2 4  key =2
//1 output
