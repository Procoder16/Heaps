#include<iostream>
#include<vector>
using namespace std;

/*
    This approach solves the problem in O(N) time complexity:
        >> We will start a for loop from the first non-leaf node and go upto the root.
        >> And for each node, we will be calling the heapify function that would arrange the nodes in their correct position.
*/


void printHeap(vector<int> v){
    for(auto i : v){
        cout<<i<<" ";
    }
}

bool minHeap = false;
bool compare(int a, int b){  // comparator fucntion
        if(minHeap){
            return a < b;
        }
        else{
            return a > b;
        }
    }

void heapify(vector<int> &v, int idx){ // taking the vector input also as we will be changing the vector 

        int min_idx = idx;
        int last = v.size() - 1;

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
            heapify(v,min_idx);
        } 
    }

void buildHeapOptimised(vector<int> &v){
    for(int i = (v.size()-1)/2; i>=1; i--){
        heapify(v, i);
    }
}

int main(){

    vector<int> v = {-1, 10, 20, 5, 6, 1, 8, 9, 4};
    cout<<"THE GIVEN VECTOR:";
    printHeap(v);
    cout<<endl;
    buildHeapOptimised(v);
    cout<<"THE BUILT HEAP:";
    printHeap(v);  
    return 0;
}
