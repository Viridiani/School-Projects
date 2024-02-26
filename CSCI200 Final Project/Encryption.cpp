/* CSCI 200: Final Project: Cryptography Machine
 *
 * Author: Avery Christie
 * 
 * Description:
 *    Implementation file for Encryption class
 * 
 * Resources used: none
 *
 */
#include "Encryption.h"

Encryption::Encryption() {} // inherit members from Cryptography.hpp

Encryption::~Encryption() {} // inherit from Cryptography.hpp

std::string Encryption::caesar() {
    std::chrono::_V2::system_clock::time_point start = std::chrono::high_resolution_clock::now();
    std::string decrypt = "";
    int key = _keys.intKeys.at(0);
    if (key > (int)_alphabet.length()) {
        key = key % (int)_alphabet.length();
    }
    for (unsigned int i = 0; i < _text.length(); i++) {
        int index = _alphabet.find(_text.at(i));
        if (index == (int)std::string::npos) {
            decrypt += _text.at(i);
            continue;
        } else {
            index += key;
            if (index > (int)_alphabet.length() - 1) {
                index -= _alphabet.length();
            } else if (index < 0) {
                index += _alphabet.length();
            }
            decrypt += _alphabet.at(index);
        }
    }
    std::chrono::_V2::system_clock::time_point end = std::chrono::high_resolution_clock::now();
    setTotalTime(start, end);
    return decrypt;
}

std::string Encryption::viginere() {
    std::chrono::_V2::system_clock::time_point start = std::chrono::high_resolution_clock::now();
    const std::string KEY = _keys.strKeys.at(0);
    std::string decrypt = "";
    int keyIndex = 0;
    for (unsigned int i = 0; i < _text.length(); i++) {
        if (_alphabet.find(_text.at(i)) == std::string::npos) {
            decrypt += _text.at(i);
            continue;
        }
        if (keyIndex > (int)KEY.length() - 1) {
            keyIndex -= (keyIndex / KEY.length()) * KEY.length();
        }
        if (_alphabet.find(KEY.at(keyIndex)) == std::string::npos) {
            keyIndex++;
        }
        int newLetterIndex = _alphabet.find(KEY.at(keyIndex)) + _alphabet.find(_text.at(i));
        if (newLetterIndex > (int)_alphabet.length() - 1) {
            newLetterIndex -= (newLetterIndex / (int)_alphabet.length()) * _alphabet.length();
        }
        decrypt += _alphabet.at(newLetterIndex);
        keyIndex++;
    }
    std::chrono::_V2::system_clock::time_point end = std::chrono::high_resolution_clock::now();
    setTotalTime(start, end);
    return decrypt;
}

std::string Encryption::affine() {
    std::chrono::_V2::system_clock::time_point start = std::chrono::high_resolution_clock::now();
    std::string decrypt = "";
    const int A = _keys.intKeys.at(0);
    const int B = _keys.intKeys.at(1);
    for (unsigned int i = 0; i < _text.length(); i++) {
        if (_alphabet.find(_text.at(i)) == std::string::npos) {
            decrypt += _text.at(i);
            continue;
        }
        int x = _alphabet.find(_text.at(i));
        int index = (A * x + B) % _alphabet.length();
        decrypt += _alphabet.at(index);
    }
    std::chrono::_V2::system_clock::time_point end = std::chrono::high_resolution_clock::now();
    setTotalTime(start, end);
    return decrypt;
}