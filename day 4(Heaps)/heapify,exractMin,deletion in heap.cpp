/*****question is done on GFG!! link(https://practice.geeksforgeeks.org/problems/operations-on-binary-min-heap/1#)*******/

// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Structure for Min Heap
struct MinHeap {
    int *harr;
    int capacity;
    int heap_size;

    // Constructor for Min Heap
    MinHeap(int c) {
        heap_size = 0;
        capacity = c;
        harr = new int[c];
    }

    ~MinHeap() { delete[] harr; }

    int parent(int i) { return (i - 1) / 2; }

    int left(int i) { return (2 * i + 1); }

    int right(int i) { return (2 * i + 2); }

    void MinHeapify(int); // Implemented in user editor
    int extractMin();
    void decreaseKey(int i, int new_val);
    void deleteKey(int i);
    void insertKey(int k);
};

// Position this line where user code will be pasted.

// Driver code
int main() {
    int t;
    cin >> t;

    while (t--) {
        ll a;
        cin >> a;
        MinHeap h(a);
        for (ll i = 0; i < a; i++) {
            int c;
            int n;
            cin >> c;
            if (c == 1) {
                cin >> n;

                h.insertKey(n);
            }
            if (c == 2) {
                cin >> n;
                h.deleteKey(n);
            }
            if (c == 3) {
                cout << h.extractMin() << " ";
            }
        }
        cout << endl;
        // delete h.harr;
        h.harr = NULL;
    }
    return 0;
}
// } Driver Code Ends


/*The structure of the class is
struct MinHeap
{
    int *harr;
    int capacity, heap_size;
    MinHeap(int cap) {heap_size = 0; capacity = cap; harr = new int[cap];}
    int extractMin();
    void deleteKey(int i);
    void insertKey(int k);
    int parent(int i);
    int left(int i);
    int right(int i);
};*/

// You need to write code for below three functions
void swap(int *p,int *q)
{
    int temp;
    temp=*p;
    *p=*q;
    *q=temp;
}
void MinHeap::MinHeapify(int i)
{
    int leftNode = left(i);
    int rightNode = right(i);
    int smallest=i;
    
    if(leftNode < heap_size && harr[leftNode]<harr[i])
    smallest=leftNode;
    if(rightNode < heap_size && harr[rightNode]<harr[smallest])
    smallest=rightNode;
    
    if(smallest!=i)
    {
        swap(&harr[smallest],&harr[i]);
        MinHeapify(smallest);
    }
}

/* Removes min element from min heap and returns it */
int MinHeap::extractMin() {
    // Your code here
    if(heap_size<=0)
    return -1;
    if(heap_size==1)
    {
        heap_size--;
        return harr[0];
    }
    // swap(harr[0],harr[heap_size-1]);
    int temp=harr[0];
     harr[0] = harr[heap_size-1]; 
    heap_size--;
    MinHeapify(0);
    return temp;
}

/* Removes element from position x in the min heap  */
void MinHeap::deleteKey(int i) {
    // Your code here
    if(i>heap_size-1)
    return ;
    decreaseKey(i,INT_MIN);
    extractMin(); 
}

/* Inserts an element at position x into the min heap*/
void MinHeap::insertKey(int k) {
    // Your code here
    if(heap_size==capacity)
    return ;
    heap_size++;
    harr[heap_size-1]=k;
    for(int i=heap_size-1;i!=0 && harr[parent(i)]>harr[i];)
    {
        swap(&harr[i],&harr[parent(i)]);
        i=parent(i);
    }
}

// Decrease Key operation, helps in deleting key from heap
void MinHeap::decreaseKey(int i, int new_val) {
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i]) {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}


