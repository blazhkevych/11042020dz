/*
ЛАБОРАТОРНАЯ РАБОТА
Зв'язок масивів і покажчиків. Операції над покажчиками.
Тема: Зв'язок масивів і покажчиків. Операції над покажчиками.
Мета : Навчитися використовувати покажчики, зрозуміти зв'язок масивів і покажчиків.
Необхідні інструменти : MS Visual Studio
Документація :
Орієнтовний час виконання : 4 години.
Вимоги до звіту : Звіт повинен бути оформлений у вигляді електронного документа :
програмний код з коментарями, висновки про результати виконуваних дій і копії
екрану.Розмір файлу звіту до 2 МБ зі скріншотами.

ЗАВДАННЯ :
	1. Оголосити дві змінні і два покажчика.Присвоїти вказівниками адреси змінних.
	Порівняти два покажчика.Пояснити результат порівняння.
	2. Для коду :
#include <iostream>
using namespace std;
void main()
{
	int a = 2;
	int* p = &a;
	// Пояснити, в чому полягає різниця між операціями
	(*p)++;
	//та
	*p++;
}
*/
#include <iostream>
using namespace std;
//1. Оголосити дві змінні і два покажчика.Присвоїти вказівниками адреси змінних.
//Порівняти два покажчика.Пояснити результат порівняння.
//2. Для коду :
void main()
{
	int a = 2; //оголошення змінної типу int та присвоєння їй значення
	int* p = &a; //оголошення покажчика p типу int та присвоєння йому (за допомогою унарної операції взяття адреси &) адреси змінної a, типу int
	// Пояснити, в чому полягає різниця між операціями
	cout << (*p)++ << endl; // інкрементується значення (2 -> 3) на яке вказує вказівник
	//та
	cout << *p++ << endl; // інкрементується сам вказівник p, а не те на що він вказує

	int PershaZminna = 123; // оголошення змінної
	int DruhaZminna = 99; // оголошення змінної
	int* PtrPershaZminna; // оголошення показчика
	int* PtrDruhaZminna; // оголошення показчика
	PtrPershaZminna = &PershaZminna; // ініціалізація вказівника (присвоєння вказівнику PtrPershaZminna адреси змінної PershaZminna)
	PtrDruhaZminna = &DruhaZminna; //  ініціалізація вказівника (присвоєння вказівнику PtrDruhaZminna адреси змінної DruhaZminna)

	if (PtrPershaZminna > PtrDruhaZminna) // порівнюємо значення вказівників, тобто адреси змінних
		cout << "PtrPershaZminna > PtrDruhaZminna" << endl;
	if (*PtrPershaZminna > * PtrDruhaZminna) // порівнюємо значення змінних, на які вказують вказівники
		cout << "*PtrPershaZminna > *PtrDruhaZminna" << endl;
}

/*
3. Для коду :
#include <iostream>
using namespace std;
void main()
{
	const int SIZE = 10;
	int A[SIZE] = { 1,2,3,4,5,6,7,8,9,10 };
	int* p = A;
	// пояснити, що буде робити операція p++ і p--
}
#include <iostream>
using namespace std;
void main()
{
	const int SIZE = 10;
	int A[SIZE] = { 1,2,3,4,5,6,7,8,9,10 };
	int* p = A; // створення вказівника p та присвоєння йому адреси змінної A
	// пояснити, що буде робити операція p++ і p--
	cout << "source array:\n" << *p << endl; // вивід значення, що міститься в змінній A через покажчик, операцією розіменування покажчика
	p++; // інкрементується вказівник, тобто адреса на яку він вказує, на 4 байти. Отримаємо вказівник з новою адресою, адресою на наступну ячейку масиву
	cout << "array after using p ++:\n" << *p << endl;
	p--; // декрементується вказівник, тобто адреса на яку він вказує, на 4 байти. Отримаємо вказівник з попередньою адресою, адресою попередньої ячейки масиву
	cout << "array after using p --:\n" << *p << endl;
}
*/
/*
4. Виправити код :
#include <iostream>
using namespace std;
void main()
{
	const int SIZE = 10;
	int A[SIZE] = { 1,2,3,4,5,6,7,8,9,10 };
	int* p = A;
	for (int i = 0; i < SIZE; i++)
		// виконати вивід масиву використовуючи покажчики
		// максимальною кількістю способів
}
*/
/*
#include <iostream>

using namespace std;
void main()
{
	const int SIZE = 10;
	int A[SIZE] = { 1,2,3,4,5,6,7,8,9,10 };
	int* p = A;
*/

