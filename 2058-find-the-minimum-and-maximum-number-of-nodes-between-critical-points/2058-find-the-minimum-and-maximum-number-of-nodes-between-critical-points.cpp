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

        int start = 0, end = 0, mini = 1e6, idx = 1;

        ListNode* temp = head->next;
        ListNode* prv = head;
        ListNode* nxt = temp->next;

        while(temp->next != NULL) {
            if(prv->val < temp->val && temp->val > nxt->val || prv->val > temp->val && temp->val < nxt->val) {
                if(start) mini = min(mini, idx - end);
                else start = idx;

                end = idx;
            }

            idx++;

            prv = temp;
            temp = nxt;
            nxt = nxt->next;
        }

        if(mini == 1e6) return {-1, -1};

        return {mini, end - start};

    }
};