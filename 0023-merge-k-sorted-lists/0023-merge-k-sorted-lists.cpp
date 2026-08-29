/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void merge(vector<ListNode*>& v) {
        ListNode* h1 = v.back();
        ListNode* h2 = v[v.size() - 2];

        ListNode* dummy = new ListNode;        
        ListNode* temp = dummy;

        while(h1 && h2) {
            if(h1->val < h2->val) {
                temp->next = h1;
                temp = h1;
                h1 = h1->next;
            } else {
                temp->next = h2;
                temp = h2;
                h2 = h2->next;
            }
        }

        h1 ? temp->next = h1 : temp->next = h2;

        v.pop_back();
        v.pop_back();

        v.push_back(dummy->next);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();

        if(n == 0) return NULL;

        while(lists.size() > 1) { merge(lists); }

        return lists[0];
    }
};