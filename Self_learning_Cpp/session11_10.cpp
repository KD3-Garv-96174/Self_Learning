#include <iostream>
#include <vector>
using namespace std;

class Matrix
{
private:
    vector<vector<int>> matrix;
    int rows, cols;

public:
    Matrix(int rows, int cols)
    {
        this->rows = rows;
        this->cols = cols;
        matrix.resize(rows, vector<int>(cols, 0));
    }

    void inputMatrix()
    {
        cout << "Enter elements of " << rows << "x" << cols << " matrix:" << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cin >> matrix[i][j];
            }
        }
    }

    void display()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    Matrix operator+(const Matrix &other)
    {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
            }
        }
        return result;
    }

    Matrix operator-(const Matrix &other)
    {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
            }
        }
        return result;
    }

    Matrix operator*(const Matrix &other)
    {
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < other.cols; j++)
            {
                result.matrix[i][j] = 0;
                for (int k = 0; k < cols; k++)
                {
                    result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
                }
            }
        }
        return result;
    }
};

int main()
{
    int rows, cols;
    cout << "Enter rows and cols for matrices: ";
    cin >> rows >> cols;

    Matrix matrixA(rows, cols), matrixB(rows, cols);

    cout << "Matrix A:" << endl;
    matrixA.inputMatrix();

    cout << "Matrix B:" << endl;
    matrixB.inputMatrix();

    cout << "Matrix A:" << endl;
    matrixA.display();

    cout << "Matrix B:" << endl;
    matrixB.display();

    Matrix matrixC = matrixA + matrixB;
    cout << "A + B:" << endl;
    matrixC.display();

    Matrix matrixD = matrixA - matrixB;
    cout << "A - B:" << endl;
    matrixD.display();

    Matrix matrixE = matrixA * matrixB;
    cout << "A * B:" << endl;
    matrixE.display();

    return 0;
}
