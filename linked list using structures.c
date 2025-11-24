#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*next;
};
int main(){
	struct node*head;
	head=(struct node*)malloc(sizeof(struct node));
	head->data=10;
	head->next=NULL;
	struct node*first;
	first=(struct node*)malloc(sizeof(struct node));
	first->data=20;
	first->next=NULL;
	head->next=first;
	while(head!=NULL){
		printf("%d\n",head->data);
		head=head->next;
	}
}
//10
//20