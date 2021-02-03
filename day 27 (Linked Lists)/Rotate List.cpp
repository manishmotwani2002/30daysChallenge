//naive approach:- make the last node point to first and second last to null, then repeat the steps k times- O(n*k)



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
    ListNode* rotateRight(ListNode* head, int k) {
        int count=1;
        if(k==0 || head==NULL || head->next==NULL)
            return head;
        ListNode  *temp=head,*root=head;
        while(temp->next != NULL)
        {
            count++;
            temp=temp->next;
        }
        temp->next=head;
        k=k%count; 
        for(int i=0;i<count-k;i++)
        {
            temp=temp->next;
        }
        root=temp->next;
        temp->next=NULL;
        return root;
    }
};
