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
    ListNode* add(ListNode* l1, ListNode* l2, int carry)
    {
        if (l1 == NULL && l2 == NULL && carry == 0)
           return NULL;

        int x=0,y=0;
        if(l1!=NULL) x=l1->val;
        if(l2!=NULL) y=l2->val;
        int sum=x+y+carry;
        ListNode* node= new ListNode(sum%10);
        if(l1!=NULL) l1=l1->next;
        if(l2!=NULL) l2=l2->next;
        node->next=add(l1, l2, sum/10);
        return node;


    }



    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return add(l1,l2,0);
    }
};