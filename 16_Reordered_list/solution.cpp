#include <iostream>
#include <vector>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* curr = head;
        vector<ListNode*> nodes;
        while(curr){
            nodes.push_back(curr);
            curr = curr->next;
        }

        ListNode* it = head;
        int left_idx = 1;
        int right_idx = size(nodes)-1;

        while(left_idx < right_idx){
            it->next = nodes[right_idx];
            it = it->next;
            it->next = nodes[left_idx];
            it = it->next;
            right_idx--;
            left_idx++;
        }
        if (left_idx == right_idx){
            it->next = nodes[left_idx];
            it = it->next;
        }
        it->next = nullptr;
    }
};

int main(){
    Solution sol = Solution();
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
    for (ListNode* it = head; it != nullptr; it = it->next){
        cout << it->val << " ";
    }
    cout << endl;
    sol.reorderList(head);
    for (ListNode* it = head; it != nullptr; it = it->next){
        cout << it->val << " ";
    }
    cout << endl;
    
    Solution sol2 = Solution();
    ListNode* head2 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    for (ListNode* it = head2; it != nullptr; it = it->next){
        cout << it->val << " ";
    }
    cout << endl;
    sol2.reorderList(head2);
     for (ListNode* it = head2; it != nullptr; it = it->next){
        cout << it->val << " ";
    }
    cout << endl;
    return 0;
}