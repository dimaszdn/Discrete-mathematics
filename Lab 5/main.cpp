#include<Coding.h>
#include <iostream>

void task3b()
{
    std::ofstream fout("files/task3b.txt");
    std::string corCode = "001010010010000";
    std::string errCode = "110100010010010";
    fout << "Остаток: " + divideByGeneratingPolynom(errCode) << "\n";
    fout << "Количество допущенных ошибок: " << hammingDist(corCode, errCode) << "\n";
}

int main()
{
    generateInformationCodes(m);
    std::vector<std::string> codeWords = getAllCodeWords();
    calcAllHammingDistances(codeWords);
    getGeneratingMatrix();
    characteristicsOfCode();
    syndromes(codeWords); //пункт 2в
    task3b();

    return 0;
}