#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    char data;
    struct node *left, *right;
} * Tree;

Tree newNode(char c)
{
    Tree n = new node;
    n->data = c;
    n->left = n->right = nullptr;
    return n;
}
 
Tree build(string& s)
{
 
    stack<Tree> stackTree;
    stack<char> stackChar;
    Tree t, t1, t2;
    int p[123] = { 0 };
    p['+'] = p['-'] = 1, p['/'] = p['*'] = 2, p['^'] = 3,
    p[')'] = 0;
 
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(') {
            stackChar.push(s[i]);
        }
        else if (isalpha(s[i]))
        {
            t = newNode(s[i]);
            stackTree.push(t);
        }
        else if (p[s[i]] > 0)
        {
        
            while (
                !stackChar.empty() && stackChar.top() != '('
                && ((s[i] != '^' && p[stackChar.top()] >= p[s[i]])
                    || (s[i] == '^'
                        && p[stackChar.top()] > p[s[i]])))
            {
 
        
                t = newNode(stackChar.top());
                stackChar.pop();

                t1 = stackTree.top();
                stackTree.pop();

                t2 = stackTree.top();
                stackTree.pop();

                t->left = t2;
                t->right = t1;

                stackTree.push(t);
            }
            stackChar.push(s[i]);
        }
        else if (s[i] == ')') {
            while (!stackChar.empty() && stackChar.top() != '(')
            {
                t = newNode(stackChar.top());
                stackChar.pop();
                t1 = stackTree.top();
                stackTree.pop();
                t2 = stackTree.top();
                stackTree.pop();
                t->left = t2;
                t->right = t1;
                stackTree.push(t);
            }
            stackChar.pop();
        }
    }
    t = stackTree.top();
    return t;
}
 
void post_order(Tree root)
{
    if (root)
    {
        post_order(root->left);
        post_order(root->right);
        cout << root->data;
    }
}

void pre_order(Tree root)
{
    if(root){
        cout<<root->data;
        pre_order(root->left);
        pre_order(root->right);
    }
    
}
 
int main()
{
    string s = "A+B*C/D^F^G-k*(F+G*H^P-E)";
    s = "(" + s;
    s += ")";
    Tree root = build(s);
    cout<<"Post Order"<<endl;
    post_order(root);
    cout<<endl;
    cout<<"Pre Order"<<endl;
    pre_order(root);
    return 0;
}