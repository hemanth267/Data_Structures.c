//merge_sort
#include <stdio.h>
merge (int a[],int n, int b[],int m,int c[],int k){
	for (int i=0,j=0,s=0;s<k;s++){
		if(i==n){
				c[s] = b[j];
				j++;
		}else if (j==m){
				c[s] = a[i];
				i++;
		}else if(a[i]<b[j]){
			c[s] = a[i];
			i++;
		}else{
			c[s] = b[j];
			j++;
		}
	}
}
int main(){
	int n,m;
	scanf("%d",&n);
	int a[n];
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	scanf("%d",&m);
	int b[m];
	for (int i=0;i<m;i++) scanf("%d",&b[i]);
	int c[m+n];
	merge(a,n,b,m,c,m+n);
	for (int i=0;i<n+m;i++) printf("%d ",c[i]);
}
//3
//1 3 5
//4
//2 4 6 8 // output = 1 2 3 4 5 6 7 8