#include<stdio.h>
#include<stdlib.h>

struct node{
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


void count(struct node *head){
	int count = 0;
	if(head == NULL){
		printf("List is empty.");
	}
	struct node *ptr = NULL;
	ptr = head;
	while(ptr != NULL){
	
		count++;
		ptr = ptr->next;
	}
	printf("The total elements are: %d \n", count);
}
 
struct node* insertAtBeg(struct node* head, int d){
	struct node *ptr = malloc(sizeof(struct node));
	
	ptr->data = d;
	ptr->next = NULL;
	
	ptr->next = head;
	head = ptr;
	return head;
	
}

void insertAtEnd(struct node* head, int d){
	
	struct node *ptr, *temp;
	ptr = head;
	
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = d;
	temp->next = NULL;
	
	while(ptr->next != NULL){
		ptr = ptr->next;	
	}
	ptr->next = temp;
	
}


void insertAtPosition(struct node* head, int d, int p){
	
	struct node *ptr = head;
	
	struct node *temp = malloc(sizeof(struct node));
	temp->data = d;
	temp->next = NULL;
	
	p--;
	while(p != 1){
		ptr = ptr->next;
		p--;
	}
	
	temp->next = ptr->next;
	ptr->next = temp;
}

int main(){
	struct node *head = NULL;
	
	head = (struct node *)malloc(sizeof(struct node));
	head->data = 25;
	head->next = NULL;
	
	struct node *current = malloc(sizeof(struct node));
	current->data = 30;
	current->next = NULL;
	head->next = current;
		
	current = malloc(sizeof(struct node));
	current->data = 10;
	current->next = NULL;
	head->next->next = current;
	
	
	
	int data = 19;
	head = insertAtBeg(head, data);
	
	int data1 = 100;
	insertAtEnd(head, data1);
	
	int data2 = 999, position = 2;
	insertAtPosition(head, data2, position);
	
	print(head); // the reason that data 19 is not printed is that i have called insertAtBeg
				//  below print and count function 
	count(head);
		
	return 0;
}
