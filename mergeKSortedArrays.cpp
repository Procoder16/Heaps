#include<bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> node; // creating our custom pair to store the value, its row number, its column number

vector<int> mergeKSortedArrays(vector<vector<int>> arr){
    vector<int> result;

    priority_queue<node, vector<node>, greater<node>> pq; // min heap

    for(int i = 0; i < arr.size(); i++){  // pushing the first nodes of all the rows of the vector
        pq.push({arr[i][0], {i,0}}); // it denotes the -> the first element of each row, the pair of row number and column number(initially 0) 
    }

    // remove the elements one by one from the queue and add it your result vector 
    while(!pq.empty()){
        node current = pq.top();
        pq.pop();
        int element = current.first;
        int row = current.second.first; // row in which the element is present
        int col = current.second.second; // col in which the element is present

        result.push_back(element);

        // now check whether the next element in that column is present or not and then push it to the heap
        if(col + 1 < arr[row].size()){
            pq.push({arr[row][col+1], {row, col+1}});
        }
    }
    return result;
}

int main(){

    vector<vector<int>> arr = {{2,6,12,15}, {1,3,14,10}, {3,5,8,10}};

    vector<int> output = mergeKSortedArrays(arr);

    cout<<"MERGED ARRAY:";
    for(int i = 0; i < output.size(); i++){
        cout<<output[i]<<" ";
    }

    return 0;
}