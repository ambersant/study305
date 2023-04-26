#include <iostream> 
#include <Windows.h> // для укр мови
#include <string>
#include <fstream>
#include <locale>
#include <map>
#include <unordered_map>
#include <locale>
#include <codecvt>
using namespace std;
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Rus");
  // setlocale(LC_ALL, "ru_RU.UTF-8");
    string text;

    ifstream file("C:/visualStd/c++/pc1.2/work.txt"); // відкриття файлу для читання
    getline(file, text);
    int numCh;

    cout << "оберіть операцію над текстом: \n1) частоти символів із урахуванням пробілу\n2) частоти символів без пробілу;\n3) частоти біграм із урахуванням пробілу, біграми з перетином;\n4) частоти біграм із урахуванням пробілу, біграми без перетину;\n5) частоти біграм без пробілів, біграми з перетином;\n6) частоти біграм без пробілів, біграми без перетину \n  ваш варіант це - " ;
    cin >> numCh;

    switch (numCh) {

    case 1: {

        //1 частоти символів з пробілом;/                                                   ///1
        cout << " 1) частоти символів з пробілом" << endl;

        map<string, int> bigram_freq;

        // iterate through the text
        for (int i = 0; i < text.length() - 1; i++) {
            // extract the bigram from the current position
            string bigram = text.substr(i, 2);

            // if the bigram is already in the map, increment its frequency
            if (bigram_freq.find(bigram) != bigram_freq.end()) {
                bigram_freq[bigram]++;
            }
            // otherwise, add it to the map with frequency 1
            else {
                bigram_freq[bigram] = 1;
            }
        }

        // print the bigram frequencies
        for (auto& entry : bigram_freq) {
            cout << entry.first << ": " << entry.second << endl;
        }

        break;
    }
    case 2: {
        //2  частоти символів без пробілу;                                                                 //2
        cout << " \t\t\t2) частоти символів без пробілу" << endl;
        unordered_map<string, int> freq;

        text.erase(remove_if(text.begin(), text.end(), [](char c) {
            return isspace(c) || ispunct(c);
            }), text.end());

        // проходимо по тексту та збільшуємо частоту біграм
        for (int i = 0; i < text.length() - 1; i++) {
            string bigram = text.substr(i, 2);
            freq[bigram]++;
        }
        // виводимо частоту біграм
        for (auto& pair : freq) {
            std::cout << "\t\t\t" << '{' << pair.first << ": " << pair.second << '}' << std::endl;
        }
        break;
    }
    case 3: {
        //3 частоти біграм із урахуванням пробілу, біграми з перетином;                                      //3
        cout << " 3) Частоти біграм із урахуванням пробілу, біграми з перетином;" << endl;

        map<string, int> bigramFreq;

        for (int i = 0; i < text.length() - 1; i++) {
            string bigram = text.substr(i, 2);
            if (bigramFreq.find(bigram) != bigramFreq.end()) {
                bigramFreq[bigram]++;
            }
            else {
                bigramFreq[bigram] = 1;
            }
        }

        for (auto const& pair : bigramFreq) {
            cout << pair.first << ": " << pair.second << endl;
        }
        break;
    }

    case 4: {
        cout << "4) частоти біграм із урахуванням пробілу, біграми без перетину" << endl;                      //4
        unordered_map<string, int> freq_no_overlap;

        for (int i = 0; i < text.length() - 1; i += 2) {
            string bigram = text.substr(i, 2);
            freq_no_overlap[bigram]++;
        }

        for (auto& pair : freq_no_overlap) {
            std::cout << '{' << pair.first << ": " << pair.second << '}' << std::endl;
        }
        break;
    }
    case 5: {
        cout << "5) частоти біграм без пробілів, біграми з перетином;" << endl;                                 //5
        map<string, int> no_space_bigram_freq;

        // remove spaces from text
        text.erase(remove_if(text.begin(), text.end(), [](char c) {
            return isspace(c);
            }), text.end());

        // iterate through the text
        for (int i = 0; i < text.length() - 1; i++) {
            // extract the bigram from the current position
            string bigram = text.substr(i, 2);

            // if the bigram is already in the map, increment its frequency
            if (no_space_bigram_freq.find(bigram) != no_space_bigram_freq.end()) {
                no_space_bigram_freq[bigram]++;
            }
            // otherwise, add it to the map with frequency 1
            else {
                no_space_bigram_freq[bigram] = 1;
            }
        }

        // print the bigram frequencies
        for (auto& entry : no_space_bigram_freq) {
            cout << entry.first << ": " << entry.second << endl;
        }
        cout << "частоти біграм з перетином" << endl;
        map<string, int> overlapping_bigram_freq;

        // iterate through the text
        for (int i = 0; i < text.length() - 1; i++) {
            // extract the bigram from the current position
            string bigram = text.substr(i, 2);

            // if the bigram is already in the map, increment its frequency
            if (overlapping_bigram_freq.find(bigram) != overlapping_bigram_freq.end()) {
                overlapping_bigram_freq[bigram]++;
            }
            // otherwise, add it to the map with frequency 1
            else {
                overlapping_bigram_freq[bigram] = 1;
            }
        }

        // print the bigram frequencies
        for (auto& entry : overlapping_bigram_freq) {
            cout << entry.first << ": " << entry.second << endl;
        }
        break;
    }
    case 6: {

        cout << " 6) частоти біграм без пробілів, біграми без перетину" << endl;                                   //6


        unordered_map<string, int> bigramFreqNoSpaces;

        // remove spaces and punctuation from the text
        text.erase(remove_if(text.begin(), text.end(), [](char c) {
            return isspace(c) || ispunct(c);
            }), text.end());

        // iterate through the text and increment the frequency of non-overlapping bigrams
        for (int i = 0; i < text.length() - 1; i += 2) {
            string bigram = text.substr(i, 2);
            bigramFreqNoSpaces[bigram]++;
        }

        // print the non-overlapping bigram frequencies
        for (auto& pair : bigramFreqNoSpaces) {
            cout << pair.first << ": " << pair.second << endl;
        }
        break;
    }
    default: {
        cout << "вибачте невірний код" << endl;
    }
    }

           return 0;
    }