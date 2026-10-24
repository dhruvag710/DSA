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
    void reorderList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return;

        ListNode *slow=head;
        ListNode *fast=head;

        while(fast!=nullptr && fast->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        //reversing second half
        ListNode *right=slow->next;
        slow->next=nullptr;

        ListNode *prev=nullptr;
        ListNode* curr=right;
        while(curr!=nullptr)
        {
            ListNode *temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        right=prev;

        //merging

        ListNode *left=head;
        while(right!=nullptr)
        {
            ListNode *leftNext=left->next;
            ListNode *rightNext=right->next;

            left->next=right;
            right->next=leftNext;

            left=leftNext;
            right=rightNext;
        }
    }
};