#include<bits/stdc++.h>
using namespace std;

// Problem: Next Greater Element
// URL: https://leetcode.com/problems/next-greater-element-i/

//------------------------1st Approach------------------------------

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int n2= nums2.size();
        int n1= nums1.size();

        // for each element in nums1, find its index in nums2
        for(int i= 0; i< n1; i++){
            int indx= find(nums2.begin(), nums2.end(), nums1[i])- nums2.begin();

            int j;
            //if you get next greater in nums2, store and break
            for(j= indx+1; j< n2; j++){
                if(nums2[j]> nums1[i]){
                    ans.push_back(nums2[j]);
                    break;
                }
            }

            //if j equals n2, then surely no next greater found
            if(j== n2) ans.push_back(-1);
        }
        return ans;
    }
};

//------------------------------- 2nd Approach -------------------------------

// Using monotonic stack
// top of stack is next greater element of present element
// if present is greater than top, then keep popping till either stack becomecomes empty, or top os stack lis lesser than present element
// if popping causes stack empty, then no nge and put -1
// else, and we get a greater element at top , then nge of present element is top of stack
// then finally put the present element in stack 

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //unordered map for storing next greater for each el in nums2
        unordered_map<int, int> nge;

        // Monotonic stack which is storing elements in decreasing order only
        stack<int> st;

        for(int i= nums2.size()-1; i>= 0; i--){

            // keep popping till top is lesser than preset el
            while(!st.empty() && st.top()<= nums2[i]){
                st.pop();
            }
            //after popping if empty
            if(st.empty()) nge[nums2[i]]= -1;
            //not empty, then top of stack is nge of present el
            else nge[nums2[i]]= st.top();

            //lastly, put the present el in stack
            st.push(nums2[i]);
        }

        vector<int> ans;
        for(auto el: nums1){
            // nge stores next greaster of each, so get it for each el in nums1
            ans.push_back(nge[el]);
        }
        return ans;
    }
};