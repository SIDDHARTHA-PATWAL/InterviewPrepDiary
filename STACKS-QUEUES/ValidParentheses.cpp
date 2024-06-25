// // Valid Parentheses

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 
https://leetcode.com/problems/valid-parentheses/description/

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.

class Solution {
public:
    bool isValid(string s) {
        //TC->O(N) SC->O(N)
        stack<char> st;

        for(auto it:s ){
            if(it=='{' || it=='(' || it=='[') st.push(it);
            else{
                if(st.empty())return false;
                char c= st.top() ;st.pop();
                if((it==')' && c=='(') || (it=='}' && c=='{')|| (it==']' && c=='[')) continue;
                else return false;
            }
        }
        if(st.empty())return true;
        else return false;
    }
};