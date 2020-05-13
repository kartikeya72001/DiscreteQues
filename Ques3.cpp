#include<iostream>
using namespace std;
template<typename T>
class Stack
{
    public:
    T arr[1000];
    int top = -1;

    void Push(T data)
    {
        if(top==999)
            return ;

        arr[++top]=data;
        return;
    }
    void Pop()
    {
        if(top==-1)
            return;
        top--;
        return;
    }
    T Top()
    {
        if(top==-1)
            return -1;
        return arr[top];
    }
    bool Empty()
    {
        if(top==-1)
            return true;
        return false;
    }
};
int Operate(int d1, int d2, char op)
{
    if(op=='A') return (d1 & d2);
    if(op=='O') return (d1 | d2);
    if(op=='I') return (!d1 | d2);
    if(op=='B') return !(d1^d2);
}
int AssignVal(char ch, int *val)
{
    int idx=ch-'a';
    return val[idx];
}
int Solve(string s, int *val)
{
    Stack<int> s1;
    Stack<char> s2;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='(')
            s2.Push(s[i]);
        if(s[i]>=65 && s[i]<=90)
            s2.Push(s[i]);
        if(s[i]>=97 && s[i]<=122)
        {
            s1.Push(AssignVal(s[i],val));
        }
        if(s[i]==')')
        {
            while(s2.Top()!='(' && !s2.Empty())
            {
                if(s2.Top()=='N')
                {
                    s2.Pop();
                    int a = s1.Top();
                    s1.Pop();
                    int b = (!a);
                    s1.Push(b);
                }
                else
                {
                    int a = s1.Top();
                    s1.Pop();
                    int b = s1.Top();
                    s1.Pop();
                    char oper = s2.Top();
                    s2.Pop();
                    s1.Push(Operate(b,a,oper));
                }
                s2.Pop();
            }
        }
    }
    return s1.Top();
}
void BinaryChange(int *arr, int i, int n)
{
    int k=n-1;

    while(i>=1)
    {
        int res=i%2;
        arr[k--]=res;
        i=i/2;
    }
}
int main()
{
    string s;
    cout<<"Enter Expression where\nN-negation\nA-and\nO-or\nI-implies\nB-bi-implies\n";
    cin>>s;
    int n;
    cout<<"Enter number of Variables\n";
    cin>>n;

    int *val = new int[n];
    for(int i=0;i<n;i++)
    {
        val[i]=0;
    }
    int t = 0;
    int f = 0;
    for(int i=0;i<(1<<n);i++)
    {
        BinaryChange(val,i,n);
        /*cout<<"Binary Change: "<<endl;
        for(int j=0;j<n;j++)
        {
            cout<<val[j]<<" ";
        }*/
        int check = Solve(s,val);
        if(check == 1)
        {
            t++;
        }
        else f++;
    }
    cout<<"True: "<<t<<endl;
    cout<<"False: "<<f<<endl;
    if(t==0)        cout<<"Contradiction\n";
    else if(f==0)   cout<<"Tautology\n";
    else    cout<<"Contingency\n";
    cout<<"Kartikeya Agarwal\n2019UCO1692";
    return 0;
}
/*
((aIb)B((Nb)I(Na)))
(aO(Na))
*/
