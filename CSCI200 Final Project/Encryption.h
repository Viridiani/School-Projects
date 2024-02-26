/* CSCI 200: Final Project: Cryptography Machine
 *
 * Author: Avery Christie
 * 
 * Description:
 *    Header file for Encryption class
 * 
 * Resources used: none
 *
 */

#include "Cryptography.h"
#include "ICryptography.h"

#ifndef ENCRYPTION_H
#define ENCRYPTION_H

class Encryption final : public Cryptography, public ICryptography {
    public:
        /**
         * @brief Construct a new Encryption object
         * 
         */
        Encryption();
        /**
         * @brief Destroy the Encryption object
         * 
         */
        ~Encryption();
        /**
         * @brief Perform caesar cipher encryption
         * 
         * @return std::string 
         */
        std::string caesar() override;
        /**
         * @brief perform viginere cipher encryption
         * 
         * @return std::string 
         */
        std::string viginere() override;
        /**
         * @brief perform affine cipher encryption
         * 
         * @return std::string 
         */
        std::string affine() override;
    private:
};

#endif //ENCRYPTION_HPP