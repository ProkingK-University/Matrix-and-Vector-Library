#include "matrix.h"

#include <iomanip>

//Matrix constuctor creates 2D array and sets them to 0;
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

//Copy constructor
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

//Prints out matrix values
void Matrix::print()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout<< std::setw(10) << std::setprecision(3) << matrix[i][j];
        }

        std::cout<<std::endl;
    }
}

//Read values into matrix file
void Matrix::readFile(istream &infile)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            infile >> matrix[i][j];
        }
    }
}

//Assignment operator for matrix
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

            for (int j = 0; j < cols; j++)
            {
                matrix[i][j] = rhs.matrix[i][j];
            }
        }

        return *this;
    }
}

//Adds two matrix
Matrix Matrix::operator+(const Matrix& rhs)
{
    if ((rows != rhs.rows) || (cols != rhs.cols))
    {
        throw "Error: adding matrices of different dimensionality";
    }
    else
    {
        Matrix a(*this);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                a.matrix[i][j] += rhs.matrix[i][j];
            }
        }

        return a;
    }
}

Matrix& Matrix::operator+=(const Matrix& rhs)
{
    if ((rows != rhs.rows) || (cols != rhs.cols))
    {
        throw "Error: adding matrices of different dimensionality";
    }
    else
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                matrix[i][j] += rhs.matrix[i][j];
            }
        }

        return *this;
    }
}

//Subtracts two matrix
Matrix Matrix::operator-(const Matrix& rhs)
{
    if ((rows != rhs.rows) || (cols != rhs.cols))
    {
        throw "Error: subtracting matrices of different dimensionality";
    }
    else
    {
        Matrix a(*this);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                a.matrix[i][j] -= rhs.matrix[i][j];
            }
        }

        return a;
    }
}

Matrix& Matrix::operator-=(const Matrix& rhs)
{
    if ((rows != rhs.rows) || (cols != rhs.cols))
    {
        throw "Error: subtracting matrices of different dimensionality";
    }
    else
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                matrix[i][j] -= rhs.matrix[i][j];
            }
        }

        return *this;
    }
}

//Performs matrix multiplication
Matrix Matrix::operator*(const Matrix& rhs)
{
    if (cols != rhs.rows)
    {
        throw "Error: invalid matrix multiplication";
    }
    else
    {
        Matrix a(rows, rhs.cols);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < rhs.cols; j++)
            {
                for (int l = 0; l < rhs.rows; l++)
                {
                    a.matrix[i][j] += matrix[i][l] * rhs.matrix[l][j];
                }
            }
        }

        return a;
    }
}

Matrix& Matrix::operator*=(const Matrix& rhs)
{
    if (cols != rhs.rows)
    {
        throw "Error: invalid matrix multiplication";
    }
    else
    {
        Matrix m(cols, rhs.rows);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < rhs.cols; j++)
            {
                for (int l = 0; l < rhs.rows; l++)
                {
                    m.matrix[i][j] += matrix[i][l] * rhs.matrix[l][j];
                }
            }
        }

        *this = m;
        
        return *this;
    }
}

//Performs matrix multiplicaton n times
Matrix Matrix::operator^(int pow)
{
    if (rows != cols)
    {
        throw "Error: non-square matrix provided";
    }
    else if(pow < 0)
    {
        throw "Error: negative power is not supported";
    }
    else if (pow == 0)
    {
        Matrix a(*this);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (i == j)
                {
                    a.matrix[i][j] = 1;
                }
                else
                {
                    a.matrix[i][j] = 0;
                }
            }
        }

        return a;
    }
    else
    {
        Matrix a(*this);

        for (int i = 1; i < pow; i++)
        {
            a *= *this;
        }
        
        return a;
    }
}

Matrix& Matrix::operator^=(int pow)
{
    if (rows != cols)
    {
        throw "Error: non-square matrix provided";
    }
    else if(pow < 0)
    {
        throw "Error: negative power is not supported";
    }
    else if (pow == 0)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (i == j)
                {
                    matrix[i][j] = 1;
                }
                else
                {
                    matrix[i][j] = 0;
                }
            }
        }

        return *this;
    }
    else
    {
        Matrix a(*this);

        for (int i = 1; i < pow; i++)
        {
            a *= *this;
        }

        *this = a;
        
        return *this;
    }
}

