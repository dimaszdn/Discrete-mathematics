#include <iostream>
#include<string>
#include<set>

//������� ��������� ���� �� 5-� ���� ����� ��������� �� ���� ����� �������������

int main()
{

    setlocale(LC_ALL, "Rus");

    std::string word = "�������������";
    std::set<std::string> fiveLetterWords;

    // ������� ���������� �� 5 ����
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
                            // ������������ ����� �� ����
                            std::string fiveLetterWord = {word[i], word[j], word[k], word[l], word[m]};

                            // ���������� � ��������� ��� ���������� ����������
                            fiveLetterWords.insert(fiveLetterWord);
                        }
                    }
                }
            }
        }
    }

    // ����� ����������
    std::cout << "���������� ��������� ���� �� 5 ����: " << fiveLetterWords.size() << std::endl;

//    for (auto str : fiveLetterWords)
//        std::cout << str << "\n";
    return 0;
}