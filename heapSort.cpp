#include<iostream>
#include<vector>
using namespace std;

bool minHeap = false;
bool compare(int a, int b){  // comparator fucntion
    if(minHeap){
        return a < b;
    }
    else{
        return a > b;
    }
}

void heapify(vector<int> &v, int idx, int size){ // taking the vector input also as we will be changing the vector 

    int min_idx = idx;
    int last = size - 1;

    int left = 2*idx;  // first child
    int right = 2*idx + 1; // second child

    if(left <= last && compare(v[left], v[min_idx])){  // comparing left child with the min_idx which is initially the idx itself 
        min_idx = left;
    }
    if(right <= last && compare(v[right], v[min_idx])){ // comparing the right child with the min_idx(if changed)
        min_idx = right;
    }

    if(min_idx != idx){ // the swapping takes place only if the min_idx is found in the children... this is also thr base case
        swap(v[min_idx], v[idx]);
        heapify(v,min_idx, size);
    } 
}


void buildHeap(vector<int> & v){
    for(int i = (v.size()-1)/2; i>=1; i--){ 
       heapify(v, i, v.size());
    }
}

void heapsort(vector<int> &arr){
    buildHeap(arr);

    int n = arr.size();

    while(n > 1){
        swap(arr[1], arr[n-1]);
        n--;
        heapify(arr, 1, n);
    }
}

void printHeap(vector<int> v){
    for(int i = 1; i < v.size(); i++){
        cout<<v[i]<<" ";
    }
}

int main(){

    vector<int> v;
    v.push_back(-1);

    int n;
    cin>>n;

    for(int i = 0; i < n; i++){
        int temp;
        cin>> temp;
        v.push_back(temp);
    }

    heapsort(v);

    printHeap(v);

    return 0;
}