//3.3.20

#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n;
    cout << "Enter the number of rows and columns for the array A: ";
    cin >> n;
    while (n < 1) {
        cout << "Input error! Enter value > 0: ";
        cin >> n;
        cout << "\n";
    }

    vector<vector<float>> A(n, vector<float>(n));
    
    cout << "Enter the value A: \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
            while (A[i][j] <= 0) {
                cin >> A[i][j];
            }
            
        }
        cout << "\n";
    }

    vector<float> C(n);
    cout << "Enter the value C: \n";
    for (int i = 0; i < n; i++) {
        cin >> C[i];
    }
    
    cout << "\n";

    for (int i = 0; i < n; i++) {
        int flag = true;
        int j = 0;
        while (flag && j < n) {
            if (C[i] < A[i][j]) {
                flag = false;
            }
            j++;
        }
        if (flag) {
            cout << C[i] << "\n";
        }

    }
    float summ = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            summ += A[i][j];
        }
    }

    cout << "The sum of the elemets of array A = " << summ;

    
    return 0;
}