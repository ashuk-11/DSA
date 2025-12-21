#include<bits/stdc++.h>
using namespace std;

// Problem: Next Smaller Element
// Link: https://www.geeksforgeeks.org/problems/immediate-smaller-element1142/1

//-------------------------------Approach ----------------------------

class Solution {
    public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        
        int n= arr.size();
        vector<int> ans(n);
        stack<int> st;
        
        for(int i= n-1; i>= 0; i--){
            int curr= arr[i];
            
            //keep popping untill 
            //stack is non-empty ans,
            //stack top is greater than current as it can't be the next smaller of our current element
            while(!st.empty() && st.top()>= curr){
                st.pop();
            }
            
            //now add the ans accordingly
            if(st.empty()){
                ans[i]= -1;
            }
            else{
                ans[i]= st.top();
            }
            
            //finally push current to stack
            st.push(curr);
        }
        return ans;
    }
};

/*
    while loop can be confusing.
    Just remember, if you can treat st.top() your next smaller element , and if not i.e st.top()>= curr , then keep popping
    And every curr will be added to stack, at the very last
*/
    
