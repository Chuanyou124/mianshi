#include <iostream>
#include <string>
#include <vector>

using namespace std;

void swap(float a[], int i, int j) {
    float tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

int partition(float a[], int low, int high) {
    int pivot = a[high];
    int pi = low;
    for (int i = low; i < high; ++i) {
        if (a[i] <= pivot) {
            swap(a, i, pi);
            pi += 1;
        }
    }
    swap(a, pi, high);
    return pi;
}

void quick_sort(float a[], int low, int high) {
   if (low < high) {
       int pi = partition(a, low, high); // pi: pivot index after this partition
       quick_sort(a, low, pi - 1);
       quick_sort(a, pi + 1, high);
   }
}

int main()
{
   cout << "Hello World" << endl;
   float a[] = {1,3,19,27,0.5, 4, 21, 6};
   //vector<float> v = {1,2,7};
   quick_sort(a, 0, 7);

   for (int i = 0; i <= 7; ++i) {
       cout << a[i] << ", ";
   }
   return 0;
}
