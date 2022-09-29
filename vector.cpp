#include "vector.h"

Vector::Vector(unsigned s) : size(s)
{
    vector = new double[size];

    for (int i = 0; i < size; i++)
    {
        vector[i] = 0;
    }
}

Vector::Vector(const Vector& rhs)
{
    size = rhs.size;

    for (int i = 0; i < size; i++)
    {
        vector[i] = rhs.vector[i];
    }
}

Vector::~Vector()
{
    delete [] vector;
    vector = NULL;
}

void Vector::print()
{

}

void Vector::readFile(istream &infile)
{

}

const Vector& Vector::operator=(const Vector& rhs)
{
    
}

Vector Vector::operator+(const Vector& rhs)
{

}

Vector& Vector::operator+=(const Vector& rhs)
{

}

Vector Vector::operator-(const Vector& rhs)
{

}

Vector& Vector::operator-=(const Vector& rhs)
{

}

Vector Vector::operator^(int pow)
{

}

Vector& Vector::operator^=(int pow)
{

}

Vector Vector::operator~()
{

}

Vector Vector::operator*(const double& rhs)
{

}

Vector operator* (const double&, const Vector&)
{

}

Vector& Vector::operator*=(const double& rhs)
{

}

Vector Vector::operator/(const double& rhs)
{

}

double& Vector::operator[](const unsigned r)
{

}

const double& Vector::operator[](const unsigned r) const
{

}

unsigned Vector::getSize() const {}