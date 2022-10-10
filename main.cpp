#include <iostream>
#include "matrix.h"
#include "vector.h"
#include <fstream>
#include <string>

using namespace std;

static void print(Arithmetic *mat) {
    mat->print();
    cout << endl;
}

static void readFile(istream &infile, Arithmetic *mat) {
    mat->readFile(infile);
}

//
static void task1() {
    ifstream infile("example_input.txt");
    // The test code below assumes that you have implemented all Task 1 functionality

    // 1. Test constructor:
    cout << "Constructors: " << endl;

    Matrix *m1 = new Matrix(3, 4);
    print(m1);

    Vector *v1 = new Vector(7);
    v1->print();
    print(v1);


    // read file.
    readFile(infile, v1);
    v1->print();

    cout << "vector  Test" << endl;
    Vector v2(3);

    cout << v2[0] << endl;

    readFile(infile, m1);
    m1->print();

    // Test assignment operator:
    Matrix *m2 = new Matrix(1, 4);
    print(m2);
    m2 = m1; // assignment
    print(m2);

    // Test getters
    cout << "Getters: " << endl;
    cout << m1->getRows() << endl;
    cout << m2->getCols() << endl;
    cout << v1->getSize() << endl;

//    // Test [][]
    cout << "Test [][]: " << endl;
    try {
        Matrix m4(3, 3);
        m4.readFile(infile);
        cout << m4[0][2] << endl;
        m4(0,2) = 5;
        cout << m4[0][2] << endl;
        m4(5,2) = 5;
    } catch (const char *error) {
        cout << error << endl;
    }

    infile.close();
}


static void task2() {

    // Matrix Arithmeitc:
    // The test code below assumes that you have implemented all Task 2 functionality.
    // ------------------------------------------------------------------------------
    // NOTE: The examples below are illustrative, NOT exhaustive. You must extend the
    // provided code with your own tests. Trigger every exception, make sure all corner
    // cases work. Test all operators!
    ifstream infile("example_input.txt");

    cout << "Matrix arithmetic" << endl;
    Matrix *m1 = new Matrix(2, 6);
    m1->readFile(infile);
    m1->print();
    // Scalar * matrix
    cout << "Matrix Multiplication by scalar:" << endl;
    m1->operator*(3.5).print();
    m1->operator*=(2);
    m1->print();

    cout << "Vector Multiplication by scalar:" << endl;
    Vector *vec1 = new Vector(5);
    vec1->readFile(infile);
    vec1->print();

    vec1->operator*(3.5).print();
    vec1->operator*=(2);
    vec1->print();


    // Scalar / matrix
    cout << "Division by scalar:" << endl;
    try {
        m1->operator/(7.2).print();
        m1->operator/(0).print();
    } // should trigger exception
    catch(const char * err) { cout << err << endl; }

    infile.close();
}

static void task3() {
    //////////////////////////////////
    // The rest is linear equations //
    //////////////////////////////////
    ifstream infile("task3Input.txt");

    cout << "Reading matrices..." << endl;
    Matrix system(3,3), augmented(3,1);
    system.readFile(infile);
    augmented.readFile(infile);

    Matrix A = system;
    Matrix b = augmented;

    A.print();
    cout<<endl;
    b.print();

    cout << "Reducing to upper-triangular form:" << endl;

    A |= b;

    A.print();
    cout<<endl;
    b.print();

    cout << "Solving the system:" << endl;
    Matrix c = A|b;
    c.print();

    cout << "Reducing to upper-triangular form AND solving the system:" << endl;
    
    c = system|augmented;
    c.print();

    infile.close();
}

