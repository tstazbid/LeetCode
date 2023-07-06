/*
Problem Link: https://leetcode.com/problems/sort-transformed-array/

two pointer approach
quadratic rules, after a long observe in the sorted vector
if a>0 then quadratic result are [large, large, small, small, large]; so left or right side larger will place at last in ans vector
if a<0 then quadratic result are [small, small, large, large, small, small]; so left or right side samllest will place at first in ans vector
 */

class Solution {
public:
    int quadracticFunction(int a, int b, int c, int x){
        return (a*x*x) + (b*x) + c; 
    }
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int len = nums.size(), leftQuadractic, rightQuadractic, resIndex=0;

        vector<int>ans(len);
        int rightPtr = len - 1, leftPtr = 0;

        if(a>0) resIndex = len - 1;

        while(leftPtr<=rightPtr){
            leftQuadractic = quadracticFunction(a,b,c,nums[leftPtr]);
            rightQuadractic = quadracticFunction(a,b,c,nums[rightPtr]);

            if(a>0){
                if(leftQuadractic > rightQuadractic){
                    ans[resIndex] = leftQuadractic;
                    leftPtr++;
                }else{
                    ans[resIndex] = rightQuadractic;
                    rightPtr--;
                }
                resIndex--;
            }
            else{
                if(leftQuadractic > rightQuadractic){
                    ans[resIndex] = rightQuadractic;
                    rightPtr--;
                }else{
                    ans[resIndex] = leftQuadractic;
                    leftPtr++;
                }
                resIndex++;
            }
        }
        return ans;
    }
};

// Time Complexity: O(N)
// Memory Complexity: O(N)