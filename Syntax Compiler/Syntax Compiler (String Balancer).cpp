#include <iostream>
#include <string.h>
#include <sstream>

using namespace std;

const int max_size=90;

template <class T>class Balance{
private:
    T arr[max_size];
    int top=-1;
public:
    bool isFull(){
        if(arr[max_size-1]!=NULL)
            return 0;
        return 1;
    }


    bool isempty(){
        if(arr[0]==NULL)
            return 1;
        return 0;
    }

     void push(T num){
        if (isFull()) //return if stack is full
        {
            cout<<"List is full"<<endl;
            return;
        }
        top = top + 1; //increment top before insertion
        arr[top] = num; // insert value
    }

    void pop(){
        if(isempty()){
            cout<<"List is Empty!!"<<endl;
            return;
        }
            top=top-1;
    }

    void disp_list(){
        for(int i=top; i>=0; i--){
            cout<<arr[i]<<endl;
        }
    }

    void check_for_balance(){
        if(top==-1)
            cout<<"Code is balanced!"<<endl;
        else
            cout<<"Code is unbalanced!"<<endl;
    }

};



int main()
{
Balance<char>b1;
string s="int main(){int i=0; i<5; i++;delete i; float b=1.5; return 0;}{}{}{}{}{}[][][][]";
string::size_type pos=string::npos;
for(string::size_type i=0; i<s.size(); ++i) {
  if(s[i] == '{') {
    pos=i;
    if(pos != string::npos) {
        b1.push('{');
    }
    }
    else if(s[i] == '[') {
        pos=i;
        if(pos != string::npos) {
            b1.push('[');
        }
    }
    else if(s[i] == '(') {
        pos=i;
        if(pos != string::npos) {
            b1.push('(');
        }
    }
}

pos=string::npos;
for(string::size_type i=0; i<s.size(); ++i) {
  if(s[i] =='}') {
    pos=i;
    if(pos != string::npos) {
      b1.pop();
    }
    }
    else if(s[i] ==']') {
        pos=i;
        if(pos != string::npos) {
          b1.pop();
        }
    }
    else if(s[i] ==')') {
        pos=i;
        if(pos != string::npos) {
          b1.pop();
        }
    }
}
b1.check_for_balance();



    return 0;
}
