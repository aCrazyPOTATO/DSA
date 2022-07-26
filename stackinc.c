#include<stdio.h>
#include<stdlib.h>
#define Lim 7

int arr[Lim];
int end =-1;

void push(int d){
	if (end == Lim-1){
		printf("Stack is Full");
		return;
	}
	else {
		end =end+1;
		arr[end]=d;
	}
}
int pop(){
	int d;
	if (end==-1){
		printf("Stack is Null");
		exit(1);
	}
	else {
		d=arr[end];
		end=end-1;
		return d;
		
	}
}
void dis(){
	int j;
	if(end == -1){
		printf("Stack is Null");
		exit(1);
	}
	for(j=end;j>=0;j--){
		printf("%d \n", arr[j]);
	}
}
int main(){
	int x;
	push(11);
	push(22);
	push(33);
	push(44);
	push(55);
	push(66);
	push(77);
	x=pop();
	dis();
	return 0;
}
