//reverse an string using recursion
#include<stdio.h>
#include<string.h>
void revstr(char s[],int i,int j){
   if(i>=j)return;//base case
	char temp=s[i];//cur 
	s[i]=s[j];
	s[j]=temp;
	revstr(s,i+1,j-1);
}
int main(){
	char s[100];
	scanf("%s", s);
	int length=strlen(s);
	 revstr(s,0,length-1);
	printf("%s\n", s);
}
//olleh-->hello
