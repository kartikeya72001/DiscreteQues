#include<iostream>
using namespace std;
void input(int *arr,int n)
{
    for(int i=0;i<n;i++)
        cin>>arr[i];
}
void display(pair<int,int> *arr,int n)
{
    for(int i=0;i<n;i++)
        cout<<"("<<arr[i].first<<","<<arr[i].second<<")"<<"  ";
    cout<<endl;
}
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partitionOfArr(int *arr,int s,int e)
{
    int pivot = arr[e];
    int i =s-1;
    for (int j=s; j<=e- 1; j++)
    {
        if (arr[j]<=pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1],&arr[e]);
    return i+1;
}
int binarySearch(int *arr,int n,int data)
{
    int li=0;
    int ri=n-1;
    while(li<=ri)
    {
        int mid=(li+ri)/2;
        if(arr[mid]<data)
            li=mid+1;
        else if(arr[mid]==data)
            return mid;
        else
            ri=mid-1;
    }
    return -1;
}
void InsertionSort(int *arr,int n)
{
     int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int makePairArr(pair<int,int> *arr,int *set,int n)
{
    int k=0,i=0;
    while(i<n)
    {
        int count=0;
        for(int j=i;j<n;j++)
        {
            if(set[i]==set[j])
                count++;
            else
                break;
        }
        arr[k++]=make_pair(set[i],count);
        i=i+count;
    }
    return k;
}
void Union(pair<int,int> *arr1,int n1,pair<int,int> *arr2,int n2)
{
    int p1=0,p2=0,p3=0;
    pair<int,int> arr3[2000];
    while(p1<n1 && p2<n2)
    {
        if(arr1[p1].first<arr2[p2].first)
            arr3[p3++]=arr1[p1++];
        else if(arr1[p1].first>arr2[p2].first)
            arr3[p3++]=arr2[p2++];
        else
        {
            int max_count=max(arr1[p1].second,arr2[p2].second);
            arr3[p3++]=make_pair(arr1[p1].first,max_count);
            p2++; p1++;
        }
    }
    while(p1<n1)
        arr3[p3++]=arr1[p1++];
    while(p2<n2)
        arr3[p3++]=arr2[p2++];
    display(arr3,p3);
}

void Intersection(pair<int,int> *arr1,int n1,pair<int,int> *arr2,int n2)
{
    int p1=0,p2=0,p3=0;
    pair<int,int> arr3[2000];
    while(p1<n1 && p2<n2)
    {
        if(arr1[p1].first<arr2[p2].first)
            p1++;
        else if(arr1[p1].first>arr2[p2].first)
            p2++;
        else
        {
            int min_count=min(arr1[p1].second,arr2[p2].second);
            arr3[p3++]=make_pair(arr1[p1].first,min_count);
            p2++;
			p1++;
        }
    }
    display(arr3,p3);
}

void Sum(pair<int,int> *arr1,int n1,pair<int,int> *arr2,int n2)
{
    int p1=0,p2=0,p3=0;
    pair<int,int> arr3[2000];
    while(p1<n1 && p2<n2)
    {
        if(arr1[p1].first<arr2[p2].first)
            arr3[p3++]=arr1[p1++];
        else if(arr1[p1].first>arr2[p2].first)
            arr3[p3++]=arr2[p2++];
        else
        {
            int count=arr1[p1].second+arr2[p2].second;
            arr3[p3++]=make_pair(arr1[p1].first,count);
            p2++; p1++;
        }
    }
    while(p1<n1)
        arr3[p3++]=arr1[p1++];
    while(p2<n2)
        arr3[p3++]=arr2[p2++];
    display(arr3,p3);
}

void Diferrence(pair<int,int> *arr1,int n1,pair<int,int> *arr2,int n2)
{
    int p1=0,p2=0,p3=0;
    pair<int,int> arr3[2000];
    while(p1<n1 && p2<n2)
    {
        if(arr1[p1].first<arr2[p2].first)
            arr3[p3++]=arr1[p1++];
        else if(arr1[p1].first>arr2[p2].first)
            p2++;
        else
        {
            if(min(arr1[p1].second,arr2[p2].second)==arr1[p1].second)
            {
                p2++;
                p1++;
            }
            else
            {
                int count=arr1[p1].second-arr2[p2].second;
                arr3[p3++]=make_pair(arr1[p1].first,count);
                p2++; p1++;
            }
        }
    }
    while(p1<n1)
        arr3[p3++]=arr1[p1++];
    display(arr3,p3);
}

int main()
{
    int n1,n2;
    cout<<"Enter Size 1: \n";
    cin>>n1;

    cout<<"Enter Elements :\n";
    int a1[1000];
    input(a1,n1);
    cout<<"Enter Size 2: \n";
    cin>>n2;
    int a2[1000];
    cout<<"Enter Elements :\n";
    input(a2,n2);

    InsertionSort(a1,n1);
    InsertionSort(a2,n2);

    pair<int,int> arr1[1000];
    int size1=makePairArr(arr1,a1,n1);
    pair<int,int> arr2[1000];
    int size2=makePairArr(arr2,a2,n2);

    cout<<"Output Format(Element,Occurrence)\n\n";

    cout<<"Union: ";
    Union(arr1,size1,arr2,size2);
    cout<<"Intersection :";
    Intersection(arr1,size1,arr2,size2);
    cout<<"Sum :";
    Sum(arr1,size1,arr2,size2);
    cout<<"Difference :";
    Diferrence(arr1,size1,arr2,size2);
    cout<<endl;
    cout<<"Kartikeya Agarwal\n2019UCO1692";
    return 0;
}
