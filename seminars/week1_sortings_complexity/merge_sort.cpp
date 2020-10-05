#include<iostream>
#include<vector>

void merge(std::vector<int>& arr, size_t start, size_t middle, size_t end) {
    std::vector<int> left_part, right_part;
    size_t left_part_size = middle - start + 1;
    size_t right_part_size = end - middle;
    int i, j, k;

    for(i = 0; i < left_part_size; i++) {
        left_part.push_back(arr[start + i]);
    }

    for(j = 0; j < right_part_size; j++) {
        right_part.push_back(arr[middle + 1 + j]);
    }

    i = 0, j = 0, k = start;

    while(i < left_part_size && j < right_part_size) {
        if(left_part[i] < right_part[j]) {
            arr[k] = left_part[i++];
        } else {
            arr[k] = right_part[j++];
        }
        k++;
    }

    while(i < left_part_size) {
        arr[k++] = left_part[i++];
    }

    while(j < right_part_size) {
        arr[k++] = right_part[j++];
    }
}

void merge_split_sort(std::vector<int>& arr, size_t start, size_t end) {
    if( start >= end) {
        return;
    }
    size_t middle = (end + start) / 2;
    merge_split_sort(arr, start, middle);
    merge_split_sort(arr, middle + 1, end);
    merge(arr, start, middle, end);
}

void merge_sort(std::vector<int>& arr) {
    merge_split_sort(arr, 0, arr.size()-1);
}

int main() {
    std::vector<int> A = { 1,10,15,2,23,45 };
    merge_sort(A);
    for(int element: A) {
        std::cout << element << ' ';
    }
    return 0;
}