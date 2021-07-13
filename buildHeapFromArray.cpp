#include<iostream>
#include<vector>
using namespace std;

/*
    The approach is very simple:
        >> We will be starting from the first child and not the root itself as it would not have any parent.
        >> At each index we will run a while loop upwards(if we visualise the tree) and backwards(if we visualise the vector)
        >> We will check if idx is greater than 1 because if it becomes 1, then its parent would be 0
        >> Here, since we are dmaking the max heap, we will check whether the parent is smaller than the child, if yes, swap and continue upwards.
*/


void printHeap(vector<int> v){
    for(auto i : v){
        cout<<i<<" ";
    }
}

void buildHeap(vector<int> &v){

    for(int i = 2; i < v.size(); i++){ // the reason for i = 2 is mentioned above
        int idx = i;
        int parent = idx/2;
        while(idx > 1 && v[idx] > v[parent]){ // the reason for idx > 1 is mentioned above... also v[idx] > v[parent] for max heap
            swap(v[idx], v[parent]);
            idx = parent;
            parent/=2;
        }
    }
}

int main(){

    vector<int> v = {-1, 10, 20, 5, 6, 1, 8, 9, 4};
    cout<<"THE GIVEN VECTOR:";
    printHeap(v);
    cout<<endl;
    buildHeap(v);
    cout<<"THE BUILT HEAP:";
    printHeap(v);  
    return 0;
}
