#include <iostream>
#include <vector>
#include <string>

struct MobilePhone {
    double weight;
    bool is_broken;
    double price;
};

int main() {
    std::vector<MobilePhone> mobiles;
    int num;

    std::cout << "Введите количество мобильных телефонов: ";
    std::cin >> num;

    for(int i = 0; i < num; ++i) {
        MobilePhone phone;
        
        std::cout << "Введите вес, состояние (1 - сломан, 0 - не сломан) и цену телефона №" << i+1 << ": ";
        std::cin >> phone.weight >> phone.is_broken >> phone.price;
        mobiles.push_back(phone);
    }

    std::cout << "\n<MobilePhones>\n";
    for (int i = 0; i < mobiles.size(); ++i) {
        std::cout << "    <MobilePhone id=\"" << i << "\" weight=\"" << mobiles[i].weight
                  << "\" is_broken=\"" << (mobiles[i].is_broken ? "true" : "false")
                  << "\" price=\"" << mobiles[i].price << "\"/>\n";
    }
    std::cout << "</MobilePhones>\n";

    return 0;
}