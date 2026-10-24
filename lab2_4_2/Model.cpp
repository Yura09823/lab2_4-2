#include "Model.h"

Model::Model() : brand("Unknown"), cpuType("Unknown"), cpuFreq(1.0), ram(1), hdd(1), gpu(1), price(0.1), quantity(0) {}

Model::Model(std::string b, std::string cpu, double freq, int r, int h, int g, double p, int q) {
    setBrand(b); setCpuType(cpu); setCpuFreq(freq);
    setRam(r); setHdd(h); setGpu(g); setPrice(p); setQuantity(q);
}

Model::Model(const Model& other) :
    brand(other.brand), cpuType(other.cpuType), cpuFreq(other.cpuFreq),
    ram(other.ram), hdd(other.hdd), gpu(other.gpu), price(other.price), quantity(other.quantity) {
}

Model::Model(const std::string& str) {
    std::stringstream ss(str);
    std::string b, cpu;
    double freq, p;
    int r, h, g, q;
    ss >> b >> cpu >> freq >> r >> h >> g >> p >> q;
    setBrand(b); setCpuType(cpu); setCpuFreq(freq);
    setRam(r); setHdd(h); setGpu(g); setPrice(p); setQuantity(q);
}

void Model::setBrand(const std::string& b) {
    if (b.empty()) throw std::invalid_argument("Марка не може бути порожньою");
    brand = b;
}
void Model::setCpuType(const std::string& cpu) {
    if (cpu.empty()) throw std::invalid_argument("Тип процесора не може бути порожнім");
    cpuType = cpu;
}
void Model::setCpuFreq(double freq) {
    if (freq <= 0) throw std::invalid_argument("Частота повинна бути > 0");
    cpuFreq = freq;
}
void Model::setRam(int r) {
    if (r <= 0) throw std::invalid_argument("RAM повинна бути > 0");
    ram = r;
}
void Model::setHdd(int h) {
    if (h <= 0) throw std::invalid_argument("HDD повинен бути > 0");
    hdd = h;
}
void Model::setGpu(int g) {
    if (g < 0) throw std::invalid_argument("GPU не може бути від'ємною");
    gpu = g;
}
void Model::setPrice(double p) {
    if (p < 0) throw std::invalid_argument("Ціна не може бути від'ємною");
    price = p;
}
void Model::setQuantity(int q) {
    if (q < 0) throw std::invalid_argument("Кількість не може бути від'ємною");
    quantity = q;
}

Model& Model::operator=(const Model& other) {
    if (this != &other) {
        brand = other.brand; cpuType = other.cpuType; cpuFreq = other.cpuFreq;
        ram = other.ram; hdd = other.hdd; gpu = other.gpu; price = other.price; quantity = other.quantity;
    }
    return *this;
}

Model::operator std::string() const {
    std::stringstream ss;
    ss << brand << " | CPU: " << cpuType << " (" << cpuFreq << "GHz) | RAM: " << ram
        << "GB | HDD: " << hdd << "GB | GPU: " << gpu << "GB | " << price << " USD | К-ть: " << quantity;
    return ss.str();
}

std::ostream& operator<<(std::ostream& os, const Model& m) {
    os << (std::string)m;
    return os;
}

std::istream& operator>>(std::istream& is, Model& m) {
    std::string b, cpu;
    double freq, p;
    int r, h, g, q;
    is >> b >> cpu >> freq >> r >> h >> g >> p >> q;
    m.setBrand(b); m.setCpuType(cpu); m.setCpuFreq(freq);
    m.setRam(r); m.setHdd(h); m.setGpu(g); m.setPrice(p); m.setQuantity(q);
    return is;
}

bool operator==(const Model& m1, const Model& m2) {
    return m1.brand == m2.brand;
}

bool operator!=(const Model& m1, const Model& m2) {
    return !(m1 == m2);
}