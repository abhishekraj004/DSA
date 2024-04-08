#include<iostream>
#include<stack>
#include<vector>
using namespace std;
vector<int> nextsmaller(int *arr,int size,vector<int>ans){
    stack<int> st;
    st.push(-1);
    for(int i=size-1;i>=0;i--){
        int curr=arr[i];
        // answer find karo current ka lia 
        while(st.top()>=curr){
            st.pop();
        }
         ans[i]=st.top();
        st.push(curr);
    }
    return ans; 
}
int main(){
    int arr[5]={8,4,6,2,3};
    int size=5;
}
