//update value in a binary minHeap
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
	void update(int key,int index)
	{
		arr[index-1]=key;
		for(int i=index-1;i!=0 && arr[parent(i)]>arr[i];)
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
	int index,key;
	cin>>index>>key;
	h.update(key,index);
	//display
	h.display();
	return 0;
}
