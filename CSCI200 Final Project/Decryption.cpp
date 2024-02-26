/* CSCI 200: Final Project: Cryptography Machine
 *
 * Author: Avery Christie
 * 
 * Description:
 *    Implementation file for Decryption class
 * 
 * Resources used: none
 *
 */
#include "Decryption.h"

Decryption::Decryption() {} // inherit members from Cryptography.hpp

Decryption::~Decryption() {} // inherit from Cryptography.hpp

std::string Decryption::caesar() {
    std::chrono::_V2::system_clock::time_point start = std::chrono::high_resolution_clock::now();
    std::string clear = "";
    int key = _keys.intKeys.at(0);
    if (key > (int)_alphabet.length()) {
        key = key % (int)_alphabet.length();
    }
    for (unsigned int i = 0; i < _text.length(); i++) {
        int index = _alphabet.find(_text.at(i));
        if (index == (int)std::string::npos) {
            clear += _text.at(i);
            continue;
        } else {
            index -= key;
            if (index > (int)_alphabet.length() - 1) {
                index -= _alphabet.length();
            } else if (index < 0) {
                index += _alphabet.length();
            }
            clear += _alphabet.at(index);
        }
    }
    std::chrono::_V2::system_clock::time_point end = std::chrono::high_resolution_clock::now();
    setTotalTime(start, end);
    return clear;
}

std::string Decryption::viginere() {
    std::chrono::_V2::system_clock::time_point start = std::chrono::high_resolution_clock::now();
    std::string clear = "";
    const std::string KEY = _keys.strKeys.at(0);
    int keyIndex = 0;
    for (unsigned int i = 0; i < _text.length(); i++) {
        if (_alphabet.find(_text.at(i)) == std::string::npos) {
            clear += _text.at(i);
            continue;
        }
        if (keyIndex > (int)KEY.length() - 1) {
            keyIndex -= (keyIndex / KEY.length()) * KEY.length();
        }
        if (_alphabet.find(KEY.at(keyIndex)) == std::string::npos) {
            keyIndex++;
        }
        int newLetterIndex = _alphabet.find(_text.at(i)) - _alphabet.find(KEY.at(keyIndex));
        if (newLetterIndex < 0) {
            newLetterIndex += _alphabet.length();
        }
        clear += _alphabet.at(newLetterIndex);
        keyIndex++;
    }
    std::chrono::_V2::system_clock::time_point end = std::chrono::high_resolution_clock::now();
    setTotalTime(start, end);
    return clear;
}

std::string Decryption::affine() {
    std::chrono::_V2::system_clock::time_point start = std::chrono::high_resolution_clock::now();
    std::string clear = "";
    const int A = _keys.intKeys.at(0);
    const int B = _keys.intKeys.at(1);
    for (unsigned int i = 0; i < _text.length(); i++) {
        if (_alphabet.find(_text.at(i)) == std::string::npos) {
            clear += _text.at(i);
            continue;
        }
        int x = _alphabet.find(_text.at(i));
        // find modular inverse
        int aPrime = 0;
        for (unsigned int i = 0; i < _alphabet.size(); i++) {
            aPrime = i;
            int test = (aPrime * A) % (int)_alphabet.size();
            if (test == 1 && aPrime < (int)_alphabet.size()) {
                break;
            }
        }
        int index = aPrime * (x - B) % (int)_alphabet.length();
        clear += _alphabet.at(index);
    }
    std::chrono::_V2::system_clock::time_point end = std::chrono::high_resolution_clock::now();
    setTotalTime(start, end);
    return clear;
}