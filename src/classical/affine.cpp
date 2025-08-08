#include "../../include/crypto_utils.h"
#include <cctype>

namespace crypto {
    // 求模逆元（扩展欧几里得算法）
    int modular_inverse(int a, int m) {
        a = a % m;
        for (int x = 1; x < m; x++) {
            if ((a * x) % m == 1) return x;
        }
        return -1; // 无逆元
    }

    std::string affine_encrypt(const std::string& text, int a, int b) {
        std::string result;
        for (char c : text) {
            if (isalpha(c)) {
                char base = isupper(c) ? 'A' : 'a';
                c = (a * (c - base) + b) % 26 + base;
            }
            result += c;
        }
        return result;
    }

    std::string affine_decrypt(const std::string& text, int a, int b) {
        int a_inv = modular_inverse(a, 26);
        std::string result;
        for (char c : text) {
            if (isalpha(c)) {
                char base = isupper(c) ? 'A' : 'a';
                c = (a_inv * ((c - base) - b + 26)) % 26 + base;
            }
            result += c;
        }
        return result;
    }
}

// 测试代码
#include <iostream>
int main() {
    int a = 5, b = 8; // 必须满足 gcd(a,26)=1
    std::string encrypted = crypto::affine_encrypt("HELLO", a, b);
    std::cout << "Encrypted: " << encrypted << std::endl; // "RCLLA"
    std::cout << "Decrypted: " << crypto::affine_decrypt(encrypted, a, b) << std::endl;
    return 0;
}