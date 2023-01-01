class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> stk;
        for (auto it : tokens)
        {
            if (it == "+")
            {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                stk.push(a + b);
            }
            else if (it == "-")
            {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                stk.push(b - a);
            }
            else if (it == "/")
            {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                stk.push(b / a);
            }
            else if (it == "*")
            {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                stk.push(b * a);
            }
            else
            {
                int a = 0;
                int y = 0;
                int f = 0;
                if (it[0] == '-')
                {
                    y++;
                    f++;
                }
                for (int i = y; i < it.size(); i++)
                {
                    a = a * 10 + (it[i] - '0');
                }
                if (f)
                    a = a * (-1);
                cout << a << endl;
                stk.push(a);
            }
        }
        return stk.top();
    }
};