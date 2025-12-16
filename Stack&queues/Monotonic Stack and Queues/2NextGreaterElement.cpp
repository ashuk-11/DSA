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