#include<iostream>
#include<queue>

using namespace std;

int main(){

    priority_queue<int> pq; // for max heap/priority queue
    //priority_queue<int, vector<int>, greater<int>> pq;  -> for min heap/priority queue 

    int n;
    cin>>n;

    for(int i = 0; i < n; i++){
        int no;
        cin>>no;
        pq.push(no);    // O(logN)
    }

    while(!pq.empty()){
        cout<<pq.top()<<" "; //O(1)
        pq.pop();  // O(logN)
    }

    return 0;
}