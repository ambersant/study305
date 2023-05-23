#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <Windows.h>

using namespace std;

const int m = 32; // кількість символів в алфавіті

string filterText(string text) {
    // Заміна символів "ё" на "е"
    replace(text.begin(), text.end(), 'ё', 'е');

    // Перетворення великих літер на малі
    transform(text.begin(), text.end(), text.begin(), ::tolower);

    return text;
}

string encrypt(string plaintext, string key) {
    string ciphertext = "";
    int keylen = key.length();
    for (int i = 0; i < plaintext.length(); i++) {
        int p = plaintext[i] - 'а';
        int k = key[i % keylen] - 'а';
        int c = (p + k) % m;
        ciphertext += char(c + 'а');
    }
    return ciphertext;
}

string decrypt(string ciphertext, string key) {
    string plaintext = "";
    int keylen = key.length();
    for (int i = 0; i < ciphertext.length(); i++) {
        int c = ciphertext[i] - 'а';
        int k = key[i % keylen] - 'а';
        int p = (c - k + m) % m;
        plaintext += char(p + 'а');
    }
    return plaintext;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Ukrainian");

    string plaintext, key;
    ifstream file("work.txt");
    getline(file, plaintext);
    file.close();
    plaintext = filterText(plaintext); // Застосовуємо фільтр до тексту
    cout << "Введіть ключ: ";
    getline(cin, key);
    string ciphertext = encrypt(plaintext, key);
    cout << "\n Зашифрований текст: " << ciphertext << endl;

    double index_of_coincidence_ciphertext = 0.0;
    for (char ch = 'а'; ch <= 'я'; ch++) {
        int freq = count(ciphertext.begin(), ciphertext.end(), ch);
        double f = static_cast<double>(freq) / ciphertext.length();
        index_of_coincidence_ciphertext += f * f;
    }

    cout << "Індекс відповідності зашифрованого тексту: " << index_of_coincidence_ciphertext << endl;

    string decryptedtext = decrypt(ciphertext, key);
    cout << "\n Розшифрований текст: " << decryptedtext << endl;

    double ic_decrypted = 0.0;
    int freq_decrypted[m] = { 0 };
    for (int i = 0; i < decryptedtext.length(); i++) {
        int p = decryptedtext[i] - 'а';
        freq_decrypted[p]++;
    }
    for (int i = 0; i < m; i++) {
        ic_decrypted += (freq_decrypted[i] * (freq_decrypted[i] - 1));
    }
    ic_decrypted /= (decryptedtext.length() * (decryptedtext.length() - 1));
    cout << "Індекс відповідності розшифрованого тексту: " << ic_decrypted << endl;
}
