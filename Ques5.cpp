#include <iostream>
using namespace std;

void swap(char* a, char* b)
{
	char t = *a;
    *a = *b;
    *b = t;
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

int main()
{
	string s;
	cout<<"Enter String\n";
	cin>>s;
	bool val = permute(s);
	if (!val)
		cout << "No next Lexical Permutation is Possible" << endl;
	else
		cout << s << endl;
    cout<<"Kartikeya Agarwal\n2019UCO1692";
	return 0;
}
