class Solution {
public:
    bool isValid(string str) {
    stack<char> s;
    int i, j, n = str.size();

    for (i = 0; i < n; i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            s.push(str[i]);
        }
        else
        {
            if (s.empty() == true)
                return false;
            else if (matching(s.top(), str[i]) == false)
                return false;
            else
                s.pop();
        }
    }
    if (s.empty() == true)
        return true;
    return false;
        
    }
    bool matching(char a, char b)
    {
    if (a == '(' && b == ')')
        return true;
    else if (a == '[' && b == ']')
        return true;
    else if (a == '{' && b == '}')
        return true;
    else
        return false;
    }
};