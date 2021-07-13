#include<iostream>
#include<vector>

using namespace std;

class Heap{
    vector<int> v;
    bool minHeap; // since we will be using the same class for max and min heap
    bool compare(int a, int b){  // comparator fucntion
        if(minHeap){
            return a < b;
        }
        else{
            return a > b;
        }
    }

    void heapify(int idx){

        int min_idx = idx;
        int last = v.size() - 1;

        int left = 2*idx;
        int right = 2*idx + 1;

        if(left <= last && compare(v[left], v[min_idx])){
            min_idx = left;
        }
        if(right <= last && compare(v[right], v[min_idx])){
            min_idx = right;
        }

        if(min_idx != idx){
            swap(v[min_idx], v[idx]);
            heapify(min_idx);
        } 
    }

    public: 
    Heap(int default_size = 10, bool type = true){  // just accepting the default parameters which get overwritten when we pass user-defined values
        v.reserve(default_size); // reserving the size of the vector until the size is not equals to 10
        v.push_back(-1); // as our array representation starts from 1st index, we are blocking the 0th index with -1
        minHeap = type; // assigning the type of the heap we are going to build
    }

    void push(int d){
        v.push_back(d);
        int idx = v.size() - 1;
        int parent = idx / 2;

        while(idx > 1 && compare(v[idx], v[parent])){ // main swap condition 
            swap(v[idx], v[parent]);
            idx = parent; // changing the idx as the idx and the parent both goes up after the swapping
            parent /= 2;
        }
    }

    int top(){
        return v[1];
    }

    void pop(){
        int last = v.size() - 1;
        swap(v[1], v[last]);
        v.pop_back();
        heapify(1);
    }

    bool empty(){
        return v.size() == 1;
    }
};

int main(){

    Heap h(6, false);
    int n;
    cin>>n;

    for(int i = 0; i < n; i++){
        int no;
        cin>>no;
        h.push(no);
    }

    while(!h.empty()){
        cout<<h.top()<<" ";
        h.pop();
    }

    return 0;
}