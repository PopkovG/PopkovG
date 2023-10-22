#include <iostream>

int getLenght(int num) {
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
        total_length = getLenght(num) + 3; // <- стиль это все
    } else { // <- стиль это все
        total_length = getLenght(num) + 2; // <- стиль это все
    } // <- стиль это все

    char *result = new char[total_length + 1]; // <- стиль это все
    result[total_length + 1] = 0; // <- стиль это все

    int i; // <- стиль это все
    if (is_negative) { // <- стиль это все
        num = num * (-1);
        result[0] = '-';
        result[1] = '0';
        result[2] = 'x';
        i = getLenght(num) + 2;
    } else {
        result[0] = '0';
        result[1] = 'x';
        i = getLenght(num) + 1;
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

int main() {
    int number;
    std::cin >> number;
    std::cout << intTohex(number) << std::endl;
    return 0;
}