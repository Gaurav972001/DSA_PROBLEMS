class MinStack
{
public:
    stack<pair<int, int>> s;
    int minimum = INT_MAX;

    void push(int val)
    {
        s.push(make_pair(val, min(val, minimum)));
        minimum = min(minimum, val);
    }

    void pop()
    {
        s.pop();
        s.empty() == true ? minimum = INT_MAX : minimum = s.top().second;
    }

    int top()
    {
        return s.top().first;
    }

    int getMin()
    {
        return minimum;
    }
};
