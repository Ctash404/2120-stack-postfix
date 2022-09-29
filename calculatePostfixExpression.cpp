/*
 * Name:Conner Tash
 * Date Submitted:9-29-2022
 * Lab Section: 003
 * Assignment Name: Stack-based Postfix Expression Calculator
 */
#include <string>
#include <stack>
#include <iostream>
using namespace std;

//Calculates a postfix expression with integer operands using a stack
//The expression is represented using an array of strings
//Each string is either an operand or operator symbol
//Operator symbols:
//"+" addition
//"-" subtraction
//"*" multiplication
//"/" divison
//"%" remainder
//Example expression: "8", "5", "-" evaluates to a result of 3:
//1: push 8, 2: push 5,
//3: "-"-> pop top two values, earlier value is the left-side operand: 8 - 5
//The result of the operation (8-5) is 3, push 3 onto stack
//After evaluation of the expression, the final result should be
//the only value on the stack, return 0 if the stack is
//non-empty after popping the result
//Return 0 if expression is zero-length or if there are insufficient operands
//for an operation
//The STL Stack class can be used
//To easily convert a numeric string to an int you may use the stoi() function
//which takes a string as a parameter and returns a string
int calculatePostfixExpression(string expression[], int length)
{
    int total = 0;
    int lvalue = 0;
    int rvalue = 0;
    stack<string> myStack;
    for(int i = 0; i < length; ++i)
    {
        if(isdigit(expression[i][0]))
        {
            myStack.push(expression[i]);
        }
        else if(expression[i] == "-")
        {
            if(myStack.empty())
            {
                return 0;
            }
            rvalue = stoi(myStack.top());
            myStack.pop();
            if(myStack.empty())
            {
                return 0;
            }
            lvalue = stoi(myStack.top());
            myStack.pop();
            total = lvalue - rvalue;
            myStack.push(to_string(total));
        }
        else if(expression[i] == "+")
        {
            if(myStack.empty())
            {
                return 0;
            }
            rvalue = stoi(myStack.top());
            myStack.pop();
            if(myStack.empty())
            {
                return 0;
            }
            lvalue = stoi(myStack.top());
            myStack.pop();
            total = lvalue + rvalue;
            myStack.push(to_string(total));
        }
        else if(expression[i] == "*")
        {
            if(myStack.empty())
            {
                return 0;
            }
            rvalue = stoi(myStack.top());
            myStack.pop();
            if(myStack.empty())
            {
                return 0;
            }
            lvalue = stoi(myStack.top());
            myStack.pop();
            total = lvalue * rvalue;
            myStack.push(to_string(total));
        }
        else if(expression[i] == "/")
        {
            if(myStack.empty())
            {
                return 0;
            }
            rvalue = stoi(myStack.top());
            myStack.pop();
            if(myStack.empty())
            {
                return 0;
            }
            lvalue = stoi(myStack.top());
            myStack.pop();
            total = lvalue / rvalue;
            myStack.push(to_string(total));
        }
        else if(expression[i] == "%")
        {
            if(myStack.empty())
            {
                return 0;
            }
            rvalue = stoi(myStack.top());
            myStack.pop();
            if(myStack.empty())
            {
                return 0;
            }
            lvalue = stoi(myStack.top());
            myStack.pop();
            total = lvalue % rvalue;
            myStack.push(to_string(total));
        }
        
    }
    return total;
}