#include <bits/stdc++.h> 
  
using namespace std; 

void heapify(int arr[], int n, int i) 
{ 
    int largest = i;
    int l = i*2 + 1;
    int r = i*2 + 2;

    if(l < n && arr[largest] < arr[l]){
        largest = l;
    }
    if(r < n && arr[largest] < arr[r]){
        largest = r;
    }
    if(largest != i){
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
} 

void buildHeap(int arr[], int n) 
{ 
    int index = n/2 - 1;

    for(int i = index; i >= 0; i--){

        heapify(arr, n, i);
    }
} 

void printHeap(int arr[], int n) 
{ 
    cout << "Array representation of Heap is:\n"; 
  
    for (int i = 0; i < n; ++i) 
        cout << arr[i] << " "; 
    cout << "\n"; 
} 

int main() 
{ 
    // Binary Tree Representation 
    // of input array 
    // 1 
    //           /     \ 
    // 3         5 
    //      /    \     /  \ 
    // 4      6   13  10 
    //    / \    / \ 
    // 9   8  15 17 
    int arr[] = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 }; 
  
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    buildHeap(arr, n); 
  
    printHeap(arr, n); 
    // Final Heap: 
    // 17 
    //           /      \ 
    // 15         13 
    //       /    \      /  \ 
    // 9      6    5   10 
    //     / \    /  \ 
    // 4   8  3    1 
  
    return 0; 
} 