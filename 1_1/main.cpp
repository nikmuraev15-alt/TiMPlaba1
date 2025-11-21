#include <iostream>
#include <clocale>
#include "modAlphaCipher.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");

    string key = "КЛЮЧ";
    modAlphaCipher cipher(key);

    cout << "Шифр с поддержкой русского алфавита" << endl;
    cout << "Ключ: " << key << endl << endl;

    string text = "ПРИВЕТ МИР";

    cout << "Исходный текст: " << text << endl;

    string cipher_text = cipher.encrypt(text);
    cout << "Зашифровано: " << cipher_text << endl;

    string decrypted_text = cipher.decrypt(cipher_text);
    cout << "Расшифровано: " << decrypted_text << endl;

    cout << endl;

    string expected_text = "";
    for (char c : text) {
        if (c != ' ') {
            expected_text += c;
        }
    }

    if (decrypted_text == expected_text) {
        cout << "Результат: Ok — шифрование работает!" << endl;
    } else {
        cout << "Результат: Fail — ошибка в шифровании." << endl;
    }

    return 0;
}
