#include <iostream>
#include <vector>
using namespace std;

int countPositiveOddSumRows(const vector<int>& row)
{
    int sum = 0;
    for (size_t i = 0; i < row.size(); ++i) 
    {
        if (i % 2 == 0)
        {
            sum += row[i];
        }
    }
    return sum > 0;
}

int main()
{
    setlocale(LC_ALL, "Ru");
    const int MAX_SIZE = 10;

    // Первый массив
    int rows1, cols1;
    cout << "Введите размеры первого массива (строки столбцы, не больше 10): ";
    cin >> rows1 >> cols1;

    //Проверка на правилность ввода
    if (rows1 <= 0 || rows1 > MAX_SIZE || cols1 <= 0 || cols1 > MAX_SIZE) {
        cout << "Некорректные размеры массива." << endl;
        return 1;
    }

    //Запись первого массива
    vector<vector<int>> mas1(rows1, vector<int>(cols1));
    cout << "Введите элементы первого массива:" << endl;
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols1; ++j) {
            cin >> mas1[i][j];
        }
    }

    // Второй массив
    int rows2, cols2;
    cout << "Введите размеры второго массива (строки столбцы, не больше 10): ";
    cin >> rows2 >> cols2;

    //Проверка на правилность ввода
    if (rows2 <= 0 || rows2 > MAX_SIZE || cols2 <= 0 || cols2 > MAX_SIZE) {
        cout << "Некорректные размеры массива." << endl;
        return 1;
    }

    //Запись второго массива
    vector<vector<int>> mas2(rows2, vector<int>(cols2));
    cout << "Введите элементы второго массива:" << endl;
    for (int i = 0; i < rows2; ++i) {
        for (int j = 0; j < cols2; ++j) {
            cin >> mas2[i][j];
        }
    }

    // Подсчет строк с положительной суммой нечетных элементов для первого массива
    int count1 = 0;
    for (int i = 0; i < rows1; ++i) {
        count1 += countPositiveOddSumRows(mas1[i]);
    }

    // Подсчет строк с положительной суммой нечетных элементов для второго массива
    int count2 = 0;
    for (int i = 0; i < rows2; ++i) {
        count2 += countPositiveOddSumRows(mas2[i]);
    }

    // Вывод результатов
    if (count1 == 0 && count2 == 0) {
        cout << "Нет строк, удовлетворяющих условию, ни для одного из массивов." << endl;
    }
    else {
        cout << "Первый массив: " << count1 << " строк с положительной суммой элементов на нечетных местах." << endl;
        cout << "Второй массив: " << count2 << " строк с положительной суммой элементов на нечетных местах." << endl;
    }
}
