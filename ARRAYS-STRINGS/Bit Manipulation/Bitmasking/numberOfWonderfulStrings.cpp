// // NUMBER of WONDERFUL STRINGS

// A wonderful string is a string where at most one letter appears an odd number of times.

// For example, "ccjjc" and "abab" are wonderful, but "ab" is not.
// Given a string word that consists of the first ten lowercase English letters ('a' through 'j'), return the number of wonderful non-empty substrings in word. If the same substring appears multiple times in word, then count each occurrence separately.

// A substring is a contiguous sequence of characters in a string.

// https://leetcode.com/problems/number-of-wonderful-substrings/description/

// https://leetcode.com/problems/number-of-wonderful-substrings/editorial/



class Solution {
public:
    long long wonderfulSubstrings(string word) {
        //earlier thought of sliding window but didn't work
        // problem similar to prefix sum

        // PREFIX BITMASK
        //TC->O(N(32+10)) 32 is number of bits in int datatype and 10 is number of distinct alphabets
        //SC->O(N)

        //alphabets-'a'->'j' is a indicator that bitmasking can be used for effiecient time complexity
        //every substring can be represented as difference of two substrings both starting from 0 th index
        //problem needs to be divided into sub tasks- ONE-susbtrings with all even alphabets
        // SECOND -substrings with exactly one alphabets with odd frequency

        // ONE- substring has all even alphabets or bitmask=0 only 
        // when both the subtrahend substrings starting from 0th index have equal bitmask value

        //SECOND-check for each bitmask whether its counterpart(which is only 1 bit flip far at any index)
        // exists already or not in map
        
        long long count=0;
        unordered_map <int ,int> mp;

        
        int bitmask=0;
        int n= word.size();
        mp[0]=1;
        for(int i=0;i<n;i++){
            bitmask^=1<<(word[i]-97); 
           
            // if(bitmask==0) count++;

            if(mp.find(bitmask)!=mp.end()){
                count+=mp[bitmask];   
            }
            //looping through all flipping bit positions and see if it is a;ready presnt in map
            // for eg '1101' one of its counterpart will be '1111' if we decide to flip the third position
            for(int i=0;i<10;i++){
                int counterpart=bitmask^(1<<i);
                if(counterpart==bitmask)cout<<"yes ";
                if(mp.find(counterpart)!=mp.end()){
                    count+=mp[counterpart];
                }
            }
           
            mp[bitmask]++;
        }

        return count;


    }
};