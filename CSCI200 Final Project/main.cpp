/* CSCI 200: Final Project: Cryptography Machine
 *
 * Author: Avery Christie
 * 
 * Description:
 *    Program which can take user-inputted strings and files and encrypt/decrypt them in various ways.
 *    Main file for Cryptography program. Handles menuing and user-input.
 * 
 * Resources used: None
 *
 */

#include "Encryption.h"
#include "Decryption.h"

#include <fstream>
#include <iostream>
#include <limits>

using namespace std;

int main() {
    Encryption encrypter;
    Decryption decrypter;
    string alphabet;
    vector<int> intKeys = encrypter.getIntKey();
    vector<string> strKeys = encrypter.getStrKey();
    string text;
    string fileIn = "text.in";
    string fileOut = "text.out";
    ifstream fin;
    ofstream fout;
    bool programRunning = true;
    int options = 0;
    int encOptions = 0;
    int decOptions = 0;
    int setOptions = 0;
    int keyOptions = 0;

    cout << "Enter an input file: " << endl;
    cout << "Enter X to leave default" << endl;
    cin >> fileIn;
    if (fileIn == "X") {
        fileIn = "text.in";
    }

    cout << "Enter an output file: " << endl;
    cout << "Enter X to leave default" << endl;
    cin >> fileOut;
    if (fileOut == "X") {
        fileOut = "text.out";
    }
    
    string fileRead = "";
    fin.open(fileIn);
    if (fin.fail()) {
        cerr << "File failed to open. Closing program." << endl;
        return -1;
    }
    while (!fin.eof()) {
        char temp = '\n';
        temp = fin.get(); // doing .get() here to include whitespaces in the text grabbed
        fileRead += temp;
    }

    fout.open(fileOut);
    if (fout.fail()) {
        cerr << "File failed to open. Closing program." << endl;
        return -1;
    }

    encrypter.setText(fileRead);
    decrypter.setText(fileRead);

    cout << "----- Cryptography Program -----" << endl << endl;
    while (programRunning) {
        cout << "Current Program Settings:" << endl;
        cout << "--Encryption--" << endl;
        cout << "Text: " << encrypter.getText() << endl << "Alphabet: " << encrypter.getAlphabet() << endl << "Keys: " << endl; 
        cout << "\tNumeric Keys: " << encrypter.getIntKey().at(0) << ", " << encrypter.getIntKey().at(1) << endl;
        cout << "\tString Keys: " << encrypter.getStrKey().at(0) << endl << endl;
        cout << "--Decryption--" << endl;
        cout << "Text: " << decrypter.getText() << endl << "Alphabet: " << decrypter.getAlphabet() << endl << "Keys: " << endl; 
        cout << "\tNumeric Keys: " << decrypter.getIntKey().at(0) << ", " << decrypter.getIntKey().at(1) << endl;
        cout << "\tString Keys: " << decrypter.getStrKey().at(0) << endl;
        cout << "--Files--" << endl;
        cout << "Input file (Text to cipher is read from here): " << fileIn << endl;
        cout << "Output file: " << fileOut << endl;
        cout << endl;
        cout << "Choose an option:" << endl;
        cout << "1. Encryption" << endl;
        cout << "2. Decryption" << endl;
        cout << "3. Settings" << endl;
        cout << "4. Quit" << endl;
        cin >> options;
        while (cin.fail()) {
            cout << "Enter a valid Option" << endl;
            cin.clear();
            char badChar = ' ';
            do { badChar = cin.get(); } while(badChar != '\n');
            cin >> options;
        }
        switch (options) {
            case 1:
                cout << "--Encryption--" << endl;
                cout << "1. " << "Caesar Cipher" << endl;
                cout << "2. " << "Atbash Cipher" << endl;
                cout << "3. " << "Viginere Cipher" << endl;
                cout << "4. " << "Affine Cipher" << endl;
                cout << "5. " << "back" << endl;
                cin >> encOptions;
                while (cin.fail()) {
                    cout << "Enter a valid Option" << endl;
                    cin.clear();
                    char badChar = ' ';
                    do { badChar = cin.get(); } while(badChar != '\n');
                    cin >> encOptions;
                }
                switch(encOptions) {
                    case 1:
                        cout << encrypter.caesar() << endl;
                        cout << encrypter.getTotalTime().count() << endl;
                        cout << "Generating output file..." << endl;
                        encrypter.generateInfo(fout, encrypter.caesar());
                        cout << "Complete" << endl;
                        break;
                    case 2:
                        cout << encrypter.atbash() << endl;
                        cout << encrypter.getTotalTime().count() << endl;
                        cout << "Generating output file..." << endl;
                        encrypter.generateInfo(fout, encrypter.atbash());
                        cout << "Complete" << endl;
                        break;
                    case 3:
                        cout << encrypter.viginere() << endl;
                        cout << encrypter.getTotalTime().count() << endl;
                        cout << "Generating output file..." << endl;
                        encrypter.generateInfo(fout, encrypter.viginere());
                        cout << "Complete" << endl;
                        break;
                    case 4:
                        cout << encrypter.affine() << endl;
                        cout << encrypter.getTotalTime().count() << endl;
                        cout << "Generating output file..." << endl;
                        encrypter.generateInfo(fout, encrypter.affine());
                        cout << "Complete" << endl;
                        break;
                    case 5:
                        options = 0;
                        break;
                    default:
                        options = 0;
                        break;
                }
                break;
            case 2:
                cout << "--Decryption--" << endl;
                cout << "1. " << "Caesar Cipher" << endl;
                cout << "2. " << "Atbash Cipher" << endl;
                cout << "3. " << "Viginere Cipher" << endl;
                cout << "4. " << "Affine Cipher" << endl;
                cout << "5. " << "back" << endl;
                cin >> decOptions;
                while (cin.fail()) {
                    cout << "Enter a valid Option" << endl;
                    cin.clear();
                    char badChar = ' ';
                    do { badChar = cin.get(); } while(badChar != '\n');
                    cin >> decOptions;
                }
                switch(decOptions) {
                    case 1:
                        cout << decrypter.caesar() << endl;
                        cout << decrypter.getTotalTime().count() << endl;
                        cout << "Generating output file..." << endl;
                        encrypter.generateInfo(fout, decrypter.caesar());
                        cout << "Complete" << endl;
                        break;
                    case 2:
                        cout << decrypter.atbash() << endl;
                        cout << decrypter.getTotalTime().count() << endl;
                        cout << "Generating output file..." << endl;
                        encrypter.generateInfo(fout, decrypter.atbash());
                        cout << "Complete" << endl;
                        break;
                    case 3:
                        cout << decrypter.viginere() << endl;
                        cout << decrypter.getTotalTime().count() << endl;
                        cout << "Generating output file..." << endl;
                        encrypter.generateInfo(fout, decrypter.viginere());
                        cout << "Complete" << endl;
                        break;
                    case 4:
                        cout << decrypter.affine() << endl;
                        cout << decrypter.getTotalTime().count() << endl;
                        cout << "Generating output file..." << endl;
                        encrypter.generateInfo(fout, decrypter.affine());
                        cout << "Complete" << endl;
                        break;
                    case 5:
                        options = 0;
                        break;
                    // case 6:
                    //     options = 0;
                    //     break;
                    default:
                        options = 0;
                        break;
                }
                break;
            case 3:
                cout << "--Settings--" << endl;
                cout << "1. " << "Alphabet" << endl;
                cout << "2. " << "Keys" << endl;
                cout << "3. " << "Input Text" << endl;
                cout << "4. " << "back" << endl;
                cin >> setOptions;
                while (cin.fail()) {
                    cout << "Enter a valid Option" << endl;
                    cin.clear();
                    char badChar = ' ';
                    do { badChar = cin.get(); } while(badChar != '\n');
                    cin >> setOptions;
                }
                switch(setOptions) {
                    case 1:
                        cout << "Enter a new alphabet:" << endl;
                        cin >> alphabet;
                        while (cin.fail()) {
                            cout << "Enter a valid alphabet" << endl;
                            cin.clear();
                            char badChar = ' ';
                            do { badChar = cin.get(); } while(badChar != '\n');
                            cin >> setOptions;
                        }
                        cout << "Setting alphabet..." << endl;
                        encrypter.setAlphabet(alphabet);
                        decrypter.setAlphabet(alphabet);
                        options = 0;
                        break;
                    case 2:
                        cout << "--Key Options--" << endl;
                        cout << "1. " << "String Key" << " (used for Viginere) " << endl;
                        cout << "2. " << "Numeric Key 1" << " (used for Caesar and first coefficient of Affine cipher) "<< endl;
                        cout << "3. " << "Numeric Key 2" << " (used for second coefficient of Affine cipher) " << endl;
                        cin >> keyOptions;
                            while (cin.fail()) {
                            cout << "Enter a valid alphabet" << endl;
                            cin.clear();
                            char badChar = ' ';
                            do { badChar = cin.get(); } while(badChar != '\n');
                            cin >> keyOptions;
                        }
                        switch(keyOptions) {
                            case 1:
                                cout << "Enter a new string key: ";
                                cin >> strKeys.at(0);
                                while (cin.fail()) {
                                    cout << "Enter a valid key" << endl;
                                    cin.clear();
                                    char badChar = ' ';
                                    do { badChar = cin.get(); } while(badChar != '\n');
                                    cin >> strKeys.at(0);
                                }
                                encrypter.setStrKey(strKeys);
                                decrypter.setStrKey(strKeys);
                                options = 0;
                                break;
                            case 2:
                                cout << "Enter a valid numerical key: ";
                                cin >> intKeys.at(0);
                                while (cin.fail()) {
                                    cout << "Enter a valid key" << endl;
                                    cin.clear();
                                    char badChar = ' ';
                                    do { badChar = cin.get(); } while(badChar != '\n');
                                    cin >> intKeys.at(0);
                                }
                                encrypter.setIntKey(intKeys);
                                decrypter.setIntKey(intKeys);
                                options = 0;
                                break;
                            case 3:
                                cout << "Enter a valid numerical key: ";
                                cin >> intKeys.at(1);
                                while (cin.fail()) {
                                    cout << "Enter a valid key" << endl;
                                    cin.clear();
                                    char badChar = ' ';
                                    do { badChar = cin.get(); } while(badChar != '\n');
                                    cin >> intKeys.at(1);
                                }
                                encrypter.setIntKey(intKeys);
                                decrypter.setIntKey(intKeys);
                                options = 0;
                                break;
                        }
                        break;
                    case 3:
                        cout << "Enter text to work with: ";
                        cin >> text;
                        while (cin.fail()) {
                            cout << "Enter valid text" << endl;
                            cin.clear();
                            char badChar = ' ';
                            do { badChar = cin.get(); } while(badChar != '\n');
                            cin >> text;
                        }
                        encrypter.setText(text);
                        decrypter.setText(text);
                        options = 0;
                        break;
                    case 4:
                        options = 0;
                        break;
                    default:
                        options = 0;
                        break;
                }
                break;
            case 4:
                cout << "Quitting Program..." << endl;
                programRunning = false;
                break;
            default:
                break;
        }
    }
    fin.close();
    fout.close();
    return 0;
}