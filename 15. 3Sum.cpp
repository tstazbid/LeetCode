/*
Approach: Two Pointers

We will follow the same two pointers pattern as in Two Sum II. It requires the array to be sorted, 
so we'll do that first. As our BCR is O(N*N), sorting the array would not change the overall time complexity.

After sorting the array, we move our pivot element nums[i] and analyze elements to its right. 
We find all pairs whose sum is equal -nums[i] using the two pointers pattern, 
so that the sum of the pivot element (nums[i]) and the pair (-nums[i]) is equal to zero.

Algorithm:

1. For the main function:
    -> Sort the input array nums.
    -> Iterate through the array:
        : If the current value is greater than zero, break from the loop. Remaining values cannot sum to zero.
        : If the current value is the same as the one before, skip it.
        : Otherwise, call twoSum for the current position i.

2. For twoSum function:
    -> Set the low pointer lo to i + 1, and high pointer hi to the last index.
    -> While low pointer is smaller than high:
        : If sum of nums[i] + nums[lo] + nums[hi] is less than zero, increment lo.
        : If sum is greater than zero, decrement hi.
        : Otherwise, we found a triplet:
            -> Add it to the result res.
            -> Decrement hi and increment lo.
            -> Increment lo while the next value is the same as before to avoid duplicates in the result.

3. Return the result res.


Time Complexity: O(N * N)
Space Complexity: O(N)

Problem Level: Medium
*/

class Solution {
private:
    void twoSum(vector<int>& nums, int i, vector<vector<int>>& triplets) {
        int l = i + 1, h = nums.size() - 1;
        while(l < h) {
            int sum = nums[i] + nums[l] + nums[h];
            if(sum < 0) l++;
            else if(sum > 0) h--;
            else {
                triplets.push_back({nums[i], nums[l], nums[h]});
                l++;
                h--;
                while(l < h && nums[l] == nums[l - 1]) l++;
            }
        }
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> triplets;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() && nums[i] <= 0; i++) {
            if(i == 0 || nums[i] != nums[i - 1]) {
                twoSum(nums, i, triplets);
            }
        }
        return triplets;
    }
};