int main() {
    /*task1();
    task2(); 
    task3();*/

    ifstream infile("matrix.txt");

    Matrix m1(3,4);
    Matrix m2(3,3);
    Matrix m3(3,4);

    cout<< m1.getRows() << " " << m1.getCols() <<endl;
    cout<< m2.getRows() << " " << m2.getCols() <<endl;
    cout<< m3.getRows() << " " << m3.getCols() <<endl;

    m1.readFile(infile);
    m2.readFile(infile);
    m3.readFile(infile);

    m1.print();
    cout<<endl;

    m2.print();
    cout<<endl;

    m3.print();
    cout<<endl;

    cout<< "Vectors:" <<endl;

    Vector v1(4);
    Vector v2(3);
    Vector v3(4);

    cout<< v1.getSize() <<endl;
    cout<< v2.getSize() <<endl;
    cout<< v3.getSize() <<endl;

    v1 = m1[0];
    v2 = m2[1];
    v3 = m3[2];

    v1.print();
    cout<<endl;

    v2.print();
    cout<<endl;

    v3.print();
    cout<<endl;

    m1(0,0) = 3;
    v3[2] = 2;

    cout<< m1(0,0) << " " << m2(2,2) << " " << m3(1,2) << " " << v1[1] << " " << v2[1] << " " << v3[2] <<endl;
    cout<<endl;

    cout<< "Error Handeling" <<endl;
    cout<<endl;

    try {m2(-1,0) = 6;}
    catch (const char * err) {cout << err << endl;}

    try {m2(0,10) = 6;}
    catch (const char * err) {cout << err << endl;}

    try {v1[-2] = 2;}
    catch (const char * err) {cout << err << endl;}

    try {v3[12] = 22;}
    catch (const char * err) {cout << err << endl;}
    cout<<endl;

    cout<< "Multiplication" <<endl;
    cout<<endl;

    Matrix m4(3,4);
    Matrix m5(3,3);

    m4 = m1 * 2;
    m5 = 3 * m2;
    m3 *= 4;

    m4.print();
    cout<<endl;

    m5.print();
    cout<<endl;

    m3.print();
    cout<<endl;

    Vector v4(4);
    Vector v5(3);

    v4 = v1 * 3;
    v5 = v2 * 2;
    v3 *= 4;

    v4.print();
    cout<<endl;

    v5.print();
    cout<<endl;

    v3.print();
    cout<<endl;

    cout<< "Division" <<endl;
    cout<<endl;

    m3 = m3 / 4;
    v3 = v3 / 4;

    m3.print();
    cout<<endl;

    v3.print();
    cout<<endl;

    try {m3 = m3 / 0;}
    catch (const char * err) {cout << err << endl;}

    try {v3 = v3 / 0;}
    catch (const char * err) {cout << err << endl;}
    cout<<endl;

    cout<< "Addition" <<endl;
    cout<<endl;

    Matrix m6(4,3);

    m6 = m1 + m3;
    m6.print();
    cout<<endl;

    m6 += m1;
    m6.print();
    cout<<endl;

    Vector v6(4);

    v6 = v1 + v3;
    v6.print();
    cout<<endl;

    v6 += v1;
    v6.print();
    cout<<endl;

    try {m6 = m2 + m3;}
    catch (const char * err) {cout << err << endl;}
    
    try {v6 = v2 + v3;}
    catch (const char * err) {cout << err << endl;}
    cout<<endl;

    cout<< "Subtraction" <<endl;
    cout<<endl;

    m6 = m1 - m3;
    m6.print();
    cout<<endl;

    m6 -= m1;
    m6.print();
    cout<<endl;

    v6 = v1 - v3;
    v6.print();
    cout<<endl;

    v6 -= v1;
    v6.print();
    cout<<endl;

    try {m6 = m2 - m3;}
    catch (const char * err) {cout << err << endl;}
    
    try {v6 = v2 - v3;}
    catch (const char * err) {cout << err << endl;}
    cout<<endl;

    cout<< "Matrix Multiplication" <<endl;
    cout<<endl;

    Matrix m7(4, 3);
    m7.readFile(infile);
    m7.print();
    cout<<endl;

    m4 = m1 * m7;
    m4.print();
    cout<<endl;

    m4 *= m2;
    m4.print();
    cout<<endl;
     
    try {m4 = m1 * m2;}
    catch (const char * err) {cout << err << endl;}
    cout<<endl;

    cout<< "Power" <<endl;
    cout<<endl;

    m2.print();
    cout<<endl;

    m5 = m2 ^ 2;
    m5.print();
    cout<<endl;

    m5 ^= 3;
    m5.print();
    cout<<endl;

    m5 ^= 0;
    m5.print();
    cout<<endl;

    v1.print();
    v4 = v1 ^ 2;
    v4.print();
    cout<<endl;

    v5.print();
    v5 ^= 3;
    v5.print();
    cout<<endl;

    try {m4 = m1 ^ 2;}
    catch (const char * err) {cout << err << endl;}

    try {m1 ^= 2;}
    catch (const char * err) {cout << err << endl;}

    try {m4 ^= -2;}
    catch (const char * err) {cout << err << endl;}
    cout<<endl;

    cout<< "Transpose" <<endl;
    cout<<endl;

    m1.print();
    cout<<endl;

    m1 = ~m1;
    m1.print();
    cout<<endl;

    Matrix m8(3,3);
    Matrix m9(3,1);

    m8.readFile(infile);
    m9.readFile(infile);

    Matrix m10(3,1);

    try {m10 = m8|m9;}
    catch (const char * err) {cout << err << endl;}

    m10.print();

    return 0;
}
