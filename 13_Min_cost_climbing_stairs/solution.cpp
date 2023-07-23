#include <iostream>
#include <vector>
class Solution {
public:
    // int minCostClimbingStairs(std::vector<int>& cost) {
    //     if(cost.size() == 2) return std::min(cost[0], cost[1]);
    //     int lowest_cost_l = cost[0];
    //     int lowest_cost_r = cost[1];
    //     int max_range = 2;
    //     while(max_range < cost.size()){
    //         int temp = lowest_cost_l;
    //         lowest_cost_l = lowest_cost_r;
    //         lowest_cost_r = std::min(temp,lowest_cost_r)+cost[max_range];
    //         max_range++;
    //     }
    //     return std::min(lowest_cost_l, lowest_cost_r);
    // }

    //v2 solution
    int minCostClimbingStairs(std::vector<int>& cost){
        int n = cost.size();
        std::vector<int> dp(n+1);
        dp[1]=cost[1];
        dp[0]=cost[0];

        for(int i=2;i<n;i++){
            dp[i]=cost[i]+std::min(dp[i-1],dp[i-2]);
        }
        return std::min(dp[n-1],dp[n-2]);
    }
};

int main(){
    std::vector<int> test1 {10,15,20};
    std::vector<int> test2 {1,100,1,1,1,100,1,1,100,1};

    Solution s = Solution();

    std::cout<<s.minCostClimbingStairs(test1)<<std::endl;
    std::cout<<s.minCostClimbingStairs(test2)<<std::endl;
    
    return 0;
}