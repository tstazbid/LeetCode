// Problem Link: https://leetcode.com/problems/intersection-of-three-sorted-arrays/

class Solution {
public:
    bool binarySearch(vector<int>& nums, int low, int high, int n){
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid] == n) return true;
            if(nums[mid]<n) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> sortedIntersect;
        for(auto num: arr3){
            bool findFromArr1 = binarySearch(arr1, 0, arr1.size()-1, num);
            bool findFromArr2 = binarySearch(arr2, 0, arr2.size()-1, num);
            if(findFromArr1 && findFromArr2) sortedIntersect.push_back(num);
        }
        return sortedIntersect;
    }
};

// TC: O(n logn logn)
// SC: O(1)
