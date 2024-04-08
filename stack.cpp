// #include<iostream>
// #include<stack>
// using namespace std;
// class Stack{
//     public:
//     int *arr;
//     int size;
//     int top;
//     Stack(int size){
//         arr=new int[size];
//         this->size=size;
//         this->top=-1;
//     }


//     void push(int data){
//         if(top==size-1){
//             cout<<"stack is overflow";
//             return;
//         }
//         else{
//            top++;
//         arr[top]=data; 
//         }
        
//     }


//     void pop(){
//         if(top==-1){
//             cout<<"stack is undefolow";
//             return;
//         }
//         else{
//             top--;
//         }
        
//     }


//     bool isempty(){
//         if(top==-1){
//             return true;
//         }
//         else{
//             return false;
//         }
//     }


//     int gettop(){
//         if(top==-1){
//             cout<<"stack is empty";
//             return -1;
//         }
//         else{
//            return arr[top]; 
//         }
//     }


//     int getsize(){
//         return top+1;
//     }


//     void print(){
//         cout<<"top: "<<top<<endl;
//         cout<<"top element "<<gettop()<<endl;
//         cout<<"stack: ";   // print the stack is not possible manually for understanding purpose we are doing this
//         for(int i=0;i<getsize();i++){
//             cout<<arr[i]<<" ";
//         }
//     }

// };


// int main(){
//     // Stack st(8);
//     // st.push(10);
//     // st.push(20);
//     // st.push(30);
//     // st.print();

//     string str="hellojee";
//     stack<char> st;
//     for(int i=0;i<str.size();i++){
//         char ch=str[i];
//         st.push(ch);
//     }

//     while(!st.empty()){
//         cout<<st.top()<<" ";
//         st.pop();
//     }
// }


//  find the middle element of the stack 
#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int> &st,int &pos , int &ans){
    // base case
    if(pos==1){
        ans= st.top();
        return;
    }
    // case we solve it than recursion solve it
    pos--;
    int temp=st.top();
    st.pop();
    //recursion
    solve(st,pos,ans);
  // here ,we are doing  backtrack
    st.push(temp);
}
int getmiddleone(stack<int> & st){
    int size=st.size();
    if(st.empty()){
        return -1;
    }
    else{
        int pos=0;
        if(size &1){
            pos=size/2 +1;
        }
        else{
            pos=size/2;
        }

        int ans=-1;
        solve(st,pos,ans);
        return ans;
    }
}


int main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);

    int mid=getmiddleone(st);
    cout<<mid<<endl;

   return 0;
}




// insert at bottom of the stack
#include<iostream>
#include<stack>
using namespace std;

void insertatbottom(stack<int> &st,int element){
    if(st.empty()){
        st.push(element);
        return;
    }
    int temp=st.top();
    st.pop();
    insertatbottom(st,element);
    st.push(temp);
}

void reversestack(stack<int> &st){
    if(st.empty()){
        return;
    }
    int temp=st.top();
    st.pop();
    reversestack(st);
    //back track;
    insertatbottom(st,temp);
}

void insertinsortedstack(stack<int> &st, int element){
    if(st.empty() || element>st.top()){
        st.push(element);
        return;
    }
    int temp=st.top();
    st.pop();
    insertinsortedstack(st,element);
    
    st.push(temp);
}


void sortastack(stack<int> &st){
    if(st.empty()){
        return;
    }
    int temp=st.top();
    st.pop();
    sortastack(st);
    insertinsortedstack(st,temp);
}

int main(){
    stack<int> st;
    st.push(50);
    st.push(10);
    st.push(30);
    st.push(4);
    st.push(60);
    
    // int element=400;
    // insertatbottom(st,element);
    sortastack(st);

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}


