def RC4(key, data):
    S = list(range(256))
    j = 0
    for i in range(256):
        j = (j + S[i] + ord(key[i % len(key)])) % 256
        S[i], S[j] = S[j], S[i]

    i = j = 0
    result = []
    for char in data:
        i = (i + 1) % 256
        j = (j + S[i]) % 256
        S[i], S[j] = S[j], S[i]
        K = S[(S[i] + S[j]) % 256]
        result.append(chr(ord(char) ^ K))
    
    return ''.join(result)

def main():
    key = input("Enter the key: ")
    data = input("Enter the data to encrypt/decrypt: ")
    encrypted_data = RC4(key, data)
    decrypted_data = RC4(key, encrypted_data)
    print("Encrypted data:", encrypted_data)
    print("Decrypted data:", decrypted_data)


if __name__ == "__main__":
    main()
