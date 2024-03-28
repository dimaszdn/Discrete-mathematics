#include<Coding.h>
#include <iostream>

int main()
{
    generateInformationCodes(m);
    std::vector<std::string> codeWords = getAllCodeWords();
//    calcAllHammingDistances(codeWords);
//    getGeneratingMatrix();
    /*std::string code1 = "100010000001001"; //1000{0}0000001001
    std::string syndrome1 = divideByGeneratingPolynom(code1);
    std::cout << "Syndrome for " + code1 + ": " << syndrome1 << "\n";

    std::string code2 = "011001001110110"; //0110{1}1001110110
    std::string syndrome2 = divideByGeneratingPolynom(code2);
    std::cout << "Syndrome for " + code2 + ": " << syndrome2 << "\n";

    std::string code3 = "000000000110101"; //000000000110101
    std::string syndrome3 = divideByGeneratingPolynom(code3);
    std::cout << "Syndrome for " + code3 + ": " << syndrome2 << "\n";*/
//    syndromes(codeWords); //пункт 2в
    /*
     * Получается, что всего при одной ошибке 14 различных синдромов,
     * которые повторяются для каждого кодового слова при ошибке
     * в соответствующем бите
     */
    std::string code = "101111010000001";
    std::cout << divideByGeneratingPolynom(code) << "\n";
    return 0;
}