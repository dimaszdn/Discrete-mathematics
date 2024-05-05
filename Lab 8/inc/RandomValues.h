#pragma once

#include<random>
#include <cassert>

struct PRNG
{
    std::mt19937 engine;
};

void initGenerator(PRNG& generator)
{
    // Создаём псевдоустройство для получения случайного зерна.
    std::random_device device;
    // Получаем случайное зерно последовательности
    generator.engine.seed(device());
}

// Генерирует целое число в диапазоне [minValue, maxValue)
int random(PRNG& generator, int minValue, int maxValue)
{
    // Проверяем корректность аргументов
    assert(minValue < maxValue);

    // Создаём распределение
    std::uniform_int_distribution<int> distribution(minValue, maxValue);

    // Вычисляем псевдослучайное число: вызовем распределение как функцию,
    //  передав генератор произвольных целых чисел как аргумент.
    return distribution(generator.engine);
}

std::vector<std::vector<int>> randomThroughput(std::vector<std::vector<int>> adjMatrix, int min, int max)
{
    PRNG generator;
    initGenerator(generator);
    for (int i = 0; i < adjMatrix.size(); ++i)
    {
        for (int j = 0; j < adjMatrix.size(); ++j)
        {
            if (adjMatrix[i][j] > 0)
                adjMatrix[i][j] = random(generator, min, max);
        }
    }
    return adjMatrix;
}