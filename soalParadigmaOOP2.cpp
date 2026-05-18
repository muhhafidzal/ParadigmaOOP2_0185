#include <iostream>
#include <string>
using namespace std;

class RekeningBank {
protected:
    string nomorRekening;
    string namaNasabah;
    double saldo;

public:
    RekeningBank(string noRek, string nama, double saldoAwal)
        : nomorRekening(noRek), namaNasabah(nama), saldo(saldoAwal) {}

    virtual ~RekeningBank() {}

    virtual void potongAdmin() = 0;

    void tampilkan() {
        cout << "Nama: " << namaNasabah
             << "No Rek: " << nomorRekening
             << "Saldo: Rp " << saldo << endl;
             
    }
};

class RekeningSyariah : public RekeningBank {
public:
    RekeningSyariah(string noRek, string nama, double saldoAwal)
        : RekeningBank(noRek, nama, saldoAwal) {}

    void potongAdmin() override {
        cout << " Syariah " << namaNasabah << " bebas biaya admin.\n";
    }
};
