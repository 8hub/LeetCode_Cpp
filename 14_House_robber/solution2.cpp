#include <iostream>
#include <vector>


class Solution {
public:
    int rob(std::vector<int>& nums) {
        int len = nums.size();
        switch (len){
            case 1:
                return nums[0];
                break;
            case 2:
                return std::max(nums[0], nums[1]);
                break;
            case 3:
                return std::max(nums[0]+nums[2], nums[1]);
                break;
            default:
                std::vector<int> max(len, 0);
                for (int i = 0; i < 2; i++){
                    max[i] = nums[i];
                }
                max[2] = nums[2] + nums[0];
                int it = 3;
                while (it < len){
                    max[it] = std::max(max[it-2], max[it-3]) + nums[it];
                    it++;
                }
                return std::max(max[it-1], max[it-2]);
                break;
        }
    }
};

int main(){
    Solution sol;
    std::vector<int> nums = {2,7,9,3,1};
    std::cout << sol.rob(nums) << std::endl;
    std::vector<int> nums2 = {1,2,3,1};
    std::cout << sol.rob(nums2) << std::endl;
    return 0;
}