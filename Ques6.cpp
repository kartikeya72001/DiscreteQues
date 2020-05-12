#include <iostream>
using namespace std;
string occur[10000];
int x=0;
void swap(char* a, char* b)
{
	char t = *a;
    *a = *b;
    *b = t;
}
void Swap(string *xp, string *yp)
{
    string temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void rev(string& s, int l, int r)
{
	while (l < r)
		swap(&s[l++], &s[r--]);
}

int BinarySearch(string& s, int l, int r, int key)
{
	int index = -1;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		if (s[mid] <= key)
			r = mid - 1;
		else {
			l = mid + 1;
        if (index == -1 || s[index] >= s[mid])
				index = mid;
		}
	}
	return index;
}

bool permute(string& s)
{
	int len = s.length(), i = len - 2;
	while (i >= 0 && s[i] >= s[i + 1])
		i--;
	if (i < 0)
		return false;
	else {
		int index = BinarySearch(s, i + 1, len - 1, s[i]);
		swap(&s[i], &s[index]);
		rev(s, i + 1, len - 1);
		return true;
	}
}
void printAll(string str)
{
    int n = str.length();
    unsigned int opsize = 1<<n;

    for (int counter = 1; counter < opsize; counter++)
    {
        string subs = "";
        for (int j = 0; j < n; j++)
        {
            if (counter & (1<<j))
                subs.push_back(str[j]);
        }

        do
        {
            occur[x] = subs;
            x++;
        }
        while (permute(subs));
    }
}
void bubbleSort(string arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)

    // Last i elements are already in place
    for (j = 0; j < n-i-1; j++)
        if (arr[j] > arr[j+1])
            Swap(&arr[j], &arr[j+1]);
}

int main()
{
    string str;
    cout<<"Enter a string\n";
    cin>>str;
    printAll(str);
    bubbleSort(occur,x);
    int flag=0;
    for(int i=0;i<x;i++)
    {
        if(str==occur[i])
        {
            flag=1;
            cout<<occur[i+1];
            break;
        }
    }cout<<endl;
    cout<<"Kartikeya Agarwal\n2019UCO1692";
    return 0;
}
