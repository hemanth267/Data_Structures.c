// sub sequence count by taking key using recursion
#include<stdio.h>
int printsubseq(int A[], int idx, int n, int key, int sum){
	//base case
	if(idx>=n){
	 if(sum==key) return 1;
	 else return 0;
	}
	if(sum==key) return 1;
	//pick call
	int left=0,right=0;
	left+=printsubseq(A,idx+1,n,key,sum+A[idx]);
	//non pick
	right+=printsubseq(A,idx+1,n,key,sum);
	return left+right;
}
int main(){
	int n;
	scanf("%d", &n);
	int A[n];
	for(int i=0;i<n;i++) scanf("%d", &A[i]);
	int key;
	scanf("%d", &key);
	int sum=0, cnt=0;
    int ans=printsubseq(A,0,n,key,sum);
	printf("%d", ans);
}
//[6
//4 6 8 1 2 3
//10]  = input
//4 =output