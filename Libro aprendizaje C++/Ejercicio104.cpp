#include <iostream>
#include <cmath>

using namespace std;

double pow1 (double, int);

int main()
{
cout << pow1(3.0,0);
    return 0;
}

double pow1 (double base, int exp) {
double result=1.0;
if (exp>0){
for(int i=1;i<=exp;++i)
result*=base;
}
if (exp <0 && base==0){
    result=HUGE_VAL;
}
if (exp <0 && base!=0 ){
int abs_exp=-exp;
for(int i=1;i<=abs_exp;++i)
result*=(1/base);
}
    return result;

}