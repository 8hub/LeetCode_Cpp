#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.size() == k){
            return *min_element(nums.begin(), nums.end());
        }
        vector<int> minHeap(nums.begin(), nums.begin() + k);
        make_heap(minHeap.begin(), minHeap.end(), greater<int>()); //create a minHeap where root is minimal value
        vector<int>::iterator it = nums.begin() + k;
        while(it != nums.end()){
            if (minHeap.front() < *it){
                pop_heap(minHeap.begin(), minHeap.end(), greater<int>());
                minHeap.pop_back();
                minHeap.push_back(*it);
                push_heap(minHeap.begin(), minHeap.end(), greater<int>());
            }
            it++;
        }
        return minHeap.front();
    }
};


int main(){
    Solution sol = Solution();
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    cout << sol.findKthLargest(nums, k) << endl;    // 5
    vector<int> nums2 = {3,2,3,1,2,4,5,5,6};
    int k2 = 4;
    cout << sol.findKthLargest(nums2, k2) << endl;    // 4
    vector<int> nums3 = {2,1};
    int k3 = 1;

    cout << sol.findKthLargest(nums3, k3) << endl;    // 1

    return 0;
}