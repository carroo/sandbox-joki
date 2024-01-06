#include <iostream>
#include <fstream>
using namespace std;

int bahasa;

string bilangan[4][12] = {
    {"kosong", "satu ", "dua ", "tiga ", "empat ", "lima ", "enam ", "tujuh ", "delapan ", "sembilan ", "sepuluh ", "sebelas "},
    {"zero", "one ", "two ", "three ", "four ", "five ", "six ", "seven ", "eight ", "nine ", "teen ", "eleven "},
    {"ree", "ichi ", "ni ", "san ", "yon ", "go ", "roku ", "nana ", "hachi ", "kyu ", "juu ", "juu ichi "},
    {"yeong", "il ", "i ", "sam ", "sa ", "o ", "yuk ", "chil ", "pal ", "gu ", "ship ", "sibil "}};

string imbuhan[4][13] = {
    {"belas ", "puluh ", "ratus ", "ribu "},
    {"teen ", "", "hundred ", "thousand "},
    {"juu ", "juu ", "hyaku ", "sen "},
    {"si", "sip ", "baek ", "cheon "}};

string puluhan_english[10] = {"", "", "twenty ", "thirty ", "forty ", "fifty ", "sixty ", "seventy ", "eighty ", "ninty "};

string eja(int angka)
{
    if (angka == 0)
    {
        return "";
    }
    else if (angka < 1)
    {
        return "Negatif " + eja(-angka);
    }
    else if (angka < 12)
    {
        return bilangan[bahasa][angka];
    }
    else if (angka < 20)
    {
        if (bahasa == 1 && angka == 12)
        {
            return "twelve";
        }
        else if (bahasa == 2)
        {
            return imbuhan[bahasa][0] + eja(angka % 10);
        }
        else
        {
            return eja(angka % 10) + imbuhan[bahasa][0];
        }
    }
    else if (angka < 100)
    {
        if (bahasa == 1)
        {
            return puluhan_english[angka / 10] + imbuhan[bahasa][1] + eja(angka % 10);
        }
        else
        {
            return eja(angka / 10) + imbuhan[bahasa][1] + eja(angka % 10);
        }
    }
    else if (angka < 1000)
    {
        if (angka < 200 && bahasa == 0)
        {
            return "Seratus " + eja(angka % 100);
        }
        else
        {
            return eja(angka / 100) + imbuhan[bahasa][2] + eja(angka % 100);
        }
    }
    else if (angka < 10000)
    {
        if (angka < 2000 && bahasa == 0)
        {
            return "Seribu " + eja(angka % 1000);
        }
        else
        {
            return eja(angka / 1000) + imbuhan[bahasa][3] + eja(angka % 1000);
        }
    }
    else
    {
        return "Masukan maksimal 4 digit aja ya";
    }
}

int main()
{
    int angka;
    do
    {
        system("CLS");
        cout << "========================================" << endl;
        cout << "         MENU Mengeja Angka            " << endl;
        cout << "========================================" << endl;
        cout << "Pilih :                                 " << endl;
        cout << "0. Bahasa (indonesia)                   " << endl;
        cout << "1. English (inggris)                    " << endl;
        cout << "2. Nihongo (jepang)                     " << endl;
        cout << "3. Hanguk (korea)                       " << endl;
        cout << "4. Keluar Program                       " << endl;
        cout << "Silahkan pilih bahasa (0-3) : ";
        cin >> bahasa;
        if (bahasa == 4)
        {
            cout << "Terima Kasih";
        }
        else if (bahasa > 3)
        {
            cout << "maaf bahasa yang dipilih masih bisa 0-3";
        }
        else
        {
            cout << "Masukan angka yang mau dieja (4digit) : ";
            cin >> angka;
            if (angka == 0)
            {
                cout << bilangan[bahasa][0];
            }
            else
            {
                cout << "hasil ejaan adalah : " << eja(angka) << endl;
            }
            fstream file;
            file.open("kamus.txt", ios::app);
            file << "bahasa : " << bahasa << " || " << angka << " : " << eja(angka) << endl;
            file.close();
        }
        cout << "Ketik apapun untuk lanjut..";
        cin.ignore();
        cin.get();
        system("clear || cls");
    } while (bahasa != 4);
    cout << "Seluruh ejaan sudah terekam di  kamus.txt" << endl;
    return 0;
}
