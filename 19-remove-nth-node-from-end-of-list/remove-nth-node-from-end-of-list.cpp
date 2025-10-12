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
        ListNode*temp=head;
        int count=0;
        while(temp!=nullptr)
        {
            count++;
            temp=temp->next;
        }
        if(count==n)
        {
            ListNode* newHead = head->next;
            delete head; 
            return newHead;
        }
        int pos=count-n-1;
        temp=head;
        for(int i=0;i<pos;i++)
        {
            temp=temp->next;
        }
        ListNode*toDelete=temp->next;
        temp->next=temp->next->next;
        delete toDelete;
        return head;
    }
};