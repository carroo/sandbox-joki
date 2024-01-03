#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;
// r = relation = nilai
// p = parent = mahasiswa
// c = child = dosen
struct pN
{
    string nama, kelas, nim;
    pN *next, *prev;
};
struct cN
{
    string dosen, matkul, nidn;
    cN *next, *prev;
};
struct rN
{
    int nilai;
    rN *next, *prev;
    pN *rp;
    cN *rc;
};

struct pN *headP, *tailP;
struct cN *headC, *tailC;
struct rN *headR, *tailR;

void dataP(struct pN *h)
{
    pN *help;
    help = h;
    if (h)
    {

        cout << "+---------------+-----------------------+--------------------+" << endl;
        cout << "|                   Data Mahasiswa (j)                       |" << endl;
        cout << "+---------------+-----------------------+--------------------+" << endl;
        cout << setw(15) << left << "| Nim" << setw(25) << left << " | Nama" << setw(20) << left << "| Kelas "
             << " |" << endl;
        cout << "+---------------+-----------------------+--------------------+" << endl;
        int jumlah = 0;
        while (help)
        {
            cout << "| " << setw(13) << left << help->nim << " | " << setw(22) << left << help->nama << "| " << setw(18) << left << help->kelas << " |" << endl;
            help = help->next;
            jumlah += 1;
        }
        cout << setfill('-') << setw(62) << "-" << setfill(' ') << endl; // Garis pemisah
        cout << "jumlah data mahasiswa : " << jumlah;
    }
    cout << endl
         << endl;
}
void dataC(struct cN *h)
{
    cN *help;
    help = h;
    if (h)
    {

        cout << "+--------------+------------------------+--------------------+" << endl;
        cout << "|                     Data Dosen (k)                         }" << endl;
        cout << "+--------------+------------------------+--------------------+" << endl;
        cout << setw(14) << left << "| Nidn" << setw(26) << left << " | Nama" << setw(20) << left << "| Matkul "
             << " |" << endl;
        cout << "+--------------+------------------------+--------------------+" << endl;
        int jumlah = 0;
        while (help)
        {
            cout << "| " << setw(12) << left << help->nidn << " | " << setw(23) << left << help->dosen << "| " << setw(18) << left << help->matkul << " |" << endl;
            help = help->next;
            jumlah += 1;
        }
        cout << setfill('-') << setw(62) << "-" << setfill(' ') << endl; // Garis pemisah
        cout << "jumlah data Dosen : " << jumlah;
    }
    cout << endl
         << endl;
}
void dataR(struct rN *h)
{
    rN *help;
    help = h;
    if (h)
    {

        cout << "+--------------+------------------------+--------------------+" << endl;
        cout << "|                     Data Nilai                             |" << endl;
        cout << "+--------------+------------------------+--------------------+" << endl;
        cout << setw(14) << left << "| Nidn" << setw(26) << left << " | Nim" << setw(20) << left << "| Nilai "
             << " |" << endl;
        cout << "+--------------+------------------------+--------------------+" << endl;
        int jumlah = 0;
        while (help)
        {
            cout << "| " << setw(12) << left << help->rc->nidn << " | " << setw(23) << left << help->rp->nim << "| " << setw(18) << left << help->nilai << " |" << endl;
            help = help->next;
            jumlah += 1;
        }
        cout << setfill('-') << setw(62) << "-" << setfill(' ') << endl; // Garis pemisah
        cout << "jumlah data Dosen : " << jumlah;
    }
    cout << endl
         << endl;
}
void dataRP(struct pN *h)
{
    pN *help;
    rN *currentR = headR;
    int PtidakmemilikiC = 0 ;
    help = h;
    if (currentR)
    {

        cout << "+-------------------+-------------------+-------------------+-------------------+-------------------+" << endl;
        cout << "|                          Data Mahasiswa Beserta Dosen Yang Menilainya (N)                         |" << endl;
        cout << "+-------------------+-------------------+-------------------+-------------------+-------------------+" << endl;
        cout << setw(19) << left << "| Nama"
             << setw(20) << left << " | Nim"
             << setw(20) << left << " | Jmlh Child (P)"
             << setw(20) << left << " | Dosen"
             << setw(20) << left << " | Nilai"
             << " |" << endl;
        cout << "+-------------------+-------------------+-------------------+-------------------+-------------------+" << endl;
        int jumlah = 0;
        while (help)
        {
            cout << "| " << setw(17) << left << help->nama
                 << " | " << setw(17) << left << help->nim
                 << " | " << setw(17) << left << " "
                 << " | " << setw(17) << left << " "
                 << " | " << setw(17) << left << " "
                 << " |" << endl;

            currentR = headR;
            int jc = 0;
            while (currentR != nullptr)
            {
                if (currentR->rp == help)
                {
                    cout << "| " << setw(17) << left << " "
                         << " | " << setw(17) << left << " "
                         << " | " << setw(17) << left << " "
                         << " | " << setw(17) << left << currentR->rc->dosen
                         << " | " << setw(17) << left << currentR->nilai
                         << " |" << endl;
                    jc += 1;
                }
                currentR = currentR->next;
            }
            if(jc == 0){
                PtidakmemilikiC += 1;
            }
            cout << "| " << setw(17) << left << " "
                 << " | " << setw(17) << left << " "
                 << " | " << setw(17) << left << jc
                 << " | " << setw(17) << left << " "
                 << " | " << setw(17) << left << " "
                 << " |" << endl;
            help = help->next;
            jumlah += 1;
        }
        cout << "+-------------------+-------------------+-------------------+-------------------+-------------------+" << endl;
        cout << "jumlah data Mahasiswa yang tidak dinilai oleh dosen (S): " << PtidakmemilikiC;
    }
    cout << endl
         << endl;
}
void dataRC(struct cN *h)
{
    cN *help;
    rN *currentR = headR;
    int CtidakmemilikiP = 0 ;
    help = h;
    if (currentR)
    {

        cout << "+-------------------+-------------------+-------------------+-------------------+-------------------+" << endl;
        cout << "|                          Data Dosen Beserta Mahasiswa Yang Dinilainya (O)                         |" << endl;
        cout << "+-------------------+-------------------+-------------------+-------------------+-------------------+" << endl;
        cout << setw(19) << left << "| Nama"
             << setw(20) << left << " | NIDN"
             << setw(20) << left << " | Jmlh Parent (Q)"
             << setw(20) << left << " | Nama MHS"
             << setw(20) << left << " | Nilai"
             << " |" << endl;
        cout << "+-------------------+-------------------+-------------------+-------------------+-------------------+" << endl;
        int jumlah = 0;
        while (help)
        {
            cout << "| " << setw(17) << left << help->dosen
                 << " | " << setw(17) << left << help->nidn
                 << " | " << setw(17) << left << " "
                 << " | " << setw(17) << left << " "
                 << " | " << setw(17) << left << " "
                 << " |" << endl;

            currentR = headR;
            int jp = 0;
            while (currentR != nullptr)
            {
                if (currentR->rc == help)
                {
                    cout << "| " << setw(17) << left << " "
                         << " | " << setw(17) << left << " "
                         << " | " << setw(17) << left << " "
                         << " | " << setw(17) << left << currentR->rp->nama
                         << " | " << setw(17) << left << currentR->nilai
                         << " |" << endl;
                    jp += 1;
                }
                currentR = currentR->next;
            }
            if(jp == 0){
                CtidakmemilikiP += 1;
            }
            cout << "| " << setw(17) << left << " "
                 << " | " << setw(17) << left << " "
                 << " | " << setw(17) << left << jp
                 << " | " << setw(17) << left << " "
                 << " | " << setw(17) << left << " "
                 << " |" << endl;
            help = help->next;
            jumlah += 1;
        }
        cout << "+-------------------+-------------------+-------------------+-------------------+-------------------+" << endl;
        cout << "jumlah data Dosen yang tidak menilai mahasiswa (R) : " << CtidakmemilikiP;
    }
    cout << endl
         << endl;
}

