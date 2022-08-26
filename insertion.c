#include<stdio.h>

void swap(int *jp, int *jpp){
	int temp = *jp;
	*jp = *jpp;
	*jpp = temp;
}

void insertionSort(int array[], int n){
	int i,j,temp;
	
	for(i=1; i<n; i++){
		temp = array[i];
		j=i-1;
		while(j>0 && array[j]>temp){
			array[j+1] = array[j];
			j--;
		}
	array[j+1]= temp;	
}

void print(int array[], int n){
	int i;
	for(i=0; i<n; i++){
		printf("%d ",array[i] );
	}
}

int main(){
	int array[100], i, j, n;
	printf("Enter total number: ");
	scanf("%d", &n);
	
	for(i=0; i<n; i++){
		printf("Enter %d st/nd/rd/th element: ", i+1);
		scanf("%d", &array[i]);
	}
	
	insertionSort(array, n);
	printf("After sorting: ");
	print(array, n);
	return 0;
}
