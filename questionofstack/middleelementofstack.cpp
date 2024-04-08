#include<iostream>
using namespace std;
#include<stack>
void solve(stack<int> st,int &pos , int &ans){
    if(pos==1){
        ans= st.top();
        return ;
    }
    // case solved usign recursion
    pos--;
    int temp=st.top();
    st.pop();
    
    solve(st,pos, ans);
    // here we doing backtrack 
    st.push(temp);
}

int getmiddleelemnet(stack<int> st){
    int size=st.size();
    if(st.empty()){
        return -1;
    }
    else{
        // odd
            int pos=0;

        if(size&1){
            pos=size/2+1;
        }
        else{
            pos=size/2;
        }

     int  ans=-1;
    solve(st,pos,ans);
    return ans;
    }
   
}
void insertatbottom(stack<int> &st,int &element){
    if(st.empty()){
        st.push(element);
        return;
    }
    // 1 case solve
    int temp=st.top();
    st.pop();
    // recursion calling
    insertatbottom(st,element);
    // backtracking
    st.push(temp);
}  

void reversestack(stack<int>&st){
    if(st.empty()){
        return;
    }
    // 1 case
    int temp=st.top();
    st.pop();
    reversestack(st);
    // backtracing , placing the element at the bottom
    insertatbottom(st,temp);
}

int main(){
    
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    int mid=getmiddleelemnet(st);
}