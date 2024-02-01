#include <iostream>
#include<string>
#include<set>

//Сколько различных слов из 5-и букв можно составить из букв слова КОМБИНАТОРИКА

int main()
{

    setlocale(LC_ALL, "Rus");

    std::string word = "комбинаторика";
    std::set<std::string> fiveLetterWords;

    // Перебор комбинаций из 5 букв
    for (int i = 0; i < word.size(); ++i) {
        for (int j = 0; j < word.size(); ++j) {
            for (int k = 0; k < word.size(); ++k) {
                for (int l = 0; l < word.size(); ++l) {
                    for (int m = 0; m < word.size(); ++m) {
                        if (i != j && i != k && i != l && i != m &&
                            j != k && j != l && j != m &&
                            k != m && k != l &&
                            l != m)
                        {
                            // Формирование слова из букв
                            std::string fiveLetterWord = {word[i], word[j], word[k], word[l], word[m]};

                            // Добавление в множество для исключения дубликатов
                            fiveLetterWords.insert(fiveLetterWord);
                        }
                    }
                }
            }
        }
    }

    // Вывод результата
    std::cout << "Количество различных слов из 5 букв: " << fiveLetterWords.size() << std::endl;

//    for (auto str : fiveLetterWords)
//        std::cout << str << "\n";
    return 0;
}