void pInput(string nim, string nama, string kelas)
{
    pN *newest, *help;
    newest = new pN;
    newest->nim = nim;
    newest->nama = nama;
    newest->kelas = kelas;
    newest->next = NULL;
    newest->prev = NULL;
    if (!headP)
    {
        headP = newest;
        tailP = headP;
    }
    else
    {
        newest->next = headP;
        headP->prev = newest;
        headP = newest;
    }
}
void cInput(string nidn, string dosen, string matkul)
{
    cN *newest, *help;
    newest = new cN;
    newest->nidn = nidn;
    newest->dosen = dosen;
    newest->matkul = matkul;
    newest->next = NULL;
    newest->prev = NULL;
    if (!headC)
    {
        headC = newest;
        tailC = headC;
    }
    else
    {
        newest->next = headC;
        headC->prev = newest;
        headC = newest;
    }
}
void rInput(string nidn, string nim, int nilai)
{
    pN *helpP = headP;
    cN *helpC = headC;
    rN *newest = new rN;
    newest->nilai = nilai;
    newest->next = NULL;
    newest->prev = NULL;

    while (helpP != NULL && helpP->nim != nim)
    {
        helpP = helpP->next;
    }

    while (helpC != NULL && helpC->nidn != nidn)
    {
        helpC = helpC->next;
    }

    if (helpP != NULL && helpC != NULL)
    {

        newest->rp = helpP;
        newest->rc = helpC;
        if (!headR)
        {
            headR = newest;
            tailR = headR;
        }
        else
        {
            newest->next = headR;
            headR->prev = newest;
            headR = newest;
        }
    }
    else
    {
        cout << "Mahasiswa atau Dosen tidak ditemukan" << endl;
    }
}

