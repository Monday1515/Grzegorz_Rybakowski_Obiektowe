#include <iostream>
#include <stdexcept>
#include <cstdlib>

using namespace std;

class Matrices {
private:
    int height;
    int width;
    int** matrix;

public:

    Matrices(int h, int w) : height(h), width(w) {
        matrix = new int*[height];
        for (int i = 0; i < height; i++ ) {
            matrix[i] = new int [width];
            for (int j = 0; j < width; j++) {
                matrix[i][j] = i + j;
            }
        }
    }

    Matrices(const Matrices& other) : height(other.height), width(other.width) {
        matrix = new int*[height];
        for (int i = 0; i < height; i++) {
            matrix[i] = new int[width];
            for (int j = 0; j < width; j++) {
                matrix[i][j] = other.matrix[i][j];
            }
        }
    }

    Matrices(Matrices&& other) noexcept : height(other.height), width(other.width), matrix(other.matrix) {
        other.matrix = nullptr;
        other.height = 0;
        other.width = 0;
    }



    ~Matrices() {
        for (int i = 0; i < height; i++) {
            delete[] matrix[i];
        }
        delete [] matrix;
    }

    void transpose_Matrix() {
        int** transposed = new int*[width];
        for (int i = 0; i < width; i++) {
            transposed[i] = new int[height];
            for (int j = 0; j < height; j++) {
                transposed[i][j] = matrix[j][i];
            }
        }

        for (int i = 0; i < height; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;

        matrix = transposed;

        swap(height, width);
    }

    void multiply_Matrix(int skalar) {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                matrix[i][j] *= skalar;
            }
        }
    }

    void display() const {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

};

int main() {
    Matrices mtrx1(3,2);

    cout << "mtrx1:" << endl;
    mtrx1.display();

    Matrices mtrx2 = mtrx1;
    cout << "mtrx2 (skopiowanie mtrx1):" << endl;
    mtrx2.display();

    Matrices mtrx3 = move(mtrx1);
    cout << "mtrx3 (przeniesienie mtrx1):" << endl;
    mtrx3.display();

    cout << "mtrx1 (zostalo przeniesione, powinno byc puste):" << endl;
    mtrx1.display();
    
    return 0;

}