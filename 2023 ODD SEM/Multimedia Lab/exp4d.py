def run_length_encode(input_string):
    encoded_string = ""
    i = 0

    while i < len(input_string):
        count = 1
        while i + 1 < len(input_string) and input_string[i] == input_string[i + 1]:
            count += 1
            i += 1
        encoded_string += str(count) + input_string[i]
        i += 1

    return encoded_string

def run_length_decode(encoded_string):
    decoded_string = ""
    i = 0

    while i < len(encoded_string):
        count = int(encoded_string[i])
        char = encoded_string[i + 1]
        decoded_string += char * count
        i += 2

    return decoded_string

if __name__ == "__main__":
    input_string = "AAAABBBCCDAA"
   
    encoded_string = run_length_encode(input_string)
    print("Encoded String:", encoded_string)
   
    decoded_string = run_length_decode(encoded_string)
    print("Decoded String:", decoded_string)