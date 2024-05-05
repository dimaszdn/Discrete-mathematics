#pragma once

#include<vector>
#include<string>
#include<sstream>
#include<fstream>
#include<iostream>
#include<iomanip>

std::vector<int> convertToRowMatrix(const std::string& row)
{
    std::vector<int> rowMatrix;
    std::istringstream is(row);
    int value;
    while(is >> value)
        rowMatrix.push_back(value);
    return rowMatrix;
}

std::vector<std::vector<int>> getMatrixFromFile(const std::string& path)
{
    std::vector<std::vector<int>> matrix;
    std::ifstream file(path);
    if (!file.is_open())
        throw std::exception("File opening error");
    else
    {
        std::string row;
        while (std::getline(file, row))
            matrix.push_back(convertToRowMatrix(row));
    }
    return matrix;
}

void print(const std::vector<std::vector<int>>& matrix)
{
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[i].size(); ++j)
            std::cout << std::right << std::setw(7) << matrix[i][j];
        std::cout << "\n";
    }
}