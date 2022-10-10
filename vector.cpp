#include "vector.h"

#include <iomanip>

//Vector constructor sets all values to 0
Vector::Vector(unsigned s) : size(s)
{
    vector = new double[size];

    for (unsigned int i = 0; i < size; i++)
    {
        vector[i] = 0;
    }
}

//Copy constructor for vector
Vector::Vector(const Vector& rhs)
{
    size = rhs.size;

    vector = new double[size];

    for (unsigned int i = 0; i < size; i++)
    {
        vector[i] = rhs.vector[i];
    }
}

Vector::~Vector()
{
    delete [] vector;
    vector = NULL;
}

//Prints out the values in the vector
void Vector::print()
{
    for (unsigned int i = 0; i < size; i++)
    {
        if (i == size-1)
        {
            std::cout<< std::setw(10) << std::setprecision(3) << vector[i] <<std::endl;
        }
        else
        {
            std::cout<< std::setw(10) << std::setprecision(3) << vector[i];
        }
    }
}

//Reads values into vector
void Vector::readFile(istream &infile)
{
    for (unsigned int i = 0; i < size; i++)
    {
        infile >> vector[i];
    }
}

//Assignment operator for vector
const Vector& Vector::operator=(const Vector& rhs)
{
    if (&rhs == this)
    {
        return *this;
    }
    else
    {
        delete [] vector;

        size = rhs.size;

        vector = new double[size];

        for (unsigned int i = 0; i < size; i++)
        {
            vector[i] = rhs.vector[i];
        }

        return *this;
    }
}

//Adds two vectors together
Vector Vector::operator+(const Vector& rhs)
{
    if (size != rhs.size)
    {
        throw "Error: adding vectors of different dimensionality";
    }
    else
    {
        Vector a(*this);

        for (unsigned int i = 0; i < size; i++)
        {
            a.vector[i] += rhs.vector[i];
        }

        return a;
    }
}

Vector& Vector::operator+=(const Vector& rhs)
{
    if (size != rhs.size)
    {
        throw "Error: adding vectors of different dimensionality";
    }
    else
    {
        for (unsigned int i = 0; i < size; i++)
        {
            vector[i] += rhs.vector[i];
        }

        return *this;
    }
}

//Subtracts two vectors
Vector Vector::operator-(const Vector& rhs)
{
    if (size != rhs.size)
    {
        throw "Error: subtracting vectors of different dimensionality";
    }
    else
    {
        Vector a(*this);

        for (unsigned int i = 0; i < size; i++)
        {
            a.vector[i] -= rhs.vector[i];
        }

        return a;
    }
}

Vector& Vector::operator-=(const Vector& rhs)
{
    if (size != rhs.size)
    {
        throw "Error: subtracting vectors of different dimensionality";
    }
    else
    {
        for (unsigned int i = 0; i < size; i++)
        {
            vector[i] -= rhs.vector[i];
        }

        return *this;
    }
}

//Powers all vector elements
Vector Vector::operator^(int pow)
{
    if (pow < 0)
    {
        throw "Error: negative power is not supported";
    }
    else
    {
        Vector a(*this);

        for (unsigned int i = 0; i < size; i++)
        {
            for (int j = 1; j < pow; j++)
            {
                a.vector[i] *= vector[i];
            }
        }

        return a;
    }
}

Vector& Vector::operator^=(int pow)
{
    if (pow < 0)
    {
        throw "Error: negative power is not supported";
    }
    else
    {
        Vector a(*this);

        for (unsigned int i = 0; i < size; i++)
        {
            for (int j = 1; j < pow; j++)
            {
                a.vector[i] *= vector[i];
            }
        }

        *this = a;

        return *this;
    }
}

//Reverses the vector
Vector Vector::operator~()
{
    Vector a(*this);

    int temp[size];

    for (unsigned int i = size-1; i >= 0; i--)
    {
        temp[i] = a.vector[i];
    }

    for (unsigned int i = 0; i < size; i++)
    {
        a.vector[i] = temp[i];
    }
    
    return a;
}

//Scalar multiplication of vector
Vector Vector::operator*(const double& rhs)
{
    Vector a(*this);

    for (unsigned int i = 0; i < size; i++)
    {
        a.vector[i] *= rhs;
    }

    return a;
}

Vector operator* (const double& n, const Vector& v)
{
    Vector a(v);

    for (unsigned int i = 0; i < a.size; i++)
    {
        a.vector[i] *= n;
    }

    return a;
}

Vector& Vector::operator*=(const double& rhs)
{
    for (unsigned int i = 0; i < size; i++)
    {
        vector[i] *= rhs;
    }

    return *this;
}

//Scalar division of vector
Vector Vector::operator/(const double& rhs)
{
    if (rhs == 0)
    {
        throw "Error: division by zero";
    }
    else
    {
        Vector a(*this);

        for (unsigned int i = 0; i < size; i++)
        {
            a.vector[i] /= rhs;
        }

        return a;
    }
}

//Subscript operator of vector
double& Vector::operator[](const unsigned r)
{
    if (r < 0 || r >= size)
    {
        throw "Error: invalid column index";
    }
    else
    {
        return vector[r];
    }
}

const double& Vector::operator[](const unsigned r) const
{
    if (r < 0 || r >= size)
    {
        throw "Error: invalid column index";
    }
    else
    {
        return vector[r];
    }
}

unsigned Vector::getSize() const {return size;}