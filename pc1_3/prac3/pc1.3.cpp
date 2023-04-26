#include <iostream>
#include <cmath>
#include <Windows.h> 
#include <string>
#include <fstream>
#include <map>
#include <unordered_map>
#include <locale>
#include <codecvt>
#include <cstring>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251); //укр локалізація 
    setlocale(LC_ALL, "Rus");
    string text;

    ifstream file("work.txt");


    getline(file, text);

    string filtered_text = ""; 
    for (int i = 0; i < text.length(); i++) {
        char c = text[i];
        if ((c >= 'а' && c <= 'я') || (c >= 'А' && c <= 'Я') || c== 'ё' || c == 'Ё') {
            filtered_text += c;
        }
    }
 
                             
    map<char, int> char_count;
    for (int i = 0; i < filtered_text.length(); i++) {
        char c = filtered_text[i];
        char_count[c]++;
    }
  
                          
    double n = filtered_text.length();
    double s = 0;
    for (auto& p : char_count) {
        int count = p.second;
        s += count * (count - 1);
    }
    double ioc = s / (n * (n - 1));

    cout << "індекс відповідності тексту - " << ioc << endl;
    return 0;
}
