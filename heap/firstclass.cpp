#include<iostream>
using namespace std;
class Heap{
    public:
    int *arr;
    int capacity;
    int size;
    Heap(int capcaity){
        this->arr= new int[capcaity];
        // size  here give info about current number of element
        this->capacity=capacity;
       this-> size=0;
    }

    void insert(int val){
        // insert karna ka badh size increase ho jaya gaa
        if(size== capacity){
            cout<<" heap overflow"<<endl;
        }
        size++;
        int index=size;
        arr[index]=val;

        // take the value to current positon
        while(index>1){
            int parentindex=index/2;
            if(arr[index]>arr[parentindex]){
                swap(arr[index],arr[parentindex]);
                index=parentindex;
            }
            else{
                break;
            }
        }
    }

    void printheap(){
        for(int i=1;i<=size;i++){
       cout<<arr[i]<<" "; 
    }
    }
};


int main(){
    Heap h(20);
    // insertion;
    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(11);
    h.insert(6);
    cout<<"printing the content of heap"<<endl;
    h.printheap();
    


}