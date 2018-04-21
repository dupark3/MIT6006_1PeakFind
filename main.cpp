/*
MIT 6.006 Data Structures and Algorithms
Find a 2D Peak
An element is a peak element if it is greater than or equal to its four neighbors, left, right, top and bottom.
Below are some facts about this problem:
    1: A Diagonal adjacent is not considered as neighbor.
    2: A peak element is not necessarily the maximal element.
    3: More than one such elements can exist.
    4: There is always a peak element. We can see this property by creating some matrices using pen and paper.
*/

#include <iostream>

using namespace std;

const int MAX = 100;

int FindLocalMaxRow(int (*matrix)[MAX], int row, int current_column){
    int MaxNumber = 0;
    int RowWithMax = 0;
    for(int i = 0; i != row; ++i){
        if (MaxNumber < matrix[i][current_column]){
            MaxNumber = matrix[i][current_column];
            RowWithMax = i;
        }
    }
    return RowWithMax;
}

int FindPeak(int (*matrix)[MAX], int row, int column, int mid){
    int max_row = FindLocalMaxRow(matrix, row, mid);
    
    // if on first or last row, global max is a peak
    if (mid == 0 || mid == column - 1){
        return matrix[max_row][mid];
    } 

    // go left if current max is smaller or equal to the left element
    else if (matrix[max_row][mid] < matrix[max_row][mid-1]){
        return FindPeak(matrix, row, column, mid/2);
    } 

    // go right if current max is smaller or equal to the right element
    else if (matrix[max_row][mid] < matrix[max_row][mid+1]){
        return FindPeak(matrix, row, column, mid + mid/2);
    } 

    // if current max is larger or equal to both left and right, it is a peak
    else {
        return matrix[max_row][mid];
    }
    
}

int main(){
    int arr[][MAX] = {{ 10, 13, 10, 10  },
                      { 19, 10, 12, 25 },
                      { 15, 29, 12, 19  },
                      { 18, 19, 12, 19 } };
    
    int row = 4;
    int column = 4;
    int mid = column/2; 
    int peak = FindPeak(arr, row, column, mid);
    cout << peak << endl;

    return 0;
}