import sympy

def is_prime(n):
    return sympy.isprime(n)

def compute_n_phi(p, q):
    N = p * q
    phi = (p - 1) * (q - 1)
    return N, phi

def compute_d(e, phi):
    print(sympy.mod_inverse(e, phi))
    return sympy.mod_inverse(e, phi)

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
    if sympy.gcd(e, phi) != 1 or e < 0:
        print("e must be a positive integer and coprime to phi(N).")
        return

    d = compute_d(e, phi)
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
