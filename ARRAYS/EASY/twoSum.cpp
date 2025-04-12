class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            // vector<int> arr;
            for(int i = 0;i < nums.size();i++) {
                for(int j = i+1;j < nums.size();j++) {
                    if(nums[i]+nums[j] == target) return {i,j};
                }
            }
            return {};
        }
    };


    // This is basic brute force approach which take upto O(n^2) complexity so use better solutions
    // after learning more in DSA
    // there is a method called hashing to reduce complexity
