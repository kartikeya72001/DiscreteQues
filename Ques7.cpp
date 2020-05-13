#include<iostream>
using namespace std;
int divisor[100];
int x=0;
void Swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                Swap(&arr[j], &arr[j+1]);
}
void ObtainDiv(int num)
{
    for(int i=1;i<=num;i++)
    {
        if(num%i==0)
        {
            divisor[x]=i;
            x++;
        }
    }
}
bool CheckLattice(int *arr, int n)
{
    int flag=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<x;j++)
        {
            if(arr[i]==divisor[j])
                flag++;
        }
    }
    if(flag==n)
        return true;
    return false;
}
int Prime(int *arr, int n)
{
    int count = 0;
    for(int i=1;i<n;i++)
    {
        int flag=1;
        for(int j=1;j<i;j++)
        {
            if(arr[i]%j==0)
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
            count++;
    }
    return count;
}
bool Checker(int *arr, int n)
{
    for(int i=0;i<n;i++)
        if(arr[i]==1)
            return true;
    return false;
}
int main()
{
    int n, arr[100];
    cout<<"Enter the no of elements\n";
    cin>>n;
    cout<<"Enter the elements\n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    bubbleSort(arr,n);
    int large = arr[n-1];
    cout<<"Maximum Element: "<<large<<endl;
    ObtainDiv(large);
    //cout<<endl;
    //int noP = Prime(arr,n);

   //if((Checker(arr,n)))
    //{
        if(CheckLattice(arr,n))
            cout<<"Given Poset is a Lattice\n";
    //}

    else
        cout<<"Not a Lattice\n";
    cout<<endl;
    cout<<"Kartikeya Agarwal\n2019UCO1692";
    return 0;
}
/*
6
1 2 3 6 8 12

7
1 2 4 6 8 24 48
*/
