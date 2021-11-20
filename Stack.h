#pragma once
#include <iostream>
#define boost ios_base::sync_with_stdio(0);
using namespace std;


template<class t>
class Stack {
private:
    struct StackNode
    {
        t item;
        StackNode* next;
    };
    StackNode* topPtr, * curPtr;
public:
    Stack() {
        topPtr = NULL;
        curPtr = NULL;
    }
    ~Stack() {
        destroy();
    }
    void destroy() {
        while (!isEmpty()) {
            curPtr = topPtr;
            topPtr = topPtr->next;
            curPtr->next = NULL;
            delete curPtr;
        }
    }
    bool isEmpty()
    {
        return topPtr == NULL;
    }
    void push(t newItem)
    {
        StackNode* newPtr = new StackNode;
        if (newPtr == NULL) {
            cout << "Stack push cannot allocate memory";
        }else{
            newPtr->item = newItem;
            newPtr->next = topPtr;
            topPtr = newPtr;
        }
    }
    void pop() {
        if (isEmpty())
            cout << "Stack empty on pop";
        else {
            StackNode* temp = topPtr;
            topPtr = topPtr->next;
            temp->next = NULL;
            delete temp;
        }
    }
    void pop(t& sItem) {

        if (isEmpty())
            cout << "Stack empty on pop";
        else {
            StackNode* temp = topPtr;
            sItem = temp->item;
            topPtr = topPtr->next;
            temp->next = NULL;
            delete temp;
        }
    }

    t getTop()
    {
        if (isEmpty()) {
            cout << "stack is empty!\n";
            return 0;
        }
        else {
            return topPtr->item;
        }
    }

    void display()
    {
        curPtr = topPtr;
        cout << "\nItems in the stack : ";
        cout << "[ ";
        while (curPtr != NULL)
        {
            cout << curPtr->item;
            curPtr = curPtr->next;
        }
        cout << " ]\n";
    }
};


/*
bool arePair(char open, char closed) {
    if (open == '(' && closed == ')')
        return true;
    else if (open == '[' && closed == ']')
        return true;
    else if (open == '{' && closed == '}')
        return true;
    return false;
}

bool areBalanced(string exp) {
    stack<char>s;
    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[' ) {
            s.push(exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (s.empty() || !arePair(s.top(), exp[i])) {
                return false;
            }
            else {
                s.pop();
            }
        }
    }
    return s.empty();
}
*/

