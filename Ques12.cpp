#include<iostream>
using namespace std;

int vertices[12] = {0};
bool checker[15] = {false};
bool checker2[15] = {false};

class Graph{
public:
    int v;
    int arr[100][100];
    Graph(int V)
    {
        v = V;
    }
    void addEdge(int x, int y)
    {
        arr[x][vertices[x]++] = y;
        arr[y][vertices[y]++] = x;
    }
    void PrintList(int n)
    {
        for (int i=0;i<n;i++)
        {
            cout<<i<<"->";
            for(int j=0;j<vertices[i];j++)
            {
                cout<<arr[i][j];
            }
            cout<<endl;
        }
        return;
    }
    void checkPath(int a, int b, string s)
    {
        if(a==b)
        {
            cout<<s<<b<<endl;
            return;
        }
        checker[a] = true;
        for(int j=0;j<vertices[a];j++)
        {
            if(checker[arr[a][j]] == false)
            {

                checkPath(arr[a][j],b,s + to_string(a) + "->");
            }
        }
            checker[a] = false;
    }
    void Cycles(int a)
    {
        for(int i=0;i<vertices[a];i++)
        {
            Cycle(a,arr[a][i],"",a);
        }
        return;
    }
    void Cycle(int a, int b,string s,int con)
    {
        if(a==b && s.length()>3)
        {
            cout<<s<<b<<"->"<<con<<endl;
            return;
        }
        checker2[a] = true;
        for(int j=0;j<vertices[a];j++)
        {
            if(checker2[arr[a][j]] == false)
            {
                Cycle(arr[a][j],b,s + to_string(a) + "->",con);
            }
        }
        checker2[a] = false;
    }
};
int main()
{
    int n,a,b;
    cout<<"Enter Graph Size\n";
    cin>>n;
    a=n;
    Graph g(n);
    cout<<"Enter Pairs\n";
    while(n--)
    {
        int x,y;
        cin>>x>>y;
        g.addEdge(x,y);
    }
    g.PrintList(a);
    cout<<"Enter the start and end pt\n";
    cin>>a>>b;
    g.checkPath(a,b,"");
    cout<<endl;
    cout<<"Enter a cycle element\n";
    cin>>a;
    g.Cycles(a);
    cout<<"Kartikeya Agarwal\n2019UCO1692\n";
    return 0;
}