/*for (int i = 0; i < SIZE; i++)
	cout << *p++ << '\t';


for (int i = 0; i < SIZE; i++)
	cout << *(p++) << '\t';


for (int i = 0; i < SIZE; i++)
	cout << *(A + i) << '\t';*/
	/*
	for (int* p = A; p < A + SIZE; p++)
		cout << *p << " ";
}
	*/
	/*
	5. Дано масив цілих чисел a1, ... an.Використовуючи покажчики, з'ясувати, яка з
	трьох ситуацій має місце : всі числа a1, ... an дорівнюють нулю; в послідовності
	перше ненульове число – позитивне; перше ненульове число - негативне.
	#include <iostream>
	#include <ctime>
	using namespace std;
	void Set(int* mas, int size) {
		for (size_t i = 0; i < size; i++)
			mas[i] = -100 + rand() % 201;
	}
	void Print(int* mas, int size) {
		for (size_t i = 0; i < size; i++)
			cout << mas[i] << "\t";
		cout << endl;
	}
	void SituationN1(int* mas, int size) {
		int count = 0;
		for (size_t i = 0; i < size; i++)
			if (mas[i] == 0) count++;
		if (count == size)
			cout << "all numbers a1, ... an are equal to zero" << endl;
	}
	void SituationN2(int* mas, int size) {
		if (mas[0] != 0 && mas[0] > 0)
		{
			cout << "in sequence the first nonzero number is positive" << endl;
		}
	}
	void SituationN3(int* mas, int size) {
		if (mas[0] != 0 && mas[0] < 0)
		{
			cout << "first nonzero number is negative" << endl;
		}
	}
	int main()
	{
		srand(time(0));
		cout << "Enter size: ";
		int size;
		cin >> size;
		int* arr = new int [size] {0};
		Set(arr, size);
		Print(arr, size);
		SituationN1(arr, size);
		SituationN2(arr, size);
		SituationN3(arr, size);
		delete[]arr;
	}
	*/
	/*
	6. Використовуючи покажчики, перенести в хвіст одномірного масиву перший
	негативний елемент.
	#include <iostream>
	#include <ctime>
	using namespace std;
	void Print(int* mas, int size) {
		for (int i = 0; i < size; i++)
		{
			cout << mas[i] << "\t";
		}
		cout << endl;
	}
	void Set(int* mas, int size, int min = -10, int max = 10) {
		for (int i = 0; i < size; i++)
			mas[i] = min + rand() % (max - min + 1);
	}
	void swap(int*& a, int*& b)
	{
		int t = *a;
		*a = *b;
		*b = t;
	}
	void main()
	{
		int size = 3;
		int* arr = new int [size] { 0 };
		srand(time(0));
		int* ptrarr = arr;

		Set(arr, size);
		cout << "Source array:\n";
		Print(arr, size);
		int* ptri = 0;
		int i;
		for (i = 0; i < size; i++)
			if (arr[i] < 0)
				break;
		if (i < size) {
			ptri = &arr[i];
			cout << "\nFirst negative element: \narr[" << i << "] \naddress=" << ptri << "\nvalue= " << *(arr + i) << endl << endl;
		}
		else
			cout << "No negatives values!" << endl;
		cout << "Array after transfer to the end of the array of the first negative element:\n";
		int* lastElAdres = (arr + size - 1);
		cout << "Address of the last element of the array:\n" << lastElAdres << endl;
		swap(ptri, lastElAdres);
		Print(arr, size);
		delete[] arr;
	}
	*/
	/*
	7. Використовуючи покажчики, підрахувати в одномірному масиві максимальну
	кількість нулів, що йдуть підряд.
	#include <iostream>
	#include <ctime>
	using namespace std;
	void Print(int* mas, int size) {
		cout << "array\t";
		for (int i = 0; i < size; i++)
		{
			cout << mas[i] << "\t";
		}
		cout << endl;
	}
	int Zeros(int* arr, int size) {
		int result = 1, cur_num = 1, i;
		for (i = 0; i < size - 1; i++) {
			if (arr[i] == arr[i + 1]) {
				cur_num++;
				if (cur_num > result) {
					result = cur_num;
				}
			}
			else {
				cur_num = 1;
			}
		}
		return result;
	}
	void main()
	{
		int size = 15;
		int* arr = new int [size] { 1, 0, 0, 0, 0, 0, 0, 20, 100, 0, 0, 0, 0, 0, 6 };
		cout << "Source array:\n";
		Print(arr, size);
		cout << "maximum number of consecutive zeros: " << Zeros(arr, size) << endl;
		delete[] arr;
	}
	*/
	/*
	8. Використовуючи покажчики, перенести в початок одномірного масиву другий
	нульовий елемент.
	#include <iostream>
	using namespace std;
	void Print(int* mas, int size) {
		for (int i = 0; i < size; i++)
		{
			cout << mas[i] << "\t";
		}
		cout << endl;
	}
	int* Find(int* begin, int* end, int value)
	{
		while (begin != end && *begin != value) ++begin;
		return begin;
	}
	int main()
	{
		int size = 10;
		int* arr = new int [size] { 1, 0, 3, 0, 5, 6, 7, 8, 9, 9 };
		cout << "Before:\n";
		Print(arr, size);
		int value = 0;
		int* temp = Find(arr, arr + size, value);
		if (temp != arr + size)
		{
			temp = Find(temp + 1, arr + size, value);
		}
		if (temp != arr + size)
		{
			while (--temp >= arr) *(temp + 1) = *temp;
			arr[0] = value;
		}
		cout << "After:\n";
		Print(arr, size);
		delete[] arr;
		system("pause");
		return 0;
	}
	*/
	/*
	9. Використовуючи покажчики, підрахувати в одномірному масиві максимальну
	кількість одиниць, що йдуть підряд.
	#include <iostream>
	using namespace std;
	int MaxNumberInArr(int* arr, int n, int fn = 1) {
		int CountMax = 0, count = 0;
		for (size_t i = 0; i < n; i++)
		{
			if (arr[i] == fn)
				count++;
			else
				count = 0;
			CountMax = CountMax < count ? count : CountMax;
		}
		return CountMax;
	}
	int main()
	{
		int mas[] = { 10,1,2,3,3,3,3,31,1,1,2,1,1,1 };
		int size = sizeof(mas) / sizeof(*mas);
		cout << "N=" << MaxNumberInArr(mas, size, 1);
		delete[] mas;
	}
	*/
	/*

	10. Використовуючи покажчики, виключити з масиву a1, ... an перший парний
	елемент, наступний за максимальним.
	#include <iostream>
	using namespace std;
	void dell(int* a, int& size) {
		int m = a[0], idx = 0;
		for (int i = 1; i < size; ++i)
			if (a[i] > m) m = a[idx = i];
		for (int i = idx + 1; i < size; ++i)
			if (a[i] % 2 == 0) {
				for (int j = i + 1; j < size; ++j)
					a[j - 1] = a[j];
				--size;
				break;
			}
	}
	int main(int argc, const char* argv[]) {
		int size = 20;
		int* a = new int[20];
		for (int i = 0; i < size; ++i) a[i] = rand() % 20;
		for (int i = 0; i < size; ++i) cout << a[i] << " "; cout << endl;
		dell(a, size);
		for (int i = 0; i < size; ++i) cout << a[i] << " "; cout << endl;
	}
	*/
	/*
	11. Дано масив цілих чисел a1, .., an.Використовуючи покажчики, знайти суму двох
	самих великих за значенням елементів масиву і надрукувати її значення.
	#include <iostream>
	using namespace std;
	int SumTwoLargestEl(int* mas, int size, int sum) {
		int max1 = 0;
		int max2 = 0;
		for (size_t i = 0; i < size; i++)
		{
			if (max1 < mas[i])
				max1 = mas[i];
			else if (max2 < mas[i] and mas[i] != max1)
				max2 = mas[i];
		}
		cout << max1 << endl;
		cout << max2 << endl;
		return sum = max1 + max2;
	}
	int main()
	{
		int a1[] = { 10,1,2,3,33,3,3,31,1,1,222,1,1,1 };
		int size = sizeof(a1) / sizeof(*a1);
		int sum = 0;
		cout << "Sum=" << SumTwoLargestEl(a1, size, sum);
		delete[] a1;
	}
	*/