#include<iostream>
using namespace std;
bool AssociativeAdd(int  n, int *arr)
{
    int counter = 0;
    for(int i=0;i<n-2;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i]+(arr[i+1]+arr[i+2]) == (arr[j]+arr[j+1])+arr[j+2])
                counter++;
        }
    }
    if(counter >= n-2)
        return true;
    else
        return false;
}
bool AssociativeSub(int  n, int *arr)
{
    int counter = 0;
    for(int i=0;i<n-2;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i]-(arr[i+1]-arr[i+2]) == (arr[j]-arr[j+1])-arr[j+2])
                counter++;
        }
    }
    if(counter >= n-2)
        return true;
    else
        return false;
}
bool AssociativeMul(int  n, int *arr)
{
    int counter = 0;
    for(int i=0;i<n-2;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i]*(arr[i+1]*arr[i+2]) == (arr[j]*arr[j+1])*arr[j+2])
                counter++;
        }
    }
    if(counter >= n-2)
        return true;
    else
        return false;
}
bool AssociativeDiv(int  n, int *arr)
{
    int counter = 0;
    for(int i=0;i<n-2;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i]/(arr[i+1]/arr[i+2]) == (arr[j]/arr[j+1])/arr[j+2])
                counter++;
        }
    }
    if(counter >= n-2)
        return true;
    else
        return false;
}
bool ClosureAdd(int n, int *arr)
{
    int counter = 0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[j] = arr[i]+arr[i+1])
                counter++;
        }
    }
    if(counter>=n-2)
        return true;
    else return false;
}
bool ClosureSub(int n, int *arr)
{
    int counter = 0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[j] = arr[i]-arr[i+1])
                counter++;
        }
    }
    if(counter>=n-2)
        return true;
    else return false;
}
bool ClosureMul(int n, int *arr)
{
    int counter = 0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[j] = arr[i]*arr[i+1])
                counter++;
        }
    }
    if(counter>=n-2)
        return true;
    else return false;
}
bool ClosureDiv(int n, int *arr)
{
    int counter = 0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[j] = arr[i]/arr[i+1])
                counter++;
        }
    }
    if(counter>=n-2)
        return true;
    else return false;
}
bool IdentityAdd(int n, int *arr)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i] == 0)
            return true;
    }
    return false;
}
bool IdentitySub(int n, int *arr)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i] == 0)
            return true;
    }
    return false;
}
bool IdentityMul(int n, int *arr)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i] == 1)
            return true;
    }
    return false;
}
bool IdentityDiv(int n, int *arr)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i] == 1)
            return true;
    }
    return false;
}
bool InverseAdd(int n, int *arr)
{
    int counter=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(-arr[i] == arr[j])
                counter++;
        }
    }
    if(counter>=n-1)
        return true;
    else return false;
}
bool InverseSub(int n, int *arr)
{
    int counter=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(-arr[i] == arr[j])
                counter++;
        }
    }
    if(counter>=n-1)
        return true;
    else return false;
}
bool InverseMul(int n, int *arr)
{
    int counter=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(1/arr[i] == arr[j])
                counter++;
        }
    }
    if(counter>=n-1)
        return true;
    else return false;
}
bool InverseDiv(int n, int *arr)
{
    int counter=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(1/arr[i] == arr[j])
                counter++;
        }
    }
    if(counter>=n-1)
        return true;
    else return false;
}
int main()
{
    int n;
    int arr[100];
    char ch;
    cout<<"Enter size of group\n";
    cin>>n;
    cout<<"Enter the elements\n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter operator\n";
    cin>>ch;
    if(ch == '+')
    {
        if(InverseAdd(n,arr) && ClosureAdd(n,arr) && AssociativeAdd(n,arr) && IdentityAdd(n,arr))
            cout<<"Group\n";
        else    cout<<"Not a Group\n";
    }
    if(ch == '-')
    {
        if(InverseSub(n,arr) && ClosureSub(n,arr) && AssociativeSub(n,arr) && IdentitySub(n,arr))
            cout<<"Group\n";
        else    cout<<"Not a Group\n";
    }
    if(ch == '*')
    {
        if(InverseMul(n,arr) && ClosureMul(n,arr) && AssociativeMul(n,arr) && IdentityMul(n,arr))
            cout<<"Group\n";
        else    cout<<"Not a Group\n";
    }
    if(ch == '/')
    {
        if(InverseDiv(n,arr) && ClosureDiv(n,arr) && AssociativeDiv(n,arr) && IdentityDiv(n,arr))
            cout<<"Group\n";
        else    cout<<"Not a Group\n";
    }
    cout<<endl;
    cout<<"Kartikeya Agarwal\n2019UCO1692";
    return 0;
}
