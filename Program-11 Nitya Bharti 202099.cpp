#include <bits/stdc++.h>
#include <time.h>
using namespace std;

void LinearSearch(int arr[], int n, int x)
{
    clock_t start = clock();
    int flag = 1;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] == x)
        {    
            cout<<"Element is present at: "<<i;
            cout<<endl;
            flag = 0;
            break;
        }
    }
    if(flag == 1)
    {
        cout<<"Element is not present";
    }
    cout<<fixed<<"\nExecution time of Linear Search: "<<float(clock() - start)/CLOCKS_PER_SEC<<endl;    
}

void BinarySearch(int arr[], int left, int right, int x)
{
    clock_t start = clock();
    int flag = 1;
    while(left <= right)
    {
        int mid = left + ((right - left)/2);

        if(arr[mid] == x)
        {    
            cout<<"Element is present at: "<<mid;
            flag = 0;
            break;
        }
        if(arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    if(flag == 1)
    cout<<"Element not present";

    cout<<fixed<<"\nExecution time of Binary Search: "<<float(clock() - start)/CLOCKS_PER_SEC<<endl;
}

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

void BubbleSort(int arr[], int n)
{
    clock_t start = clock();
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
            }
        }   
    }
    cout<<fixed<<"\nExecution time of Bubble Sort: "<<float(clock() - start)/CLOCKS_PER_SEC<<endl;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j <= high - 1; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

void QuickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    {
        int pi = partition(arr, low, high); 
        QuickSort(arr, low, pi - 1); 
        QuickSort(arr, pi + 1, high); 
    }
}

void printArray(int arr[], int size) 
{ 
    for(int i = 0; i < size; i++) 
        cout<<arr[i]<<" "; 
    cout<<endl; 
} 

int main()
{
    int Array[1000], newArray[1000], element;
    for(int i = 0; i < 1000; i++)
    {
        Array[i] = rand()%1000;
    }
    for(int i = 0; i < 1000; i++)
    {
        newArray[i] = Array[i];
    }

    cout<<"The array is:\n";
    printArray(Array, 1000);

    cout<<"Enter a element to search: ";
    cin>>element;

    LinearSearch(Array, 1000, element);
    
    BubbleSort(Array, 1000);
    printArray(Array, 1000);

    BinarySearch(Array, 0, 999, element);


    clock_t start = clock();
    QuickSort(newArray, 0, 999);
    cout<<fixed<<"\nExecution time of Quick Sort: "<<float(clock() - start)/CLOCKS_PER_SEC<<endl; 
    
    printArray(newArray, 1000);
    
    return 0;
}