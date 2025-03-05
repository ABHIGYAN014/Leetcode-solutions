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
        
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast!=NULL &&fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;


        //recursive
        // int length=0;
        // ListNode*temp=head;
        // while(temp1==temp2)
        // {
        //     temp1=temp1->next;}

    //     while(temp!=NULL)
    //     {
    //         temp=temp->next;
    //         length++;
    //     }
    //     int middle;
    //     if(length%2==0)
    //     {
    //          middle=(length/2)+1;
    //     }
    //     else
    //     {
    //         middle=(length+1)/2;
    //     }
    //     for(int i=0;i<middle-1;i++)
    //     {
    //         temp1=temp1->next;
    //     }
    //     return temp1;
    }
};