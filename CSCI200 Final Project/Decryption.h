/* CSCI 200: Final Project: Cryptography Machine
 *
 * Author: Avery Christie
 * 
 * Description:
 *    Header file for Decryption class
 * 
 * Resources used: none
 *
 */

#include "Cryptography.h"
#include "ICryptography.h"

#ifndef DECRYPTION_H
#define DECRYPTION_H

class Decryption final : public Cryptography, public ICryptography {
    public:
        /**
         * @brief Construct a new Decryption object
         * 
         */
        Decryption();
        /**
         * @brief Destroy the Decryption object
         * 
         */
        ~Decryption();
        /**
         * @brief perform caesar cipher decryption
         * 
         * @return std::string 
         */
        std::string caesar() override;
        /**
         * @brief perfrom viginere cipher decryption
         * 
         * @return std::string 
         */
        std::string viginere() override;
        /**
         * @brief perform affine cipher decryption
         * 
         * @return std::string 
         */
        std::string affine() override;
    private:
};

#endif //DECRYPTION_H