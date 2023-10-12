#include <iostream>

// Ошибки по стилю кода:
// Правлю первый и последний раз
// 1. Необходимо использовать camelCase либо under_score
// 2. Необходимо использовать const там, где это возможно
// 3. Добавляйте в .gitignore файлы, которые не должны попадать в репозиторий к примеру файлы сборки

// Можем собраться и подумать
// getIntLen - название функции не соответствует ее действию -> правильно length
// Нужна ли нам эта функция вообще?
// Максимальное int число 7fffffff -> 8 символов, следовательно мы можем выделить 8 + 3 символов
// 8 для числа 1 для знака два для 0x и один для \0
// Зато сложность нашего алгоритма будет O(n) где n - длина числа
// Мы же проходим по числу дважды, следовательно сложность O(2n), что конечно в глобальном смысле роли не играет
// Но все же

// Программа не собирается отсутствует CMake проект
// и в ней нет main функции
// Необходимо добавить main функцию
// Необходимо добавить в .gitignore файлы сборки и файлы .vscode
// Необходимо написать тесты используя assert()

// хау ту юз ассерт ?
// #include <cassert>
// assert(1 == 2);

// Конечная функция написана с ошибками (-0) != 0x


int getIntLen(int num) {
    int length = 0; // <- стиль это все
    while (num > 0) { // <- стиль это все
        num = num / 16; // <- стиль это все
        length = length + 1; // <- стиль это все
    }
    return length; // <- стиль это все
}

char *intTohex(int num) {
    bool is_negative = (num < 0); // <- стиль это все и можео проще )
    int total_length; // <- стиль это все

    if (is_negative) { // <- стиль это все
        total_length = getIntLen(num) + 3; // <- стиль это все
    } else { // <- стиль это все
        total_length = getIntLen(num) + 2; // <- стиль это все
    } // <- стиль это все

    char *result = new char[total_length + 1]; // <- стиль это все
    result[total_length + 1] = 0; // <- стиль это все

    int i; // <- стиль это все
    if (is_negative) { // <- стиль это все
        num = num * (-1);
        result[0] = '-';
        result[1] = '0';
        result[2] = 'x';
        i = getIntLen(num) + 2;
    } else {
        result[0] = '0';
        result[1] = 'x';
        i = getIntLen(num) + 1;
    }

    while (num > 0) {
        int ost = num % 16;
        char res;

        if (ost > 9) {
            res = char(64 + (ost - 9));
        } else {
            res = char(48 + ost);
        }

        result[i] = res;
        num = num / 16;
        i = i - 1;
    }

    return result;
}

int main() { std::cout << intTohex(-0) << std::endl; }