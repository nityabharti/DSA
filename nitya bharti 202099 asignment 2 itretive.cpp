#include <iostream>
using namespace std;
int binarysearch(int ar[], int l, int r, int num)
{
    int m;
    while (l <= r)
    {
        m = l + (r - l) / 2;
        if (ar[m] == num)
        {
            return m;
        }
        else if (ar[m] < num)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
        return -1;
    }
}

int main()
{
    int a, number, check;
    cout << "Enter the size of arry" << endl;
    cin >> a;
    int arry[a];
    cout << "Enter the elements of in acending order" << endl;
    for (int i = 0; i < a; i++)
    {
        cin >> arry[i];
    }
    cout << "Enter the element to find" << endl;
    cin >> number;
    check = binarysearch(arry, 0, a, number);
    if (check == -1)
    {
        cout << "Element not found " << endl;
    }
    else
    {
        cout << "Element found at " << check << endl;
    }
    return 0;
}