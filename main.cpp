#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

long double taylorSeries(long double x)
{
    int approx = 100;
    long double firstPart = x - 1;
    long double result = 0;
    for (int i = 2; i < approx + 1; i++)
    {
        result += pow(-1, i) * (((long double)1 / i) * (pow((x - 1), i)));
    }
    result = (firstPart - result);
    return result;
}

long double logFunctionForAnyBase(long double a, long double b){
    return log(a) / log(b);
}

// if you want to calculate log10 60, follow this format logbase x
long double calc_log(long double x, int base)
{

    int exponent = 0, secondPart = 10; // the first step of log calculation, split it into two parts, for example: log10 60 = log10 0.6 + log10 100, log10 100 here is the second part
    double copy = x;
    long double result = 0.0;
    if (copy > 1) // if statement here process the splitting of the first and second part
    {
        while (copy > 1) // standardization process so that we are left with log10 0.6 (the first part)
        {
            copy /= 10;
            exponent++;
        } // this while loop gets us log10 0.6
        for (int i = 1; i < exponent; i++)
        {
            secondPart *= 10;
        } // this while loop gets us log10 100

        // log10 0.6 = ln 0.6/ln 10
        long double lnx = taylorSeries(copy);
        long double firstPart = lnx / log(base); // the two lines calculate ln 0.6 / ln 10
        result = firstPart + logFunctionForAnyBase(secondPart,base);  // log10 60 = log10 0.6 + log10 100
    }
    else // if the input value is sth like log10 0.6 (i.e if x < 1), then you don't need to split it so no second part. You can just ln 0.6/ ln 10
    {
        long double lnx = taylorSeries(x);
        result = lnx / log(base);
    }
    return result;
}
int main()
{
    // cout << taylorSeries(0.3) << endl;
    cout << setprecision(30) << calc_log(0.2, 35); // 60
}
