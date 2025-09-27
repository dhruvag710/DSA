/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode*temp=headA;
        int x=0;
        int y=0;
        while(temp!=nullptr)
        {
            x++;
            temp=temp->next;
        }
        ListNode*temp1=headB;
        while(temp1!=nullptr)
        {
            y++;
            temp1=temp1->next;
        }
        int diff=x-y;
        temp=headA;
        temp1=headB;
        if(diff>0)
        {
           while(diff--)
           {
                temp=temp->next;
           }
        }
        else
        {
            while(diff<0)
            {
                temp1=temp1->next;
                diff++;
            }
        }
        while(temp!=nullptr)
        {
            if(temp==temp1) return temp;
            else
            temp=temp->next;
            temp1=temp1->next;
        }
    return 0;
    }
};