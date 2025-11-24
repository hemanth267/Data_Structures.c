// 87346578 count how many digits are there in a no
#include<stdio.h>
int count(int n){
	if(n==0)return n;//base case
	int sub=count(n/10);//sub problem
	int cur=sub+1;//cur sol
	
}
int main(){
	int n; 
	scanf("%d", &n);
	int ans=count(n);
	printf("%d", ans);
	
}
//87346578-->8