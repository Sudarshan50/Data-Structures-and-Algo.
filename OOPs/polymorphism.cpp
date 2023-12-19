///Complex Number Addition...
#include<iostream>
using namespace std;
#define rep(i,j,k) for(int i = j;i<k;i++)
#define vi vector<int>

class Complex
{
    private:
        int real,imag;
    public:
        Complex(int r,int i)
        {
            real = r;
            imag = i;
        }
    Complex operator + (Complex const &a)
    {
        Complex res(0,0);
        res.real = real+a.real;
        res.imag = imag+a.imag;
        return res;
    }
    void display()
    {
        cout<<real<<"+"<<imag<<"i"<<endl;
    }

};

signed main()
{
    Complex c1(4,5),c2(5,2);
    Complex c3 = c1+c2;
    c3.display();

}