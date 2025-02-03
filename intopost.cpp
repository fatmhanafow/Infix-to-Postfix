#include<iostream>
#include<stack>
#include<string>
#include<cctype>
#include<unordered_map>
#include<cmath>

using namespace std;

// Determine the precedence of operators
int precedence(char op){
    if(op == '+' || op == '-' ) return 1;
    if(op == '*' || op == '/') return 2;
    if(op == '^') return 3;
    return 0;
}

// Apply the mathematical operation on two values
float applyOp(float x, float y, char op){
    switch(op){
        case '+' : return x + y;
        case '-' :return x - y;
        case '*' : return x * y; // Fixed multiplication symbol
        case '/' :return x / y;
        case '^' : return pow(x , y);
    }
    return 0;
}

// Convert infix expression to postfix expression
string infixToPostfix(string infix){
    stack<char> st;
    string postfix;

    for(char token : infix){
        if(isalnum(token)){
            // if the token is an operand
            postfix += token;
        }
        else if (token == '('){
        // If it's an opening parenthesis, push it onto the stack
            st.push(token);
        }
        else if(token == ')'){
            // If it's a closing parenthesis, pop from stack until an opening parenthesis is found
            while(st.top()!= '('){
                postfix += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop(); // Remove '(' from the stack

        }else {
            // if the token is an operator
            while(!st.empty() && precedence(st.top()) >= precedence(token)){
                postfix += st.top();
                st.pop();
            }
            st.push(token);
        }
    }
    // pop all operator from the stack
    while(!st.empty()){
        postfix += st.top();
        st.pop();
    }
    return postfix;
}

// Evaluate the postfix expression using given variable values
float evaluatepostfix(const string& postfix, const unordered_map<char ,float> &values){
    stack<float> operands;

    for(char ch : postfix){
        if(isalpha(ch)){
            // If it's a variable, retrieve its value from the map and push onto stack
            operands.push(values.at(ch));
        }else{
            // Pop two values from stack and apply the operator
            float val2 = operands.top();operands.pop();
            float val1 = operands.top();operands.pop();
            float result = applyOp(val1, val2, ch);
            operands.push(result);
        }
    }
    return operands.top(); // The final result is on top of the stack
}

int main(){
    string infix;
    
    cout << "Please enter an infix mathematical expression: ";    cout<< "please enter an infix string:";
    cin>> infix;

    unordered_map<char, float> values;

    string postfix = infixToPostfix(infix);

// Display the postfix expression
    cout<<"Equivalent postfix expression: "<<postfix << endl;
    cout<<"Please enter the values of the variables:" << endl ;
    
    // Get values of variables from user input
    for(char token : infix){
        if(isalpha(token)){
            if(values.find(token) == values.end()){
                 cout<< token<< ":";
                 cin>> values[token];
            } 
        }
    }
    float result = evaluatepostfix(postfix, values);
    cout<< "Final result:" << result << endl;
    return 0;
}

