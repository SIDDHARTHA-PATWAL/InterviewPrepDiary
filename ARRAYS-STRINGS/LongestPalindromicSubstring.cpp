// // // Longest Palindromic Substring

// Given a string s, return the longest palindromic substring in s.

// https://leetcode.com/problems/longest-palindromic-substring/description/
// https://leetcode.com/problems/longest-palindromic-substring/editorial/

// Example 1:

// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.
// Example 2:

// Input: s = "cbbd"
// Output: "bb"
 

// Constraints:

// 1 <= s.length <= 1000
// s consist of only digits and English letters.

class Solution {
    public:
        //TC-> O(N^3) SC-> O(1) 
        string longestPalindrome(string s) {
            for (int length=s.size(); length>0;length--){
                for (int start=0; start <= s.size()-length; start++){
                    if (check(s,start,start+length)) 
                        return s.substr(start,length);
                    }
                }
            }
    
            return "";
        }
    
    private:
        bool check(string s,int i,int j){
            int left = i;
            int right = j - 1;
    
            while (left<right) {
                if (s[left]!=s[right]){
                    return false;
                }
    
                left++;
                right--;
            }
    
            return true;
        }
};
class Solution {
public:
    //USING DYNAMIC PROGRAMMING
    //TC-> O(N^2) SC-> O(N*2) 
    string longestPalindrome(string s) {
        int n =s.length();
        int ansl=0,ansr=0;
        vector<vector<bool>> dp(n, vector<bool>(n,false));
        // i,j in dp represnts whetehr substring(i,j) is palindrome or not
        for(int i=0;i<n;i++){
            dp[i][i]=true; // single element susbtring are always palindromic and populating dp
            if(i<n-1 && s[i]==s[i+1]){ // checking condiiton for two eleemnts substring and populatin g dp
                dp[i][i+1]=true;
                ansl=i, ansr=i+1;
            } 
        }
        //odd length substrings will be using only odd length substrings and same for even substrings
        for(int length=3;length<=n;length++){
            for(int start=0;start<=n-length;start++){
                dp[start][start+length-1]= (s[start]==s[start+length-1]) && dp[start+1][start+length-2];
                if(dp[start][start+length-1]==true){
                    ansl=start, ansr= start+length-1;
                }
            }
        }
        return s.substr(ansl,ansr-ansl+1);
    }
};

class Solution {
    public:
        string expand(string s, int i, int j){
            while(i>=0 && j<s.length() && s[i]==s[j]){
                i--; j++;
            }
            return s.substr(i+1,j-1-(i+1)+1);
        }
        //USING EXPAND FROM CENTRES ->Opposite of (startng check from endings and then going inwards)
        //TC-> O(N^2) SC-> O(1) 
        // Other approaches focuesed on edges or bounds (i,j) can have,
        // But this current appraoch focuses on centres rather
        // There are n odd centres and n-1 even centres , I.E total 2*n-1 centres 
        string longestPalindrome(string s) {
            int n = s.length();
            string ans;
            for(int i=0;i<n;i++){
                string odd=expand(s,i,i);
                if(odd.size()>ans.size())ans=odd;
                string even =expand(s,i,i+1);
                if(even.size()>ans.size())ans=even;
            }
            return ans;
        }
    };