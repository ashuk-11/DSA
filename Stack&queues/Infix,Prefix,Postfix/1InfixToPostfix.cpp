#include<bits/stdc++.h>
using namespace std;

// Problem: Infix to Postfix
// Link: https://www.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1

//-------------------------------Approach ----------------------------

// have string ans, stack<char> st, priority() function
// when input char is alnum: add in ans
// when input is '(': push in st
// when input is ')': keep popping from st untill ( encounters, remove ( too
// else: 
//      if st is empty, push directly in st; 
//      if input is ^, keep popping till priority of top of st is greater than(>) ^ (normally push directly)
//      else: if priority(st top) is greater or equal to input, keep popping
//                  then push it finally
// remove remaining in st and add to ans

class Solution {
  public:
    int priority(char c){
        if(c == '^') return 3;
        else if(c == '*' || c == '/') return 2;
        else if(c == '+' || c == '-') return 1;
        else if(c == '(') return -1;
    }
  
    string infixToPostfix(string& s) {
        stack<char> st;
        string ans;
        
        int n= s.size();
        
        for(int i= 0; i<n; i++){
            if(isalnum(s[i])){
                ans+=s[i];
            }
            else if(s[i]== '('){
                st.push(s[i]);
            }
            else if(s[i]== ')'){
                while(!st.empty() && st.top()!= '('){
                    ans+= st.top();
                    st.pop();
                }
                if(!st.empty() && st.top()== '(') st.pop();
            }
            else{
                if(st.empty()){
                    st.push(s[i]);
                }
                else if(s[i]== '^'){
                    while(!st.empty() && priority(st.top()) > priority(s[i])){
                        ans+= st.top();
                        st.pop();
                    }
                    st.push(s[i]);
                }
                else{
                    while(!st.empty() && priority(st.top()) >= priority(s[i])){
                        ans+= st.top();
                        st.pop();
                    }
                    st.push(s[i]);
                }
                
            }
            
        }
        while(!st.empty()){
            ans+= st.top();
            st.pop();
        }
        
        return ans;
    }
};
