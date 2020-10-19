#include<iostream>
#include<stack>

using namespace std;

bool isOperand(char c)
{
    if((c >= 'a' && c <='z')|| (c >='A' && c <='Z'))
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

string PrefixTopostfix(string prefix)
{
    stack <string> s;
    for(int i=prefix.length()-1;i>=0;i--)
    {
        if(isOperand(prefix[i]))
        {
            string op(1,prefix[i]);
            s.push(op);
        }
        else 
        {
           string op1=s.top();
           s.pop();
           string op2=s.top();
           s.pop();
           s.push(op1+op2+prefix[i]);
        }
    }
    return s.top();
}

int main()
{
    string postfix_exp,prefix_exp;
    cout<<" Enter the Prefix Expression:"<<endl;
    cin>>prefix_exp;
    stack <char> stack;
    cout<<"PRETFIX EXPRESSION :"<<prefix_exp<<endl;
    postfix_exp=PrefixTopostfix(prefix_exp);
    cout<<" POSTFIX EXPRESSION :"<<postfix_exp<<endl;

    return 0;
}