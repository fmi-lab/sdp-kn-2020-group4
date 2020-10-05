#include<iostream>
#include<vector>

void bubble_sort(std::vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        for(int j = 0; j < arr.size() - i - 1; j++) {
            if(arr[j] > arr[j+1]) {
                std::swap(arr[j], arr[j+1]);
            }
        }
    }
}
// T(n) = (n-1) + (n-2) + (n-3) + .... + 3 + 2 + 1
// T(n) = n(n-1)/2 = n^2

int main() {
    std::vector<int> A = { 1, 15, 0, 110, 2, 23 };
    bubble_sort(A);
    for(auto element: A) {
        std::cout << element << ' ';
    }
    return 0;
}