void rDelete(pN *p, cN *c)
{
    rN *current = headR, *previous = nullptr;

    while (current != nullptr)
    {
        if (current->rp == p || current->rc == c)
        {
            // jika current nya itu head
            if (previous == nullptr)
            {
                headR = current->next;
                if (headR != nullptr)
                    headR->prev = nullptr;
            }
            // jika current nya itu bukan head
            else
            {
                previous->next = current->next;
                if (current->next != nullptr)
                    current->next->prev = previous;
            }

            cout << "Relasi yang terhubung juga ikut dihapus (F)" << endl;
        }

        previous = current;
        current = current->next;
    }
}
void pDelete(string nim)
{
    pN *current = headP, *previous = nullptr;

    while (current != nullptr)
    {
        if (current->nim == nim)
        {
            // jika current nya itu head
            if (previous == nullptr)
            {
                headP = current->next;
                if (headP != nullptr)
                    headP->prev = nullptr;
            }
            // jika current nya itu bukan head
            else
            {
                previous->next = current->next;
                if (current->next != nullptr)
                    current->next->prev = previous;
            }

            rDelete(current, nullptr);

            // menghapus node dari memory
            delete current;

            cout << "Mahasiswa dengan NIM " << nim << " telah di hapus." << endl;
            return;
        }

        previous = current;
        current = current->next;
    }

    // If the NIM is not found
    cout << "Mahasiswa dengan NIM " << nim << " tidak ada." << endl;
}
void cDelete(string nidn)
{
    cN *current = headC, *previous = nullptr;

    while (current != nullptr)
    {
        if (current->nidn == nidn)
        {
            // jika current nya itu head
            if (previous == nullptr)
            {
                headC = current->next;
                if (headC != nullptr)
                    headC->prev = nullptr;
            }
            // jika current nya itu bukan head
            else
            {
                previous->next = current->next;
                if (current->next != nullptr)
                    current->next->prev = previous;
            }
            rDelete(nullptr, current);

            // menghapus node dari memory
            delete current;
            cout << "Dosen dengan NIDN " << nidn << " telah dihapus." << endl;
            return;
        }

        previous = current;
        current = current->next;
    }

    // If the NIDN is not found
    cout << "Dosen dengan NIDN " << nidn << " tidak ada." << endl;
}

