#include "../../include/crypto_utils.h"
#include <cctype>

namespace crypto {
    std::string caesar_encrypt(const std::string& text, int shift) {
        std::string result;
        for (char c : text) {
            if (isalpha(c)) {
                char base = isupper(c) ? 'A' : 'a';
                c = (c - base + shift) % 26 + base;
            }
            result += c;
        }
        return result;
    }

    std::string caesar_decrypt(const std::string& text, int shift) {
        return caesar_encrypt(text, 26 - shift); // 反向位移
    }
}

// test
#include <iostream>
int main() {
    std::string encrypted = crypto::caesar_encrypt("HELLO", 3);
    std::cout << "Encrypted: " << encrypted << std::endl; // "KHOOR"
    std::cout << "Decrypted: " << crypto::caesar_decrypt(encrypted, 3) << std::endl;
    return 0;
}