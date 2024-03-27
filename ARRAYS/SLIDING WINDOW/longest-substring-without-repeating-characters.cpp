// // LONGEST SUBSTRING WITHOUT REPEATING CHARACTERS

//Given a string s, find the length of the longest substring without repeating characters.

// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

// https://takeuforward.org/data-structure/length-of-longest-substring-without-any-repeating-character/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
            // better - can be implmented using unordered_set also
            // TC->O(2N)  SC->O(N)
            unordered_map<char,int> st;
            int longest=0; int start=0 , end=0;
            for(int i=0;i<s.length();i++){
                if(st.find(s[i])!=st.end()){
                    //st.clear();
                    int pos_start=start;
                    int pos_end=st[s[i]]; //position/index of already occurred character
                    for(int j=pos_start;j<=pos_end;j++){  //for removing the seen elements till pod_end
                        st.erase(s[j]);
                    }
                    st.insert({s[i],i});
                    start=pos_end+1;
                    end++;
                    longest=max(longest,end-start);
                }
                else{
                    st.insert({s[i],i});
                    end++;
                    longest=max(longest,end-start);
                }
            }
            return longest;
    }

    int lengthOfLongestSubstring(string s) {
        //OPTIMAL 
        //TC->O(N)  SC->O(N)
        //In this , we won't move start through the array , whenever we we found an element that occurred before , rather we would take direct jumps of start variable 
        //We would check if even if the eleemnet is found in the map , that its stored index lies on the {start-end} range of non-repeating substring or not , if does not lie in the range , we would extend the non-repeating substring  , ptheriwse , take jump of start
        //kept the code repetitive for better understanding of code


        int start=0, end=0;
        int longest=0;
        unordered_map <char,int> mp; //{charcter, index it l}
        //in this , I am integrating end and i variable as they are evrytime 1 distance far
        for(  ; end<s.length();end++){
            if(mp.find(s[end])!=mp.end()){
                char c= s[end];
                //element will always be smaller than current end value
                if(mp[c]<start){ 
                    //element present outside the range of non-repeated substring // would have been expelled earlier
                    mp[c]=end;
                    longest=max(longest,end-start+1);
                }
                else{
                    start=mp[c]+1;
                    mp[c]=end;
                    longest=max(longest,end-start+1);
                }

            }
            else {
                //element not found in map
                //cout<<" start : "<<start<<" end : "<<end<<endl;
                mp.insert({s[end],end});
                longest=max(longest, end -start +1);
            }
        }
        return longest;
    }
};