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


std::vector<std::vector<int>> generate_permutations() {
    std::vector<std::vector<int>> permutations;
    for (int A = 0; A < 2; ++A) {
        for (int B = 0; B < 2; ++B) {
            for (int C = 0; C < 2; ++C) {
                int decimal_value = (A << 2) | (B << 1) | C;
                permutations.push_back({A, B, C, decimal_value});
            }
        }
    }
    return permutations;
}

int main(){

    Solution s = Solution();
    vector<int> vec1 = {1,2,3};
    vector<vector<int>> my_solution = s.permute(vec1);

    /*
    Idea of creating bit manipulation and then convert bits to specific values of elements in array
    Each 1 in binary corresponds to specific value eg.
    array [2,5] permutations would be
    A correspont to 2
    B correspond to 5
    A | B | permutation| result
    --|---|------------|-------
    0 | 0 |     -      |  []
    0 | 1 |     B      |  [5]
    1 | 0 |     A      |  [2]
    1 | 1 |     AB     |  [2,5]

    But the more bits the more nested loops 2^n, where n-nr of elements
    */
    std::vector<std::vector<int>> permutations = generate_permutations();
    for (const auto& permutation : permutations) {
        std::cout << "[" << permutation[0] << ", " << permutation[1] << ", " << permutation[2] << ", " << permutation[3] << "]" << std::endl;
    }
    return 0;
}