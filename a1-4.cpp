#include <iostream>

using namespace std;

//write your code here

// Function to find the median
double findMedian(int arr1[], int size1, int arr2[], int size2) {
    int count[101] = {0}; // Initializes the count array with zeros

    // Update frequency array for arr1
    for (int i = 0; i < size1; ++i) {
        count[arr1[i]]++;
    }

    // Update frequency array for arr2
    for (int i = 0; i < size2; ++i) {
        count[arr2[i]]++;
    }

    int total_students = size1 + size2;
    int mid = (total_students + 1) / 2;
    int cumulative_count = 0;

    // Find the median using the frequency array
    for (int i = 0; i <= 100; ++i) {
        cumulative_count += count[i];
        
        if (cumulative_count >= mid) {
            // Check for even number of total students to get the average of the two middle elements
            if (total_students % 2 == 0 && cumulative_count == mid) {
                for (int j = i + 1; j <= 100; ++j) {
                    if (count[j] > 0) {
                        return (i + j) / 2.0; // Return the average of the two middle elements
                    }
                }
            }
            return i; // The median score for odd number of total students
        }
    }

    return -1; // If no median found (should not happen in a valid input)
}




int main() {
    // You can use cout statements, but ensure that you submit after commenting them out, as the autograder will otherwise mistake it for your actual output
    // Everything else in the main function remains unchanged
    
    int size1;
    // cout << "Enter the size of the array1: ";
    cin >> size1;

    int arr[size1];
    // cout << "Enter " << size1 << " elements:" << endl;
    for (int i = 0; i < size1; ++i) {
        cin >> arr[i];
    }

    // cout << "The array elements are: ";
    // for (int i = 0; i < size1; ++i) {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    int size2;
    // cout << "Enter the size of the array2: ";
    cin >> size2;

    int arr1[size2];
    // cout << "Enter " << size2 << " elements:" << endl;
    for (int i = 0; i < size2; ++i) {
        cin >> arr1[i];
    }

    // cout << "The array elements are: ";
    // for (int i = 0; i < size2; ++i) {
    //     cout << arr1[i] << " ";
    // }
    // cout << endl;
    
    cout << "Median = " << findMedian(arr, size1, arr1, size2) << endl; // do not comment this out
    
    return 0;
}
