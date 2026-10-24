    #ifndef PRICELIST_H
    #define PRICELIST_H

    #include "Model.h"

    #pragma pack(push, 1)
    struct PriceListPack {
        char date[20];
        double exchangeRate;
        ModelPack data[100];
        int size;
        int count;
    };
    #pragma pack(pop)

    class PriceList {
    private:
        static const int MAX_SIZE = 100;
        std::string date;
        double exchangeRate;
        Model data[MAX_SIZE];
        int size;
        int count;

    public:
        PriceList();
        PriceList(std::string d, double rate);
        PriceList(const PriceList& other);

        std::string getDate() const { return date; }
        double getExchangeRate() const { return exchangeRate; }
        int getSize() const { return size; } 
        int getCount() const { return count; }

        void setDate(const std::string& d);
        void setExchangeRate(double rate);

        bool add(const Model& m);
        bool modify(const Model& m);
        bool remove(const std::string& brand);
        Model searchByBrand(const std::string& brand) const;
        Model searchBySpecs(int minRam, int minHdd, int minGpu) const;
        double totalSum() const;

        PriceList& operator=(const PriceList& other);
        Model& operator[](int index);
        const Model& operator[](int index) const;
        operator std::string() const;

        friend PriceList operator+(const PriceList& p1, const PriceList& p2); 
        friend PriceList operator*(const PriceList& p1, const PriceList& p2); 
        friend PriceList operator-(const PriceList& p1, const PriceList& p2); 
        friend std::ostream& operator<<(std::ostream& os, const PriceList& pl);
    };

    #endif