#include <iostream>
#include <string>
using namespace std;
void parentheses(string &s, int &len);
void deletion(string &s, int start, int end, int &len);
void display(string &s, int &len);

int main(){
    string s = "(()())((()))";
    int len = s.size();
    cout << "Original String : ";
    display(s,len);
    parentheses(s,len);
    cout << "New String : ";
    display(s,len);
    return 0;
}

void parentheses(string &s, int &len){
    int start, end, count;
    for (int i = 0; i < len; i++){
        start = i;
        count = 1;
        for (int j = i+1; j < len; j++){
            if (s[j] == '('){
                count++;
            }
            else if (s[j] == ')'){
                count--;
            }
            if (count == 0){
                end = j;
                i = j - 2;
                deletion(s,start,end,len);
                break;
            }
        }
    }
}

void deletion(string &s, int start, int end, int &len){
    for (int i = start; i < len; i++){
        s[i] = s[i+1];
    }
    for (int i = end - 1; i < len; i++){
        s[i] = s[i+1];
    }
    len -= 2;
}

void display(string &s, int &len){
    for (int i = 0; i < len; i++){
        cout << s[i];
    }
    cout << endl;
}