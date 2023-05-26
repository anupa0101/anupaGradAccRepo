#include<iostream>
#include<conio.h>
#include<math.h>
//heap is a tree based data structure that is a COMPLETE BINARY TREE-( all levels filled - except lower levels which should be filled from left to right)

//types of heaps
//1. Max heap- value at the root node must be the greatest compared to all children. Must be recursively true for all subtrees 

//          45
//    33         40
// 18    12                 all top levels filled and leaf nodes are filled from left to right

//2. Min heap- value at the root node must be the smallest compared to all children. Must be recursively true for all subtrees

//          4
//    33         40
// 34    39    90           all top levels filled and leaf nodes are filled from left to right


//Applications 
//1. heap sort  2. For graph algorithms like prim's minimum spanning tree and dijkstras shortest path
//3. Implementing priority queues


//complexities

//1.Getmin in min heap and getmax in mmax heap is o(1)
//2. extractmin or extractmax - deletes it. is log(n) as heapify needs to be called to fix the treee
//3. insert and delte is log(n)
//4. heapify fix the max heap or min heap 

//HEAPSORT HAS nlogn time complexity. does logn tasks(exttractmin) n times.

//here implementation as arrays is much better.

// A[(i-1)/2]= returns parent node
// A[(2*1)+1]= returns left child node
// A[(2*1)+2]= returns right child node
using namespace std;

// A utility function to swap two elements
void swap(int & x, int & y) {
  int temp = x;
  x = y;
  y = temp;
}

class MinHeap {
  public:
    int * harr; // pointer to array of elements in heap
  int capacity; // maximum possible size of min heap
  int heap_size; // Current number of elements in min heap

  MinHeap(int cap) { //initalizes minheap object with an array of given capacity
    heap_size = 0;// current number of elements is zero
    capacity = cap;
    harr = new int[cap];//dynnamic array
  }
  int parent(int i) { //returns the parent node index
    return (i - 1) / 2;
  }

  int left(int i) {  //returns the left node index
    return (2 * i + 1);
  }

  int right(int i) {  //returns the right node index
    return (2 * i + 2);
  }

  int getMin() {  //returns the root node value
    return harr[0];
  }

  void insertKey(int k) {
    if (heap_size == capacity) {
      cout << "\nOverflow: Could not insert Key\n";
      return;
    }

    // First insert the new key at the end
    heap_size++;
    int i = heap_size - 1;// append to the end then check
    harr[i] = k;

    // Fix the min heap property if it is violated
    while (i != 0 && harr[parent(i)] > harr[i]) {
      swap(harr[i], harr[parent(i)]); //swap parent and child if min heap property is violated
      i = parent(i);
    }
  }
  void decreaseKey(int i, int new_val) {
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i]) { //bring to the top when smaller
      swap(  harr[i], harr[parent(i)]);
      i = parent(i);
    }
  }
  // This function deletes key at index i. It first reduced value to minus
  // infinite, then calls extractMin()
  void deleteKey(int i) {
    decreaseKey(i, INT_MIN);// first make the node to int_min. then it moves to the root node
    extractMin();//removes the int_min that moves to the root, extract min has heapify
  }
  void linearSearch(int val) {
    for (int i = 0; i < heap_size; i++) {
      if (harr[i] == val) {
        cout << "Value Found!";
        return;
      }
    }
    cout << "Value NOT Found!";
  }

  // Method to remove minimum element (or root) from min heap
  int extractMin() {
    if (heap_size <= 0)//if empty return max integer
      return INT_MAX;
    if (heap_size == 1) {
      heap_size--;
      return harr[0];// return value of root
    }

    // Store the minimum value, and remove it from heap
    int root = harr[0];// store the root to return later
    harr[0] = harr[heap_size - 1];//assign the last element of the array to root for now
    heap_size--;//reduce heap size
    MinHeapify(0);//heapify 0 is the index of the root node

    return root;
  }

  // A recursive method to heapify a subtree with the root at given index
  // This method assumes that the subtrees are already heapified
  void MinHeapify(int i) {
    int l = left(i);  //returns left child index
    int r = right(i);//returns right child index
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])// 
      smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
      smallest = r;
    if (smallest != i) {
      swap( harr[i], harr[smallest]);
      MinHeapify(smallest);//recursively call 
    }
  }

  void printArray() {
    for (int i = 0; i < heap_size; i++)
      cout << harr[i] << " ";
    cout << endl;
  }
  int height() {
    return ceil(log2(heap_size + 1)) - 1;
  }



  void heapsort(){

//assume already heapified 
    int *sort_arr= new int[capacity];
    for(int i=0;i<capacity;i++){

        sort_arr[i]=extractMin();//continiously extract min. it has heapify inside

    }
  }

};

int main(){
 




    return 0;
}
