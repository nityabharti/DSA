//Program for Quick SORT technique
#include <iostream>
using namespace std;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partiation(int arr[], int left, int right)
{
    int pivot = arr[right];
    int i = (left - 1);
    for (int j = left; j <= right - 1; j++)
    {

        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[right]);
    return (i + 1);
}

void quickshort(int arr[], int l, int r)
{

    if (l < r)
    {
        int pi = partiation(arr, l, r);
        quickshort(arr, l, pi - 1);
        quickshort(arr, pi + 1, r);
    }
}
void printarry(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";
    }
}
int main()
{
    int n;
    cout << "Enter the size of the arry" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements of arry" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Before shorting " << endl;
    printarry(arr, n);
    quickshort(arr, 0, n - 1);
    cout << "\nAfter shorting" << endl;
    printarry(arr, n);
}