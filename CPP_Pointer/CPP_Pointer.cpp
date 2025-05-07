//ポインタと参照の参照のサンプル
#include <conio.h>
#include <iostream>
#include <vector>

#define ESCBLK "\033[30m"
#define ESCRED "\033[31m"
#define ESCGRN "\033[32m"
#define ESCYRW "\033[33m"
#define ESCBLU "\033[34m"
#define ESCMGN "\033[35m"
#define ESCCYN "\033[36m"
#define ESCWHT "\033[37m"
#define ESCDEF "\033[0m"

//ポインタが難しいというより、'&' や '*' の使い方に混乱があるので難しく感じます。
//Cの開発当時、使える記号の数が限られていたので、'&' や '*' が複数の意味を持つようになっています。
//演算子(それも複数の意味)だったり、参照だったり、ポインタだったりします。
//これらの記号は使われる場所によって意味が変わるので、よく注意しましょう。

// '*' の使い方
//  宣言時（型の一部として）: ポインタ型を宣言します。
// int* p;  // p は int 型のポインタ
// 式中の単項演算子として: ポインタの指す先の値にアクセス（デリファレンス）します。
// *p = 10;  // p が指す場所に 10 を書き込む
// int a = *p;  // a に p が指す場所にある値を書き込む
// 二項演算子として: 乗算を行います。
//     int c = a * b;  // a と b を掛け算

// '&' の使い方
// 宣言時（型の一部として）: 参照型を宣言します。
// int& r = x;  // r は x の参照（エイリアス）
// 式中の単項演算子として: 変数のアドレスを取得します。
// int* p = &x;  // x のアドレスを p に代入
// 二項演算子として: ビット単位の AND 演算を行います。
// int d = x & y;  // x と y のビット毎の AND

//実行のたびにアドレスが変わるのを確認してください。
//パソコンのメモリの空き具合などで毎回同じアドレスにはならないです。

//デバッグモードでビルドしてください
//デバッガでF10で1行ずつ確認してください
//ウォッチウィンドウで変数やポインタの値を確認してください

int main()
{
    int VALUE_X;
    int VALUE_Y;
    int* PT; 
    // ここでは「 * 」はポインタ型の変数を宣言するための記号です。

    VALUE_X = 4410;
    PT = &VALUE_X; 
   
    std::cout<< "PT = &VALUE_X; // ポインタ変数PTにVALUE_Xのアドレスを代入" << std::endl;
    std::cout << ESCGRN;

    //これは普通の「値」
    std::cout << "VALUE_Xの値           : " << VALUE_X << std::endl;

    //ポインタのアドレスになります。
    std::cout << "PTの値(アドレス)      : " << PT << std::endl;

    //この「 * 」は ポインタの差すメモリの「値」を出すための間接参照演算子としての使い方になります。
    VALUE_Y = *PT; 
    std::cout << "PTの差すメモリにある値: " << VALUE_Y << std::endl;

    std::cout << "ポインタを使った代入操作" << std::endl;
    //ここでも「 * 」は ポインタの差すメモリの「値」を出すための間接参照演算子としての使い方になります。
    *PT = 196809;

    //ポインタの差すメモリの「値」になります。
    std::cout << "PTの差すメモリにある値: " << *PT << std::endl;
    //これは普通の整数の「値」ポインタの差すメモリに代入されたので値が変わっているはず。
    std::cout << "VALUE_Xの値           : " << VALUE_X << std::endl;
    std::cout << ESCDEF << std::endl;

    std::cout << "整数VALUE_Aの値と、そのアドレス" << std::endl;
    int VALUE_A = 196809;
    std::cout << ESCGRN;
    std::cout << "VALUE_Aの値       : " << VALUE_A << std::endl;
    std::cout << "VALUE_Aのアドレス: " << &VALUE_A << std::endl;
    std::cout << ESCDEF << std::endl;

    std::cout << "整数VALUE_Aのアドレスを 整数に代入して観察" << std::endl;
    std::cout << "ADDRESS_OF_Aの「値」と「VALUE_Aのアドレス」が同じかどうか確認してください。" << std::endl;

    int64_t ADDRESS_OF_A = (int64_t)&VALUE_A; // ポインタ変数pにaのアドレスを代入 64bit環境ではアドレスは64bitなので、int64_tを使う
    std::cout << ESCGRN << std::endl;
    std::cout << "ADDRESS_OF_Aの値(10進数表示): " << std::dec << ADDRESS_OF_A << std::endl;
    std::cout << "ADDRESS_OF_Aの値(16進数表示): " << std::hex << ADDRESS_OF_A << std::endl;
    std::cout << ESCDEF << std::endl;

    std::cout << "【解説】" << std::endl;
    std::cout << "「 & 」を付けると、ポインタのアドレスが返される。" << std::endl;
    std::cout << std::endl;

    std::cout << "整数のADDRESS_OF_Aの差すメモリにある値" << std::endl;
    std::cout << ESCGRN;
    std::cout << "ADDRESS_OF_Aの差すメモリにある値: " << std::dec << *((int*)ADDRESS_OF_A) << std::endl;
    std::cout << ESCDEF;

    std::cout << "【解説】" << std::endl;
    std::cout << "ADDRESS_OF_Aの「値」をポインタ型に変換。" << std::endl;
    std::cout << "さらに、間接参照演算子を使って、ポインタの指す先の値を取得して表示" << std::endl;
    std::cout << std::endl;

    std::cout << "整数のADDRESS_OF_Aの差すメモリの隣にある値（何が出るかなドキドキ）" << std::endl;
    std::cout << ESCGRN << std::endl;
    std::cout << "ADDRESS_OF_Aの差すメモリの隣にある値: " << std::dec << *((int*)ADDRESS_OF_A + 1) << std::endl;
    std::cout << ESCDEF;
    std::cout << "【解説】\n";
    std::cout << "ADDRESS_OF_Aの「値」にプラス1してから、ポインタ型に変換。\n";
    std::cout << "さらに、間接参照演算子を使って、ポインタの指す先の値を取得して表示\n";


    return 0;

}


