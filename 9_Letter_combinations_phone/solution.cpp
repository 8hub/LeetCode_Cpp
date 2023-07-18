#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> answer;
        if(digits.length() == 0) return answer;
        string curr_combination = "";
        addCombination(digits, 0, curr_combination, answer);
        return answer;
    }
private:
    void addCombination(string &digits, int curr_nr, string &curr_combination, vector<string> &answer){
        if(curr_combination.length() == digits.length()) answer.push_back(curr_combination);
        for(int i = 0; i < keyboard[digits[curr_nr]].length(); i++){
            curr_combination.push_back(keyboard[digits[curr_nr]][i]);
            addCombination(digits, curr_nr+1, curr_combination, answer);
            curr_combination.pop_back();
        }
    }
    unordered_map<char,string> keyboard = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
};

int main(){
    Solution s = Solution();
    s.letterCombinations("23");
    s.letterCombinations("79");
    s.letterCombinations("9");
    s.letterCombinations("");
    
    return 0;
}