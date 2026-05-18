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

class RekeningKonvensional : public RekeningBank {
public:
    RekeningKonvensional(string noRek, string nama, double saldoAwal)
        : RekeningBank(noRek, nama, saldoAwal) {}

    void potongAdmin() override {
        saldo -= 15000;
        cout << " Konvensional " << namaNasabah << " dipotong Rp 15.000.\n";
    }
};

class RekeningPremium : public RekeningBank {
public:
    RekeningPremium(string noRek, string nama, double saldoAwal)
        : RekeningBank(noRek, nama, saldoAwal) {}

    void potongAdmin() override {
        if (saldo > 10000000) 
        {
            cout << " Premium " << namaNasabah << " bebas biaya admin.\n";
        } 
        else 
        {
            saldo -= 50000;
            cout << " Premium " << namaNasabah << " dipotong Rp 50.000.\n";
        }
    }
};
