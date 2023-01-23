# Tugas Kecil 1 IF2211 Strategi Algoritma: Penyelesaian Permainan Kartu 24 dengan Algoritma Brute Force

## Daftar Isi
- [Deskripsi Singkat](#deskripsi-singkat)
- [Sistematika File](#sistematika-file)
- [Tampilan Program](#tampilan-program)
- [Instruksi Menjalankan Program](#instruksi-menjalankan-program)
- [Credits](#credits)

## Deskripsi Singkat
```
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWXOxONMMMMMMMMMMMMMMMMWd..kWNXk,.;xKMMMMMWX0kxxxk0NMMMMMNd..c0k;.:KMMMMMMMMMMMMMMMMMMMMMMMNxl0WMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXOOkxolc::coxONMMMWd..kWO;,kKc. ;KMW0o;..     .'cONMXl..xN0OKl.;KMMMMMMMMMMMMMMMMMMMMMKxkXMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWO;         'ckNO..xWN:  ,KX:  ;x:.             ,o: 'OWx..dK: :XMMMMWNNNNWMMMMMMMMWko0WMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMWKOxdddxO0NWMMMMMMMMMMMMMMMNd.          .. ;XMNc  ,KM0o'       ..''..       .xWX;  :N0'.dWKxl;'.'',cxXMMMMXdoKMMMMMMMMMMMMMMMX0NM
MMMMMMMMMMMMMMMMMMNkl,.       ..:xXMMMMMMMMMMMMMMWO:ckxoc'      dWMMKc,xWMWNo    .cx0Kkx00x:.    :XMX; .dWWl .:.          'xNMKodNMMMMMMMMMMMMMMNO:.;k
MMMMMMMMMMMMMMMMXx,               .dNMMMMMMMMMMMMMMXocd0XKd,    :kxoooodxxdd:.  .:ddo;..,ldx:    cKNNOcxNMMx.     .,;,'.   .d0lxWMMMMMMMMMMMMMMKdo:.'d
MMMMMMMMMMMMMMWO,                   :KMMMMMMMMMMMMMMNl..lodlllodxxxxxkOOOOOOOkkO0OOOOO0Oxxxxxooolldddxdoddx:    :kKWN0OOo.  .:OWMMMMMMMMMMMMMWOoxxc..k
MMMMMMMMMMMMMMO'                     ;KMMMMMMMMMMMMMMNocOK0Oxddllc:;::::::;;,'';::::::::llllodddxOO000K00OOkddlloooo:..ckk, .kWMMMMMMMMMMMMMXxdxxkl'.x
MMMMMMMMMMMMMWl                      .kMMMMMMMMMMMMMMMK:..                                         ...',;:loxxO0KXXKKOxdoo,.xWMMMMMMMMMMMMMWxoddxo,;:x
MMMMMMMMMMMMMWc                      .kMMMMMMMMMMMMMMMWd    ......',,,,,,,,,,,,,,,,,,,,'.....                  ..',:lodk0OldWMMMMMMMMMMMMMMWd:xxxdcco0
MMMMMMMMMMMMMWx.                     ,KMMMMMMMMMMMMMMMMk:dO0KXXXXXNWWWWWWWWWWWWWWWWWWWWWXXXX0Ok:':'.,.....              ..cXMMMMMMMMMMMMMMMWdcddd;;coX
MMMMMMMMMMMMMMNo.                   .kWMMMMMMMMMMMMMMMMOdNMNNWMMMMMMMMMMMMMMMMWNK0OxxxO0XWMMMMMXdOko0odxcx;;c,:''...     ;KMMMMMMMMMMMMMMMMMd;ddxcoodW
MMMMMMMMMMMMMMMWk,                 :0WMMMWMMMMMMMMMMMMMk;:lccccc:l0MMMMMMMMMXo;,,;;:cclooddkXMMMkd0oxOoOoxOckxxdodcl:c;.'dMMMMMMMMMMMMMMMMMWd,oko;xxkM
MMMMMMMMN0OkkO0XWNx'             .dXXOdl:;;clx0NMMMMMMMk,l0XX0kdoxXMMMMMMMMMNOxk0KXXNWMMWN0kkKWMKoOddKlxkdKlokoxldloooxlodKMMMMMMMMMMMMMMMMMo,ldd;oddW
MMMMMNkc'.     .;o0x.            .;;.         .;xNMMMMMk;lkO00000O000NMMMMMMMXocdxkO0K00KWMMMWMMXldxlKooOlOddKokoodlxcdloodWMMMMMMMMMMMMMMMMo.lxd:looX
MMMWk,            ..                             ;0MMMM0:colc:lllll::0MMMMMMMX;.,,':oooddoxNMMMMWdx0o0do0okxdKlxdcd:xldolxl0MMMMMMMMMMMMMMMMo'lkO:;dd0
MMNd.                                             ;KMMMXc';:..ccd0kl;kMMMMMMNd;';c:l:;oo:..oKWMMMkkKd0OxKxOxc0xxdcOcxdoxcxlxMMMMMMMMMMMMMMMMx:kkdd:odk
MMk.                                              .xMMMX:':cdxdok0OolXMMMMMMN0OxoxOxoxOk0kkXWMMMMkkKlOOxKxOxcOoxxokcxdokcxxkMMMMMMMMMMMMMMMMO:lO0d;lxo
MWo                                                dMMMX:lKKXNWWNXKkKMMMMMMMMMWKkO0OO0XWMMMMMMMMMkk0:xxoKxOxcOlddlkcxkdkckxkMMMMMMMMMMMMMMMMkck0d0k:dd
MWo                     .    ..                   .xMMMKcdMWKO00OOxkWMMMMMMMMMMN00OxxOXWMMMMMMMMMxx0lkolKxOxcOlddcOcxdokckxkMMMMMMMMMMMMMMMMOcokKOo;lO
MMk.                  .xXc   cXo                  ,KMMM0lOMMWXNWW0kXMMMMMWWNWMMMMMMMMMMMMMMMMMMMMxx0d0dl0okkxOlOxd0cxolOckxkMMMMMMMMMMMMMMMMk:kKxdKo,k
MMWd.                .xWNc   :XXc                .kWMMMdcKMMMMMMKOXMMMXkOXOokNMMMMMMMMMMMMMMMMMMMxk0oKolOckddk:Oxx0l0ddkckxkMMMMMMMMMMMMMMMMOlddO0xo,d
MMMNd.              .xNM0'   .OMNd.            .:0WMMMK:oWMMMMMM0x0XWMXOxdocdXMMMMMMMMMMMMMMMMMMNldxcKdoOd0ddk:OldOlKkkOo0xkMMMMMMMMMMMMMMMMO;l0kd0k:x
MMMMW0c.          'l0WMWo     lWMWKd,.      .'cONMMMMWl'OMMMMMMMWXOOkKWMWKO0XMMMMMMMMMMMMMMMMMMMNcdx:KxxOdKodkckloxcKkkOlOxkMMMMMMMMMMMMMMMMOoxdxKx.;k
MMMMMMWXkoc,,',:okXMMMM0'     .kMMMMWXOxxxkOKNMMMMMMWO':XMMMMMMXx:c0WNWKl:oxONMMMMMMMMMMMMMMMMMMNoxxcKxxOdKxxkckloOcOxd0lkooWMMMMMMMMMMMMMMMO;c0Ooc,od
MMMMMMMMMMMWWWWMMMMMMMNc       ,0MMMMMMMMMMMMMMMMMMMXdcxNMMMMNx,.;dXMMMXxc;,,:OWMMMMMMMMMMMMMMMMNldxc0dxOo0xx0oOdd0cxdc0dxxc0MMMMMMMMMMMMMMMOlkxlkoldl
MMMMMMMMMMMMMMMMMMMMMWd.        ,0MMMMMMMMMMMMMMMMMWkxocKMMM0lcdKN0doddoo0NWXxodONMMMMMMMMMMMMMMNcoxc0xx0ckkdKdkOo0oo0lkklOllXMMMMMMMMMMMMMMO;:xk:'lld
MMMMMMMMMMMMMMMMMMMMWk.          ;XMMMMMMMMMMMWKOOKKdkc.kWMMXKNX0o,'...,,:oxkxkKXWMMMMMMMMMMMMNKKodOl0xoKodOcxock:cc'l;,l:;;';lx0NMMMMMMMMMMOcxxo:cdoK
MMMMMMMMMMMMMMMMMMMMNx:::::::::::l0MMMMMMMMMMNxoxko;dd,;xNMMMMWXOk00kkkOKXK00OKWMMMMMMMMMMMMWXKdxxo0ld0cdl;c;',,,,,,::,;coddoolcddOWMMMMMMMMO:ckk;ldxW
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMKlxKkdxkc;odOMMMMMMMMW0dxxx0WMWMMMMMMMMMMMMMMMNXxxkdkokdlXo,xOkOOkdoooxdkklxkokxd0dkOoKMMMMMMMMOcdko;odxM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMW0odxxdx0O0dxMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNOodldddxoOxolkKodkoOKdkdlKxkOl0dd0oOxxOdXMMMMMMMMO;:kx,ldoN
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWKxdol::k0kOxkKKNNMMMMMMMMMMMMMMMMMMMMMMMMMWW0lloddo:'oxd0x,oOdd0xdXdkxlKdxOoOodxod,;dKMMMMMMMMMk;lddlcxlk
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWOoOOxkO0d,lOxkdxxO00XXWNWMMMMMMMMMMMMMMMWNNXocd00OOO0d;okdkkxkOOkxkddklkOodcll;:,colc:lx0XWMMMMMO,:O0o,odl
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMKcxKoxKdkk;xxxxdxdOxkxkk;dX0loXKkKNXWXXXkKkxXl:XKox0dxNo.;oxkkkkkkOxdo,,c,'.     ;0WNo.   .;lxKNWklkkd0o,xo
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWKOdccc,oKxdOkolkxdkdkdxxdd;:.  ..  :l;ckxkkdKxd0od0O0KKNNooNx.  .;lloolc;.           :KMXl.        .';,'lO0dl:ld
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWKOkko.  .xXx':xkkkxxl:lcl:',....:.          ':,ollOdxOoo0OxkOddK0;                       :KMXc              'OOlkKl,d
MMMMMMMMMMMMMMMMMMMMMMMMMMMMWKklco;:Kx.  dMO'  .:o;..'o;;l'      :o.             ..':.;o;':xkkkdc.                       cXMXc               .ld0Ooc;d
MMMMMMMMMMMMMMMMMMMMMMMMWNKOx,  ,KkdXk.  oW0,..c0d.  dWxlkkddl'   :l.                                                   cXMNl                .dKxl00lO
MMMMMMMMMMMMMMMMMMMMMN0dcokKNl  .kKoOXc  .lOOkkxc.  ;KMN0OO00Oo.   :c.                                                 cXMNl                 :OodXK;:O
MMMMMMMMMMMMMMMMMWKxc'.   .';.   ;K0d0Kl.   ...   .oKXkollldkKXx.  .c:                                          .ld;  :XMNo.                 .:OXkc'od
MMMMMMMMMMMMMMWKx:,;;,...         'ddlxX0o,.....;d00c.       .:kx.  .l;  ...                                'ol..dOc.;KMNd.                  '00dkdlxc
MMMMMMMMMMMNOl,.   ....''''''..     ...'oOKK000XWWx.  .;oxxl'  .ol   ;d.,OXXo.                          .  .dWNc    ,0MWx.                   'oo0O:dol

======================================================================================================================================================

          $$$$$$   $$    $$         $$$$$$                                            $$$$$$             $$
         $$  __$$  $$ |  $$ |      $$  __$$                                          $$  __$$            $$ |
          __/  $$ |$$ |  $$ |      $$ /   __| $$$$$$   $$$$$$ $$$$    $$$$$$         $$ /   __| $$$$$$   $$ |$$     $$   $$$$$$    $$$$$$
          $$$$$$  |$$$$$$$$ |      $$ |$$$$    ____$$  $$  _$$  _$$  $$  __$$         $$$$$$   $$  __$$  $$ | $$   $$  |$$  __$$  $$  __$$
         $$  ____/  _____$$ |      $$ | _$$ | $$$$$$$ |$$ / $$ / $$ |$$$$$$$$ |        ____$$  $$ /  $$ |$$ |  $$ $$  / $$$$$$$$ |$$ |   __|
         $$ |            $$ |      $$ |  $$ |$$  __$$ |$$ | $$ | $$ |$$   ____|      $$    $$ |$$ |  $$ |$$ |   $$$  /  $$   ____|$$ |
         $$$$$$$$        $$ |       $$$$$$  | $$$$$$$ |$$ | $$ | $$ | $$$$$$$         $$$$$$  | $$$$$$  |$$ |    $  /    $$$$$$$  $$ |
          ________|       __|        ______/   _______| __|  __|  __|  _______|        ______/   ______/  __|     _/      _______| __|

                                                         by Arleen Chrysantha Gunardi (13521059)

======================================================================================================================================================
```
Permainan Kartu 24 merupakan salah satu permainan yang memanfaatkan nilai-nilai angka pada kartu. Permainan ini dilakukan dengan cara melakukan operasi aritmetika (pertambahan, pengurangan, perkalian, dan pembagian) terhadap empat buah angka kartu yang diambil secara acak dari dek. Operasi aritmetika tersebut dilakukan sedemikian rupa sehingga hasilnya adalah 24. Kartu A direpresentasikan sebagai angka satu (1), kartu J sebagai angka sebelas (11), kartu Q sebagai angka dua belas (12), kartu K sebagai angka tiga belas (13), dan kartu angka sesuai dengan nilai angkanya. Setiap kartu hanya boleh dioperasikan satu kali (tidak boleh dioperasikan secara berulang). Untuk membantu menyelesaikan permainan ini, dibuatlah sebuah program "24 Game Solver" yang menampilkan semua kemungkinan solusi operasi aritmetika dari empat buah angka yang dapat menghasilkan 24.

## Sistematika File
```
Tucil1_13521059
├─── bin
|   └─── kartu24.out
├─── doc
|   └─── Tucil1_13521059.pdf
├─── src
|   └─── kartu24.cpp
├─── test
│   ├─── t1.txt
│   ├─── t2.txt
│   ├─── t3.txt
│   ├─── t4.txt
│   ├─── t5.txt
|   └─── t6.txt
└─── README.md
```

## Tampilan Program
### Tampilan Awal
![My Remote Image](https://drive.google.com/file/d/1B98cofMRYCHL-FQBB7Pq4Vyv44fk2gQn/view?usp=sharing)

### Input Angka Kartu dari Pengguna


### Input Angka Kartu Acak


## Instruksi Menjalankan Program
- Clone repository ini.
- Buka terminal pada folder bin.
- Jalankan program secara langsung dengan command ./kartu24.out pada terminal.

## Credits
Dibuat oleh Arleen Chrysantha Gunardi (NIM. 13521059).
