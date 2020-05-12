#include <iostream>
using namespace std;
void Display(int n,int *arr)
{   cout<<"{ ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<",";
    }
    cout<<" }";
    cout<<endl;
    return;
}
void Swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
int removeDuplicates(int arr[], int n)
{
    if (n==0 || n==1)
        return n;
    int temp[n];
    int j = 0;
    for (int i=0; i<n-1; i++)
        if (arr[i] != arr[i+1])
            temp[j++] = arr[i];
    temp[j++] = arr[n-1];
    for (int i=0; i<j; i++)
        arr[i] = temp[i];
    return j;
}
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)

    for (j = 0; j < n-i-1; j++)
        if (arr[j] > arr[j+1])
            Swap(&arr[j], &arr[j+1]);
}
int binarySearch(int *arr,int n,int data)
{
    int s=0;
    int e=n-1;
    while(s<=e)
    {
        int mid=(s+e)/2;

        if(arr[mid]<data)
            s=mid+1;
        else if(arr[mid]==data)
            return mid;
        else
            e=mid-1;
    }
    return -1;
}
void Addition(int n1, int n2, int *arr1, int *arr2)
{
    int n=0;
    cout<<"Set Addition:\n";
    cout<<"{ ";
    int arr[100];
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<n2;j++)
        {
            cout<<arr1[i]+arr2[j]<<" ";
            n++;
        }
    }
    cout<<" }";
    cout<<endl;
    return;
}
void Subtraction(int n1, int n2, int *arr1, int *arr2)
{
    int n=0;
    cout<<"Set Subtraction:\n";
    cout<<"{ ";
    int arr[100];
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<n2;j++)
        {
            cout<<arr1[i]-arr2[j]<<",";
            n++;
        }
    }
    cout<<" }";
    cout<<endl;
    return;
}
void Union(int n1, int n2, int *arr1, int *arr2)
{
    int arr[10000];
    int x=0;
    int flag=0;
    for(;x<n1;x++)
    {
        arr[x]=arr1[x];
    }
    for(int i=0;i<n2;i++)
    {
        arr[x] = arr2[i];
        x++;
    }
    bubbleSort(arr,x);
    x = removeDuplicates(arr,x);
    Display(x,arr);
    return;
}
void Intersection(int n1, int n2, int *arr1, int *arr2)
{
    cout<<"Intersection of sets is: \n";
    int arr[10000];
    int x=0;
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<n2;j++)
        {
            if(arr1[i]==arr2[j])
            {
                arr[x] = arr2[j];
                x++;
            }
        }
    }
    Display(x,arr);
    return;
}
void Diferrence(int n1,int n2, int *arr1, int *arr2)
{
    cout<<"Diferrence of set is: \n";
    int arr[1000];
    int x=0;
    bubbleSort(arr1,n1);
    bubbleSort(arr2,n2);
    for(int i=0;i<n1;i++)
    {
        if(binarySearch(arr2,n2,arr1[i])==-1)
        {
            arr[x]=arr1[i];
            x++;
        }
    }

    Display(x,arr);
}
void SymmDiferrence(int n1,int n2, int *arr1, int *arr2)
{
    int arrx1[1000];
    int arrx2[1000];
    int x1=0;
    bubbleSort(arr1,n1);
    bubbleSort(arr2,n2);
    for(int i=0;i<n1;i++)
    {
        if(binarySearch(arr2,n2,arr1[i])==-1)
        {
            arrx1[x1]=arr1[i];
            x1++;
        }
    }
    int x2=0;
    for(int i=0;i<n1;i++)
    {
        if(binarySearch(arr1,n2,arr2[i])==-1)
        {
            arrx2[x2]=arr2[i];
            x2++;
        }
    }
    cout<<"Symmetric Difference is: \n";
    Union(x1,x2,arrx1,arrx2);
}
int main()
{
    int n1,n2;
    int arr1[10000];
    int arr2[10000];
    cout<<"Enter the size of first set\n";
    cin>>n1;
    cout<<"Enter the set\n";
    for(int i=0;i<n1;i++)
    {
        cin>>arr1[i];
    }
    cout<<"Enter the size of second set\n";
    cin>>n2;
    cout<<"Enter the set\n";
    for(int i=0;i<n2;i++)
    {
        cin>>arr2[i];
    }
    cout<<"\n\n";
    Addition(n1,n2,arr1,arr2);
    Subtraction(n1,n2,arr1,arr2);
    cout<<"Union of Sets\n";
    Union(n1,n2,arr1,arr2);
    Intersection(n1,n2,arr1,arr2);
    cout<<"A-B ";
    Diferrence(n1,n2,arr1,arr2);
    cout<<"B-A ";
    Diferrence(n2,n1,arr2,arr1);
    SymmDiferrence(n1,n2,arr1,arr2);
    cout<<endl;
    cout<<"Kartikeya Agarwal\n2019UCO1692";
    return 0;
}
