#pragma once

#include<string>
#include<fstream>
#include<bitset>
#include<vector>

#include<Parameters.h>

void removeLeadingZeros(std::string& str, int& count)
{
    int i = 0;
    while (str[i] == '0')
        i++;
    str.erase(0, i);
    count -= i;
}

//Сложение по модулю 2
std::string XOR(std::string a, std::string b)
{
    std::string result;
    char sum;
    for (int i = 0; i < a.size(); ++i)
    {
        sum = ((a[i] - '0') ^ (b[i] - '0')) + '0';
        result.push_back(sum);
    }
    return result;
}

void addControlPart(std::string& codeWord, const std::string& controlPart)
{
    for (int i = 0; i < controlPart.size(); ++i)
        codeWord[codeWord.size() - 1 - i] = controlPart[controlPart.size() - 1 - i];
}

int hammingDist(const std::string& a, const std::string& b)
{
    std::string result = XOR(a, b);
    int weight = 0;
    for (auto c : result)
        weight += (c - '0');
    return weight;
}