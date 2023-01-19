#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

int charToInt (string s){
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

void brute_force(int angkaKartu[4]){
    /* KAMUS LOKAL */
    int counter1,counter2,counter3,temp;
    /* Permutasi 4 Kartu */
    for (counter1=0; counter1<=3; counter1++){
        /* Swap angkaKartu[0] dengan elemen indeks 0,1,2,3 */
        temp = angkaKartu[0];
        angkaKartu[0] = angkaKartu[counter1];
        angkaKartu[counter1] = temp;

        for (counter2=1; counter2<=3; counter2++){
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
                
            }
        }
    }
}


int main(){
    /* KAMUS */
    std::string kartu[4]; //array of string yang menyimpan input dari pengguna
    int angkaKartu[4]; //array of int yang menyimpan angka / nilai kartu
    int count; //angka penghitung
    int inputType; //jenis input: input dari pengguna atau random
    bool isInputValid = false; //validasi input

    /* ALGORITMA */
    /* Output Title */
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWXOxONMMMMMMMMMMMMMMMMWd..kWNXk,.;xKMMMMMWX0kxxxk0NMMMMMNd..c0k;.:KMMMMMMMMMMMMMMMMMMMMMMMNxl0WMMMMMMMMMMMMMM\n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXOOkxolc::coxONMMMWd..kWO;,kKc. ;KMW0o;..     .'cONMXl..xN0OKl.;KMMMMMMMMMMMMMMMMMMMMMKxkXMMMMMMMMMMMMMMMM\n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWO;         'ckNO..xWN:  ,KX:  ;x:.             ,o: 'OWx..dK: :XMMMMWNNNNWMMMMMMMMWko0WMMMMMMMMMMMMMMMMM\n";
    cout << "MMMMMMMMMMMMMMMMMMMMMWKOxdddxO0NWMMMMMMMMMMMMMMMNd.          .. ;XMNc  ,KM0o'       ..''..       .xWX;  :N0'.dWKxl;'.'',cxXMMMMXdoKMMMMMMMMMMMMMMMX0NM\n";
    cout << "MMMMMMMMMMMMMMMMMMNkl,.       ..:xXMMMMMMMMMMMMMMWO:ckxoc'      dWMMKc,xWMWNo    .cx0Kkx00x:.    :XMX; .dWWl .:.          'xNMKodNMMMMMMMMMMMMMMNO:.;k\n";
    cout << "MMMMMMMMMMMMMMMMXx,               .dNMMMMMMMMMMMMMMXocd0XKd,    :kxoooodxxdd:.  .:ddo;..,ldx:    cKNNOcxNMMx.     .,;,'.   .d0lxWMMMMMMMMMMMMMMKdo:.'d\n";
    cout << "MMMMMMMMMMMMMMWO,                   :KMMMMMMMMMMMMMMNl..lodlllodxxxxxkOOOOOOOkkO0OOOOO0Oxxxxxooolldddxdoddx:    :kKWN0OOo.  .:OWMMMMMMMMMMMMMWOoxxc..k\n";
    cout << "MMMMMMMMMMMMMMO'                     ;KMMMMMMMMMMMMMMNocOK0Oxddllc:;::::::;;,'';::::::::llllodddxOO000K00OOkddlloooo:..ckk, .kWMMMMMMMMMMMMMXxdxxkl'.x\n";
    cout << "MMMMMMMMMMMMMWl                      .kMMMMMMMMMMMMMMMK:..                                         ...',;:loxxO0KXXKKOxdoo,.xWMMMMMMMMMMMMMWxoddxo,;:x\n";
    cout << "MMMMMMMMMMMMMWc                      .kMMMMMMMMMMMMMMMWd    ......',,,,,,,,,,,,,,,,,,,,'.....                  ..',:lodk0OldWMMMMMMMMMMMMMMWd:xxxdcco0\n";
    cout << "MMMMMMMMMMMMMWx.                     ,KMMMMMMMMMMMMMMMMk:dO0KXXXXXNWWWWWWWWWWWWWWWWWWWWWXXXX0Ok:':'.,.....              ..cXMMMMMMMMMMMMMMMWdcddd;;coX\n";
    cout << "MMMMMMMMMMMMMMNo.                   .kWMMMMMMMMMMMMMMMMOdNMNNWMMMMMMMMMMMMMMMMWNK0OxxxO0XWMMMMMXdOko0odxcx;;c,:''...     ;KMMMMMMMMMMMMMMMMMd;ddxcoodW\n";
    cout << "MMMMMMMMMMMMMMMWk,                 :0WMMMWMMMMMMMMMMMMMk;:lccccc:l0MMMMMMMMMXo;,,;;:cclooddkXMMMkd0oxOoOoxOckxxdodcl:c;.'dMMMMMMMMMMMMMMMMMWd,oko;xxkM\n";
    cout << "MMMMMMMMN0OkkO0XWNx'             .dXXOdl:;;clx0NMMMMMMMk,l0XX0kdoxXMMMMMMMMMNOxk0KXXNWMMWN0kkKWMKoOddKlxkdKlokoxldloooxlodKMMMMMMMMMMMMMMMMMo,ldd;oddW\n";
    cout << "MMMMMNkc'.     .;o0x.            .;;.         .;xNMMMMMk;lkO00000O000NMMMMMMMXocdxkO0K00KWMMMWMMXldxlKooOlOddKokoodlxcdloodWMMMMMMMMMMMMMMMMo.lxd:looX\n";
    cout << "MMMWk,            ..                             ;0MMMM0:colc:lllll::0MMMMMMMX;.,,':oooddoxNMMMMWdx0o0do0okxdKlxdcd:xldolxl0MMMMMMMMMMMMMMMMo'lkO:;dd0\n";
    cout << "MMNd.                                             ;KMMMXc';:..ccd0kl;kMMMMMMNd;';c:l:;oo:..oKWMMMkkKd0OxKxOxc0xxdcOcxdoxcxlxMMMMMMMMMMMMMMMMx:kkdd:odk\n";
    cout << "MMk.                                              .xMMMX:':cdxdok0OolXMMMMMMN0OxoxOxoxOk0kkXWMMMMkkKlOOxKxOxcOoxxokcxdokcxxkMMMMMMMMMMMMMMMMO:lO0d;lxo\n";
    cout << "MWo                                                dMMMX:lKKXNWWNXKkKMMMMMMMMMWKkO0OO0XWMMMMMMMMMkk0:xxoKxOxcOlddlkcxkdkckxkMMMMMMMMMMMMMMMMkck0d0k:dd\n";
    cout << "MWo                     .    ..                   .xMMMKcdMWKO00OOxkWMMMMMMMMMMN00OxxOXWMMMMMMMMMxx0lkolKxOxcOlddcOcxdokckxkMMMMMMMMMMMMMMMMOcokKOo;lO\n";
    cout << "MMk.                  .xXc   cXo                  ,KMMM0lOMMWXNWW0kXMMMMMWWNWMMMMMMMMMMMMMMMMMMMMxx0d0dl0okkxOlOxd0cxolOckxkMMMMMMMMMMMMMMMMk:kKxdKo,k\n";
    cout << "MMWd.                .xWNc   :XXc                .kWMMMdcKMMMMMMKOXMMMXkOXOokNMMMMMMMMMMMMMMMMMMMxk0oKolOckddk:Oxx0l0ddkckxkMMMMMMMMMMMMMMMMOlddO0xo,d\n";
    cout << "MMMNd.              .xNM0'   .OMNd.            .:0WMMMK:oWMMMMMM0x0XWMXOxdocdXMMMMMMMMMMMMMMMMMMNldxcKdoOd0ddk:OldOlKkkOo0xkMMMMMMMMMMMMMMMMO;l0kd0k:x\n";
    cout << "MMMMW0c.          'l0WMWo     lWMWKd,.      .'cONMMMMWl'OMMMMMMMWXOOkKWMWKO0XMMMMMMMMMMMMMMMMMMMNcdx:KxxOdKodkckloxcKkkOlOxkMMMMMMMMMMMMMMMMOoxdxKx.;k\n";
    cout << "MMMMMMWXkoc,,',:okXMMMM0'     .kMMMMWXOxxxkOKNMMMMMMWO':XMMMMMMXx:c0WNWKl:oxONMMMMMMMMMMMMMMMMMMNoxxcKxxOdKxxkckloOcOxd0lkooWMMMMMMMMMMMMMMMO;c0Ooc,od\n";
    cout << "MMMMMMMMMMMWWWWMMMMMMMNc       ,0MMMMMMMMMMMMMMMMMMMXdcxNMMMMNx,.;dXMMMXxc;,,:OWMMMMMMMMMMMMMMMMNldxc0dxOo0xx0oOdd0cxdc0dxxc0MMMMMMMMMMMMMMMOlkxlkoldl\n";
    cout << "MMMMMMMMMMMMMMMMMMMMMWd.        ,0MMMMMMMMMMMMMMMMMWkxocKMMM0lcdKN0doddoo0NWXxodONMMMMMMMMMMMMMMNcoxc0xx0ckkdKdkOo0oo0lkklOllXMMMMMMMMMMMMMMO;:xk:'lld\n";
    cout << "MMMMMMMMMMMMMMMMMMMMWk.          ;XMMMMMMMMMMMWKOOKKdkc.kWMMXKNX0o,'...,,:oxkxkKXWMMMMMMMMMMMMNKKodOl0xoKodOcxock:cc'l;,l:;;';lx0NMMMMMMMMMMOcxxo:cdoK\n";
    cout << "MMMMMMMMMMMMMMMMMMMMNx:::::::::::l0MMMMMMMMMMNxoxko;dd,;xNMMMMWXOk00kkkOKXK00OKWMMMMMMMMMMMMWXKdxxo0ld0cdl;c;',,,,,,::,;coddoolcddOWMMMMMMMMO:ckk;ldxW\n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMKlxKkdxkc;odOMMMMMMMMW0dxxx0WMWMMMMMMMMMMMMMMMNXxxkdkokdlXo,xOkOOkdoooxdkklxkokxd0dkOoKMMMMMMMMOcdko;odxM\n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMW0odxxdx0O0dxMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNOodldddxoOxolkKodkoOKdkdlKxkOl0dd0oOxxOdXMMMMMMMMO;:kx,ldoN\n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWKxdol::k0kOxkKKNNMMMMMMMMMMMMMMMMMMMMMMMMMWW0lloddo:'oxd0x,oOdd0xdXdkxlKdxOoOodxod,;dKMMMMMMMMMk;lddlcxlk\n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWOoOOxkO0d,lOxkdxxO00XXWNWMMMMMMMMMMMMMMMWNNXocd00OOO0d;okdkkxkOOkxkddklkOodcll;:,colc:lx0XWMMMMMO,:O0o,odl\n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMKcxKoxKdkk;xxxxdxdOxkxkk;dX0loXKkKNXWXXXkKkxXl:XKox0dxNo.;oxkkkkkkOxdo,,c,'.     ;0WNo.   .;lxKNWklkkd0o,xo\n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWKOdccc,oKxdOkolkxdkdkdxxdd;:.  ..  :l;ckxkkdKxd0od0O0KKNNooNx.  .;lloolc;.           :KMXl.        .';,'lO0dl:ld\n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWKOkko.  .xXx':xkkkxxl:lcl:',....:.          ':,ollOdxOoo0OxkOddK0;                       :KMXc              'OOlkKl,d\n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMWKklco;:Kx.  dMO'  .:o;..'o;;l'      :o.             ..':.;o;':xkkkdc.                       cXMXc               .ld0Ooc;d\n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMWNKOx,  ,KkdXk.  oW0,..c0d.  dWxlkkddl'   :l.                                                   cXMNl                .dKxl00lO\n";
    cout << "MMMMMMMMMMMMMMMMMMMMMN0dcokKNl  .kKoOXc  .lOOkkxc.  ;KMN0OO00Oo.   :c.                                                 cXMNl                 :OodXK;:O\n";
    cout << "MMMMMMMMMMMMMMMMMWKxc'.   .';.   ;K0d0Kl.   ...   .oKXkollldkKXx.  .c:                                          .ld;  :XMNo.                 .:OXkc'od\n";
    cout << "MMMMMMMMMMMMMMWKx:,;;,...         'ddlxX0o,.....;d00c.       .:kx.  .l;  ...                                'ol..dOc.;KMNd.                  '00dkdlxc\n";
    cout << "MMMMMMMMMMMNOl,.   ....''''''..     ...'oOKK000XWWx.  .;oxxl'  .ol   ;d.,OXXo.                          .  .dWNc    ,0MWx.                   'oo0O:dol\n\n";
    cout << "======================================================================================================================================================\n\n";
    cout << "          $$$$$$   $$    $$         $$$$$$                                            $$$$$$             $$                                 \n";
    cout << "         $$  __$$  $$ |  $$ |      $$  __$$                                          $$  __$$            $$ |                               \n";
    cout << "          __/  $$ |$$ |  $$ |      $$ /   __| $$$$$$   $$$$$$ $$$$    $$$$$$         $$ /   __| $$$$$$   $$ |$$     $$   $$$$$$    $$$$$$   \n";
    cout << "          $$$$$$  |$$$$$$$$ |      $$ |$$$$    ____$$  $$  _$$  _$$  $$  __$$         $$$$$$   $$  __$$  $$ | $$   $$  |$$  __$$  $$  __$$  \n";
    cout << "         $$  ____/  _____$$ |      $$ | _$$ | $$$$$$$ |$$ / $$ / $$ |$$$$$$$$ |        ____$$  $$ /  $$ |$$ |  $$ $$  / $$$$$$$$ |$$ |   __|\n";
    cout << "         $$ |            $$ |      $$ |  $$ |$$  __$$ |$$ | $$ | $$ |$$   ____|      $$    $$ |$$ |  $$ |$$ |   $$$  /  $$   ____|$$ |      \n";
    cout << "         $$$$$$$$        $$ |       $$$$$$  | $$$$$$$ |$$ | $$ | $$ | $$$$$$$         $$$$$$  | $$$$$$  |$$ |    $  /    $$$$$$$  $$ |      \n";
    cout << "          ________|       __|        ______/   _______| __|  __|  __|  _______|        ______/   ______/  __|     _/      _______| __|      \n\n";
    cout << "                                                     by Arleen Chrysantha Gunardi (13521059)\n\n";
    cout << "======================================================================================================================================================\n\n";

    /* INPUT */
    cout << "Silakan pilih jenis input!\n1. Input dari pengguna\n2. Input random\n";
    cin >> inputType;
    cout << "\n";

    if (inputType==1){
        /* Input dari pengguna */
        while (!isInputValid){
            /* Input 4 Kartu */
            cout << "Silakan masukkan 4 angka kartu [A,2,3,4,5,6,7,8,9,10,J,Q,K]!\n";
            for (count=0; count<=3; count++){
                std::cin >> kartu[count];
            }
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
                cout << "Masukan tidak sesuai.\n\n";
                isInputValid = false;
            }
        }
    } else{
        /* Input Random */
        angkaKartu[0] = rand() % 13 + 1;
        angkaKartu[1] = rand() % 13 + 1;
        angkaKartu[2] = rand() % 13 + 1;
        angkaKartu[3] = rand() % 13 + 1;
        for (count=0; count<=3; count++){
            kartu[count] = intToChar(angkaKartu[count]);
        }
    }
    /* Cetak 4 angka kartu */
    cout << "\nKartu: ";
    for (count=0; count<=3; count++){
        cout << kartu[count] << " ";
    }
    cout << "\nAngka: ";
    for (count=0; count<=3; count++){
        cout << angkaKartu[count] << " ";
    }
    
    //for (int count=0; count<=3; count++){
    //    std::cout << angkaKartu[count] << "\n";
    //}

    /* PROSES BRUTE FORCE */
    //brute_force(angkaKartu);

    return 0;
}