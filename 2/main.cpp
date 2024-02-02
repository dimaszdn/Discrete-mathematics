#include <iostream>
#include<fstream>
#include<vector>

double resultingFormula(int n)
{
    double res =  (pow(-5, n) / 7.0f) + ((6  * pow(2, n)) / 7.0f);
    return res;
}

double a_(int n)
{
    static std::vector<double> values = {1, 1};
    double numb1, numb2, res;

    if (n == 0 || n == 1)
        return 1;

    //определяем numb1
    if (values.size() > n - 1)
        numb1 = values[n - 1];
    else
        numb1 = a_(n - 1);

    //определяем numb2
    if (values.size() > n - 2)
        numb2 = values[n - 2];
    else
        numb2 = a_(n - 2);


    res =
    values.push_back(res);
    return res;
}

int main()
{
    /*std::ofstream fout("Res.txt");
    double result = recurrence(100);
    std::cout.setf(std::ios_base::fixed); //задаёт формат вывода
    std::cout << "a_100 = " << result << "\n";

    for (int i = 0; i <= 100; ++i)
    {
        std::cout << i << ") " << recurrence(i + 2) + 3 * recurrence(i + 1) - 10 * recurrence(i) << "\n";
    }*/

    std::cout << a_(3);

    return 0;
}
