#include <stdio.h>
#include <string.h>
struct human{
	char name[20];
	int age;
};
int main(){
	struct human h[3] = {{"hemanth",18},{"brock",19},{"ash",17}};
	for (int i=0;i<2;i++){
		for (int j=0;j<2;j++){
			int ans = strcmp(h[j].name,h[j+1].name);
			char temp[20];
			int temp1;
			if (ans==1){
				strcpy(temp,h[j].name);
				temp1 = h[j].age;
				strcpy(h[j].name,h[j+1].name);
				h[j].age = h[j+1].age;
				strcpy(h[j+1].name,temp);
				h[j+1].age = temp1;
			}
		}
	}
	for (int i=0;i<3;i++) printf("%s %d\n",h[i].name,h[i].age);
}
//ash 17
//brock 19
//hemanth 18