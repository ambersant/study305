﻿#include <iostream> 
#include <Windows.h>
#include <math.h>
#include <string>

using namespace std;

string removeSpaces(string str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Ukrainian");  //add ukr   string input;
    string input;
    string chars = "0123456789-=,./!&@#$%^&*()";
    string result = "";
    int a;

    cout << "Введіть слова українською мовою: ";
    getline(cin, input);

    cout << "оберіть фільтр обробки: \n1) Фільтр у режимі звичайного алфавіту \n2) Фільтр у режимі алфавіту з пробілом   \n очікуємо - " ;
    cin >> a;
 
 

    switch (a) {
    case 1: {
        // Змінюємо всі літери на малі
        for (int i = 0; i < input.length(); i++)
        {
            input[i] = tolower(input[i]);
        }

        // Замінюємо декілька пробілів на один
        int i = 0;
        while (i < input.length())
        {
            if (input[i] == ' ')
            {
                result += ' ';
                while (input[i] == ' ')
                {
                    i++;
                }
            }
            else
            {
                result += input[i];
                i++;
            }
        }
        input = result;

        // Замінюємо пробіли на символ нижнього підкреслення
        for (int i = 0; i < input.length(); i++)
        {
            if (input[i] == ' ')
            {
                input[i] = '!';
            }
        }

        // Видаляємо заборонені символи з рядка перед виведенням
        for (int i = 0; i < chars.length(); i++)
        {
            input.erase(remove(input.begin(), input.end(), chars[i]), input.end());
        }

        // Виводимо результат
        cout << "Результат: " << input << endl;



      

        break;
    }
      case 2: {
          // Змінюємо всі літери на малі
          for (int i = 0; i < input.length(); i++)
          {
              input[i] = tolower(input[i]);
          }

          // Замінюємо декілька пробілів на один
          int i = 0;
          while (i < input.length())
          {
              if (input[i] == ' ')
              {
                  result += ' ';
                  while (input[i] == ' ')
                  {
                      i++;
                  }
              }
              else
              {
                  result += input[i];
                  i++;
              }
          }
          input = result;

          // Замінюємо пробіли на символ нижнього підкреслення
          for (int i = 0; i < input.length(); i++)
          {
              if (input[i] == ' ')
              {
                  input[i] = '_';
              }
          }

          // Видаляємо заборонені символи з рядка перед виведенням
          for (int i = 0; i < chars.length(); i++)
          {
              input.erase(remove(input.begin(), input.end(), chars[i]), input.end());
          }

          // Виводимо результат
          cout << "Результат: " << input << endl;



        

          break;
    }
    default:
        cout << "wrong";

    }

   
    return 0;
}



































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































