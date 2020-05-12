#include<iostream>
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
void Union(int n1, int n2, int *arr1, int *arr2)
{
    cout<<"Union of Sets is: ";
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
int Intersection(int n1, int n2, int *arr1, int *arr2)
{
    cout<<"Intersection of sets is: ";
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
    return x;
}
int countDivisors(int N, int a, int b)
{
    int count1 = N / a;
    int count2 = N / b;

    int count3 = (N / (a * b));

    return count1 + count2 - count3;
}
int main()
{
    int n1,n2;
    int arr1[100],arr2[100];
    cout<<"Enter the size of first set\n";
    cin>>n1;
    cout<<"Enter the elements of the first set\n";
    for(int i=0;i<n1;i++)
    {
        cin>>arr1[i];
    }
    cout<<"Enter the size of second set\n";
    cin>>n2;
    cout<<"Enter the elements of the second set\n";
    for(int i=0;i<n2;i++)
    {
        cin>>arr2[i];
    }
    int n = Intersection(n1,n2,arr1,arr2);
    Union(n1,n2,arr1,arr2);
    cout<<"n(AUB) = n(A) + n(B) - n(A^B) where ^ is intersection\n";
    cout<<"According to Inclusion Exclusion Principle: "<<n1+n2-n<<endl<<endl;
    int N;
    cout<<"Enter the limiting Value\n";
    cin>>N;
    int a,b;
    cout<<"Enter the value of a and b\n";
    cin>>a>>b;
    cout<<"No. of divisors between 0 to "<<N<<" for "<<a<<", "<<b<<" are :"<< countDivisors(N, a, b);
    cout<<endl;
    cout<<"Kartikeya Agarwal\n2019UCO1692\n";
    return 0;
}
