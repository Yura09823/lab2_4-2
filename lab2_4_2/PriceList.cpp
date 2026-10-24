#include "PriceList.h"

PriceList::PriceList() : date("01.01.2000"), exchangeRate(1.0), size(MAX_SIZE), count(0) {}

PriceList::PriceList(std::string d, double rate) : size(MAX_SIZE), count(0) {
    setDate(d); setExchangeRate(rate);
}

PriceList::PriceList(const PriceList& other) : date(other.date), exchangeRate(other.exchangeRate), size(other.size), count(other.count) {
    for (int i = 0; i < count; ++i) data[i] = other.data[i];
}

void PriceList::setDate(const std::string& d) {
    if (d.empty()) throw std::invalid_argument("Дата не може бути порожньою");
    date = d;
}

void PriceList::setExchangeRate(double rate) {
    if (rate <= 0) throw std::invalid_argument("Курс валют має бути більше 0");
    exchangeRate = rate;
}

bool PriceList::add(const Model& m) {
    if (count >= size) return false;
    for (int i = 0; i < count; ++i) {
        if (data[i] == m) return false;
    }
    data[count++] = m;
    return true;
}

bool PriceList::modify(const Model& m) {
    for (int i = 0; i < count; ++i) {
        if (data[i].getBrand() == m.getBrand()) {
            data[i] = m;
            return true;
        }
    }
    return false;
}

bool PriceList::remove(const std::string& brand) {
    for (int i = 0; i < count; ++i) {
        if (data[i].getBrand() == brand) {
            for (int j = i; j < count - 1; ++j) data[j] = data[j + 1];
            count--;
            return true;
        }
    }
    return false;
}

Model PriceList::searchByBrand(const std::string& brand) const {
    for (int i = 0; i < count; ++i) {
        if (data[i].getBrand() == brand) return data[i];
    }
    throw std::runtime_error("Модель не знайдена");
}

Model PriceList::searchBySpecs(int minRam, int minHdd, int minGpu) const {
    for (int i = 0; i < count; ++i) {
        if (data[i].getRam() >= minRam && data[i].getHdd() >= minHdd && data[i].getGpu() >= minGpu)
            return data[i];
    }
    throw std::runtime_error("Модель не знайдена");
}

double PriceList::totalSum() const {
    double sum = 0;
    for (int i = 0; i < count; ++i) {
        sum += data[i].getPrice() * data[i].getQuantity() * exchangeRate;
    }
    return sum;
}

PriceList& PriceList::operator=(const PriceList& other) {
    if (this != &other) {
        date = other.date; exchangeRate = other.exchangeRate; count = other.count;
        for (int i = 0; i < count; ++i) data[i] = other.data[i];
    }
    return *this;
}

Model& PriceList::operator[](int index) {
    if (index < 0 || index >= count) throw std::out_of_range("Індекс поза межами");
    return data[index];
}

const Model& PriceList::operator[](int index) const {
    if (index < 0 || index >= count) throw std::out_of_range("Індекс поза межами");
    return data[index];
}

PriceList::operator std::string() const {
    std::stringstream ss;
    ss << "Прайс від " << date << " (Курс: " << exchangeRate << " грн)\n";
    for (int i = 0; i < count; ++i) ss << "[" << i << "] " << (std::string)data[i] << "\n";
    return ss.str();
}

std::ostream& operator<<(std::ostream& os, const PriceList& pl) {
    os << (std::string)pl;
    return os;
}

PriceList operator+(const PriceList& p1, const PriceList& p2) {
    PriceList res(p1.date, p1.exchangeRate);
    for (int i = 0; i < p1.count; ++i) res.add(p1[i]);
    for (int i = 0; i < p2.count; ++i) res.add(p2[i]);
    return res;
}

PriceList operator*(const PriceList& p1, const PriceList& p2) {
    PriceList res(p1.date, p1.exchangeRate);
    for (int i = 0; i < p1.count; ++i) {
        for (int j = 0; j < p2.count; ++j) {
            if (p1[i] == p2[j]) { res.add(p1[i]); break; }
        }
    }
    return res;
}

PriceList operator-(const PriceList& p1, const PriceList& p2) {
    PriceList res(p1.date, p1.exchangeRate);
    for (int i = 0; i < p1.count; ++i) {
        bool found = false;
        for (int j = 0; j < p2.count; ++j) {
            if (p1[i] == p2[j]) { found = true; break; }
        }
        if (!found) res.add(p1[i]);
    }
    return res;
}