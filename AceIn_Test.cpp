#include <iostream>
using namespace std;
struct stack
{
    int arr[200000],now;
    stack() : now(0){}
    int top()
    {
        return arr[now-1];
    }
    void pop()
    {
        now--;
    }
    void push(int val)
    {
        arr[now++]=val;
    }
    int size()
    {
        return now;
    }
} st;

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    int m,num,inp;
    cin >> m;
    for(int p=0;p<m;p++)
    {
        cin >> num;
        if(num==1)
        {
            cin >> inp;
            st.push(inp);
        }
        else if(num==2)
        {
            if(st.size()==0)cout << "QQ\n";
            else st.pop();
        }
        else if(num==3)
        {
            if(st.size()==0)cout << "QQ\n";
            else cout << st.top()<<'\n';
        }
        else if(num==4)cout << st.size()<<'\n';
    }
    return 0;
}
