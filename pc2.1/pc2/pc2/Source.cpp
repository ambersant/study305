#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <Windows.h>

using namespace std;

const int m = 32; // ������� ������� � ������

string filterText(string text) {
    // ����� ������� "�" �� "�"
    replace(text.begin(), text.end(), '�', '�');

    // ������������ ������� ���� �� ���
    transform(text.begin(), text.end(), text.begin(), ::tolower);

    return text;
}

string encrypt(string plaintext, string key) {
    string ciphertext = "";
    int keylen = key.length();
    for (int i = 0; i < plaintext.length(); i++) {
        int p = plaintext[i] - '�';
        int k = key[i % keylen] - '�';
        int c = (p + k) % m;
        ciphertext += char(c + '�');
    }
    return ciphertext;
}

string decrypt(string ciphertext, string key) {
    string plaintext = "";
    int keylen = key.length();
    for (int i = 0; i < ciphertext.length(); i++) {
        int c = ciphertext[i] - '�';
        int k = key[i % keylen] - '�';
        int p = (c - k + m) % m;
        plaintext += char(p + '�');
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
    plaintext = filterText(plaintext); // ����������� ������ �� ������
    cout << "������ ����: ";
    getline(cin, key);
    string ciphertext = encrypt(plaintext, key);
    cout << "\n ������������ �����: " << ciphertext << endl;

    double index_of_coincidence_ciphertext = 0.0;
    for (char ch = '�'; ch <= '�'; ch++) {
        int freq = count(ciphertext.begin(), ciphertext.end(), ch);
        double f = static_cast<double>(freq) / ciphertext.length();
        index_of_coincidence_ciphertext += f * f;
    }

    cout << "������ ���������� ������������� ������: " << index_of_coincidence_ciphertext << endl;

    string decryptedtext = decrypt(ciphertext, key);
    cout << "\n ������������� �����: " << decryptedtext << endl;

    double ic_decrypted = 0.0;
    int freq_decrypted[m] = { 0 };
    for (int i = 0; i < decryptedtext.length(); i++) {
        int p = decryptedtext[i] - '�';
        freq_decrypted[p]++;
    }
    for (int i = 0; i < m; i++) {
        ic_decrypted += (freq_decrypted[i] * (freq_decrypted[i] - 1));
    }
    ic_decrypted /= (decryptedtext.length() * (decryptedtext.length() - 1));
    cout << "������ ���������� �������������� ������: " << ic_decrypted << endl;
}
