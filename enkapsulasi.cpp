#include <iostream>
using namespace std;

class remoteLampu {
private:
    string saklarNO[5];
public:
    void setSaklarNo (int i, string value) {
        saklarNO[i] = value;
    }
    string getSaklarNo(int i) {
        return saklarNO[i];
    }
};