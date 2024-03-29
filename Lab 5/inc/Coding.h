#pragma once
#include<iostream>
#include<Func.h>

void generateInformationCodes(int degree)
{
    std::ofstream fout("files/informationCodes.txt");
    for (int i = 0; i < pow(2, degree); ++i)
    {
        std::bitset<m> code(i);
        fout << code;
        if (i != pow(2, degree) - 1)
            fout << "\n";
    }
    fout.close();
}

std::string divideByGeneratingPolynom(std::string dividend)
{
    int count = dividend.size();
    removeLeadingZeros(dividend, count);
    while (count >= Px.size())
    {
        dividend = XOR(dividend, Px + std::string(count - Px.size(), '0'));
        removeLeadingZeros(dividend, count); //счетчик изменяется здесь
    }
    return dividend;
}

std::string getCodeWord(const std::string& infCode)
{
    std::string codeWord = infCode + std::string(k, '0'); //добавили 4 избыточных элемента
    addControlPart(codeWord, divideByGeneratingPolynom(codeWord)); //вычисляем и добавляем кр/ч
    return codeWord;
}

std::vector<std::string> getAllCodeWords()
{
    std::ifstream fin("files/informationCodes.txt");
    std::ofstream fout("files/codeWords.txt");
    std::vector<std::string> codeWords;
    if (!fin.is_open())
        throw std::exception("The file cannot be opened or it is missing!");
    else
    {
        std::string infCode;
        while (!fin.eof())
        {
            std::getline(fin, infCode);
            std::string codeWord = getCodeWord(infCode);
            codeWords.push_back(codeWord);
            fout << codeWord << "\n";
        }
    }
    fin.close();
    fout.close();
    return codeWords;
}

void calcAllHammingDistances(const std::vector<std::string>& codeWords)
{
    std::ofstream fout("files/hammingDistance.txt");

    std::string result;
    for (int i = 0; i < codeWords.size(); ++i)
    {
        for (int j = i + 1; j < codeWords.size() - 1; ++j)
        {
            fout << hammingDist(codeWords[i], codeWords[j]) << "  ";
        }
        fout << "\n";
    }
    fout.close();
}

void getGeneratingMatrix()
{
    std::ofstream fout("files/generatingMatrix.txt");
    std::vector<std::string> matrix;
    for (int i = 0; i < m; ++i)
    {
        std::bitset<m> code(pow(2, i));
        matrix.push_back(code.to_string());
    }

    for (auto& bitStr : matrix)
        bitStr = getCodeWord(bitStr);

    for (const auto& code : matrix)
        fout << code << "\n";
}

//----------------------------------------------------
void characteristicsOfCode()
{
    std::ofstream fout("files/characteristics.txt");

    int q_i;
    if (d % 2 != 0)
        q_i = (d - 1) / 2;
    else
        q_i = d / 2 - 1;

    int q_o = d - 1;

    int countVec = pow(2, n - m) - 1;
    fout << "Количество исправляемых ошибок: " << q_i << "\n"; //задание 2 пункт а
    fout << "Количество различных векторов ошибок: " << countVec << "\n"; //задание 2 пункт б
    fout << "Количество обнаруживаемых ошибок: " << q_o << "\n"; //задание 3 пункт а
}

std::string invertBit(std::string codeWord, int pos)
{
    if (codeWord[pos] == '0')
        codeWord[pos] = '1';
    else
        codeWord[pos] = '0';
    return codeWord;
}

void syndromes(const std::vector<std::string>& codeWords)
{
    std::ofstream fout("files/syndromes.txt");
    fout << "[Кодовое слово]" << "\t" << "[Инвертирован]" << "\t\t" << "[Синдром]" << "\t\t" << "[Номер бита]" << "\n";
    std::string tmpCodeWord;
    for (int i = 0; i < codeWords.size(); ++i)
    {
        for (int j = 0; j < codeWords[i].size(); ++j)
        {
            tmpCodeWord = invertBit(codeWords[i], j);
            fout << codeWords[i] << "\t" << tmpCodeWord << "\t\t" << divideByGeneratingPolynom(tmpCodeWord) << "\t\t\t" << j << "\n";
        }
        fout << "\n";
    }
}