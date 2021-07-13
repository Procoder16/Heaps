#include<iostream>
#include<vector>
using namespace std;

void printHeap(vector<int> v){
    for(auto i : v){
        cout<<i<<" ";
    }
}

void buildHeap(vector<int> &v){

    for(int i = 2; i < v.size(); i++){
        int idx = i;
        int parent = idx/2;
        while(idx > 1 && v[idx] > v[parent]){
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
