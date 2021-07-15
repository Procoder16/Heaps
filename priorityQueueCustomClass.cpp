#include<bits/stdc++.h>

using namespace std;

class Person{ // person class
    public:
        string name;
        int age;

        Person(){

        }
        Person(string n, int a){
            name = n;
            age = a;
        }
};

class PersonCompare{ // This is the comparator class
    public:
        bool operator()(Person A, Person B){
            return A.age < B.age;
        }
};

int main(){

    int n;
    cin>>n;

    priority_queue<Person, vector<Person>, PersonCompare> pq; // we are using a class for comparison as STL takes classes as inputs

    for(int i = 0; i < n; i++){
        string name;
        int age;
        cin>>name>>age;
        Person p(name, age);
        pq.push(p);
    }

    int k;  
    cin>>k;
    for(int i = 0; i < k; i++){  // printing the top 3 oldest people
        Person P = pq.top();
        cout<<P.name<<" "<<P.age<<endl;
        pq.pop();
    }

    return 0;
}