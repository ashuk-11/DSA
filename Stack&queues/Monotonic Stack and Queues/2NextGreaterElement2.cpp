#include<bits/stdc++.h>
using namespace std;

// Problem: 503. Next Greater Element II
// Link: https://leetcode.com/problems/next-greater-element-ii/description/

//-------------------------------Approach ----------------------------

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        //hypothetical array with another nums ahead nums ahead!!
        //if nums= [1,2,1]
        //hpyo arr nums'= [1,2,1,1,2,1]
        //keeping a monotonic stack
        //starting from end
        //adding to ans array only when real elements are reached
        int n= nums.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i= 2*n-1; i>=0; i--){
            //getting the real index
            int idx= i%n;
            int curr_el= nums[idx];

            while(!st.empty() && st.top()<= curr_el){
                st.pop();
            }
            
            //only add to ans[] when i<n
            if(i< n){
                if(st.empty()){
                    ans[i]= -1;
                }
                else{
                    ans[i]=st.top();
                }
            }
            //lastly push the curr in stack
            //either stack empty
            //or not: top > curr_el
            st.push(curr_el);  
        }

        return ans;
    }
};