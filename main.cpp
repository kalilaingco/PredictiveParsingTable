#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <cstring>

using namespace std;

void printStack(stack<char> st);

int main(){

    //initialize map and insert values of parsing table
    // key = char
    // value = string
    
    map<char, string> mapE;
    map<char, string> mapQ;
    map<char, string> mapT;
    map<char, string> mapR;
    map<char, string> mapF;
    
    mapE['i'] = "TQ";
    mapE['('] = "TQ";

    mapQ['+'] = "+TQ";
    mapQ['-'] = "-TQ";
    mapQ[')'] = "lambda";
    mapQ['$'] = "accepted";

    mapT['i'] = "FR";
    mapT['('] = "FR";

    mapR['+'] = "lambda";
    mapR['-'] = "lambda";
    mapR['*'] = "*FR";
    mapR['/'] = "/FR";
    mapR[')'] = "lambda";
    mapR['$'] = "lambda";

    mapF['i'] = "i";
    mapF['('] = "(E)";


    //initialize stack
    stack<char> st;
    st.push('$'); //will be compared to $ at the end for acceptance
    st.push('E'); // starting state 
    cout << "Stack: ";
    printStack(st);
    cout << "\n";
    char stackTop = st.top();
    st.pop();


    string inputString; // string to be traced 
    cout << "please input a string ending with $ \n";
    cin >> inputString;

    const char* pInputString = &inputString[0]; //starts pointer at first character in string
    cout << *pInputString << " \n"; //prints content of pointer
    char compChar = *pInputString;
    
    //compare stack top with input
    while(!st.empty()){
        if(stackTop == compChar){ // terminal
            pInputString++;
            compChar = *pInputString; 
            cout << "\n";
            cout << *pInputString << " \n";
            stackTop = st.top();
            st.pop();                           //equal then read next character
        }
        else if (stackTop == 'E') { // non-terminal 
             if(mapE.find(compChar) != mapE.end()){
                if(mapE.at(compChar) == "TQ"){
                    st.push('Q');
                    st.push('T');
                    cout << "Stack: ";
                    printStack(st);
                    cout << "\n";
            } 
        }  else {
                cout << "rejected";
                break;
            }
            stackTop = st.top();
            st.pop();
            cout << "Stack: ";
            printStack(st);
            cout << "\n";
        }
        else if (stackTop == 'Q') { 
            if(mapQ.find(compChar) != mapQ.end()){
                if(mapQ.at(compChar) == "+TQ"){
                    st.push('Q');
                    st.push('T');
                    st.push('+');
                    cout << "Stack: ";
                    printStack(st);
                    cout << "\n";
                }
                if(mapQ.at(compChar) == "-TQ"){
                    st.push('Q');
                    st.push('T');
                    st.push('-');
                    cout << "Stack: ";
                    printStack(st);
                    cout << "\n";
                }
                if(mapQ.at(compChar) == "lambda"){
                    cout << "Stack: ";
                    printStack(st);
                    cout << "\n";
                
                }
                if(mapQ.at(compChar) == "accepted"){
                    cout << "accepted";
                    break;
                }
            }
                else {
                    cout << "rejected";
                    break;
                }

            stackTop = st.top();
            st.pop();
            cout << "Stack: ";
            printStack(st);
            cout << "\n";
        }   

        else if (stackTop == 'T') {
            if(mapT.find(compChar) != mapT.end()){
                if(mapT.at(compChar) == "FR"){
                    st.push('R');
                    st.push('F');
                    cout << "Stack: ";
                    printStack(st);
                    cout << "\n";
                }
            }
                else {
                    cout << "rejected";
                    break;
                }
            stackTop = st.top();
            st.pop();
            cout << "Stack: ";
            printStack(st);
            cout << "\n";
        }

        else if (stackTop == 'R') {
            if(mapR.find(compChar) != mapR.end()){
                if(mapR.at(compChar) == "lambda"){
                    cout << "Stack: ";
                    printStack(st);
                    cout << " \n";

                }
                if(mapR.at(compChar) == "*FR"){
                    st.push('R');
                    st.push('F');
                    st.push('*');
                    cout << "Stack: ";
                    printStack(st);
                    cout << " \n";
                }
                if(mapR.at(compChar) == "/FR"){
                    st.push('R');
                    st.push('F');
                    st.push('/');
                    cout << "Stack: ";
                    printStack(st);
                    cout << " \n";
                }
            }
            else {
                cout << "rejected";
                break;
            }
            stackTop = st.top();
            st.pop();
            cout << "Stack: ";
            printStack(st);
            cout << "\n";
        }
        else if (stackTop == 'F'){
            if(mapF.find(compChar) != mapF.end()){
                if(mapF.at(compChar) == "i"){
                    st.push('i');
                    cout << "Stack: ";
                    printStack(st);
                    cout << "\n";
                }
                if(mapF.at(compChar) == "(E)"){
                    st.push(')');
                    st.push('E');
                    st.push('(');
                    cout << "Stack: ";
                    printStack(st);
                    cout << "\n";
                }
                
            }
            else {
                    cout << "rejected";
                    break;
                }
            stackTop = st.top();
            st.pop();
            cout << "Stack: ";
            printStack(st);
            cout << "\n";
        }
        else if (st.empty()){
            cout << "error";
            break;
        }
    }


    

    return 0;
}

void printStack(stack<char> st){
    if (st.empty())
        return;
    char temp = st.top();
    st.pop();
    printStack(st);
    cout << temp << " ";
    st.push(temp);
}

