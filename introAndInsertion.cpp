#include<iostream>
#include<vector>

using namespace std;

class Heap{
    vector<int> v;
    bool minHeap; // since we will be using the same class for max and min heap
    bool compare(int a, int b){
        if(minHeap){
            return a < b;
        }
        else{
            return a > b;
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

        while(idx > 1 && compare(v[idx], v[parent])){
            swap(v[idx], v[parent]);
            idx = parent;
            parent /= 2;
        }
    }
};

int main(){

}