void pFind(string nim)
{
    pN *current = headP, *previous = nullptr;

    while (current != nullptr)
    {
        if (current->nim == nim)
        {
            cout << "+-------------------------------------+" << endl;
            cout << "| Berhasil mencari Data Mahasiswa (G) |" << endl;
            cout << "+-------------------------------------+" << endl;
            cout << "| NIM   : " << current->nim << endl;
            cout << "| Nama  : " << current->nama << endl;
            cout << "| Kelas : " << current->kelas << endl;
            cout << "+----------------------------------------+" << endl;
            cout << "| Relasi Dosen yang memberikan nilai (L) |" << endl;
            cout << "+----------------------------------------+" << endl;
            cout << "| ";

            rN *currentR = headR;

            while (currentR != nullptr)
            {
                if (currentR->rp == current)
                {
                    cout << currentR->rc->dosen << " | ";
                }

                currentR = currentR->next;
            }
            cout << endl;
            return;
        }
        current = current->next;
    }
    cout << "Mahasiswa dengan NIM " << nim << " tidak ada." << endl;
}
void cFind(string nidn)
{
    cN *current = headC, *previous = nullptr;

    while (current != nullptr)
    {
        if (current->nidn == nidn)
        {
            cout << "+---------------------------------+" << endl;
            cout << "| Berhasil mencari Data Dosen (H) |" << endl;
            cout << "+---------------------------------+" << endl;
            cout << "| NIDN       : " << current->nidn << endl;
            cout << "| Nama Dosen : " << current->dosen << endl;
            cout << "| Matkul     : " << current->matkul << endl;
            cout << "+-------------------------------------------+" << endl;
            cout << "| Relasi Mahasiswa yang diberikan nilai (M) |" << endl;
            cout << "+-------------------------------------------+" << endl;
            cout << "| ";
            rN *currentR = headR;

            while (currentR != nullptr)
            {
                if (currentR->rc == current)
                {
                    cout << currentR->rp->nama << " | ";
                }

                currentR = currentR->next;
            }
            cout << endl;
            return;
        }

        previous = current;
        current = current->next;
    }
    cout << "Dosen dengan NIDN " << nidn << " tidak ada." << endl;
}
void rFind(string nim, string nidn)
{
    rN *current = headR, *previous = nullptr;
    string ingin;
    int nilai;
    while (current != nullptr)
    {
        if (current->rp->nim == nim && current->rc->nidn == nidn)
        {
            cout << "+-----------------------------+" << endl;
            cout << "|     Relasi Ditemukan        |" << endl;
            cout << "+-----------------------------+" << endl;
            cout << "| Nama mahasiswa : " << current->rp->nama << endl;
            cout << "| Telah dinilai oleh " << endl;
            cout << "| Dosen : " << current->rc->dosen << endl;
            cout << "| Dengan nilai :  "<< current->nilai << endl;
            cout << "Apakah kamu ingin merubah data relasi (T) ? (y/Y) : ";
            cin >> ingin;
            if(ingin == "y" || ingin == "Y"){
                cout << "Masukan nilai baru : ";
                cin >>  nilai;
                current->nilai = nilai;
                cout << "Data Relasi Telah diperbarui"<<endl;
            }
        }

        previous = current;
        current = current->next;
    }
}