//Transposes matrix
Matrix Matrix::operator~()
{
    Matrix a(cols, rows);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            a.matrix[j][i] = matrix[i][j];
        }
    }

    return a;
}

//Scalar multiplication of matrix
Matrix Matrix::operator*(const double& rhs)
{
    Matrix a(*this);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            a.matrix[i][j] *= rhs;
        }
    }

    return a;
}

Matrix operator* (const double& n, const Matrix& m)
{
    Matrix a(m);

    for (int i = 0; i < a.rows; i++)
    {
        for (int j = 0; j < a.cols; j++)
        {
            a.matrix[i][j] *= n;
        }
    }

    return a;
}

Matrix& Matrix::operator*=(const double& rhs)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] *= rhs;
        }
    }

    return *this;
}

//Scaler division of matrix
Matrix Matrix::operator/(const double& rhs)
{
    if (rhs == 0)
    {
        throw "Error: division by zero";
    }
    else
    {
        Matrix a(*this);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                a.matrix[i][j] /= rhs;
            }
        }

        return a;
    }
}

//Gets value from matrix
double& Matrix::operator()(const unsigned r, const unsigned c)
{
    if (r < 0 || r >= rows)
    {
        throw "Error: invalid row index";
    }
    else if (c < 0 || c >= cols)
    {
        throw "Error: invalid column index";
    }
    else
    {
        return matrix[r][c];
    }
}

const double& Matrix::operator()(const unsigned r, const unsigned c) const
{
    if (r < 0 || r >= rows)
    {
        throw "Error: invalid row index";
    }
    else if (c < 0 || c >= cols)
    {
        throw "Error: invalid column index";
    }
    else
    {
        return matrix[r][c];
    }
}

Vector Matrix::operator[](const unsigned r) const
{
    if (r < 0 || r >= rows)
    {
        throw "Error: invalid row index";
    }
    else
    {
        Vector v(cols);

        if (matrix[r])
        {
            for (int i = 0; i < cols; i++)
            {
                v[i] = matrix[r][i];
            }
            
            return v;
        }
        else
        {
            return v;
        }
    }
}

unsigned Matrix::getRows() const {return rows;}

unsigned Matrix::getCols() const {return cols;}

//Performs backwards substitution
Matrix Matrix::operator|(const Matrix& rhs)
{
    if (rows != cols)
    {
        throw "Error: non-square matrix provided";
    }
    else if (rhs.rows != rows && rhs.cols != 1)
    {
        throw "Error: incorrect augmentation";
    }
    else
    {
        bool augmented = true;

        Matrix A(*this);
        Matrix s(rhs);

        Matrix copyA(*this);
        Matrix copyS(rhs);

        copyA|=copyS;

        for (int i = 0; i < A.rows; i++)
        {
            for (int j = 0; j < A.cols; j++)
            {
                if (A(i,j) != copyA(i,j))
                {
                    augmented = false;
                    break;
                }
            }
        }

        for (int i = 0; i < s.rows; i++)
        {
            if (s(i,0) != copyS(i,0))
            {
                augmented = false;
            }
        }

        if (!augmented)
        {
            A |= s;
        }

        for (int i = rows-1; i >= 0; i--)
        {
            for (int j = i+1; j < rows; j++)
            {
                s(i,0) -= A(i,j) * s(j,0);
            }

            if (A(i,i) == 0)
            {
                throw "Error: division by zero";
            }
            else
            {
                s(i,0) /= A(i,i);
            }
        }

        return s;
    }
}

//Performs Gaussian elimination
Matrix& Matrix::operator|=(Matrix& rhs)
{
    if (rows != cols)
    {
        throw "Error: non-square matrix provided";
    }
    else if (rhs.rows != rows || rhs.cols != 1)
    {
        throw "Error: incorrect augmentation";
    }
    else
    {
        double m;

        Matrix A(*this);
        Matrix b(rhs);

        for (int i = 0; i < rows-1; i++)
        {
            for (int j = i+1; j < rows; j++)
            {
                if (A(i,i) == 0)
                {
                    throw "Error: division by zero";
                }
                else
                {
                    
                    m = A(j,i) / A(i,i);

                    for (int k = 0; k < cols; k++)
                    {
                        A(j,k) -= m * A(i,k);
                    }

                    b(j,0) -= m * b(i,0);
                }
            }
        }

        *this = A;
        rhs = b;

        return *this;
    }
}

// ;)