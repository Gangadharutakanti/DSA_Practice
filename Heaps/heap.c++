#include<iostream>
#include<limits.h>
using namespace std;
class BinaryHeap{
public:
    int capacity;
    int size;
    int k;
    int* arr;
    BinaryHeap(int cap){
        capacity=cap;
        size=0;
        k=0;
        arr=new int[capacity];
    }

    int parent(int i){
        return (i-1)/2;
    }

    int left(int i){
        return 2*i+1;
    }
    int right(int i){
        return 2*i+2;
    }
    void swap(int* x,int* y){
        int k=*x;
        *x=*y;
        *y=k;
    }
    void Insert(int x){
        if(capacity==size){
            cout<<"Heap capacity is full";
        }
        arr[size]=x;
        int k=size;
        size++;
        while(k!=0 && arr[parent(k)]>arr[k]){
            swap(&arr[parent(k)],&arr[k]);
            k=parent(k);
        }
    }

    void heapify(int i){
    int smallest = i;
    int l = left(i);
    int r = right(i);

    if(l < size && arr[l] < arr[smallest])
        smallest = l;

    if(r < size && arr[r] < arr[smallest])
        smallest = r;

    if(smallest != i){
        swap(&arr[i], &arr[smallest]);
        heapify(smallest);
    }
}

    int getMin(){
        return arr[0];
    }

    int ExtractMin(){
        if(size<=0){
            return INT_MAX;
        }
        if(size==1){
            size--;
            return arr[0];
        }
        int k=arr[0];
        arr[0]=arr[size-1];
        size--;
        heapify(0);
        return k;
    }

    void Decreasekey(int i,int value){
        arr[i]=value;
        k=i;
        while(k!=0&& arr[parent(k)]>arr[k]){
            swap(&arr[parent(k)],&arr[k]);
            k=parent(k);
        }
    }

    void Delete(int i){
        Decreasekey(i,INT_MIN);
        ExtractMin();
    }
};


int main() {
    BinaryHeap h(20);
    h.Insert(4);
    h.Insert(1);
    h.Insert(2);
    h.Insert(6);
    h.Insert(7);
    h.Insert(3);
    h.Insert(8);
    h.Insert(5);

    cout << "Min value is " << h.getMin() << endl;

    h.Insert(-1);
    cout << "Min value is " << h.getMin() << endl;

    h.Decreasekey(3, -2);
    cout << "Min value is " << h.getMin() << endl;

    h.ExtractMin();
    cout << "Min value is " << h.getMin() << endl;

    h.Delete(0);
    cout << "Min value is " << h.getMin() << endl;

    return 0;
}

