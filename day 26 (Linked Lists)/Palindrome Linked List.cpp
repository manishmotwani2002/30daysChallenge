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
    ListNode* reverse(ListNode* root)
    {
        ListNode *pre=NULL,*next=NULL;
        
        while(root!=NULL)
        {
            next=root->next;
            root->next=pre;
            pre=root;
            root=next;
        }
        return pre;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return true;
        ListNode *fast=head,*slow=head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        
        slow->next=reverse(slow->next);
        slow=slow->next;
        
        while(slow!=NULL)
        {
            if(slow->val!=head->val)
                return false;
            slow=slow->next;
            head=head->next;
        }
        return true;
    }
};
