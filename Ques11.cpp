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
bool IdentityAdd(int n, int *arr)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i] == 0)
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
bool CommutativeAdd(int n, int *arr)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i]+arr[j]!=arr[j]+arr[i])
                return false;
        }
    }
    return true;
}
bool Semigroup(int n, int *arr)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                if( arr[i]*(arr[j]*arr[k]) != (arr[i]*arr[j])*arr[k] )
                    return false;
            }
        }
    }
    return true;
}
bool DistributeLeft(int n, int *arr)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                if( arr[i]*(arr[j]+arr[k]) != (arr[i]*arr[j])+(arr[i]*arr[k]) )
                    return false;
            }
        }
    }
    return true;
}
bool DistributeRight(int n, int *arr)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                if( (arr[i]+arr[j])*arr[k] != (arr[i]*arr[k])+(arr[j]*arr[k]) )
                    return false;
            }
        }
    }
    return true;
}
int main()
{
    int n, arr[100];
    cout<<"Enter size of group\n";
    cin>>n;
    cout<<"Enter Group Elements\n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    bool check = AssociativeAdd(n,arr) && ClosureAdd(n,arr) && IdentityAdd(n,arr) && InverseAdd(n,arr) && CommutativeAdd(n,arr) && Semigroup(n,arr) && DistributeLeft(n,arr) && DistributeRight(n,arr);
    if(check)
        cout<<"Entered elements form a ring\n";
    else    cout<<"Not a ring\n";
    cout<<endl;
    cout<<"Kartikeya Agarwal\n2019UCO1692";
    return 0;
}
