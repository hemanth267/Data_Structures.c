#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
};
struct Node *head=NULL;
struct Node *tail=NULL;
struct Node *Create_A_Node(int val){
	struct Node *newnode;
	newnode=(struct Node*)malloc(sizeof(struct Node));
	newnode->data=val;
	newnode->next=NULL;
	return newnode;
}
void Insert_to_Linkedlist(int val){
	if(head==NULL){
		head=Create_A_Node(val);
		tail=head;	
	}
	else{
		tail->next=Create_A_Node(val);
		tail=tail->next;
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int val;
		scanf("%d",&val);
		Insert_to_Linkedlist(val);
	}
	while(head!=NULL){
		printf("%d\n",head->data);
		head=head->next;
	}
}
/*5
10 20 30 40 50
10
20
30
40
50*/
