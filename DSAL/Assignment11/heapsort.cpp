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