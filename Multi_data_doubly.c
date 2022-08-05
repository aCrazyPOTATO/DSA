#include<stdio.h>
#include<stdlib.h>



struct node{
	struct node *pre;
	int data;
	struct node *pro;
};

void print(struct node *head)
{
	if(head==NULL){
		printf("the list is empty:");
	}
	struct node *ptr=NULL;
	ptr=head;
	while(ptr!=NULL){
		printf("%d",ptr->data);
		ptr=ptr->pro;
		printf(" ");
	}
	
}

void addData(struct node* head, int d){
	
	struct node *ptr, *temp;
	ptr = head;
	
	temp = (struct node*)malloc(sizeof(struct node));
	temp->pre=NULL;
	temp->data = d;
	temp->pro = NULL;
	
	while(ptr->pro != NULL){
		ptr = ptr->pro;	
	}
	ptr->pro = temp;
	temp->pre=ptr;
	
}


int main(){
	struct node *head=NULL;
	head=malloc(sizeof(struct node));
	head->pre=NULL;
	head->data=22;
	head->pro=NULL;
	
	
	addData(head,33);
	addData(head,44);
	addData(head,55);
	
	print(head);
	return 0;
}