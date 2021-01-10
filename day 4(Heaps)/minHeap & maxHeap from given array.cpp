//insertion/creation of a binary heap data structure
#include<iostream>
using namespace std;
class heap
{
	int *arr;
	int capacity;
	int size;
	public:
		heap(int c)
		{
			size=0;
			capacity=c;
			arr = new int[c];
		}
		int left(int i){
			return 2*i+1;	
		}
			
		int right(int i) {
			return 2*i+2;	
		}
		int parent(int i) {
			return (i-1)/2;		
		}
	void insert(int val)
	{
		if(size == capacity)
		return ;
		size++;
		arr[size-1]=val;
		
		for(int i=size-1;i!=0 && arr[parent(i)]>arr[i];)
		{
			swap(arr[i],arr[parent(i)]);
			i=parent(i);
		}
	}
	void display()
	{
		for(int i=0;i<capacity;i++)
		cout<<arr[i]<<" ";
	}
	void maxHeapify(int i)
	{
		int l=left(i);
		int r=right(i);
		int large;
		
		if(l<size && arr[l]>arr[i])
		{
			large=l;
		}
		if(r<size && arr[r]>arr[large])
		{
			large=r;
		}
		
		if(i!=large)
		{
			swap(arr[large],arr[i]);
			maxHeapify(large);	
		}
	}
	void maxHeap()
	{
		for(int i=(size-2)/2;i>=0;i--)
		{
			maxHeapify(i);
		}
	}
};
int main()
{
	int n,i,element;
	cin>>n;
	heap h(n);
	for(i=0;i<n;i++)
	{
		cin>>element;
		h.insert(element);
	}
	h.maxHeap();
	//display
	h.display();
	//for min heap the similar minheapify function is called which is implemented in the previous program
	return 0;
}
