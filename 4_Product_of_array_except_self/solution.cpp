#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prefix = 1;
        int postfix = 1;
        vector<int> answer;

        for(int i = 0; i < nums.size(); i++){
            answer.push_back(prefix);
            prefix = prefix * nums[i];
        }
        for(int i = nums.size()-1; i > -1; i--){
            answer[i] = answer[i] * postfix;
            postfix = postfix * nums[i];
        }
        return answer;
    }
};