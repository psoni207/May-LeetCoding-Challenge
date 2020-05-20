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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL){
            return head;
        }
        
        struct ListNode *evenHead, *oddHead;
        struct ListNode *even = head->next;
        struct ListNode *odd = head;
        
        struct ListNode *curr = head->next->next;
        
        evenHead = even;
        oddHead = odd;
        
        while(curr){
            odd->next = curr;
            even->next = curr->next;
            
            odd = odd->next;
            even = even->next;
            if(curr->next){
                curr = curr->next->next;
            }else{
                curr = NULL;
            }
        }
        
        odd->next = evenHead;
        return oddHead;
        
    }
};