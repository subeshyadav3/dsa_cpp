#include<bits/stdc++.h>
#define SIZE 100
int tos=-1;
char myStack[SIZE];

using namespace std;

int main(){
    char exp[SIZE];
    cout<<"Enter the expression"<<endl;
    cin>>exp;
    cout<<exp;
    
    for(int i=0;exp[i]!='\0';i++){
        cout<<"value"<<exp[i]<<endl;
        cout<<"value tos"<<tos<<endl;
        cout<<"stack"<<myStack[tos]<<endl;
        if(exp[i]== '(' || exp[i] =='{' || exp[i]=='['){
                myStack[++tos]=exp[i];
        }
        else if(exp[i]==')' || exp[i]=='}' || exp[i]==']'){
            if(tos==-1){
                cout<<"Parenthesis Rule Error, Can't use closing parenthesis before opening!"<<endl;
                return 1;
            }
            if(exp[i]==')' && myStack[tos]=='('){
                myStack[tos--];
            }
            else if(exp[i]=='}' && myStack[tos]=='{'){
                myStack[tos--];
            }
            else if(exp[i]==']' && myStack[tos]=='['){
                myStack[tos--];
            }
            else {
                cout<<"Parenthesis order not matched!!"<<endl;
                return 1;
            }
        }
        else{
            continue;
        }
    }

    if(tos!=-1){
        cout<<"Missing closing parenthesis!"<<endl;
    }
    else{
        cout<<"All right!"<<endl;
    }

    return 0;
}