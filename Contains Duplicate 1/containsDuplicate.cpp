#include <unordered_set>

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hashTable;
        int numSize = nums.size();
        
        for( int i = 0; i < numSize; i++)
        {
            if ( hashTable.count(nums[i]) != 0 )
                return true;
            else
                hashTable.insert(nums[i]);
        }
        
        return false;
    }
};