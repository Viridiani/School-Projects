/* CSCI 200: Final Project: Cryptography Machine
 *
 * Author: Avery Christie
 * 
 * Description:
 *    Implementation Cryptography Class to define getters/setters
 * 
 * Resources used: None
 *
 */

#include "Cryptography.h"

Cryptography::Cryptography() {
    _text = "hello world";
    _alphabet = "abcdefghijklmnopqrstuvwxyz";
    _keys.intKeys.push_back(5);
    _keys.intKeys.push_back(3);
    _keys.strKeys.push_back("key");
}
void Cryptography::setText(std::string text) {
    _text = text;
}
void Cryptography::setAlphabet(std::string alphabet) {
    _alphabet = alphabet;
}

void Cryptography::setIntKey(std::vector<int> ints) {
    _keys.intKeys = ints;
}

void Cryptography::setStrKey(std::vector<std::string> strings) {
    _keys.strKeys = strings;
}

void Cryptography::generateInfo(std::ostream& out, const std::string TEXT) {
    std::string format = "Input: " + _text + "\nOutput: " + TEXT + "\n";
    out << format;
}

std::string Cryptography::getText() const {
    return _text;
}

std::string Cryptography::getAlphabet() const {
    return _alphabet;
}

std::vector<int> Cryptography::getIntKey() const {
    return _keys.intKeys;
}

std::vector<std::string> Cryptography::getStrKey() const {
    return _keys.strKeys;
}

std::string Cryptography::atbash() {
    std::chrono::_V2::system_clock::time_point start = std::chrono::high_resolution_clock::now();
    std::string decrypt = "";
    std::string reverseAlphabet;
    for (unsigned int i = 1; i <= _alphabet.size(); i++) {
        reverseAlphabet.push_back(_alphabet.at(_alphabet.size() - i));
    }
    for (unsigned int i = 0; i < _text.length(); i++) {
        if (_alphabet.find(_text.at(i)) == std::string::npos) {
            decrypt += _text.at(i);
            continue;
        } else {
            decrypt += reverseAlphabet.at(_alphabet.find(_text.at(i)));
        }
    }
    std::chrono::_V2::system_clock::time_point end = std::chrono::high_resolution_clock::now();
    setTotalTime(start, end);
    return decrypt;
}

void Cryptography::setTotalTime(const std::chrono::_V2::system_clock::time_point START, const std::chrono::_V2::system_clock::time_point END) {
    std::chrono::duration<double, std::milli> timeMilliseconds(END - START);
}

std::chrono::duration<double, std::milli> Cryptography::getTotalTime() const {
    // double time = (double)(_end - _start) * 1000 / (double)CLOCKS_PER_SEC;
    return _time;
}