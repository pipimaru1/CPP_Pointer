//変数の中を確認するためのプログラム
#include <iostream>

// 課題
// floatはintと同じサイズの4バイトの変数です。
// float型の変数を4バイトのint型の変数に分解して表示してみてください。
// 8バイトのdouble型の変数を4バイトのint型の変数に分解して表示するプログラムを作成してください。

int print_4bytes(int _v);
int add_4bytes(int& _v, int _pos, int _add);

int main()
{
	//変数の宣言
	int value_1 = 1;
	print_4bytes(value_1);

	value_1 = 86;
	print_4bytes(value_1);

	value_1 = 255;
	print_4bytes(value_1);

	value_1 = 256;
	print_4bytes(value_1);

	value_1 = 256 * 256;
	print_4bytes(value_1);

	value_1 = 256 * 256 * 256;
	print_4bytes(value_1);

	value_1 = 256 * 256 * 256 + 17;
	print_4bytes(value_1);

	value_1 = -1;
	print_4bytes(value_1);

	value_1 = 1;
	add_4bytes(value_1, 1, 1);
	print_4bytes(value_1);
	std::cout << " value_1 = " << value_1 << std::endl;

	value_1 = -1;
	add_4bytes(value_1, 0, 1);
	print_4bytes(value_1);
	std::cout << " value_1 = " << value_1 << std::endl;
	//※4バイトに分解して、加算しているので、桁上りが波及しない

	return 0;
}

//////////////////////////////////////////////////////////////////////////////
//下記は、int型の変数を4バイトに分解して表示する関数
int print_4bytes(int _v)
{
	//一旦void型のポインタに変換
	void* ptv = &_v;

	// void型ポインタをバイト型(unsigned char)のポインタに変換 
	// 1行にまとめることもできる
	unsigned char* ptc = (unsigned char*)ptv;

	std::cout << " バイトに分解 : ";
	std::cout << (int)ptc[3] << " , ";
	std::cout << (int)ptc[2] << " , ";
	std::cout << (int)ptc[1] << " , ";
	std::cout << (int)ptc[0] << std::endl;

	return 0;
}

//////////////////////////////////////////////////////////////////////////////
//下記は、int型の変数を4バイトに分解、_posで指定したバイトに_addを加算する関数
// _posは0から3の値を指定すること
int add_4bytes(int& _v, int _pos, int _add)
{
	//一旦void型のポインタに変換
	void* ptv = &_v;

	// さらにvoid型ポインタをバイト型(unsigned char)のポインタに変換 
	unsigned char* ptc = (unsigned char*)ptv;

	ptc[_pos] += _add;

	return 0;
}

