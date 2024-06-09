// // Count Days Without Meetings

// You are given a positive integer days representing the total number of days an employee is available for work (starting from day 1). You are also given a 2D array meetings of size n where, meetings[i] = [start_i, end_i] represents the starting and ending days of meeting i (inclusive).

// Return the count of days when the employee is available for work but no meetings are scheduled.

// Note: The meetings may overlap.

// (https://leetcode.com/problems/count-days-without-meetings/description/)

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        
        sort(meetings.begin(),meetings.end());
        int n=meetings.size();
        
        int count=0;
        int maxi=0;
        int day=1;
        int start=1;
        for(int i=0;i<n;i++){
            maxi=max(meetings[i][1],maxi);
            start =meetings[i][0];
            count+=start-day>=0?start-day:0;
            day=maxi+1;
        }
        count+= days-maxi;
        return count;
    }
};