/* CSCI 200: Final Project: Cryptography Machine
 *
 * Author: Avery Christie
 * 
 * Description:
 *    Interface for Cryptography class
 * 
 * Resources used: none
 *
 */

#ifndef ICRYPTOGRAPHY_H
#define ICRYPTOGRAPHY_H

#include <string>
#include <iostream>

class ICryptography {
    public:
        /**
         * @brief Destroy the ICryptography object
         * 
         */
        virtual ~ICryptography() {}
        /**
         * @brief caesar cipher virtual function
         * 
         * @return std::string 
         */
        virtual std::string caesar() = 0;
        /**
         * @brief viginere virtual function
         * 
         * @return std::string 
         */
        virtual std::string viginere() = 0;
        /**
         * @brief affine cipher virtual function
         * 
         * @return std::string 
         */
        virtual std::string affine() = 0;
    private:
};
#endif //ICRYPTOGRAPHY_H