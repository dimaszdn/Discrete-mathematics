#include <iostream>
#include<fstream>

double recurrence(int n)
{
    double res =  (pow(-5, n) / 7.0f) + ((6  * pow(2, n)) / 7.0f);
    return res;
}

int main()
{
    std::ofstream fout("Res.txt");
    double result = recurrence(100);
    std::cout.setf(std::ios_base::fixed); //задаёт формат вывода
    std::cout << "a_100 = " << result << "\n";

    for (int i = 0; i <= 100; ++i)
    {
        std::cout << i << ") " << recurrence(i + 2) + 3 * recurrence(i + 1) - 10 * recurrence(i) << "\n";
    }

    return 0;
}
