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
    ListNode* middleNode(ListNode* head) {
        ListNode *tortoise=head,*rabbit=head;
        while(rabbit!=0 && rabbit->next!=0)
        {
            tortoise=tortoise->next;        //it will move 1 step
            rabbit=rabbit->next;
            rabbit=rabbit->next;      //it will move twice as tortoise   i.e 2 steps
        }
        return tortoise;            //it will point to middle element of the linked list as per question
    }
};
