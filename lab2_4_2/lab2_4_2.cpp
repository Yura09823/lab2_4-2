#include <iostream>

#include "PriceList.h"
#include "Windows.h"


using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Розмір PriceList: " << sizeof(PriceList) << " байт" << endl;
    cout << "Розмір PriceListPack: " << sizeof(PriceListPack) << " байт" << endl;

    Model m1("Asus", "Intel_i7", 3.2, 16, 512, 4, 1000, 5);
    Model m2("Dell", "AMD_Ryzen5", 3.6, 8, 256, 2, 800, 10);
    Model m3("HP", "Intel_i5", 2.8, 16, 1024, 6, 950, 3);
    Model m4("Apple", "M2", 3.5, 16, 512, 8, 1500, 2);

    Model arrayModels[2] = { m1, m2 };
    cout << "Елемент масиву об'єктів: \n" << arrayModels[0] << "\n\n";

    PriceList list1("01.10.2023", 38.5);
    list1.add(m1);
    list1.add(m2);
    list1.add(m3);

    PriceList list2("01.10.2023", 38.5);
    list2.add(m2);
    list2.add(m4);

    cout << "Прайс-лист 1 \n" << list1 << endl;
    cout << "Прайс-лист 2 \n" << list2 << endl;

    cout << "Елемент list1[0]: " << (string)list1[0] << "\n\n";

    PriceList unionList = list1 + list2;
    cout << "Об'єднання (list1 + list2) \n" << unionList << endl;

    PriceList intersectList = list1 * list2;
    cout << "Перетин (list1 * list2) \n" << intersectList << endl;

    PriceList diffList = list1 - list2;
    cout << "Віднімання (list1 - list2) \n" << diffList << endl;

    cout << "Пошук ПК (RAM>=16, HDD>=1000, GPU>=4):" << endl;
    Model found = list1.searchBySpecs(16, 1000, 4);
    cout << found << "\n\n";

    cout << "Загальна сума у прайсі 1 (в грн): " << list1.totalSum() << " грн" << endl;

    return 0;
}