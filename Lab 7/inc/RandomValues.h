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