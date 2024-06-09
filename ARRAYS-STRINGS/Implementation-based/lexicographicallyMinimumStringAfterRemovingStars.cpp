// //Lexicographically Minimum String After Removing Stars

// You are given a string s. It may contain any number of '*' characters. Your task is to remove all '*' characters.

// While there is a '*', do the following operation:

// Delete the leftmost '*' and the smallest non-'*' character to its left. If there are several smallest characters, you can delete any of them.
// Return the 
// lexicographically smallest
//  resulting string after removing all '*' characters.

// (https://leetcode.com/problems/lexicographically-minimum-string-after-removing-stars/)


class Solution {
public:
    string clearStars(string s){
        string ans;
        int n = s.size();
        
        vector<vector<int>> positions(26);
        vector<int> deleted(n , 0);
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '*'){
                deleted[i] = 1;
                for(int j = 0 ; j < 26 ; j++){
                    if(positions[j].size()){
                        deleted[positions[j].back()] = 1;
                        positions[j].pop_back();
                        break;
                    }
                }
            }
            else{
                positions[s[i]-'a'].push_back(i);
            }
        }
        
        for(int i = 0 ; i < n ; i++){
            if(deleted[i]!=1) ans.push_back(s[i]);
        }
        return ans;
    }
};