#include<iostream>
using namespace std;
void Pair(int *arr1, int *arr2, pair<int,int> *arr, int n)
{
    for(int i=0;i<n;i++)
    {
        arr[i] = make_pair(arr1[i],arr2[i]);
    }
}
bool SymmetericCheck(pair<int,int> *arrM, int n)
{
    for(int i=0;i<n;i++)
    {
        int flag=0;
        for(int j=0;j<n;j++)
        {
            if((arrM[i].first==arrM[j].second) && (arrM[i].second==arrM[j].first))
                flag = 1;
        }
        if(flag==0)
            return false;
    }
    return true;
}
bool ReflexiveCheck(pair<int,int> *arrM, int nr, int *arrU, int nu)
{
    int flag=0;
    for(int i=0;i<nr;i++)
    {
        for(int j=0;j<nu;j++)
        {
            if(arrU[j]==arrM[i].first && arrU[j]==arrM[i].second)
                flag++;
        }
    }
    if(flag == nu)
        return true;
    return  false;
}
bool TransitiveCheck(pair<int,int> *arrM,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arrM[j].first==arrM[i].second)
            {
                int check=0;
                for(int k=0;k<n;k++)
                {
                    if(arrM[k].second==arrM[j].second && arrM[k].first==arrM[i].first)
                    {
                        check=1;
                    }
                }
                if(!check)
                    return false;
            }
        }
    }
    return true;
}
int main()
{
    int nu;
    cout<<"Enter Size Of Univ Set\n";
    cin>>nu;
    int arr1[10000],arr2[10000], arrU[10000];
    cout<<"Universal Set\n";
    for(int i=0;i<nu;i++)
    {
        cin>>arrU[i];
    }
    cout<<"Size of Relation\n";
    int n;
    cin>>n;
    cout<<"Enter the element array a\n";
    for(int i=0;i<n;i++)
    {
        cin>>arr1[i];
    }
    cout<<"Enter the element array b\n";
    for(int i=0;i<n;i++)
    {
        cin>>arr2[i];
    }
    pair<int,int> arrM[1000];
    Pair(arr1, arr2, arrM,n);

    bool sym = (SymmetericCheck(arrM,n));
    bool refl = (ReflexiveCheck(arrM,n,arrU,nu));
    bool trans = (TransitiveCheck(arrM,n));

    cout<<endl;
    cout<<"Sym "<<sym<<endl<<"refl "<<refl<<endl<<"trans "<<trans<<endl;
    cout<<endl;

    if(sym&&refl&&trans)
        cout<<"Given Relation is Equivalence\n";
    else    cout<<"Not Equivalence\n";
    cout<<"Kartikeya Agarwal\n2019UCO1692";
    return 0;
}
