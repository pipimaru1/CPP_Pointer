/////////////////////////////////////////////////////////
// 関数のポインターのサンプル
/////////////////////////////////////////////////////////

#include <iostream>

// 関数ポインタの宣言
float (*funcPtr)(float, float);

// 関数の定義
float add(float a, float b) {
	return a + b;
}
float subtract(float a, float b) {
	return a - b;
}
float multiply(float a, float b) {
	return a * b;
}
float divide(float a, float b) {
	if (b == 0) {
		std::cerr << "Error: Division by zero!" << std::endl;
		return 0;
	}
	return a / b;
}

// 関数ポインタを使って計算を行う関数
float calculate(float (*operation)(float, float), float a, float b) {
	return operation(a, b);
}

int main()
{
	float answer = 0;
	float a = 8.5;
	float b = 4.2;

	//値の表示
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
		
	// 関数ポインタに関数のアドレスを代入
	//キー入力で関数を選択する
	while(true)
	{
		std::cout << "演算方法を選んでください: 0.足し算 1.引き算 2.掛け算 4.割り算" << std::endl;	
		char choice;
		std::cin >> choice;

		switch (choice) 
		{
		case '1':
			funcPtr = add;
			break;

		case '2':
			funcPtr = subtract;
			break;

		case '3':
			funcPtr = multiply;
			break;

		case '4':
			funcPtr = divide;
			break;

		case 'q':
		case 'Q':
			std::cout << "終了します。" << std::endl;
			goto PROGRAM_END;

		default:
			std::cerr << "Invalid choice!" << std::endl;
			break;
		}
		answer = calculate(funcPtr, a, b);
		std::cout << "答え: " << answer << std::endl;
	}

PROGRAM_END:

	return 0;
}

// 関数ポインタの配列の宣言
float (*funcPtrArry[4])(float, float) { add, subtract, multiply, divide };

int main_1()
{
	float answer = 0;
	float a = 8.5;
	float b = 4.2;

	//値の表示
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	
	//関数配列
	//キー入力で関数を選択する
	while (true)
	{
		std::cout << "演算方法を選んでください: 1.足し算 2.引き算 3.掛け算 4.割り算" << std::endl;
		int choice;
		std::cin >> choice;
		answer = calculate(funcPtrArry[choice], a, b);
		std::cout << "答え: " << answer << std::endl;
	}

	return 0;
}

