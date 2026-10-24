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
    ListNode* partition(ListNode* head, int x) {
        ListNode *temp1=new ListNode(-1);
        ListNode *temp2=new ListNode(-1);
        ListNode *left=temp1;
        ListNode *right=temp2;

        ListNode *curr=head;

        while(curr!=nullptr)
        {
            if(curr->val<x)
            {
                left->next=curr;
                left=left->next;
            }
            else
            {
                right->next=curr;
                right=right->next;
            }
            curr=curr->next;
        }
        left->next=temp2->next;
        right->next=nullptr;
        return temp1->next;
    }
};