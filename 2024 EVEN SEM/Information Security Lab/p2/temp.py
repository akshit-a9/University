import math


def is_prime(n):
    if n <= 1:
        return False
    if n <= 3:
        return True
    if n % 2 == 0 or n % 3 == 0:
        return False
    i = 5
    while i * i <= n:
        if n % i == 0 or n % (i + 2) == 0:
            return False
        i += 6
    return True


def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a


def mod_inverse(a, m):
    m0, x0, x1 = m, 0, 1
    while a > 1:
        q = a // m
        m, a = a % m, m
        x0, x1 = x1 - q * x0, x0
    return x1 + m0 if x1 < 0 else x1


def compute_n_phi(p, q):
    N = p * q
    phi = (p - 1) * (q - 1)
    return N, phi


def encrypt(message, e, N):
    return [pow(ord(char), e, N) for char in message]


def decrypt(ciphertext, d, N):
    return ''.join(chr(pow(char, d, N)) for char in ciphertext)


def main():
    p = int(input("Enter a prime number p: "))
    if not is_prime(p) or p < 0:
        print("p must be a positive prime number.")
        return

    q = int(input("Enter a prime number q: "))
    if not is_prime(q) or q < 0:
        print("q must be a positive prime number.")
        return

    N, phi = compute_n_phi(p, q)

    e = int(input("Enter a public exponent e: "))
    if gcd(e, phi) != 1 or e < 0:
        print("e must be a positive integer and coprime to phi(N).")
        return

    d = mod_inverse(e, phi)
    if d is None:
        print("No modular inverse exists for e and phi, choose a different e.")
        return

    choice = input("Do you want to encrypt or decrypt? (e/d): ")
    filename = input("Enter the filename of the message: ")

    with open(filename, 'r') as file:
        text = file.read()

    if choice == 'e':
        result = encrypt(text, e, N)
    elif choice == 'd':
        text = [int(x) for x in text.split()]
        result = decrypt(text, d, N)
    else:
        print("Invalid choice.")
        return

    with open('results.txt', 'w') as file:
        if choice == 'e':
            file.write(' '.join(map(str, result)))
        else:
            file.write(result)

    print("Operation completed. Check results.txt for the output.")


if __name__ == "__main__":
    main()
