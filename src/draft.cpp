#include <string>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

/* KAMUS GLOBAL */
vector<string> list_operation; //array of strings: list dari semua operasi yang menghasilkan nilai 24
int ln_operation; //jumlah solusi yang ditemukan (panjang list operation) ln_operation = list_operation.size()

float charToInt (string s){
    /*
    Mengubah string menjadi angka yang sepadan dengan nilai kartu
    Misalkan 'A'=1, '2'=2, 'J'=11, 'Q'=12, 'K'=13
    Jika string s bukan nilai kartu (misalnya '1', '0', atau huruf selain J,Q,K), maka mengembalikan nilai -1
    */
    if (s=="A"){
        return 1;
    } else if (s=="2"){
        return 2;
    } else if (s=="3"){
        return 3;
    } else if (s=="4"){
        return 4;
    } else if (s=="5"){
        return 5;
    } else if (s=="6"){
        return 6;
    } else if (s=="7"){
        return 7;
    } else if (s=="8"){
        return 8;
    } else if (s=="9"){
        return 9;
    } else if (s=="10"){
        return 10;
    } else if (s=="J"){
        return 11;
    } else if (s=="Q"){
        return 12;
    } else if (s=="K"){
        return 13;
    } else {
        return -1;
    }
}

string intToChar (int i){
    /*
    Mengubah angka (int) menjadi string yang sepadan dengan nilai kartu
    Misalkan 'A'=1, '2'=2, 'J'=11, 'Q'=12, 'K'=13
    */
    if (i==1){
        return "A";
    } else if (i==2){
        return "2";
    } else if (i==3){
        return "3";
    } else if (i==4){
        return "4";
    } else if (i==5){
        return "5";
    } else if (i==6){
        return "6";
    } else if (i==7){
        return "7";
    } else if (i==8){
        return "8";
    } else if (i==9){
        return "9";
    } else if (i==10){
        return "10";
    } else if (i==11){
        return "J";
    } else if (i==12){
        return "Q";
    } else if (i==13){
        return "K";
    }
}

float charToOp (char op, float operand1, float operand2){
    /* Menghitung operasi antara operand1 dan operand2 dengan operator op */
    if (op=='+'){
        return operand1 + operand2;
    } else if (op=='-'){
        return operand1 - operand2;
    } else if (op=='*'){
        return operand1 * operand2;
    } else if (op=='/'){
        return operand1 / operand2;
    }
}

vector<string> splitString (const string &s, char delimiter){
    /* Melakukan split string setiap delimiter */
    vector<string> hasil;
    stringstream ss (s);
    string item;
    while (getline (ss, item, delimiter)) {
        hasil.push_back (item);
    }
    return hasil;
}

vector<string> split(const string& str, const string& delim)
{
    vector<string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == string::npos) pos = str.length();
        string token = str.substr(prev, pos-prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    }
    while (pos < str.length() && prev < str.length());
    return tokens;
}

