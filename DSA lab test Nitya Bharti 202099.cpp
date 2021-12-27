// C++ Program to convert infix to postfix expression using stack Data structure 
#include <iostream>
#include <string>
#define MAX 30
using namespace std;
char strk[30];
int top = -1;

void push(char alpha)
{
    if (top == MAX - 1)
    {
        cout << "stack is full ";
    }

    else
    {
        top++;
        strk[top] = alpha;
    }
}

char pop()
{
    char ch;
    if (top == -1)
    {
        cout << "stack is empty ";
    }
    else
    {
        ch = strk[top];
        strk[top] = '\0';
        top--;
        return (ch);
    }
    return 0;
}
int prec(char symbol)
{
    if (symbol == '+' || symbol == '-')
    {
        return (1);
    }

    if (symbol == '*' || symbol == '/')
    {
        return (2);
    }
    return 0;
}
string infixtopost(string infix)
{
    int i = 0;
    string postfix = "";
    while (infix[i] != '\0')
    {
        if (infix[i] >= 'a' && infix[i] <= 'z' || infix[i] >= 'A' && infix[i] <= 'Z')
        {
            postfix.insert(postfix.end(), infix[i]);
            i++;
        }
        else if (infix[i] == '(' || infix[i] == '{' || infix[i] == '[')
        {
            push(infix[i]);
            i++;
        }
        else if (infix[i] == ')' || infix[i] == '}' || infix[i] == ']')
        {
            if (infix[i] == ')')
            {
                while (strk[top] != '(')
                {
                    postfix.insert(postfix.end(), pop());
                }
                pop();
                i++;
            }
            if (infix[i] == ']')
            {
                while (strk[top] != '[')
                {
                    postfix.insert(postfix.end(), pop());
                }
                pop();
                i++;
            }

            if (infix[i] == '}')
            {
                while (strk[top] != '{')
                {
                    postfix.insert(postfix.end(), pop());
                }
                pop();
                i++;
            }
        }
        else
        {
            if (top == -1)
            {
                push(infix[i]);
                i++;
            }

            else if (prec(infix[i]) <= prec(strk[top]))
            {
                postfix.insert(postfix.end(), pop());

                while (prec(strk[top]) == prec(infix[i]))
                {
                    postfix.insert(postfix.end(), pop());
                    if (top < 0)
                    {
                        break;
                    }
                }
                push(infix[i]);
                i++;
            }
            else if (prec(infix[i]) > prec(strk[top]))
            {
                push(infix[i]);
                i++;
            }
        }
    }
    while (top != -1)
    {
        postfix.insert(postfix.end(), pop());
    }
    cout << "The converted postfix string is : " << postfix;
    return postfix;
}

int main()
{
    string infix, postfix;
    cout << "\nEnter the infix expression : "; 
    cin >> infix;
    postfix = infixtopost(infix);
    return 0;
}