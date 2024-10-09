// orted GCD Pair Queries
// Solved
// Hard
// Topics
// Companies
// Hint
// You are given an integer array nums of length n and an integer array queries.

// Let gcdPairs denote an array obtained by calculating the 
// GCD
//  of all possible pairs (nums[i], nums[j]), where 0 <= i < j < n, and then sorting these values in ascending order.

// For each query queries[i], you need to find the element at index queries[i] in gcdPairs.

// Return an integer array answer, where answer[i] is the value at gcdPairs[queries[i]] for each query.

// The term gcd(a, b) denotes the greatest common divisor of a and b.

// https://leetcode.com/problems/sorted-gcd-pair-queries/description/


// Example 1:

// Input: nums = [2,3,4], queries = [0,2,2]

// Output: [1,2,2]

// Explanation:

// gcdPairs = [gcd(nums[0], nums[1]), gcd(nums[0], nums[2]), gcd(nums[1], nums[2])] = [1, 2, 1].

// After sorting in ascending order, gcdPairs = [1, 1, 2].

// So, the answer is [gcdPairs[queries[0]], gcdPairs[queries[1]], gcdPairs[queries[2]]] = [1, 2, 2].

// Example 2:

// Input: nums = [4,4,2,1], queries = [5,3,1,0]

// Output: [4,2,1,1]

// Explanation:

// gcdPairs sorted in ascending order is [1, 1, 1, 2, 2, 4].

// Example 3:

// Input: nums = [2,2], queries = [0,0]

// Output: [2,2]

// Explanation:

// gcdPairs = [2].

 

// Constraints:

// 2 <= n == nums.length <= 105
// 1 <= nums[i] <= 5 * 104
// 1 <= queries.length <= 105
// 0 <= queries[i] < n * (n - 1) / 2

// SOLUTION - https://leetcode.com/problems/sorted-gcd-pair-queries/solutions/5875685/c-divisors-counting-and-binary-search-o-n-sqrt-maxelement-easy-to-understand/

class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        // Unique Divisorrs count + Gcdcount+ binary search on GCD
        // TC->O(N*sqrt(Maxi)) + O(Maxi*log(Maxi) + Maxi + Qlog(Maxi))
        // SC->O(3N)
        int n = nums.size();
        int maxi= *max_element(nums.begin(),nums.end());

        vector<int> divCount(maxi+1,0);
        for(int i=0;i<n;i++){
            for(int d=1;d*d<=nums[i];d++){
                if(nums[i]%d==0){
                    divCount[d]++;
                    if(d!=nums[i]/d){
                        divCount[nums[i]/d]++;
                    }
                }
            }
        }
        //  for(int d=1;d<=maxi;d++)   cout<<divCount[d]<<" ";

        // Inclusion - exclusion
        vector<long long> gcdCount(maxi+1,0);
        for(int g= maxi;g>=1;g--){
            gcdCount[g] = (long long)divCount[g]*(long long)(divCount[g]-1)/2;
            //you can think , that divCount should  be dcreased/subtracted but if you will check, rather gcdCount should be decreased/subtracted
            // nums=2,3,4  divCount 1->3 2->2 3->1 4->1 if we reduce 2->2 to 2->1 , then numbers with div 2 cannot form pair with div 4 , and it leads to zero pairs with gcd zero in this case.
            // Rather, we want to subtract gcdcount[4] from gcdCount[2].
            // it should be noted that,as on theory,pairs of gcd 2 can have numbers with divsior as 2(only muliple of 2 ie 2*1=1) and other number with  multiples of 2 (2*1=2 , 2*2=4,2*3=6,  ...) (4 in this case) . One of the number will have the divisor equal to 2.
            // Pairs with gcd 4 will have one number with div 4 and other can have either div4 or multiple of 4.

            // Initially ,gcdCount[2] has pairs with one number having div 2 or multiple of 2 and other div2 or multiple of 2. These muliples of 2 came in gcdCount[2] because they also have div2, due to which pairs with both numbers having diviaiors muliples of 2 (except 2 ) will be there in gcdCount[2].
            // for gcdCount[2] to be correct as on theory, gdcdCoutn[4] or gcdCount[mulitples of 2 except 2 itself] needs to be removed.
            for(int mul=2*g; mul<=maxi;mul+=g){
                gcdCount[g]-=gcdCount[mul];
            }
            // cout<<gcdCount[g]<<" ";
        }
        vector<long long> prefixSum(maxi+1,0);
        for(int g=1;g<=maxi;g++){
            prefixSum[g]= gcdCount[g]+ prefixSum[g-1];
            // cout<<prefixSum[g]<<" ";
        }
        vector<int> answer(queries.size());
        for(int i=0;i<queries.size();i++){
            int low=1, high= maxi;
            while(low<=high){
                int mid= low+ (high-low)/2;
                if(prefixSum[mid]>queries[i]){
                    answer[i]=mid; high=mid-1;
                }
                else low=mid+1;
            }
        }
        return answer;
    }
};