// swapping two numbers using call by value
#include<iostream>
using namespace std;
void swap(int,int);
int main()
{
        int x,y,z;
        cout<<"\n Enter First Number : ";
        cin>>x;
        cout<<"\n Enter Second Number : ";
        cin>>y;
        cout<<"\n Before Swapping the Value : \n"<<" "<<x<<"\t"<<y<<"\n";
        swap(x,y);
        cout<<"\n Outside Function After Swapping the Value : \n"<<" "<<x<<"\t"<<y<<"\n";
}
void swap(int x,int y)
{
        int z;
        z=x;
        x=y;
        y=z;
        cout<<"\n Inside Function After Swapping the Value : \n"<<" "<<x<<"\t"<<y;
}

