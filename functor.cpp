#include<iostream>

using namespace std;

class Fun{
    public:
        // void operator()(){
        //     cout<<"Having fun with functor or functional objects!!!";
        // }
        void operator()(string s){
            cout<<"Having fun with "<<s;
        }
};

int main(){

    Fun f;
    //f();
    f("C++");

    // So here f is an object which is also acting as a functional object. We can also pass some parameters if we wish to.
    // This is called a functor.
    // Basically this concept is used to to define the comparators for the priority queue. 

    return 0;
}