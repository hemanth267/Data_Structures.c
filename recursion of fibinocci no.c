// Recursive function to find Fibonacci numbers

#include<stdio.h>
int fib(int k){
	if(k<=1)return k;
	int sub1=fib(k-1);
	int sub2=fib(k-2);
	int cur=sub1+sub2;
	return cur;
}
int main(){
	int n;
	scanf("%d", &n);
	int ans=fib(n);
	printf("%d", ans);
}
//5-->5
//input-->5
//fib(5) = fib(4) + fib(3)
//fib(4) = fib(3) + fib(2)
//fib(3) = fib(2) + fib(1)
//fib(2) = fib(1) + fib(0)
//fib(1) = 1
//fib(0) = 0
// fib(2) = 1
//fib(3) = 2
//fib(4) = 3
//fib(5) = 5
//output-->5
