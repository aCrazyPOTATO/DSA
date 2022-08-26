#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

char stack[MAX];
char infix[MAX], postfix[MAX];
int top = -1;

void push(char); // its void type
char pop(); // pop is char becoz of character not integer
int isEmpty(); // you guys know it
void inToPost(); // this too
int space(char); 
void print(); // this too
int precedence(char); // this too

int main(){
	
  	printf("Enter the infix expression: "); // asks user for infix expression
    gets(infix);
    
    inToPost();
    print();
    
    return 0;
	}

void inToPost(){
    int i,j=0;
    char symbol,next;
    for(i=0;i<strlen(infix); i++){ // till the length of infix
        symbol = infix[i]; // passing expression one by one in symbol
		
		if(!space(symbol)) // check white space in expression : don't know white space?: google it
		{
        switch(symbol){
            case '(': 
                push(symbol);
                break;
            
            case ')': // while checking right we must evaluate expression betn ( and )
             while((next=pop()) != '(')  // checking expression between small parenthesis
             	postfix[j++] = next;
             	break;
             	
            case '^':
            case '/':
            case '*':
            case '+':
            case '-':
            	while(!isEmpty() && precedence(stack[top]) >= precedence(symbol)) 
				// loop to check empty stack and priority of operators in stack and current symbol operator
            	    postfix[j++] = pop();
            	push(symbol);
			    break;           
            
            default: // for operands
                postfix[j++] =  symbol;	               
        	}
		}
	}		
	
	while(!isEmpty()) // to check remaining operators in stack, if found pop and store in postfix
		postfix[j++] = pop();
	postfix[j++]= '\0';
	
}

int space(char c){
	if(c == ' ' || c == '\t') // check blank space and tab
		return 1;
	else
		return 0;
}

int precedence(char symbol){
	switch(symbol){
			case '^':
				return 3;
            case '/':
            case '*':
            	return 2;
            case '+':
            case '-':
            	return 1;
            default: 
            	return 0;
	}
}

void print(){
	int i = 0;
	printf("the equivalent postfix expression is: ");
	while(postfix[i]){
		printf("%c", postfix[i++]); // printing postfix
	 }
	printf("\n"); 
}

void push(char c){
	if(top == MAX -1){
		printf("Stack Overflow."); // remember this code and overflow meaning by going back 4 days ago
		return;
	}
	top++; // you know this too think 2 min or less
	stack[top] = c;
}

char pop(){
	char c;
	if(top == -1){
		printf("Stack Underflow.\n");
		exit(1);
	}
	c = stack[top]; /// what is c? == think 4 days back . c means data . we did it then just see old program too
	top = top - 1;
	return c;
}

int isEmpty()
{
	if(top == -1)
		return 1;
	else 
		return 0;
}




