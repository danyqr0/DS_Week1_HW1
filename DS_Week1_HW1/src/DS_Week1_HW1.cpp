//============================================================================
// Name        : DS_Week1_HW1.cpp
// Author      : Daniel Ramirez
// Version     :
// Copyright   : HW1_Week1
// Description : Check brackets in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stack>
#include <string>

using std::cin;
using std::cout;
using std::stack;
using std::string;

struct Bracket {
    Bracket(char type, int positionb):
        type(type),
        positionb(positionb)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    int pos(){
        return positionb;
    }

    char type;
    int positionb;
};

stack <Bracket> opening_brackets_stack;
int position,posbracket;
int flag=0;

bool IsBalanced(string text){
    posbracket=0;
    if(text.length() >= 1 && text.length() < 10e5){
        for(position=1;position<=text.length();position++){
            char next=text[position-1];
            //char next=&text;
            posbracket=position;
            if (next == '(' || next == '[' || next == '{') {
                // Process opening bracket, write your code here
                opening_brackets_stack.push(Bracket(next,position));
            }
            if (next == ')' || next == ']' || next == '}') {
            // Process closing bracket, write your code here
                if(opening_brackets_stack.empty()) {
                    posbracket=position;
                    flag=1;
                    return false;
                }
                if(!((opening_brackets_stack.top()).Matchc(next))){
                    posbracket=position;
                    flag=2;
                    return false;
                }
                opening_brackets_stack.pop();
            }
        }
    }
    return opening_brackets_stack.empty();
}

int main() {
    string text;
    getline(std::cin, text);
    bool result;

    result=IsBalanced(text);

    if(result) cout<<"Success"<<"\n";
    else if(!result && flag==1) cout<<posbracket<<"\n";
    else if(!result && flag==2) cout<<posbracket<<"\n";
    else cout << (opening_brackets_stack.top()).pos() <<"\n";
    return 0;
   }
