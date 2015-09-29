/*
 * Heap Sort
 * */
#include <iostream>

#define PQ_SIZE 1000

using namespace std;
struct priority_queue{
	int q[PQ_SIZE+1];
	int n;
};

int pq_parent(int n){
	if(n == 1) return -1;
	else return (int)n/2;
}

int pq_young_child(int n){
	return 2*n;
}

void pq_swap(priority_queue *q, int i, int j)
{
	int temp;			/* placeholder */

	temp = q->q[i];
	q->q[i] = q->q[j];
	q->q[j] = temp;
}

void bubble_up(priority_queue *q, int p){
	if(pq_parent(p) == -1) return;

	if(q->q[ pq_parent(p) ] > q->q[p]){
		pq_swap(q, p, pq_parent(p));
		bubble_up(q, pq_parent(p));
	}
}

void pq_insert(priority_queue *q, int x){
	if(q->n >= PQ_SIZE)
		cout<<"warning: priority queue overflow insert x = "<<x<< "\n";
	else{
		q->n = q->n + 1;
		q->q[q->n] = x;
		bubble_up(q, q->n);
	}
}

void pq_init(priority_queue *q){
	q->n = 0;
}

/*make heap by inserting new elements*/
void make_heap(priority_queue *q, int *s, int n){
	int i;

	pq_init(q);
	for(i=0; i<n; i++)
		pq_insert(q, s[i]);
}

void bubble_down(priority_queue *q, int p){
	int c;
	int i;
	int min_index;

	c = pq_young_child(p);
	min_index = p;

	for(i=0; i<=1; i++){
		if( c+i <= q->n){
			if(q->q[min_index] > q->q[c+i]) min_index = c + i;
		}
	}

	if(min_index != p){
		pq_swap(q, p, min_index);
		bubble_down(q, min_index);
	}
}

int extract_min(priority_queue *q){
	int min = -1;
	if(q->n <= 0)
		cout<<"Warning: empty priority queue. \n";
	else{
		min = q->q[1];

		q->q[1] = q->q[ q->n ];
		q->n = q->n -1;
		bubble_down(q,1);
	}

	return min;

}

/*make heap by bubble down each element*/
void makeheap(priority_queue *q, int *s, int n){
	int i;
	q->n = n;
	for(i=0; i<n; i++) q->q[i+1] = s[i];

	for(i=q->n; i>=1; i--) bubble_down(q, i);

}

void heapsort(int *s,int n){
	int i;
	priority_queue q;

	makeheap(&q, s, n);

	for(i=0; i<n; i++) s[i]=extract_min(&q);
}

int main(int argc, char *argv[]){
	int a[] = {14, 20, 36, 10, 12, 30, 40, 44, 21, 34};
	int n=9;

	heapsort(a, n);
	for(int i=0; i<n; i++) cout<<a[i]<< '\n';

}
