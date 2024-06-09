// // Hand of Straights

// Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.

// Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.

// https://leetcode.com/problems/hand-of-straights/description/

// Note: This question is the same as 1296: https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/

typedef long long ll;
class Solution {
public:
    //this solution is working
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize!=0)return false;

        int mini=INT_MAX;
        int maxi=INT_MIN;
        unordered_map<int,int> mp;
        for (int i=0;i<n;i++){
            mp[hand[i]]++;
            mini=min(mini,hand[i]);
            maxi=max(maxi,hand[i]);
        }

        for(auto it: hand){
            int x = it;
            if(mp.find(x)==mp.end())continue;
            while(mp.find(x-1)!=mp.end()){
                x--;
            }
            int temp_x=x;
            for(int i=1;i<=groupSize;i++){
                if(mp.find(temp_x)==mp.end())return false;
                mp[temp_x]--;
                // cout<<temp_x<<"-> "<<mp[temp_x]<<endl;
                if(mp[temp_x]==0)mp.erase(temp_x);
                temp_x++;
            }
        }
        return true;
     }

    //this solution is not working
    // bool isNStraightHand(vector<int>& hand, int groupSize) {
    //     int n = hand.size();
    //     if(n%groupSize!=0)return false;

    //     int mini=INT_MAX;
    //     int maxi=INT_MIN;
    //     unordered_map<int,int> mp;
    //     for (int i=0;i<n;i++){
    //         mp[hand[i]]++;
    //         mini=min(mini,hand[i]);
    //         maxi=max(maxi,hand[i]);
    //     }
    //     // cout<<mini;
    //     int x= mini;
    //     // int flag=1;
    //     int cnt=0;
    //     while(cnt<mp.size()){
    //         cnt++;
           

    //         int freq= mp[x];
    //         if(freq>0){ // do the operation
    //             mp[x]--;
                
    //             int temp_x=x;
    //             for(int i=2;i<=groupSize;i++){
    //                 if(mp.find(temp_x+1)!=mp.end()){
    //                     mp[temp_x+1]--;
    //                     temp_x++;
    //                 }
    //                 else  return false;
                   
    //             }
    //             // x++;  //it is for handling duplicates if it exists
                
    //         }
    //         else{ x++; while((mp.find(x)==mp.end()&& x+1<=maxi)){x++;}}
    //     }
    //     return true;
    
    // }

};