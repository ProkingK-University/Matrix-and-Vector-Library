#include "matrix.h"

Matrix::Matrix(unsigned r, unsigned c) : rows(r), cols(c)
{
    matrix = new double*[rows];

    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new double[cols];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

Matrix::Matrix(const Matrix& rhs)
{
    rows = rhs.rows;
    cols = rhs.cols;

    matrix = new double*[rows];

    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new double[cols];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = rhs.matrix[i][j];
        }
    }
}

Matrix::~Matrix()
{
    for (int i = 0; i < rows; i++)
    {
        delete [] matrix[i];
        matrix[i] = NULL;
    }

    delete [] matrix;
    matrix = NULL;
}

void Matrix::print()
{

}

void Matrix::readFile(istream &infile)
{

}

const Matrix& Matrix::operator=(const Matrix& rhs)
{
    if (&rhs == this)
    {
        return *this;
    }
    else
    {
        for (int i = 0; i < rows; i++)
        {
            delete [] matrix[i];
            matrix[i] = NULL;
        }

        delete [] matrix;
        matrix = NULL;

        rows = rhs.rows;
        cols = rhs.cols;

        matrix = new double*[rows];

        for (int i = 0; i < rows; i++)
        {
            matrix[i] = new double[cols];
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                matrix[i][j] = rhs.matrix[i][j];
            }
        }
    }
}

Matrix Matrix::operator+(const Matrix& rhs)
{

}

Matrix& Matrix::operator+=(const Matrix& rhs)
{

}

Matrix Matrix::operator-(const Matrix& rhs)
{

}

Matrix& Matrix::operator-=(const Matrix& rhs)
{

}

Matrix Matrix::operator*(const Matrix& rhs)
{

}

Matrix& Matrix::operator*=(const Matrix& rhs)
{

}

Matrix Matrix::operator^(int pow)
{

}

Matrix& Matrix::operator^=(int pow)
{

}

Matrix Matrix::operator~()
{

}

Matrix Matrix::operator*(const double& rhs)
{

}

Matrix operator* (const double&, const Matrix&)
{

}

Matrix& Matrix::operator*=(const double& rhs)
{

}

Matrix Matrix::operator/(const double& rhs)
{

}

double& Matrix::operator()(const unsigned r, const unsigned c)
{

}

const double& Matrix::operator()(const unsigned r, const unsigned c) const
{

}

Vector Matrix::operator[](const unsigned r) const
{

}

unsigned Matrix::getRows() const {}

unsigned Matrix::getCols() const {}

Matrix Matrix::operator|(const Matrix& rhs)
{

}

Matrix& Matrix::operator|=(Matrix& rhs)
{
    
}