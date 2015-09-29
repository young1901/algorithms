/*
 *  Merge Sort
 *
 * */
#include <iostream>
#include <queue>

using namespace std;

void merge(int *s, int low, int middle, int high){
	int i;
	std::queue <int> buf1, buf2;

	for(i=low; i<=middle; i++) buf1.push(s[i]);
	for(i=middle+1; i<=high; i++) buf2.push(s[i]);

	i = low;
	while(!(buf1.empty() || buf2.empty())){
		if(buf1.front() <= buf2.front()){
			s[i++]=buf1.front();
			buf1.pop();
		}else{
			s[i++]=buf2.front();
			buf2.pop();
		}
	}

	while(!buf1.empty()){
		s[i++] = buf1.front();
		buf1.pop();
	}

	while(!buf2.empty()){
		s[i++] = buf2.front();
		buf2.pop();
	}

}

void mergesort(int *a, int low, int high){

	int middle;

	if(low < high){
		middle = (low+high)/2;

		mergesort(a, low, middle);
		mergesort(a, middle+1, high);

		merge(a, low, middle, high);
	}

}

int main(int argc, char *argv[]){

	int a[] = {14, 20, 36, 10, 12, 30, 40, 44, 21, 34};

	mergesort(a, 0, 9);
	for(int i=0; i<10; i++)
		cout<<a[i]<<'\n';

}
