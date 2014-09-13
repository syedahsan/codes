#include<iostream>
#include<stack>
using namespace std;
void Put1(stack<int> *s,int a)
{
    
    if(s->empty()) {s->push(a); return;}
    int b = s->top();
    s->pop();
    if(b!=a)
        Put1(s,a);
    s->push(b);
    return;
}
void Rev_s(stack<int> *s)
{
        if(s->empty()) return;
        int a = s->top();
        s->pop();
        Rev_s(s);
        Put1(s,a);
        return;
}

int main()
{
        stack<int> s;
        int n,a;
        cin >> n;
        while(n--)
        {
                cin >> a;
                s.push(a);
        }
       // Rev_s(&s);
        while(!s.empty())
        {
            cout << s.top()<< " ";
            s.pop();
        }
        system("pause");
        return 0;
}
