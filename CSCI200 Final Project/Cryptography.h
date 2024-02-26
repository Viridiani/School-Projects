/* CSCI 200: Final Project: Cryptography Machine
 *
 * Author: Avery Christie
 * 
 * Description:
 *    Header Cryptography Class to inherit from
 * 
 * Resources used: documentation for chrono because ctime was not precise enough
 * https://en.cppreference.com/w/cpp/chrono/high_resolution_clock
 *
 */

#ifndef CRYPTOGRAPHY_H
#define CRYPTOGRAPHY_H

#include <chrono>
#include <string>
#include <vector>

// #include <ctime>

class Cryptography {
    public:
        /**
         * @brief Construct a new Cryptography object
         * 
         */
        Cryptography();
        /**
         * @brief Set the Text object
         * @param text Text to set string to
         * 
         */
        void setText(std::string);
        /**
         * @brief Set the Alphabet object
         * @param alphabet to set string to
         * 
         */
        void setAlphabet(std::string);
        /**
         * @brief Set the Int Key object
         * @param vector of integers to set keys to
         * 
         */
        void setIntKey(std::vector<int>);
        /**
         * @brief Set the Str Key object
         * @param vector of strings to set keys to
         * 
         */
        void setStrKey(std::vector<std::string>);
        /**
         * @brief Set the Total Time object
         * @param start time
         * @param end time
         * 
         */
        void setTotalTime(const std::chrono::_V2::system_clock::time_point, const std::chrono::_V2::system_clock::time_point);
        /**
         * @brief Generates output file
         * @param output location
         * @param string to write
         * 
         */
        void generateInfo(std::ostream&, const std::string);
        /**
         * @brief performs atbash cipher on _text
         * 
         * @return std::string 
         */
        std::string atbash();
        /**
         * @brief Get the _text object
         * 
         * @return std::string 
         */
        std::string getText() const;
        /**
         * @brief Get the _alphabet object
         * 
         * @return std::string 
         */
        std::string getAlphabet() const;
        /**
         * @brief Get the Int Key object
         * 
         * @return std::vector<int> 
         */
        std::vector<int> getIntKey() const;
        /**
         * @brief Get the Str Key object
         * 
         * @return std::vector<std::string> 
         */
        std::vector<std::string> getStrKey() const;
        /**
         * @brief Get the Total Time object
         * 
         * @return std::chrono::duration<double, std::milli> 
         */
        std::chrono::duration<double, std::milli> getTotalTime() const;
    protected:
        std::string _text;
        std::string _alphabet;
        // std::clock_t _start, _end;
        std::chrono::duration<double, std::milli> _time;
        struct {
            std::vector<std::string> strKeys;
            std::vector<int> intKeys;
        } _keys;
};

#endif //CRYPTOGRAPHY_H