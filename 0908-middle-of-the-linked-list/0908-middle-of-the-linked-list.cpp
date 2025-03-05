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
        int length=0;
        ListNode*temp=head;
        ListNode*temp1=head;
        // ListNode*temp2=tail;

        // while(temp1==temp2)
        // {
        //     temp1=temp1->next;}
        while(temp!=NULL)
        {
            temp=temp->next;
            length++;
        }
        int middle;
        if(length%2==0)
        {
             middle=(length/2)+1;
        }
        else
        {
            middle=(length+1)/2;
        }
        for(int i=0;i<middle-1;i++)
        {
            temp1=temp1->next;
        }
        return temp1;
    }
};