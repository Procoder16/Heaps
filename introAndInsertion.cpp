#include<iostream>

using namespace std;

class heap{
    public:
    int arr[100];
    int size;

    heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int val){
        size++;
        int index = size;
        arr[index] = val;

        while(index > 1){
            int parent = index / 2;

            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }else{
                return;
            }
        }
    }

    void deleteFromHeap(){
        if(size == 0){
            cout<<"NOTHING TO DELETE!";
        }

        arr[1] = arr[size];
        size--;

        int i = 1;
        while(i < size){
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;

            if(leftIndex < size && arr[i] < arr[leftIndex]){
                swap(arr[i], arr[leftIndex]);
            }else if(rightIndex < size && arr[i] < arr[rightIndex]){
                swap(arr[i], arr[rightIndex]);
            }else{
                return;
            }
        }
    }

    void print(){
        for(int i = 1; i <= size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if(left < n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right < n && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

int main(){

    heap hp;
    hp.insert(55);
    hp.insert(60);
    hp.insert(40);
    hp.insert(70);

    hp.print();

    hp.deleteFromHeap();

    hp.print();

    //Testing heapify function

    int arr[] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    for(int i = n / 2; i > 0; i--){
        heapify(arr, n, i);
    }

    return 0;
}