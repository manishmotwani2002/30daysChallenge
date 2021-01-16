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
    void insert(ListNode **ans,int value)
    {
        ListNode *p,*last=*ans;
        p=new ListNode;
        p->val=value;
        p->next=NULL;
        if(*ans==NULL)
        {
            *ans=p;
        }
        else
        {
            while(last->next!=NULL)
            {
                last=last->next;	
            }
            last->next=p;
        }
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *ans=NULL;
        while(l1!=0 && l2!=0)
        {
            if(l1->val == l2->val)
            {
                insert(&ans,l1->val);
                insert(&ans,l2->val);
                l1=l1->next;
                l2=l2->next;
            }
            else if(l1->val > l2->val)
            {
                insert(&ans,l2->val);
                l2=l2->next;
            }
            else
            {
                insert(&ans,l1->val);
                l1=l1->next;
            }
            
        }
        if(l1==NULL)
        {
            while(l2!=0)
            {
                insert(&ans,l2->val);
                l2=l2->next;
            }
        }
        else
        {
            while(l1!=0)
            {
                insert(&ans,l1->val);
                l1=l1->next;
            }
        }
        return ans;
    }
};
