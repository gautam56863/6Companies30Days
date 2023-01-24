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
class Solution
{
public:
    ListNode *removeZeroSumSublists(ListNode *head)
    {
        vector<int> v;
        ListNode *p = head;
        while (p)
        {
            v.push_back(p->val);
            p = p->next;
        }
        int sum = 0;
        unordered_map<int, int> m;
        m[0] = -1;
        for (int i = 0; i < v.size(); i++)
        {
            sum = sum + v[i];
            if (m.find(sum) != m.end())
            {
                int g = m[sum];
                while (i >= 0 && i > g)
                {
                    m.erase(sum);
                    sum = sum - v[i];
                    v.erase(v.begin() + i);
                    i--;
                }
            }
            m[sum] = i;
        }
        if (v.size() == 0)
            return NULL;
        p = head;
        for (int i = 0; i < v.size(); i++)
        {
            p->val = v[i];

            if (i == v.size() - 1)
                p->next = NULL;
            else
                p = p->next;
        }

        return head;
    }
};