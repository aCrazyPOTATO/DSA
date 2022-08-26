#include<stdio.h>

void swap(int *jp, int *jpp){
	int temp = *jp;
	*jp = *jpp;
	*jpp = temp;
}

void quickSort(int array[], int l, int r){
	int p = l;
	int i = l;
	int j = r;
	
	if(l<r){
		while(array[i]<=array[p] && i<r){
			i++;
		}
		while(array[j]>array[p]){
			j--;
		}
		
		if(i<j){
			swap(&array[i], &array[j]);
		}
		swap(&array[p], &array[j]);
		quickSort(array, l, j-1);
		quickSort(array, j+1, r);
	}
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
	
	quickSort(array, 0, n-1);
	printf("After sorting: ");
	print(array, n);
	return 0;
}
