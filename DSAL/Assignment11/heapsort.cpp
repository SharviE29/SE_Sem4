/*
Implement the Heap sort algorithm implemented in CPP/Java demonstrating heap
data structure with modularity of programming language
*/

// #include <iostream>
// using namespace std;

// class Heap
// {
// private:
//     int *arr;
//     int size;

// public:
//     Heap()
//     {
//         this->arr = nullptr;
//         this->size = 0;
//     }
//     Heap(int arr[], int size)
//     {
//         this->size = size;
//         this->arr = new int[size];
//         for (int i = 0; i < size; i++)
//         {
//             this->arr[i] = arr[i];
//         }
//     }
//     void insert(int x, int n);
//     void createHeap();
//     void heapify();
//     void deleteItem(int heapSize);
//     void heapSort();
//     void display();
// };
// void Heap::insert(int x, int n)
// {
//     if (n == 0)
//     {
//         this->arr[n] = x;
//     }
//     else
//     {
//         this->arr[n] = x;
//         int temp = arr[n];
//         int i = n;
//         while (i > 0 && temp > arr[(i - 1) / 2])
//         {
//             this->arr[n] = this->arr[(i - 1) / 2];
//             i = (i - 1) / 2;
//         }
//         this->arr[i] = temp;
//     }
// }
// void Heap::createHeap()
// {

//     for (int i = 0; i < this->size; i++)
//     {
//         insert(arr[i], i);
//     }
// }
// void Heap::heapify()
// {
//     // O(n) insertion fastest
//     for (int i = size - 1; i >= 0; i--)
//     {
//         if (2 * i + 1 > size - 1)
//         {
//             continue;
//         }
//         else
//         {
//             int temp = 0;
//             if (2 * i + 2 > size - 1)
//             {
//                 if (arr[2 * i + 1] > arr[i])
//                 {
//                     temp = arr[i];
//                     arr[i] = arr[2 * i + 1];
//                     arr[2 * i + 1] = temp;
//                 }
//             }
//             else
//             {
//                 int max = arr[2 * i + 1];
//                 int ind = 2 * i + 1;
//                 if (arr[2 * i + 2] > max)
//                 {
//                     max = arr[2 * i + 2];
//                     ind++;
//                 }
//                 if (arr[i] < max)
//                 {
//                     temp = arr[i];
//                     arr[i] = arr[ind];
//                     arr[ind] = temp;
//                 }
//             }
//         }
//     }
// }
// void Heap::deleteItem(int heapSize)
// {
//     // Only root node of the heap can be deleted
//     //  it should be replaced by last node in the heap(complete binary tree)
//     int x = this->arr[0];
//     this->arr[0] = this->arr[heapSize - 1];
//     int i = 0;
//     int j = 2 * i + 1;
//     while (j < heapSize - 2)
//     {
//         if (this->arr[j + 1] > this->arr[j])
//         {
//             j = j + 1;
//         }
//         if (this->arr[i] < this->arr[j])
//         {
//             int temp = this->arr[i];
//             this->arr[i] = this->arr[j];
//             this->arr[j] = temp;
//             i = j;
//             j = 2 * i + 1;
//         }
//         else
//         {
//             break;
//         }
//     }
//     this->arr[heapSize - 1] = x;
// }
// void Heap::heapSort()
// {
//     int heapSize = this->size;
//     while (heapSize)
//     {
//         deleteItem(heapSize);
//         heapSize--;
//     }
// }
// void Heap::display()
// {
//     for (int i = 0; i < this->size; i++)
//     {
//         cout << this->arr[i] << " ";
//     }
//     cout << "\n";
// }

// int main()
// {
//     int arr[] = {10, 20, 30, 25, 5, 40, 35};
//     Heap H(arr, 7);
//     H.heapify();
//     H.display();
//     H.heapSort();
//     H.display();
//     return 0;
// }


#include <iostream>
#include <math.h>	

using namespace std;

class MinHeap
{
    int *harr;     // pointer to array of elements in heap
    int capacity;  // maximum possible size of min heap
    int heap_size; // Current number of elements in min heap
public:
    MinHeap(int cap)
    {
        heap_size = cap;
        capacity = cap;
        harr = new int[cap];
    }

    void printArray()
    {
        for (int i = 0; i < heap_size; i++)
            cout << harr[i] << " ";
        cout << endl;
    }

    int parent(int i)
    {
        return (i - 1) / 2;
    }

    int left(int i)
    {
        return (2 * i + 1);
    }

    int right(int i)
    {
        return (2 * i + 2);
    }
    int getMin()
    {
        return harr[0];
    }
    void MinHeapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l < heap_size && harr[l] < harr[i])
            smallest = l;
        if (r < heap_size && harr[r] < harr[smallest])
            smallest = r;
        if (smallest != i)
        {
            swap(harr[i], harr[smallest]);
            MinHeapify(smallest);
        }
    }
    // Method to remove minimum element (or root) from min heap
    int extractMin()
    {
        if (heap_size <= 0)
            return 999999;
        if (heap_size == 1)
        {
            heap_size--;
            return harr[0];
        }

        // Store the minimum value, and remove it from heap
        int root = harr[0];
        harr[0] = harr[heap_size - 1]; //replace the last element with the first one
        heap_size--;
        MinHeapify(0);
        // printArray();
        // cout <<"--"<<harr[0]<<"--";
        return root;
    }

    void getUnsortedArray()
    {
        cout << "Enter " << capacity << " no of elements to sort using HEAPSORT" << endl;
        for (int i = 0; i < capacity; i++)
            cin >> harr[i];
    }

    void heapSort()
    {
        int temp[capacity];
        for (int j = 0; j < capacity; j++)
        {
            // cout<<extractMin()<<" ";
            temp[j] = extractMin();
            cout << temp[j] << " ";
        }
    }
};

int main()
{
    int s;
    cout << "Enter Size of Min Heap" << endl;
    cin >> s; // 5
    if(s<=0)
    {
        cout<<"Not possible";
        return 0;
    }
    MinHeap obj(s);
    obj.getUnsortedArray(); // 7 4 3 9 8

    cout << "Unsorted Array :" << endl;
    obj.printArray();

    for (int i = s / 2 - 1; i >= 0; i--)
    {
        obj.MinHeapify(i);
    }

    cout << "Heap Sorted Array :" << endl;
    obj.heapSort();
    return 0;
}