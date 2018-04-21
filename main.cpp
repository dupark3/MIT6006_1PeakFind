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
    
    if (mid == 0 || mid == column - 1){
        return matrix[max_row][mid];
    } else if (matrix[max_row][mid] <= matrix[max_row][mid-1]){
        return FindPeak(matrix, row, column, mid/2);
    } else if (matrix[max_row][mid] < matrix[max_row][mid+1]){
        return FindPeak(matrix, row, column, mid + mid/2);
    } else {
        return matrix[max_row][mid];
    }
    
}

int main(){
    int arr[][MAX] = {{ 10, 12, 10, 10  },
                      { 14, 23, 32, 45 },
                      { 15, 29, 21, 19  },
                      { 16, 27, 19, 20 } };

    int row = 4;
    int column = 4;
    int mid = column/2; 
    int peak = FindPeak(arr, row, column, mid);
    cout << peak << endl;

    return 0;
}