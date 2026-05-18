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

int main() {
    RekeningBank* rekening1 = new RekeningSyariah("SYR001", "Rofif", 5000000);
    RekeningBank* rekening2 = new RekeningKonvensional("KONV002", "Lutfi", 3000000);
    RekeningBank* rekening3 = new RekeningPremium("PREM003", "Aldi", 15000000);
    RekeningBank* rekening4 = new RekeningPremium("PREM004", "Jarwo", 8000000);

    cout << "=========== SALDO AWAL =============\n";
    rekening1->tampilkan();
    rekening2->tampilkan();
    rekening3->tampilkan();
    rekening4->tampilkan();

    cout << "\n========== PROSES ADMIN BULANAN ==========\n";
    rekening1->potongAdmin();
    rekening2->potongAdmin();
    rekening3->potongAdmin();
    rekening4->potongAdmin();

    cout << "\n============ SALDO AKHIR ==========\n";
    rekening1->tampilkan();
    rekening2->tampilkan();
    rekening3->tampilkan();
    rekening4->tampilkan();

    delete rekening1;
    delete rekening2;
    delete rekening3;
    delete rekening4;

    return 0;
}