//reverse a no using recursion
#include<stdio.h>
#include<math.h>
int reverse(int n, int rev){
	if(n==0) return rev;
	rev=rev*10+n%10;
	return reverse(n/10,rev);
	
}
int main(){
	int n;
	scanf("%d", &n);
	int ans=reverse(n, 0);
	printf("%d\n", ans);

}
//4321-->1234