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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fst = head;
        ListNode* snd = head;
        
        for(int i=0; i<n; i++){
            fst = fst->next;
        }
        
        if(fst==nullptr){
            return head->next;
        }
        
        while(fst->next!=nullptr){
            fst = fst->next;
            snd = snd->next;
        }
        
        snd->next = (snd->next)->next;
        
        return head;
    }
};