/*
#include <iostream>
#include <stack>
#include <list>
#include <string>
#include <queue>
#include <stdlib.h>
#include "Stack.h"
#include "Sorts.h"
#include "orderedList.h"
#include "unorderedList.h"

#define ll long long
using namespace std;

// 2 * 4 - 2 ->  2 4 * 2 -
// 8 / 2 + 7 -4 * 2 -> 8 2 / 7 + 4 2 * -
// 10 * (2 + 1 + 5) / 2 - 1 -> 10 2 1 + 5 + * 2 / 1 -

// Function to convert Infix expression to postfix
string InfixToPostfix(string expression);

// Function to verify whether an operator has higher precedence over other
int HasHigherPrecedence(char operator1, char operator2);

// Function to verify whether a character is operator symbol or not.
bool IsOperator(char C);

// Function to verify whether a character is alphanumeric chanaracter (letter or numeric digit) or not.
bool IsOperand(char C);

int main()
{
    string expression;
    cout << "Enter Infix Expression \n";
    getline(cin, expression);
    string postfix = InfixToPostfix(expression);
    cout << "Output = " << postfix << "\n";
    return 0;

    return 0;
}

// Function to evaluate Postfix expression and return output
string InfixToPostfix(string expression)
{
    // Declaring a Stack from Standard template library in C++.
    stack<char> S;
    string postfix = ""; // Initialize postfix as empty string.
    for (unsigned int i = 0; i < expression.length(); i++) {

        // Scanning each character from left.
        // If character is a delimitter, move on.
        if (expression[i] == ' ' || expression[i] == ',') continue;

        // If character is operator, pop two elements from stack, perform operation and push the result back.
        else if (IsOperator(expression[i]))
        {
            while (!S.empty() && S.top() != '(' && HasHigherPrecedence(S.top(), expression[i]))
            {
                postfix += S.top();
                S.pop();
            }
            S.push(expression[i]);
        }
        // Else if character is an operand
        else if (IsOperand(expression[i]))
        {
            postfix += expression[i];
        }

        else if (expression[i] == '(')
        {
            S.push(expression[i]);
        }

        else if (expression[i] == ')')
        {
            while (!S.empty() && S.top() != '(') {
                postfix += S.top();
                S.pop();
            }
            S.pop();
        }
    }

    while (!S.empty()) {
        postfix += S.top();
        S.pop();
    }

    return postfix;
}

// Function to verify whether a character is english letter or numeric digit.
// We are assuming in this solution that operand will be a single character
bool IsOperand(char C)
{
    if (C >= '0' && C <= '9') return true;
    if (C >= 'a' && C <= 'z') return true;
    if (C >= 'A' && C <= 'Z') return true;
    return false;
}

// Function to verify whether a character is operator symbol or not.
bool IsOperator(char C)
{
    if (C == '+' || C == '-' || C == '*' || C == '/' || C == '$')
        return true;

    return false;
}

// Function to verify whether an operator is right associative or not.
int IsRightAssociative(char op)
{
    if (op == '$') return true;
    return false;
}

// Function to get weight of an operator. An operator with higher weight will have higher precedence.
int GetOperatorWeight(char op)
{
    int weight = -1;
    switch (op)
    {
    case '+':
    case '-':
        weight = 1;
    case '*':
    case '/':
        weight = 2;
    case '$':
        weight = 3;
    }
    return weight;
}

// Function to perform an operation and return output.
int HasHigherPrecedence(char op1, char op2)
{
    int op1Weight = GetOperatorWeight(op1);
    int op2Weight = GetOperatorWeight(op2);

    // If operators have equal precedence, return true if they are left associative.
    // return false, if right associative.
    // if operator is left-associative, left one should be given priority.
    if (op1Weight == op2Weight)
    {
        if (IsRightAssociative(op1)) return false;
        else return true;
    }
    return op1Weight > op2Weight ? true : false;
}
*/


/*
#include <iostream>
#include <stack>
#include <list>
#include <string>
#include <queue>
#include <cassert>
#include <stdlib.h>
#include "Stack.h"
#include "Sorts.h"
#include "orderedList.h"
#include "unorderedList.h"
#include "arrayQueueType.h"
#include "LinkedQueue.h"
#define ll long long
using namespace std;

stack<int> addStack(stack<int> N1, stack<int> N2);
void display(stack<int>& res);

int main()
{
    stack<int> N1;
    N1.push(5);
    N1.push(8);
    N1.push(7);
    N1.push(4);

    stack<int> N2;
    N2.push(2);
    N2.push(1);
    N2.push(3);

    stack<int> res = addStack(N1, N2);

    display(res);
    return 0;
}

stack<int> addStack(stack<int> N1,stack<int> N2)
{
    stack<int> res;
    int sum = 0, carry = 0;

    while (!N1.empty() and !N2.empty()) {

        // Calculate the sum of the top
        // elements of both the stacks
        sum = (carry + N1.top() + N2.top());

        // Push the sum into the stack
        res.push(sum % 10);

        // Store the carry
        carry = sum / 10;

        // Pop the top elements
        N1.pop();
        N2.pop();
    }

    // If N1 is not empty
    while (!N1.empty()) {
        sum = (carry + N1.top());
        res.push(sum % 10);
        carry = sum / 10;
        N1.pop();
    }
    // If N2 is not empty
    while (!N2.empty()) {
        sum = (carry + N2.top());
        res.push(sum % 10);
        carry = sum / 10;
        N2.pop();
    }

    // If carry remains
    while (carry > 0) {
        res.push(carry);
        carry /= 10;
    }

    // Reverse the stack.so that
    // most significant digit is
    // at the bottom of the stack
    while (!res.empty()) {
        N1.push(res.top());
        res.pop();
    }
    res = N1;
    return res;
}

// Function to display the
// resultamt stack
void display(stack<int>& res)
{
    int N = res.size();
    string s = "";
    while (!res.empty()) {
        s = to_string(res.top()) + s;
        res.pop();
    }

    cout << s << endl;

}
*/