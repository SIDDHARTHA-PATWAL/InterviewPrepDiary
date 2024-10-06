## Classical Binary Search ALgorithm

Python
```
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        
        low ,high = 0,len(nums)-1
        while(low<=high):
            mid = low + (high-low)//2
            if(nums[mid]==target):
                return mid
            elif nums[mid]>target:
                high=mid-1
            else : low=mid+1
        return -1
```

C++
```
class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int low=0,high=nums.size()-1;
            while(low<=high){
                int mid = low + (high-low)/2;
                if(nums[mid]==target)
                    return mid;
                else if(nums[mid]>target)
                    high=mid-1;
                else
                    low=mid +1;
            }
            return -1;
        }
};```