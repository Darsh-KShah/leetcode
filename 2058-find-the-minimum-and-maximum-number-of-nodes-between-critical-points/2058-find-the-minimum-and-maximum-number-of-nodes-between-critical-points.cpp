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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head->next->next == NULL) return {-1, -1};

        int start = 0, prev = -1, mini = 1e6, idx = 1;

        ListNode* temp = head->next;
        ListNode* prv = head;

        while(temp->next != NULL) {
            if(prv->val < temp->val && temp->val > temp->next->val || prv->val > temp->val && temp->val < temp->next->val) {
                if(start) mini = min(mini, idx - prev);
                else start = idx;

                prev = idx;
            }

            idx++;

            prv = temp;
            temp = temp->next;
        }

        if(mini == 1e6) return {-1, -1};

        return {mini, prev - start};

    }
};