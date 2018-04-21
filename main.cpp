#include <algorithm> // max()
#include <iostream>

using namespace std;

const int MAX = 100;

int FindLocalMax(int (*matrix)[MAX], int row, int current_column){
    int MaxNum = 0;
    int RowWithMax = 0;
    for(int i = 0; i != row; ++i){
        MaxNum = max(MaxNum, matrix[i][current_column]);
        if (MaxNum == matrix[i][current_column])
            RowWithMax = i;
    }
    return RowWithMax;
}

int FindPeak(int (*matrix)[MAX], int row, int column, int mid){
    int max_row = FindLocalMax(matrix, row, mid);
    
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
    int arr[][MAX] = {{ 10, 12, 10, 10  },
                      { 19, 10, 12, 25 },
                      { 15, 29, 21, 19  },
                      { 18, 39, 39, 39 } };

    int row = 4;
    int column = 4;
    int mid = column/2; 
    int peak = FindPeak(arr, row, column, mid);
    cout << peak << endl;

    return 0;
}