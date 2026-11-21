#include <iostream>
using namespace std;

class Matrix {
    int rows, cols;
    int** grid;
public:
    Matrix(int m, int n) : rows(m), cols(n) {
        grid = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            grid[i] = new int[cols]{0};
        }
    }

    // Deep copy constructor
    Matrix(const Matrix& o) : rows(o.rows), cols(o.cols) {
        grid = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            grid[i] = new int[cols];
            for (int j = 0; j < cols; ++j) {
                grid[i][j] = o.grid[i][j];
            }
        }
    }

    void set(int r, int c, int val) { grid[r][c] = val; }

    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) cout << grid[i][j] << " ";
            cout << endl;
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; ++i) delete[] grid[i];
        delete[] grid;
    }
};

int main() {
    Matrix m1(2, 2);
    m1.set(0, 0, 5);
    m1.set(1, 1, 9);

    Matrix m2 = m1; // deep copy
    m2.set(0, 0, 99);

    cout << "Original:\n"; m1.print();
    cout << "Copy:\n";     m2.print();
    return 0;
}