void brute_force(vector<float> angkaKartu){
    /* KAMUS LOKAL */
    int counter1,counter2,counter3; //indeks permutasi urutan kartu
    float temp; //variabel untuk swap kartu
    char list_operator[4] = {'+','-','*','/'};
    int countOp1,countOp2,countOp3; //indeks permutasi urutan operator
    float hasil1,hasil2,hasil; //hasil perhitungan
    /* ALGORITMA */

    //std::cout << list_operator[0] << " " << list_operator[1] << " " << list_operator[2] << " " << list_operator[3] << "\n";
    float angka0 = angkaKartu[0]; //fixed urutan angka asli
    float angka1 = angkaKartu[1];
    float angka2 = angkaKartu[2];
    float angka3 = angkaKartu[3];
    /* Permutasi 4 Kartu */
    for (counter1=0; counter1<=3; counter1++){
        angkaKartu[0] = angka0; //kembalikan ke urutan kartu aslinya
        angkaKartu[1] = angka1;
        angkaKartu[2] = angka2;
        angkaKartu[3] = angka3;
        /* Swap angkaKartu[0] dengan elemen indeks 0,1,2,3 */
        temp = angkaKartu[0];
        angkaKartu[0] = angkaKartu[counter1];
        angkaKartu[counter1] = temp;

        float angkaKomb0 = angkaKartu[0];
        float angkaKomb1 = angkaKartu[1];
        float angkaKomb2 = angkaKartu[2];
        float angkaKomb3 = angkaKartu[3];

        for (counter2=1; counter2<=3; counter2++){
            /* Kembalikan ke urutan kartu swap pertama */
            angkaKartu[0] = angkaKomb0;
            angkaKartu[1] = angkaKomb1;
            angkaKartu[2] = angkaKomb2;
            angkaKartu[3] = angkaKomb3;
            /* Swap angkaKartu[1] dengan elemen indeks 1,2,3 */
            temp = angkaKartu[1];
            angkaKartu[1] = angkaKartu[counter2];
            angkaKartu[counter2] = temp;

            for (counter3=2; counter3<=3; counter3++){
                /* Swap angkaKartu[2] dengan elemen indeks 2,3 */
                temp = angkaKartu[2];
                angkaKartu[2] = angkaKartu[counter3];
                angkaKartu[counter3] = temp;
                /*
                for (int count=0; count<=3; count++){
                    cout << angkaKartu[count] << " ";
                }
                cout << "\n";
                */

                /* Operasi */
                for (countOp1=0; countOp1<=3; countOp1++){
                    for (countOp2=0; countOp2<=3; countOp2++){
                        for (countOp3=0; countOp3<=3; countOp3++){
                            /* list_operator[countOp1] list_operator[countOp2] list_operator[countOp3] */
                            //std::cout << list_operator[countOp1] << list_operator[countOp2] << list_operator[countOp3] << "\n";
                            /* jenis operasi kurung:
                            ((A  _  B) _  C) _ D
                            ( A  _ (B  _  C))_ D
                             (A  _  B) _ (C  _ D)
                              A  _((B  _  C) _ D)
                              A  _( B  _ (C  _ D))
                            */
                            /* ((A  _  B) _  C) _ D */
                            hasil1 = charToOp(list_operator[countOp1], angkaKartu[0], angkaKartu[1]); //(A _ B)
                            hasil2 = charToOp(list_operator[countOp2], hasil1, angkaKartu[2]); //((A _ B) _ C)
                            hasil = charToOp(list_operator[countOp3], hasil2, angkaKartu[3]); //((A _ B) _ C) _ D
                            
                            if (hasil==24.0 && find(list_operation.begin(), list_operation.end(), "((" + std::to_string((int) angkaKartu[0]) + list_operator[countOp1] + std::to_string((int) angkaKartu[1]) + ")" + list_operator[countOp2] + std::to_string((int) angkaKartu[2]) + ")" + list_operator[countOp3] + std::to_string((int) angkaKartu[3])) == list_operation.end()){
                                //std::cout << "yes\n";
                                //cout << "hasil = " << hasil << " = " << "((" + std::to_string(angkaKartu[0]) + list_operator[countOp1] + std::to_string(angkaKartu[1]) + ")" + list_operator[countOp2] + std::to_string(angkaKartu[2]) + ")" + list_operator[countOp3] + std::to_string(angkaKartu[3]) << "\n";
                                list_operation.push_back("((" + std::to_string((int) angkaKartu[0]) + list_operator[countOp1] + std::to_string((int) angkaKartu[1]) + ")" + list_operator[countOp2] + std::to_string((int) angkaKartu[2]) + ")" + list_operator[countOp3] + std::to_string((int) angkaKartu[3]));
                            }
                            /* ( A  _ (B  _  C))_ D */
                            hasil1 = charToOp(list_operator[countOp2], angkaKartu[1], angkaKartu[2]); //(B _ C)
                            hasil2 = charToOp(list_operator[countOp1], angkaKartu[0], hasil1); //(A _ (B _ C))
                            hasil = charToOp(list_operator[countOp3], hasil2, angkaKartu[3]); //(A _ (B _ C)) _ D
                            
                            if (hasil==24.0 && find(list_operation.begin(), list_operation.end(), "(" + std::to_string((int) angkaKartu[0]) + list_operator[countOp1] + "(" + std::to_string((int) angkaKartu[1]) + list_operator[countOp2] + std::to_string((int) angkaKartu[2]) + "))" + list_operator[countOp3] + std::to_string((int) angkaKartu[3])) == list_operation.end()){
                                //std::cout << "yes\n";
                                //cout << "hasil = " << hasil << " = " << "(" + std::to_string(angkaKartu[0]) + list_operator[countOp1] + "(" + std::to_string(angkaKartu[1]) + list_operator[countOp2] + std::to_string(angkaKartu[2]) + "))" + list_operator[countOp3] + std::to_string(angkaKartu[3]) << "\n";
                                list_operation.push_back("(" + std::to_string((int) angkaKartu[0]) + list_operator[countOp1] + "(" + std::to_string((int) angkaKartu[1]) + list_operator[countOp2] + std::to_string((int) angkaKartu[2]) + "))" + list_operator[countOp3] + std::to_string((int) angkaKartu[3]));
                            }
                            /* (A  _  B) _ (C  _ D) */
                            hasil1 = charToOp(list_operator[countOp1], angkaKartu[0], angkaKartu[1]); //(A _ B)
                            hasil2 = charToOp(list_operator[countOp3], angkaKartu[2], angkaKartu[3]); //(C _ D)
                            hasil = charToOp(list_operator[countOp2], hasil1, hasil2); //(A _ B) _ (C _ D)
                            
                            if (hasil==24.0 && find(list_operation.begin(), list_operation.end(), "(" + std::to_string((int) angkaKartu[0]) + list_operator[countOp1] + std::to_string((int) angkaKartu[1]) + ")" + list_operator[countOp2] + "(" + std::to_string((int) angkaKartu[2]) + list_operator[countOp3] + std::to_string((int) angkaKartu[3]) + ")") == list_operation.end()){
                                //std::cout << "yes\n";
                                //cout << "hasil = " << hasil << " = " << "(" + std::to_string(angkaKartu[0]) + list_operator[countOp1] + std::to_string(angkaKartu[1]) + ")" + list_operator[countOp2] + "(" + std::to_string(angkaKartu[2]) + list_operator[countOp3] + std::to_string(angkaKartu[3]) + ")" << "\n";
                                list_operation.push_back("(" + std::to_string((int) angkaKartu[0]) + list_operator[countOp1] + std::to_string((int) angkaKartu[1]) + ")" + list_operator[countOp2] + "(" + std::to_string((int) angkaKartu[2]) + list_operator[countOp3] + std::to_string((int) angkaKartu[3]) + ")");
                            }
                            /* A  _((B  _  C) _ D) */
                            hasil1 = charToOp(list_operator[countOp2], angkaKartu[1], angkaKartu[2]); //(B _ C)
                            hasil2 = charToOp(list_operator[countOp3], hasil1, angkaKartu[3]); //((B _ C) _ D)
                            hasil = charToOp(list_operator[countOp1], angkaKartu[0], hasil2); //A _ ((B _ C) _ D)
                            
                            if (hasil==24.0 && find(list_operation.begin(), list_operation.end(), std::to_string((int) angkaKartu[0]) + list_operator[countOp1] + "((" + std::to_string((int) angkaKartu[1]) + list_operator[countOp2] + std::to_string((int) angkaKartu[2]) + ")" + list_operator[countOp3] + std::to_string((int) angkaKartu[3]) + ")") == list_operation.end()){
                                //std::cout << "yes\n";
                                //cout << "hasil = " << hasil << " = " << std::to_string(angkaKartu[0]) + list_operator[countOp1] + "((" + std::to_string(angkaKartu[1]) + list_operator[countOp2] + std::to_string(angkaKartu[2]) + ")" + list_operator[countOp3] + std::to_string(angkaKartu[3]) + ")" << "\n";
                                list_operation.push_back(std::to_string((int) angkaKartu[0]) + list_operator[countOp1] + "((" + std::to_string((int) angkaKartu[1]) + list_operator[countOp2] + std::to_string((int) angkaKartu[2]) + ")" + list_operator[countOp3] + std::to_string((int) angkaKartu[3]) + ")");
                            }
                            /* A  _( B  _ (C  _ D)) */
                            hasil1 = charToOp(list_operator[countOp3], angkaKartu[2], angkaKartu[3]); //(C _ D)
                            hasil2 = charToOp(list_operator[countOp2], angkaKartu[1], hasil1); //(B _ (C _ D))
                            hasil = charToOp(list_operator[countOp1], angkaKartu[0], hasil2); //A _ (B _ (C _ D))
                            
                            if (hasil==24.0 && find(list_operation.begin(), list_operation.end(), std::to_string((int) angkaKartu[0]) + list_operator[countOp1] + "(" + std::to_string((int) angkaKartu[1]) + list_operator[countOp2] + "(" + std::to_string((int) angkaKartu[2]) + list_operator[countOp3] + std::to_string((int) angkaKartu[3]) + "))") == list_operation.end()){
                                //std::cout << "yes\n";
                                //cout << "hasil = " << hasil << " = " << std::to_string(angkaKartu[0]) + list_operator[countOp1] + "(" + std::to_string(angkaKartu[1]) + list_operator[countOp2] + "(" + std::to_string(angkaKartu[2]) + list_operator[countOp3] + std::to_string(angkaKartu[3]) + "))" << "\n";
                                list_operation.push_back(std::to_string((int) angkaKartu[0]) + list_operator[countOp1] + "(" + std::to_string((int) angkaKartu[1]) + list_operator[countOp2] + "(" + std::to_string((int) angkaKartu[2]) + list_operator[countOp3] + std::to_string((int) angkaKartu[3]) + "))");
                            }
                        }
                    }
                }
            }
        }
    }
}


