#include <iostream>
using namespace std;
int binarysearch(int ary[], int l, int r, int number)
{
    int mid;

    if (l <= r)
    {
        mid = (l + r) / 2;
        if (ary[mid] == number)
        {
            return mid;
        }
        if (ary[mid] > number)
        {
            return binarysearch(ary, l, mid - 1, number);
        }
        if (ary[mid] < number)
        {
            return binarysearch(ary, mid + 1, r, number);
        }
    }

    return -1;
}

int main()
{
    int n, number, result;
    cout << "enter the size of arry" << endl;
    cin >> n;
    int arry[n];
    cout << "Enter the elements of the arry in acending order" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arry[i];
    }
    cout << "Enter the element to search" << endl;
    cin >> number;
    result = binarysearch(arry, 0, n, number);
    if (result == -1)
    {
        cout << "Element not found " << endl;
    }
    else
    {
        cout << "Element found at " << result << endl;
    }
    return 0;
}
