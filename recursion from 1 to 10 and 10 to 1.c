// printing 1 to 10 and 10 to 1 using only recursions
#include<stdio.h>
void fun(int n){
    if(n>10)return;
	printf("%d ", n);
	fun(n+1);
}
int main(){
	int n;
	scanf("%d", &n);
	fun(n);
}
//1--->1 2 3 4 5 6 7 8 9 10
//recursion time complicity and space complicity is--->o(n)
//--------
#include <stdio.h>
#include<math.h>
void Fun(int n){ // 9
    //base case
    if(n == 0)return; // 9 == 0
    printf("%d ",n); // 10 , 9
    //recursive call -> which is working towards base case
    Fun(n-1); // 8
}
//backtracking
int main(){
	int n;
	scanf("%d", &n);
	Fun(n);
}
//10-->10 9 8 7 6 5 4 3 2 1
