#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> vec_permutations;
    vector<vector<int>> answer;
    vector<bool> elem_checked;

    vector<vector<int>> permute(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++){
            elem_checked.push_back(false);
        }
        
        permutation(nums, nums.size());

        return answer;
    }
    void permutation(vector <int>& nums, int len){
        if (vec_permutations.size() == len){
            answer.push_back(vec_permutations);
            return;
        }
        for(int i = 0; i < len; i++){
            //There are no repetition values in premutation
            if (elem_checked[i] == true){
                continue;
            }
            elem_checked[i] = true;
            vec_permutations.push_back(nums[i]);
            permutation(nums, len);
            elem_checked[i] = false;
            vec_permutations.pop_back();
        }
    }
};
int main(){

    Solution s = Solution();
    vector<int> vec1 = {1,2,3};
    vector<vector<int>> my_solution = s.permute(vec1);
    return 0;
}