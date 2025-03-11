/*#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <openssl/sha.h> // Include OpenSSL library for SHA-256
#include <chrono>

// Function to compute SHA-256 hash of a string
std::string sha256(const std::string &input) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char *)input.c_str(), input.size(), hash);

    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }

    return ss.str();
}

int main() {
    std::string input;
    std::cout << "Enter the input string: ";
    std::cin >> input;

    const std::string threshold = "000ff"; // Threshold: first 3 hex digits must be 0
    unsigned int nonce = 0;
    std::string hash;

    // Measure the time taken to find the nonce
    auto start_time = std::chrono::high_resolution_clock::now();

    // Loop until a valid nonce is found
    while (true) {
        std::string combined = input + std::to_string(nonce);
        hash = sha256(combined);

        if (hash.substr(0, threshold.size()) < threshold) {
            break;
        }

        ++nonce;
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_time = end_time - start_time;

    std::cout << "Nonce: " << nonce << std::endl;
    std::cout << "Hash: " << hash << std::endl;
    std::cout << "Time taken: " << elapsed_time.count() << " seconds" << std::endl;

    return 0;
}*/

#include "sha256.h"
#include <iostream>
#include <iomanip>
#include <sstream>

std::string sha256(const std::string& input) {
    BYTE hash[32];
    SHA256_CTX ctx;
    sha256_init(&ctx);
    sha256_update(&ctx, reinterpret_cast<const BYTE*>(input.c_str()), input.size());
    sha256_final(&ctx, hash);

    std::stringstream ss;
    for (int i = 0; i < 32; ++i) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss.str();
}

int main() {
    std::string input = "Hello, World!";
    std::string hash = sha256(input);
    std::cout << "SHA-256: " << hash << std::endl;
    return 0;
}
