#include<iostream>
using namespace std;

float root1,root2;

float sqrt(int n)
{
    int s=0;
    int e=n;
    float ans=-1;
    while(s<=e)
    {
        int mid=((s+e)>>1);

        if(mid*mid==n)
            return mid;
        else if(mid*mid<n)
        {
            ans=mid;
            s=mid+1;
        }
        else
            e=mid-1;
    }
    float inc=0.1;
    for(int t=1;t<=2;t++)
    {
        while(ans*ans<=n)
            ans=ans+inc;
        ans=ans-inc;
        inc=inc/10;
    }

    return ans;
}
void QuadraticSolver(int a, int b, int c)
{
	float d;
	d=(b*b)-4*a*c;
	if(d>=0)
    {
        root1 = ((-b-(sqrt(d)))/2*a);
        root2 = ((-b+(sqrt(d)))/2*a);
	}
	return;
}
int main()
{
    cout<<"Choose: "<<endl;
    cout<<"a. c1*an = c2*an-1 + c3*an-2"<<endl;
    cout<<"b. an = c1*an-1 + c2*n^c"<<endl;
    char a;
    cin>>a;
    if(a=='a')
    {
        cout<<"Enter number of Literals\n";
        int n;
        cin>>n;
        cout<<"Enter Coefficients of recurrence relation as an=an-1+an-2...\n";
        int arr[10];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        cout<<"Enter initial Conditions\n";
        int a=0,b=0;
        cin>>a>>b;

        QuadraticSolver(arr[0],-arr[1],-arr[2]);

        float c1 = (a*root2-b)/(root2-root1);
        float c2 = (a*root1-b)/(root1-root2);

        cout<<"Solution of the given Recurrence: "<<arr[0]<<"an = "<<arr[1]<<"an-1 + "<<arr[2]<<"an-2 is :\n";
        cout<<"\t"<<c1<<"*("<<root1<<")^n"<<" + "<<c2<<"*("<<root2<<")^n";
    }
    else
    {
        cout<<"Enter k,c,ao\n";
        int k,c,a;
        cin>>k>>c>>a;
        if(c==0) cout<<a<<" + "<<k<<"*"<<"n";
        if(c==1) cout<<a<<" + "<<k<<"*"<<"n(n-1)/2";
        if(c==2) cout<<a<<" + "<<k<<"*"<<"n(n-1)(n-2)/6";
        if(c==3) cout<<a<<" + "<<k<<"*"<<"(n(n-1)/2)^2";
    }
    cout<<endl;
    cout<<"Kartikeya Agarwal\n2019UCO1692";
    return 0;
}
