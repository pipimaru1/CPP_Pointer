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
    int INT_A = 12345678; // 整数型の変数INT_Aを宣言し、値12345678で初期化します。  
    int* PT_INT;
    void* PT_VOID;
    char* PT_STR;
    char STRING_X[6] = "Hello";                         // 文字列リテラル "Hello" は null 終端されているため、配列のサイズは 6 になります。
    char STRING_Y[5] = { 'H', 'e', 'l', 'l', 'o' };     // 文字列リテラルを使用せずに、文字の配列を初期化しています。

    PT_INT = &INT_A;
    PT_VOID = &INT_A;
    std::cout << "INT_A    = " << INT_A << std::endl;    // 値が表示されるはず。
    std::cout << "PT_INT   = " << PT_INT << std::endl;   // メモリのアドレスが表示されるはず。PT_INTはINT_Aのアドレスを指しているので、INT_Aのアドレスが表示されるはずです。
    std::cout << "*PT_INT  = " << *PT_INT << std::endl;  // *PT_INTはINT_Aの値を表示するはずです。
    std::cout << "PT_VOID  = " << PT_VOID << std::endl;  // メモリのアドレスが表示されるはず。PT_VOIDはINT_Aのアドレスを指しているので、INT_Aのアドレスが表示されるはずです。
    std::cout << "*PT_VOID = " << *((int*)PT_VOID) << std::endl; // 用する前に適切な型にキャストする必要がります。INT_Aの値が表示されるはずです。
    std::cout << "&PT_VOID = " << &PT_VOID << std::endl;  // PT_VOIDのアドレスが表示されるはずです。アドレス値のアドレス。

	PT_STR = STRING_X; // 配列名は配列の先頭要素のアドレスを表すので、PT_STRにSTRING_Xを代入することで、PT_STRはSTRING_Xの先頭要素のアドレスを指すようになります。
    PT_VOID = PT_STR    ;

	std::cout << "STRING_X = " << STRING_X << std::endl;
	std::cout << "PT_STR   = "<< PT_STR << std::endl;  // PT_STRはSTRING_Xの先頭要素のアドレスを指しているので、STRING_Xの内容が表示されるはずです。
	std::cout << "PT_VOID  = "<< PT_VOID << std::endl; // PT_VOIDはPT_STRのアドレスを指しているので、STRING_Xの内容が表示されるはずです。

    PT_STR = STRING_Y; // 配列名は配列の先頭要素のアドレスを表すので、PT_STRにSTRING_Xを代入することで、PT_STRはSTRING_Xの先頭要素のアドレスを指すようになります。
    PT_VOID = PT_STR;

	std::cout << "STRING_Y = " << STRING_Y << std::endl; // STRING_Yはnull終端されていないので、文字列の最後にゴミデータが入っている可能性があります。表示される内容は環境によって異なります。
	std::cout << "PT_STR   = " << PT_STR << std::endl;   // PT_STRはSTRING_Yの先頭要素のアドレスを指しているので、STRING_Yの内容が表示されるはずですが、null終端されていないので、文字列の最後にゴミデータが入っている可能性があります。表示される内容は環境によって異なります。
	std::cout << "PT_VOID  = " << PT_VOID << std::endl;  // PT_VOIDはPT_STRのアドレスを指しているので、STRING_Yの内容が表示されるはずですが、null終端されていないので、文字列の最後にゴミデータが入っている可能性があります。表示される内容は環境によって異なります。

    std::cout << "PT_STR = " << PT_STR +   100 << std::endl; // 何が出るかなドキドキ
    std::cout << "PT_STR   = " << PT_STR +  1000 << std::endl; // 何が出るかなドキドキ
	std::cout << "PT_STR   = " << PT_STR + 10000 << std::endl; // スタックを越えている可能性があるので、多分例外

    return 0;
}
    
int _main()
{
    int VALUE_X;
    int VALUE_Y;
	char STRING_X[6] = "Hello";                         // 文字列リテラル "Hello" は null 終端されているため、配列のサイズは 6 になります。
	char STRING_Y[5] = { 'H', 'e', 'l', 'l', 'o' };     // 文字列リテラルを使用せずに、文字の配列を初期化しています。
                                                       // こちらは null 終端されていないため、配列のサイズは 5 になります。

    int* PT_INT;
    char* PT_STR;
    void* PT_VOID;
    // ここでは「 * 」はポインタ型の変数を宣言するための記号です。

    VALUE_X = 4410;
    PT_INT = &VALUE_X;
	PT_STR = STRING_X; // 配列名は配列の先頭要素のアドレスを表すので、PT_STRにSTRING_Xを代入することで、PT_STRはSTRING_Xの先頭要素のアドレスを指すようになります。

    std::cout<< "PT = &VALUE_X; // ポインタ変数PTにVALUE_Xのアドレスを代入" << std::endl;
    std::cout << ESCGRN;

    PT_VOID = &VALUE_X; // void*型のポインタ変数VOID_PTにVALUE_Xのアドレスを代入。void*は任意の型のポインタを格納できる特殊なポインタ型です。
    PT_VOID = STRING_X; // void*型のポインタ変数VOID_PTにSTRING_Xのアドレスを代入。これも問題ありません。void*は任意の型のポインタを格納できるため、異なる型のアドレスを代入することができます。
    PT_VOID = &STRING_X; // void*型のポインタ変数VOID_PTにSTRING_Xのアドレスを代入。これも問題ありません。void*は任意の型のポインタを格納できるため、異なる型のアドレスを代入することができます。
    PT_VOID = STRING_Y; // void*型のポインタ変数VOID_PTにSTRING_Yのアドレスを代入。これも問題ありません。void*は任意の型のポインタを格納できるため、異なる型のアドレスを代入することができます。
	// void*型のポインタは型指定(データサイズ)が未定義のため、ウォッチでVOID_PTの値を確認しても、
    // アドレスは表示されますが、そこにあるデータの内容は表示されません。
    // void*型のポインタを使用する場合、特定の型にキャストして使用する必要があります。
    size_t SZ_INT = sizeof(PT_INT);
    PT_VOID = &VALUE_X; // void*型のポインタ変数VOID_PTにVALUE_Xのアドレスを代入。void*は任意の型のポインタを格納できる特殊なポインタ型です。
    size_t SZ_VOID = sizeof(PT_VOID);
    
    //これは普通の「値」
    std::cout << "VALUE_Xの値           : " << VALUE_X << std::endl;

    //ポインタのアドレスになります。
    std::cout << "PTの値(アドレス)      : " << PT_INT << std::endl;

    //この「 * 」は ポインタの差すメモリの「値」を出すための間接参照演算子としての使い方になります。
    VALUE_Y = *PT_INT;
    std::cout << "PTの差すメモリにある値: " << VALUE_Y << std::endl;

    std::cout << "ポインタを使った代入操作" << std::endl;
    //ここでも「 * 」は ポインタの差すメモリの「値」を出すための間接参照演算子としての使い方になります。
    *PT_INT = 196809;

    //ポインタの差すメモリの「値」になります。
    std::cout << "PTの差すメモリにある値: " << *PT_INT << std::endl;
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


