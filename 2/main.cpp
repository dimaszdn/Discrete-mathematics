#include <iostream>

double a_n(int n) //полученная формула
{
    double res =  (pow(-5, n)  + (6 * pow(2, n))) / 7.0;
    return res;
}

double recurrenceRelation(int n) //само рекуррентное соотношение
{
    double a = 1;
    double b = 1;
    double result = 0;

    for (int i = 2; i <= n; i++)
    {
        result = 10 * b - 3 * a;
        b = a;
        a = result;
    }

    return result;
}

int main()
{
    double firstRes = recurrenceRelation(100);
    double secondRes = a_n(100);
    std::cout << firstRes << "\n\n";
    std::cout << secondRes << "\n\n";

    return 0;
}