main()
{
    int menu, menu1;
    string nama, nim, kelas;
    string dosen, nidn, matkul;
    int nilai;
    do
    {
        system("CLS");
        cout << endl;
        cout << "+----------------------------------------+" << endl;
        cout << "|                 Menu Utama             |" << endl;
        cout << "+----------------------------------------+" << endl;
        cout << "| 1. Input Data (A)(B)(C)                |" << endl;
        cout << "| 2. Lihat Data (J)(K)(N)(O)(P)(Q)(R)(S) |" << endl;
        cout << "| 3. Hapus Data (D)(E)(F)                |" << endl;
        cout << "| 4. Cari Data (G)(H)(I)(L)(M)(T)        |" << endl;
        cout << "+----------------------------------------+" << endl;
        cout << "Pilih menu : ";
        cin >> menu;
        if (menu == 1)
        {
            cout << "+--------------------------------+" << endl;
            cout << "|         Menu Input Data        |" << endl;
            cout << "+--------------------------------+" << endl;
            cout << "| 1. Mahasiswa (parent) (a)      |" << endl;
            cout << "| 2. Dosen (Child) (b)           |" << endl;
            cout << "| 3. Nilai (Relation) (c)        |" << endl;
            cout << "+--------------------------------+" << endl;
            cout << "Pilih menu : ";
            cin >> menu1;
            if (menu1 == 1)
            {
                cout << "Masukan Nama Mahasiswa    : ";
                cin >> nama;
                cout << "Masukan Nim Mahasiswa     : ";
                cin >> nim;
                cout << "Masukan Kelas Mahasiswa   : ";
                cin >> kelas;
                pInput(nim, nama, kelas);
            }
            else if (menu1 == 2)
            {
                cout << "Masukan Nama Dosen    : ";
                cin >> dosen;
                cout << "Masukan NIDN Dosen    : ";
                cin >> nidn;
                cout << "Masukan Mata Kuliah   : ";
                cin >> matkul;
                cInput(nidn, dosen, matkul);
            }
            else if (menu1 == 3)
            {
                cout << "masukan nim mahasiswa : ";
                cin >> nim;
                cout << "masukan nidn dosen : ";
                cin >> nidn;
                cout << "masukan nilai : ";
                cin >> nilai;
                rInput(nidn, nim, nilai);
            }
        }
        else if (menu == 2)
        {
            dataP(headP);
            dataC(headC);
            dataR(headR);
            dataRP(headP);
            dataRC(headC);
        }
        else if (menu == 3)
        {
            cout << "+--------------------------------+" << endl;
            cout << "|           Hapus Data           |" << endl;
            cout << "+--------------------------------+" << endl;
            cout << "| 1. Mahasiswa (parent) (D)      |" << endl;
            cout << "| 2. Dosen (Child) (E)           |" << endl;
            cout << "+--------------------------------+" << endl;
            cout << "Pilih menu : ";
            cin >> menu1;
            if (menu1 == 1)
            {
                cout << "Masukan Nim Mahasiswa     : ";
                cin >> nim;
                pDelete(nim);
            }
            else if (menu1 == 2)
            {
                cout << "Masukan NIDN Dosen    : ";
                cin >> nidn;
                cDelete(nidn);
            }
        }
        else if (menu == 4)
        {
            cout << "+--------------------------------+" << endl;
            cout << "|         Menu Cari Data         |" << endl;
            cout << "+--------------------------------+" << endl;
            cout << "| 1. Mahasiswa (parent) (G) (L)  |" << endl;
            cout << "| 2. Dosen (Child) (H) (M)       |" << endl;
            cout << "| 3. Nilai (Relation) (I) (T)    |" << endl;
            cout << "+--------------------------------+" << endl;
            cout << "Pilih menu : ";
            cin >> menu1;
            if (menu1 == 1)
            {
                cout << "Masukan Nim Mahasiswa     : ";
                cin >> nim;
                pFind(nim);
            }
            else if (menu1 == 2)
            {
                cout << "Masukan NIDN Dosen    : ";
                cin >> nidn;
                cFind(nidn);
            }
            else if (menu1 == 3)
            {
                cout << "Masukan Nim Mahasiswa     : ";
                cin >> nim;
                cout << "Masukan NIDN Dosen    : ";
                cin >> nidn;
                rFind(nim,nidn);
            }
        }
        cout << "klik untuk lanjut";
        getch();
    } while (menu != 0);
}
