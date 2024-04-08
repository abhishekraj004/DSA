#include<iostream>
using namespace std;
#include<stack>
void insertinsortedstack(stack<int>&st,int element){
    if(st.empty() || element>st.top()){
        st.push(element);
        return;
    }
    // 1 case 
    int temp=st.top();
    st.pop();
    // recursion calling
    insertinsortedstack(st,element);
    // backtrack
    st.push(temp);
}
void sortastack(stack<int>&st){
    if(st.empty()){
        return;
    }
    int temp=st.top();
    st.pop();
    // recursion 
    sortastack(st);
    // backtracking
    insertinsortedstack(st,temp);
}
int main(){
    stack<int> st;
    st.push(1);
    st.push(20);
    st.push(9);
    st.push(4);
    st.push(0);
    sortastack(st);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}