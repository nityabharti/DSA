//swapping two numbers using call by reference
#include <iostream>
using namespace std;

void swap(int *, int *);
int main()
{

    int x, y;
    cout << "Enter any two numbers for x and y:";
    cin >> x >> y;
    cout << "Before swap x is:"<<x;
    cout <<"\nbefore swap y is:"<<y;
    swap(&x, &y);

    cout << "\nAfter swap x is:" << x;
    cout << "\nAfter swap y is:" << y;
    return 0;
}
void swap(int *a,int *b)
{
    int temp;
    temp=*b;
    *b=*a;
    *a=temp;
}