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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        vector<int> arr;
        stack<int> st;
        ListNode* temp = head;
        while (temp) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        int n = arr.size();
        ans.resize(n, 0);
        st.push(0);

        for (int i = n - 1; i >= 0; i--) {
            int curr = arr[i];

            while (st.top() != 0 && st.top() <= curr) {
                st.pop();
            }
            ans[i] = st.top();
            st.push(curr);
        }

        return ans;
    }

};