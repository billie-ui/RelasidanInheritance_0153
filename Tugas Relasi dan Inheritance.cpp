#include <iostream>
#include <string>
using namespace std;

class user {
protected:
    static int globalId;

public:
    int id;
    string nama;
    string email;

    user(string pNama, string pEmail) {
        id = generateId();
        nama = pNama;
        email = pEmail;
    }

    static int generateId() {
        return ++globalId;
    }
};

int user::globalId = 0;

class member : public user {
public:
    bool status;

    member(string pNama, string pEmail, bool pStatus)
        : user(pNama, pEmail) {
        status = pStatus;
    }

    void showProfile() {
        cout << "===== Profile Member =====" << endl;
        cout << "ID     : " << id << endl;
        cout << "Nama   : " << nama << endl;
        cout << "Email  : " << email << endl;
        cout << "Status : " << (status ? "Aktif" : "Nonaktif") << endl;
        cout << endl;
    }
};

class admin : public user {
public:
    admin(string pNama, string pEmail)
        : user(pNama, pEmail) {}

    void showAllMember(member members[], int jumlah) {
        cout << "===== Daftar Member =====" << endl;

        for (int i = 0; i < jumlah; i++) {
            cout << "ID     : " << members[i].id << endl;
            cout << "Nama   : " << members[i].nama << endl;
            cout << "Email  : " << members[i].email << endl;
            cout << "Status : "
                 << (members[i].status ? "Aktif" : "Nonaktif")
                 << endl << endl;
        }
    }

    void toggleActivationMember(member &m) {
        m.status = !m.status;

        cout << "Status member " << m.nama
             << " berhasil diubah menjadi "
             << (m.status ? "Aktif" : "Nonaktif")
             << endl;
    }
};

int main() {
    admin admin1("Billie", "asdfgha@gmail.com");

    member member1("verdi", "qwerty@gmail.com", true);
    member member2("Lia", "zxcvbn@gmail.com", false);

    member daftarMember[] = {member1, member2};

    admin1.showAllMember(daftarMember, 2);

    admin1.toggleActivationMember(daftarMember[1]);

    daftarMember[1].showProfile();

    return 0;
}