// Pinter_Array.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>

void edit_arry(int* p, size_t size);
void print_arry(int* p, size_t size);

int main()
{
    int ARRAY0[5] = { 1, 2, 3, 4, 5 };
    int ARRAY1[5] = { 11, 12, 13, 14, 15 };
    int ARRAY2[10] = { 21, 22, 23, 24, 25, 26, 27, 28, 29, 30 };

    int* POINTER=nullptr;

    //アドレスを表示する
    std::cout << "POINTER: " << POINTER << std::endl;

    ///////////////////////////////////////////////////
    //値を見る(たぶん、ランタイムエラーになる)
    //std::cout << "*POINTER: " << *POINTER << std::endl;

    // 実行中のアプリケーションの外のメモリを見ようとすると
    // CPUもしくはOSのプロテクションが働いてエラーになる。
    // 覗きはダメョ♡ていうこと。
    // アドレスを表示することは問題ない。

    std::cout << "\nPOINTER = ARRAY0\n";
    POINTER = ARRAY0; // ポインタ変数に配列のアドレスを代入
    //アドレスを表示する。POINTERとARRAY0は同じアドレスを指しているはず。
    std::cout << "ARRAY0 : " << POINTER << std::endl;
    std::cout << "POINTER: " << POINTER << std::endl;
    
    //値を見てみる
    std::cout << "POINTER[0]: " << POINTER[0] << std::endl;
    std::cout << "POINTER[1]: " << POINTER[1] << std::endl;
    std::cout << "POINTER[2]: " << POINTER[2] << std::endl;
    std::cout << "POINTER[3]: " << POINTER[3] << std::endl;
    std::cout << "POINTER[4]: " << POINTER[4] << std::endl;

    //ポインタ変数に配列のアドレスを代入
    std::cout << "\nPOINTER = ARRAY1\n";
    POINTER = ARRAY1;
    // アドレスを表示する。POINTERとARRAY1は同じアドレスを指しているはず。
    std::cout << "ARRAY1 : " << POINTER << std::endl;
    std::cout << "POINTER: " << POINTER << std::endl;
    //値を見てみる
    std::cout << "POINTER[0]: " << POINTER[0] << std::endl;
    std::cout << "POINTER[1]: " << POINTER[1] << std::endl;
    std::cout << "POINTER[2]: " << POINTER[2] << std::endl;
    std::cout << "POINTER[3]: " << POINTER[3] << std::endl;
    std::cout << "POINTER[4]: " << POINTER[4] << std::endl;

    //ポインタ変数に配列のアドレスを代入
    std::cout << "\nPOINTER = ARRAY2\n";
    POINTER = ARRAY2; // ポインタ変数に配列のアドレスを代入
    // アドレスを表示する。POINTERとARRAY2は同じアドレスを指しているはず。
    //またARRAY1と ARRAY2は20バイト「くらい」離れたアドレスを指しているはず。int型は4バイト。
    //20バイトは16進数で0x14
    std::cout << "ARRAY2 : " << POINTER << std::endl;
    std::cout << "POINTER: " << POINTER << std::endl;
    //値を見てみる
    std::cout << "POINTER[0]: " << POINTER[0] << std::endl;
    std::cout << "POINTER[1]: " << POINTER[1] << std::endl;
    std::cout << "POINTER[2]: " << POINTER[2] << std::endl;
    std::cout << "POINTER[3]: " << POINTER[3] << std::endl;
    std::cout << "POINTER[4]: " << POINTER[4] << std::endl;
    std::cout << "POINTER[5]: " << POINTER[5] << std::endl;
    std::cout << "POINTER[6]: " << POINTER[6] << std::endl;
    std::cout << "POINTER[7]: " << POINTER[7] << std::endl;
    std::cout << "POINTER[8]: " << POINTER[8] << std::endl;
    std::cout << "POINTER[9]: " << POINTER[9] << std::endl;

    //ポインタ変数に配列のアドレスを代入
    std::cout << "\nPOINTER = ARRAY2[5]\n";
    POINTER = &ARRAY2[5];
    // ポインタ変数に配列の「途中の」アドレスを代入
    // 　　　　　　　　　　↓ここを先頭として指定
    //{ 21, 22, 23, 24, 25, 26, 27, 28, 29, 30 };
    // アドレスを表示する。POINTERとARRAY2は「ちょうど」20バイト離れたアドレスを指しているはず。
    //20バイトは16進数で0x14
    std::cout << "ARRAY2 : " << POINTER << std::endl;
    std::cout << "POINTER: " << POINTER << std::endl;
    //値を見てみる
    std::cout << "POINTER[0]: " << POINTER[0] << std::endl;
    std::cout << "POINTER[1]: " << POINTER[1] << std::endl;
    std::cout << "POINTER[2]: " << POINTER[2] << std::endl;
    std::cout << "POINTER[3]: " << POINTER[3] << std::endl;
    std::cout << "POINTER[4]: " << POINTER[4] << std::endl;

    // 以下はゴミデータが出る 
    // アドレスが近いためアプリケーションの中のメモリ(スタック領域)と思われる。
    // プロテクションは働かず、値を見る事が出来るはず
    std::cout << "POINTER[5]: " << POINTER[5] << std::endl;
    std::cout << "POINTER[6]: " << POINTER[6] << std::endl;
    std::cout << "POINTER[7]: " << POINTER[7] << std::endl;
    std::cout << "POINTER[8]: " << POINTER[8] << std::endl;
    std::cout << "POINTER[9]: " << POINTER[9] << std::endl;
    
    // とりあえずエラーが出ずに機能してしまうため、
    // 場合によっては普通に動ているように見えるが、
    // たまたま動いているだけで、実際にはエラーになる事がある。バクである。
    // 実数を入れているのですぐに判別できるが、変数や関数になるとすぐには分らない。

    //再びポインタ変数に配列ARRAY0のアドレスを代入
    std::cout << "\nPOINTER = ARRAY0 ポインタ側の配列に代入\n";
    POINTER = ARRAY0;
    //ポインタ側の配列に値を代入
    POINTER[0] = 31; 
    POINTER[1] = 32;
    POINTER[2] = 33;
    POINTER[3] = 34;
    POINTER[4] = 35;

    //オリジナルの配列ARRAY0の値を表示してみる 
    std::cout << "ARRAY0[0]: " << ARRAY0[0] << std::endl;
    std::cout << "ARRAY0[1]: " << ARRAY0[1] << std::endl;
    std::cout << "ARRAY0[2]: " << ARRAY0[2] << std::endl;
    std::cout << "ARRAY0[3]: " << ARRAY0[3] << std::endl;
    std::cout << "ARRAY0[4]: " << ARRAY0[4] << std::endl;

    //再びポインタ変数に配列ARRAY1のアドレスを代入
    std::cout << "\nPOINTER = ARRAY1 関数でポインタを操作\n";
    POINTER = ARRAY1;
    edit_arry(POINTER, 5); // ポインタ変数に配列のアドレスを代入
    //オリジナルの配列ARRAY1の値を表示してみる
    std::cout << "ARRAY1[0]: " << ARRAY1[0] << std::endl;
    std::cout << "ARRAY1[1]: " << ARRAY1[1] << std::endl;
    std::cout << "ARRAY1[2]: " << ARRAY1[2] << std::endl;
    std::cout << "ARRAY1[3]: " << ARRAY1[3] << std::endl;
    std::cout << "ARRAY1[4]: " << ARRAY1[4] << std::endl;

    std::cout << "\nPOINTER = new int[10000] 動的メモリ確保\n";
    POINTER = new int[10000]; // 新しくメモリを確保　動的メモリ確保と言う 40KBのメモリを確保
    edit_arry(POINTER, 10000); // ポインタ変数に配列のアドレスを代入
    print_arry(POINTER, (size_t)100); // 全部表示すると大変なので100個だけ表示

    std::cout << "アドレスがどのくらい離れているか見てみる" << std::endl;
    std::cout << "ARRAY2 : " << ARRAY2 << std::endl;
    std::cout << "POINTER: " << POINTER << std::endl;

    delete[] POINTER; // 確保したメモリを解放する

    std::cout << "\nPOINTER = new int[SZ] 変数で動的メモリ確保\n";
    size_t SZ = 20;
    POINTER = new int[SZ]; // 新しくメモリを確保　動的メモリ確保と言う
    edit_arry(POINTER, SZ); // ポインタ変数に配列のアドレスを代入
    print_arry(POINTER, SZ); 

    std::cout << "アドレスがどのくらい離れているか見てみる" << std::endl;
    std::cout << "ARRAY2 : " << ARRAY2 << std::endl;
    std::cout << "POINTER: " << POINTER << std::endl;

    delete[] POINTER; 

    std::cout << "\n削除したメモリを覗く たぶんエラー\n";
    //削除したメモリを覗くとどうなるか ドキドキ
    print_arry(POINTER, SZ); 
    //プロテクションが働いてエラーになるはず
    return 0;
}

//関数の定義
//引数にポインタを指定することで、ポインタの指す先の値を変更する
//関数の中からはサイズが分からないので、配列を扱う関数はサイズを指定する事が多い
void edit_arry(int* pt, size_t size)
{
    for (int i = 0; i < size; i++)
    {
        pt[i] = i+100;
    }
}

void print_arry(int* p, size_t size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << p[i] << " ";
    }
    std::cout << std::endl;
}
