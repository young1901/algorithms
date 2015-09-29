/*
 * quick sort
 *
 * */

#include<iostream>
using namespace std;

int partition(int *s, int low, int high){
	int i;
	int p;   //pivot element index
	int firsthigh;

	int buf;

	p = high;  //use the last element as pivot element
	firsthigh = low;
	for(i=low; i<high; i++){
		if(s[i] < s[p]){
			buf = s[firsthigh];
			s[firsthigh] = s[i];
			s[i]       = buf;

			firsthigh ++;
		}
	}

	buf = s[firsthigh];
	s[firsthigh] = s[p];
	s[p] = buf;

	return firsthigh;

}

void quicksort(int *s, int low, int high){
	int p;
	if(high > low){
		p= partition(s, low, high);
		quicksort(s, low, p-1);
		quicksort(s, p+1, high);
	}
}

int main(int argc, char *argv[]){
	int a[] = {14, 20, 36, 10, 12, 30, 40, 44, 21, 34};

	quicksort(a, 0, 9);
	for(int i=0; i<10; i++)
		cout<<a[i]<<'\n';

	return 1;
}
