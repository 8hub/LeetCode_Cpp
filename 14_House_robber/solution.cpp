#include <iostream>
#include <vector>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        else if(nums.size() == 2) return std::max(nums[0], nums[1]);
        else if(nums.size() == 3) return std::max(nums[0]+nums[2], nums[1]);
        std::vector<int> house_max_money(nums.size());
        checkHouse(3, house_max_money, nums);
        return std::max(house_max_money[nums.size()-1], house_max_money[nums.size()-2]);
    }
private:
    void checkHouse(int house_nr, std::vector<int> &house_max_money, std::vector<int> &nums){
        for(int i = 0; i <= 1; i++) house_max_money[i] = nums[i];
        house_max_money[2] = nums[0]+nums[2];
        while (house_nr < nums.size()){
            house_max_money[house_nr] = std::max(house_max_money[house_nr-3], house_max_money[house_nr-2])+nums[house_nr];
            house_nr++;
        }
    }
};

int main(){
    Solution s = Solution();
    std::vector<int> test1 {1,2,3,1};
    std::vector<int> test2 {2,7,9,3,1};
    std::cout<<s.rob(test1)<<std::endl; //Output: 4
    std::cout<<s.rob(test2)<<std::endl; //Output: 13
    
    return 0;
}