int main(){
    /* KAMUS */
    std::string inputKartu=""; //string input 4 angka kartu yang nanti akan displit ke dalam array kartu
    vector<string> kartu; //array of string yang menyimpan input dari pengguna
    vector<float> angkaKartu; //array of int yang menyimpan angka / nilai kartu
    int count; //angka penghitung
    int inputType; //jenis input: input dari pengguna atau random
    bool isInputValid = false; //validasi input 4 kartu dari pengguna
    bool isInputTypeValid = false; //validasi input random atau dari pengguna
    char saveSolution; //apakah ingin menyimpan solusi (y/n)
    std::string filename; //nama file text untuk menyimpan solusi
    bool isFilenameValid = false; //validasi input nama file

    /* ALGORITMA */
    /* Output Title */
    /*
    std::cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWXOxONMMMMMMMMMMMMMMMMWd..kWNXk,.;xKMMMMMWX0kxxxk0NMMMMMNd..c0k;.:KMMMMMMMMMMMMMMMMMMMMMMMNxl0WMMMMMMMMMMMMMM\n";
    std::cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXOOkxolc::coxONMMMWd..kWO;,kKc. ;KMW0o;..     .'cONMXl..xN0OKl.;KMMMMMMMMMMMMMMMMMMMMMKxkXMMMMMMMMMMMMMMMM\n";
    std::cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWO;         'ckNO..xWN:  ,KX:  ;x:.             ,o: 'OWx..dK: :XMMMMWNNNNWMMMMMMMMWko0WMMMMMMMMMMMMMMMMM\n";
    std::cout << "MMMMMMMMMMMMMMMMMMMMMWKOxdddxO0NWMMMMMMMMMMMMMMMNd.          .. ;XMNc  ,KM0o'       ..''..       .xWX;  :N0'.dWKxl;'.'',cxXMMMMXdoKMMMMMMMMMMMMMMMX0NM\n";
    std::cout << "MMMMMMMMMMMMMMMMMMNkl,.       ..:xXMMMMMMMMMMMMMMWO:ckxoc'      dWMMKc,xWMWNo    .cx0Kkx00x:.    :XMX; .dWWl .:.          'xNMKodNMMMMMMMMMMMMMMNO:.;k\n";
    std::cout << "MMMMMMMMMMMMMMMMXx,               .dNMMMMMMMMMMMMMMXocd0XKd,    :kxoooodxxdd:.  .:ddo;..,ldx:    cKNNOcxNMMx.     .,;,'.   .d0lxWMMMMMMMMMMMMMMKdo:.'d\n";
    std::cout << "MMMMMMMMMMMMMMWO,                   :KMMMMMMMMMMMMMMNl..lodlllodxxxxxkOOOOOOOkkO0OOOOO0Oxxxxxooolldddxdoddx:    :kKWN0OOo.  .:OWMMMMMMMMMMMMMWOoxxc..k\n";
    std::cout << "MMMMMMMMMMMMMMO'                     ;KMMMMMMMMMMMMMMNocOK0Oxddllc:;::::::;;,'';::::::::llllodddxOO000K00OOkddlloooo:..ckk, .kWMMMMMMMMMMMMMXxdxxkl'.x\n";
    std::cout << "MMMMMMMMMMMMMWl                      .kMMMMMMMMMMMMMMMK:..                                         ...',;:loxxO0KXXKKOxdoo,.xWMMMMMMMMMMMMMWxoddxo,;:x\n";
    std::cout << "MMMMMMMMMMMMMWc                      .kMMMMMMMMMMMMMMMWd    ......',,,,,,,,,,,,,,,,,,,,'.....                  ..',:lodk0OldWMMMMMMMMMMMMMMWd:xxxdcco0\n";
    std::cout << "MMMMMMMMMMMMMWx.                     ,KMMMMMMMMMMMMMMMMk:dO0KXXXXXNWWWWWWWWWWWWWWWWWWWWWXXXX0Ok:':'.,.....              ..cXMMMMMMMMMMMMMMMWdcddd;;coX\n";
    std::cout << "MMMMMMMMMMMMMMNo.                   .kWMMMMMMMMMMMMMMMMOdNMNNWMMMMMMMMMMMMMMMMWNK0OxxxO0XWMMMMMXdOko0odxcx;;c,:''...     ;KMMMMMMMMMMMMMMMMMd;ddxcoodW\n";
    std::cout << "MMMMMMMMMMMMMMMWk,                 :0WMMMWMMMMMMMMMMMMMk;:lccccc:l0MMMMMMMMMXo;,,;;:cclooddkXMMMkd0oxOoOoxOckxxdodcl:c;.'dMMMMMMMMMMMMMMMMMWd,oko;xxkM\n";
    std::cout << "MMMMMMMMN0OkkO0XWNx'             .dXXOdl:;;clx0NMMMMMMMk,l0XX0kdoxXMMMMMMMMMNOxk0KXXNWMMWN0kkKWMKoOddKlxkdKlokoxldloooxlodKMMMMMMMMMMMMMMMMMo,ldd;oddW\n";
    std::cout << "MMMMMNkc'.     .;o0x.            .;;.         .;xNMMMMMk;lkO00000O000NMMMMMMMXocdxkO0K00KWMMMWMMXldxlKooOlOddKokoodlxcdloodWMMMMMMMMMMMMMMMMo.lxd:looX\n";
    std::cout << "MMMWk,            ..                             ;0MMMM0:colc:lllll::0MMMMMMMX;.,,':oooddoxNMMMMWdx0o0do0okxdKlxdcd:xldolxl0MMMMMMMMMMMMMMMMo'lkO:;dd0\n";
    std::cout << "MMNd.                                             ;KMMMXc';:..ccd0kl;kMMMMMMNd;';c:l:;oo:..oKWMMMkkKd0OxKxOxc0xxdcOcxdoxcxlxMMMMMMMMMMMMMMMMx:kkdd:odk\n";
    std::cout << "MMk.                                              .xMMMX:':cdxdok0OolXMMMMMMN0OxoxOxoxOk0kkXWMMMMkkKlOOxKxOxcOoxxokcxdokcxxkMMMMMMMMMMMMMMMMO:lO0d;lxo\n";
    std::cout << "MWo                                                dMMMX:lKKXNWWNXKkKMMMMMMMMMWKkO0OO0XWMMMMMMMMMkk0:xxoKxOxcOlddlkcxkdkckxkMMMMMMMMMMMMMMMMkck0d0k:dd\n";
    std::cout << "MWo                     .    ..                   .xMMMKcdMWKO00OOxkWMMMMMMMMMMN00OxxOXWMMMMMMMMMxx0lkolKxOxcOlddcOcxdokckxkMMMMMMMMMMMMMMMMOcokKOo;lO\n";
    std::cout << "MMk.                  .xXc   cXo                  ,KMMM0lOMMWXNWW0kXMMMMMWWNWMMMMMMMMMMMMMMMMMMMMxx0d0dl0okkxOlOxd0cxolOckxkMMMMMMMMMMMMMMMMk:kKxdKo,k\n";
    std::cout << "MMWd.                .xWNc   :XXc                .kWMMMdcKMMMMMMKOXMMMXkOXOokNMMMMMMMMMMMMMMMMMMMxk0oKolOckddk:Oxx0l0ddkckxkMMMMMMMMMMMMMMMMOlddO0xo,d\n";
    std::cout << "MMMNd.              .xNM0'   .OMNd.            .:0WMMMK:oWMMMMMM0x0XWMXOxdocdXMMMMMMMMMMMMMMMMMMNldxcKdoOd0ddk:OldOlKkkOo0xkMMMMMMMMMMMMMMMMO;l0kd0k:x\n";
    std::cout << "MMMMW0c.          'l0WMWo     lWMWKd,.      .'cONMMMMWl'OMMMMMMMWXOOkKWMWKO0XMMMMMMMMMMMMMMMMMMMNcdx:KxxOdKodkckloxcKkkOlOxkMMMMMMMMMMMMMMMMOoxdxKx.;k\n";
    std::cout << "MMMMMMWXkoc,,',:okXMMMM0'     .kMMMMWXOxxxkOKNMMMMMMWO':XMMMMMMXx:c0WNWKl:oxONMMMMMMMMMMMMMMMMMMNoxxcKxxOdKxxkckloOcOxd0lkooWMMMMMMMMMMMMMMMO;c0Ooc,od\n";
    std::cout << "MMMMMMMMMMMWWWWMMMMMMMNc       ,0MMMMMMMMMMMMMMMMMMMXdcxNMMMMNx,.;dXMMMXxc;,,:OWMMMMMMMMMMMMMMMMNldxc0dxOo0xx0oOdd0cxdc0dxxc0MMMMMMMMMMMMMMMOlkxlkoldl\n";
    std::cout << "MMMMMMMMMMMMMMMMMMMMMWd.        ,0MMMMMMMMMMMMMMMMMWkxocKMMM0lcdKN0doddoo0NWXxodONMMMMMMMMMMMMMMNcoxc0xx0ckkdKdkOo0oo0lkklOllXMMMMMMMMMMMMMMO;:xk:'lld\n";
    std::cout << "MMMMMMMMMMMMMMMMMMMMWk.          ;XMMMMMMMMMMMWKOOKKdkc.kWMMXKNX0o,'...,,:oxkxkKXWMMMMMMMMMMMMNKKodOl0xoKodOcxock:cc'l;,l:;;';lx0NMMMMMMMMMMOcxxo:cdoK\n";
    std::cout << "MMMMMMMMMMMMMMMMMMMMNx:::::::::::l0MMMMMMMMMMNxoxko;dd,;xNMMMMWXOk00kkkOKXK00OKWMMMMMMMMMMMMWXKdxxo0ld0cdl;c;',,,,,,::,;coddoolcddOWMMMMMMMMO:ckk;ldxW\n";
    std::cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMKlxKkdxkc;odOMMMMMMMMW0dxxx0WMWMMMMMMMMMMMMMMMNXxxkdkokdlXo,xOkOOkdoooxdkklxkokxd0dkOoKMMMMMMMMOcdko;odxM\n";
    std::cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMW0odxxdx0O0dxMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNOodldddxoOxolkKodkoOKdkdlKxkOl0dd0oOxxOdXMMMMMMMMO;:kx,ldoN\n";
    std::cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWKxdol::k0kOxkKKNNMMMMMMMMMMMMMMMMMMMMMMMMMWW0lloddo:'oxd0x,oOdd0xdXdkxlKdxOoOodxod,;dKMMMMMMMMMk;lddlcxlk\n";
    std::cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWOoOOxkO0d,lOxkdxxO00XXWNWMMMMMMMMMMMMMMMWNNXocd00OOO0d;okdkkxkOOkxkddklkOodcll;:,colc:lx0XWMMMMMO,:O0o,odl\n";
    std::cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMKcxKoxKdkk;xxxxdxdOxkxkk;dX0loXKkKNXWXXXkKkxXl:XKox0dxNo.;oxkkkkkkOxdo,,c,'.     ;0WNo.   .;lxKNWklkkd0o,xo\n";
    std::cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWKOdccc,oKxdOkolkxdkdkdxxdd;:.  ..  :l;ckxkkdKxd0od0O0KKNNooNx.  .;lloolc;.           :KMXl.        .';,'lO0dl:ld\n";
    std::cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWKOkko.  .xXx':xkkkxxl:lcl:',....:.          ':,ollOdxOoo0OxkOddK0;                       :KMXc              'OOlkKl,d\n";
    std::cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMWKklco;:Kx.  dMO'  .:o;..'o;;l'      :o.             ..':.;o;':xkkkdc.                       cXMXc               .ld0Ooc;d\n";
    std::cout << "MMMMMMMMMMMMMMMMMMMMMMMMWNKOx,  ,KkdXk.  oW0,..c0d.  dWxlkkddl'   :l.                                                   cXMNl                .dKxl00lO\n";
    std::cout << "MMMMMMMMMMMMMMMMMMMMMN0dcokKNl  .kKoOXc  .lOOkkxc.  ;KMN0OO00Oo.   :c.                                                 cXMNl                 :OodXK;:O\n";
    std::cout << "MMMMMMMMMMMMMMMMMWKxc'.   .';.   ;K0d0Kl.   ...   .oKXkollldkKXx.  .c:                                          .ld;  :XMNo.                 .:OXkc'od\n";
    std::cout << "MMMMMMMMMMMMMMWKx:,;;,...         'ddlxX0o,.....;d00c.       .:kx.  .l;  ...                                'ol..dOc.;KMNd.                  '00dkdlxc\n";
    std::cout << "MMMMMMMMMMMNOl,.   ....''''''..     ...'oOKK000XWWx.  .;oxxl'  .ol   ;d.,OXXo.                          .  .dWNc    ,0MWx.                   'oo0O:dol\n\n";
    std::cout << "======================================================================================================================================================\n\n";
    std::cout << "          $$$$$$   $$    $$         $$$$$$                                            $$$$$$             $$                                 \n";
    std::cout << "         $$  __$$  $$ |  $$ |      $$  __$$                                          $$  __$$            $$ |                               \n";
    std::cout << "          __/  $$ |$$ |  $$ |      $$ /   __| $$$$$$   $$$$$$ $$$$    $$$$$$         $$ /   __| $$$$$$   $$ |$$     $$   $$$$$$    $$$$$$   \n";
    std::cout << "          $$$$$$  |$$$$$$$$ |      $$ |$$$$    ____$$  $$  _$$  _$$  $$  __$$         $$$$$$   $$  __$$  $$ | $$   $$  |$$  __$$  $$  __$$  \n";
    std::cout << "         $$  ____/  _____$$ |      $$ | _$$ | $$$$$$$ |$$ / $$ / $$ |$$$$$$$$ |        ____$$  $$ /  $$ |$$ |  $$ $$  / $$$$$$$$ |$$ |   __|\n";
    std::cout << "         $$ |            $$ |      $$ |  $$ |$$  __$$ |$$ | $$ | $$ |$$   ____|      $$    $$ |$$ |  $$ |$$ |   $$$  /  $$   ____|$$ |      \n";
    std::cout << "         $$$$$$$$        $$ |       $$$$$$  | $$$$$$$ |$$ | $$ | $$ | $$$$$$$         $$$$$$  | $$$$$$  |$$ |    $  /    $$$$$$$  $$ |      \n";
    std::cout << "          ________|       __|        ______/   _______| __|  __|  __|  _______|        ______/   ______/  __|     _/      _______| __|      \n\n";
    std::cout << "                                                     by Arleen Chrysantha Gunardi (13521059)\n\n";
    std::cout << "======================================================================================================================================================\n\n";
    */
    /* INPUT */
    while (!isInputTypeValid){
        std::cout << "Silakan pilih jenis input!\n1. Input dari pengguna\n2. Input random\n";
        std::cin >> inputType;
        if (inputType==1){
            /* Input dari pengguna */
            isInputTypeValid = true;
            while (!isInputValid){
                /* Input 4 Kartu */
                std::cout << "\nSilakan masukkan 4 angka kartu [A,2,3,4,5,6,7,8,9,10,J,Q,K]!\n";

                for (count=0; count<=3; count++){
                    std::cin >> kartu[count];
                }

                //std::cin >> inputKartu;
                //cin.ignore();
                //getline (std::cin, inputKartu, '\n');

                //std::cout << inputKartu;
                /* Split string input */
                //kartu = splitString(inputKartu,' ');
                //kartu = split(inputKartu," ");

                //istringstream iss(inputKartu);
                /* Iterasi istringstream */
                /*
                count = 0;
                do {
                    string strAngka;
                    iss >> strAngka;
                    kartu[count] = strAngka;
                    count++;
                } while (iss);
                */
                
                
                for (count=0; count<=3; count++){
                    std::cin >> kartu[count];
                }
                
               //std::cout << inputKartu << "\n";
               //std::cout << kartu[0] << " " << kartu[1] << " "  << kartu[2] << " "  << kartu[3] << "\n";

                /* Ubah Input dari Bentuk String Menjadi Int */
                count = 0;
                while (count <=3 && charToInt(kartu[count]) > 0){
                    angkaKartu[count] = charToInt(kartu[count]);
                    //std::cout << angkaKartu[count] << "\n";
                    isInputValid = true;
                    count++;
                }
                /* Validasi Input */
                if (charToInt(kartu[count]) == -1){
                    std::cout << "Masukan tidak sesuai.\n\n";
                    isInputValid = false;
                }
            }
        } else if (inputType==2) {
            /* Input Random */
            isInputTypeValid = true;
            srand((unsigned) time(NULL));
            angkaKartu[0] = rand() % 13 + 1;
            angkaKartu[1] = rand() % 13 + 1;
            angkaKartu[2] = rand() % 13 + 1;
            angkaKartu[3] = rand() % 13 + 1;
            for (count=0; count<=3; count++){
                kartu[count] = intToChar(angkaKartu[count]);
            }
        } else {
            std::cout << "Masukan tidak sesuai.\n\n";
        }
    }

    /* Cetak 4 angka kartu */
    std::cout << "\nKartu: ";
    for (count=0; count<=3; count++){
        std::cout << kartu[count] << " ";
    }
    std::cout << "\nAngka: ";
    for (count=0; count<=3; count++){
        std::cout << angkaKartu[count] << " ";
    }
    std::cout << "\n";
    
    //for (int count=0; count<=3; count++){
    //    std::cout << angkaKartu[count] << "\n";
    //}

    //std::cout << charToOp('/',angkaKartu[2],angkaKartu[3]) << "\n";

    /* PROSES BRUTE FORCE */
    clock_t tStart = clock(); //hitung waktu eksekusi
    brute_force(angkaKartu);
    ln_operation = list_operation.size();

    /* OUTPUT */
    if (ln_operation==0){
        std::cout << "No solutions found\n";
    } else {
        std::cout << ln_operation << " solutions found\n";
        for (count=0; count<=ln_operation-1; count++){
            cout << list_operation[count] << "\n";
        }
    }
    std::cout << "Execution Time: " << (double)(clock() - tStart)/CLOCKS_PER_SEC * 1000 << " ms\n\n";

    /* Simpan hasilnya ke text file */
    std::cout << "Apakah Anda ingin menyimpan solusi? (y/n)\n";
    std::cin >> saveSolution;
    
    if (saveSolution=='y'){
        /* Simpan solusi */
        while (!isFilenameValid){
            std::cout << "Masukkan nama file untuk menyimpan solusi!\n";
            std::cin >> filename;
            ofstream outfile;
            outfile.open("../test/" + filename + ".txt", ios_base::out | ios_base::in);
            if (!outfile.is_open()){
                isFilenameValid = true;
                outfile.open("../test/" + filename + ".txt");
                outfile << "Kartu: " << kartu[0] << " " << kartu[1] << " " << kartu[2] << " " << kartu[3] << endl;
                if (ln_operation==0){
                    outfile << "No solutions found" << endl;
                } else {
                    outfile << ln_operation << " solutions found" << endl;
                    for (count=0; count<=ln_operation-1; count++){
                        outfile << list_operation[count] << endl;
                    }
                }
                std::cout << "File " << filename << ".txt berhasil tersimpan!\n";
            } else {
                std::cout << filename << ".txt sudah ada. Silakan masukkan kembali nama file yang berbeda!\n\n";
            }
            outfile.close();
        }
    }

    return 0;
}