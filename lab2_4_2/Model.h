#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>

#pragma pack(push, 1)
struct ModelPack {
    char brand[30];
    char cpuType[30];
    double cpuFreq;
    int ram, hdd, gpu, quantity;
    double price;
};
#pragma pack(pop)

class Model {
private:
    std::string brand;
    std::string cpuType;
    double cpuFreq;
    int ram;
    int hdd;
    int gpu;
    double price;
    int quantity;

public:
    Model();
    Model(std::string b, std::string cpu, double freq, int r, int h, int g, double p, int q);
    Model(const Model& other);
    Model(const std::string& str);

    std::string getBrand() const { return brand; }
    std::string getCpuType() const { return cpuType; }
    double getCpuFreq() const { return cpuFreq; }
    int getRam() const { return ram; }
    int getHdd() const { return hdd; }
    int getGpu() const { return gpu; }
    double getPrice() const { return price; }
    int getQuantity() const { return quantity; }

    void setBrand(const std::string& b);
    void setCpuType(const std::string& cpu);
    void setCpuFreq(double freq);
    void setRam(int r);
    void setHdd(int h);
    void setGpu(int g);
    void setPrice(double p);
    void setQuantity(int q);

    Model& operator=(const Model& other);
    operator std::string() const;

    friend std::ostream& operator<<(std::ostream& os, const Model& m);
    friend std::istream& operator>>(std::istream& is, Model& m);
    friend bool operator==(const Model& m1, const Model& m2);
    friend bool operator!=(const Model& m1, const Model& m2);
};

#endif