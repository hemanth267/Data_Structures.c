#include<stdio.h>
int Fact(int n){
    //base case 
    if(n == 1)return n;
    
    //finding sub problem
    int sub = Fact(n-1); // n = 2 sub = 1
    
    //with the help of sub problem find current sloution
    int cur = sub * n; // 1*2
    return cur;//2
}
int main(){
	int n;
	scanf("%d", &n);
	int ans=Fact(n);//current solution
	printf("%d", ans);
}
// 5-->120
