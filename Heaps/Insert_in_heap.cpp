#include <bits/stdc++.h>
using namespace std;
class heap
{
public:
    int arr[100];
    int size = 0;
    void insert(int val)
    {
        // o(log(n))
        size++;
        int index = size;
        arr[index] = val;
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i];
        }
        cout << endl;
    }
    void deleteNode()
    {
        // O(log(n))
        if (size == 0)
        {
            cout << "nothing to delete" << endl;
            return;
        }

        // Put the last element into the first index
        arr[1] = arr[size];
        size--; // Reduce the heap size

        // Heapify from the root down
        int i = 1;
        while (i <= size)
        {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;
            int largest = i;

            // Compare with the left child
            if (leftIndex <= size && arr[leftIndex] > arr[largest])
            {
                largest = leftIndex;
            }

            // Compare with the right child
            if (rightIndex <= size && arr[rightIndex] > arr[largest])
            {
                largest = rightIndex;
            }

            // If the largest element is not the current node, swap
            if (largest != i)
            {
                swap(arr[i], arr[largest]);
                i = largest; // Move down to the child node
            }
            else
            {
                // If the node is in the correct position, stop
                break;
            }
        }
    }
};
void heapify(int arr[], int n, int index)
{
    int largest = index;
    int left = 2 * index;
    int right = 2 * index + 1;
    if (left <= n && arr[largest] < arr[left])
        largest = left;
    if (right <= n && arr[largest] < arr[right])
        largest = right;
    if (largest != index)
    {
        swap(arr[index], arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n)
{
    int size = n;
    while (size > 1)
    {
        cout << size << arr[1] << " ";
        swap(arr[1], arr[size]);
        cout << size << arr[1] << endl;
        size--;
        heapify(arr, size, 1);
    }
}
void heapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[i])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    cout << "largest" << arr[largest] << endl;
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}
vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
{
    for (int i = 0; i < m; i++)
    {
        a.push_back(b[i]);
    }
    // return a;
    for (int i : a)
    {
        cout << i << " ";
    }
    cout << endl;
    n = a.size();
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        // cout<<"i"<<i<<endl;
        heapify(a, n, i);
    }
    return a;
}
int main()
{
    // heap h;
    // h.insert(23);
    // h.insert(21);
    // h.insert(55);
    // h.print();
    // h.deleteNode();
    // h.print();
    vector<int> arr = {6, 5, 4};
    vector<int> arr2 = {12, 7, 2};
    vector<int> arr3 = mergeHeaps(arr, arr2, 3, 3);
    for (int i : arr3)
    {
        cout << i << " " << endl;
    }

    return 0;
}