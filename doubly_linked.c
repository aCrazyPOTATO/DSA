#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node *prev;
	int data;
	struct node *next;
};

void print(struct node *head){
	if(head == NULL){
		printf("List is empty.");
	}	
	struct node *ptr = NULL;
	ptr = head;
	printf("The elements are: ");
	while(ptr != NULL){
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}

struct node* addData(struct node *head, int d){
	struct node *temp = malloc(sizeof(struct node));
	temp->prev = NULL;
	temp->data = d;
	temp->next = NULL;
	
	head = temp;
	return head;
}

struct node* addAtBeg(struct node *head, int d){
	struct node *temp = malloc(sizeof(struct node));
	temp->prev = NULL;
	temp->data = d;
	temp->next = NULL;
	
	temp->next = head;
	head->prev = temp;
	
	head = temp;
	return head;
}

struct node* addAtEnd(struct node *head, int d){
	struct node *temp , *ptr;
	temp = malloc(sizeof(struct node));
	
	temp->prev = NULL;
	temp->data = d;
	temp->next = NULL;
	
	ptr = head;
	while(ptr->next != NULL){
		ptr = ptr->next;
	}
	ptr->next = temp;
	temp->prev = ptr;
	return head;

}

struct node* addAtPos(struct node *head, int d, int p){
	
	struct node *ptr = NULL;
	struct node *temp = head;
	struct node *link = head;
	
	ptr = addData(head, d);
	
	while(p != 1){
		temp = temp->next;
		p--;
	}
	if(temp->next == NULL){
		temp->next = ptr;
		ptr->prev = temp;
	}else{
		link->next = ptr;
		ptr->prev = link;
		ptr->next = temp;
		temp->prev = ptr;
	}
	return head;
}

 struct node* delAtBeg(struct node *head){
 	if(head == NULL){
 		printf("List is empty.");
 	}
 	struct node *temp=head;
 	head=head->next;
 	free(temp);
 	temp=NULL;
 	head->prev=NULL;
 	return head;
 }

 struct node* delAtEnd(struct node *head){
 	struct node *ptr=head;
	while(ptr->next != NULL){
		ptr = ptr->next;
	}
	struct node *temp; // added new pointer
	temp = ptr->prev;
	temp->next = NULL;
	free(ptr);
	return head;
 }
 
 struct node* delAtPos(struct node *head, int p){
 	struct node *temp = head;
 	if(p==1){
 		head = delAtBeg(head);
 		return head;
	 }
	while(p>1){
		temp = temp->next;
		p--;	
	}
	if(temp->next == NULL){
		head = delAtEnd(head);
	}
	else{
		struct node *ptr;
		ptr = temp->prev;
		ptr->next = temp->next;
		temp->next->prev = ptr;
		free(temp);
		temp = NULL;
	}
	return head;
 }
 


int main(){
	struct node *head = NULL;
	head = malloc(sizeof(struct node));

	head = addData(head, 30);
	head = addAtBeg(head, 40);
	head = addAtEnd(head, 80);
	int position = 2;
	head = addAtPos(head, 120, position);
	
	head = delAtBeg(head);
	head= delAtEnd(head);
	int position1 = 1;
	head = delAtPos(head, position1);
	
	
	print(head);
	return 0;
}
