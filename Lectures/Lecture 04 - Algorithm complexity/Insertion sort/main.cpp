#include <iostream>

void insertion_sort(std::vector<int>&);

int main() {
    std::vector<int> A = {34, 23, 3, 4, 15, 64, 74, 8, 29, 101};
    // Print the original vector A :
    for (int i: A){
        std::cout << i << ' ';
    }
    std::cout << std::endl; // Use a new line
    // Sort A using the insertion sort algorithm :
    insertion_sort(A);
    // Print the sorted vector A :
    for (int i: A){
        std::cout << i << ' ';
    }

    return 0;
}

void insertion_sort(std::vector<int> &A)
{
    int i;
    int j;
    int key;
    for(j=1; j<A.size(); j++)
    {
        key = A[j];
        i = j-1;
        while(i>=0 && A[i]>key)
        {
            A[i+1] = A[i];
            i = i-1; }
        A[i+1] = key;
    }
}
