# ## Max Fruits Into Baskets

# You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

# You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

# You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
# Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
# Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
# Given the integer array fruits, return the maximum number of fruits you can pick.

# https://leetcode.com/problems/fruit-into-baskets/description/

class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        # TC->O(N) SC->O(2) or O(1)  
        # SLIDING WINDOW - WHICH DOESN'T SHRINK
        # its current size represnts the longest subarray (or largest number of fruits)
        #  encounterred yet wheter the current window is in bad condition or good
        # bad condtion means more than two types of fruits are there

        n=len(fruits)
        dict={}
        maxi=0

        start=0
        for end in range(n):
            # if(len(st)<2):
            #     st.add(fruits[end])
            # else:
            #     st.add
            #     st.remove(fruits[start])
            #     fruit+=1

            dict[fruits[end]]= dict.get(fruits[end],0)+1
            if(len(dict)>2):   # bad condtion enters or still exists
                dict[fruits[start]] -=1
                if(dict[fruits[start]]==0): 
                    del dict[fruits[start]]
                start+=1
            # print(start,end)
        return end-start+1

       
