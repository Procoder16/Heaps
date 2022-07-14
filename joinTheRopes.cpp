#include<iostream>
#include<queue>
#include<vector>
using namespace std;

/*
    Problem Statement :-> Given N ropes of different sizes, we have to join the ropes. 
    The cost of joining two ropes of different sizes A and B is (A+B). Find the minimum cost to join all the ropes together.
*/

/*
    So, the algo to be followed here is:
        >> Pick the 2 smallest ropes and join them and add to the cost. Also remove these two ropes.
        >> Add the newly formed rope to the min heap.
        >> Repeat until the number of ropes is 1
*/

int join_ropes(int ropes[], int n){

    priority_queue<int, vector<int>, greater<int>> pq(ropes, ropes+n);
    int cost = 0;
    while(pq.size() > 1){
        int A = pq.top();
        pq.pop();
        int B = pq.top();
        pq.pop();

        int new_rope = A + B;

        cost+=new_rope;

        pq.push(new_rope);
    }
    return cost;
}

int main(){

    int ropes[] = {4,3,2,6};
    int n = 4;

    cout<<join_ropes(ropes, n)<<endl;

    return 0;
}