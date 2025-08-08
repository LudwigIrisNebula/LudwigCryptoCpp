#pragma once
#include <string>

namespace crypto {
    // Caesar加密/解密
    std::string caesar_encrypt(const std::string& text, int shift);
    std::string caesar_decrypt(const std::string& text, int shift);
    std::string affine_encrypt(const std::string& text, int a, int b);
    std::string affine_decrypt(const std::string& text, int a, int b);
    int modular_inverse(int a, int m); // 辅助函数：求模逆元
}