def lzmc_compress(input_string, window_size, lookahead_buffer_size):
    compressed_data = []
    i = 0

    while i < len(input_string):
        match = ""
        offset = 0
        length = 0
        predicted_char = ""

        for j in range(1, min(lookahead_buffer_size, len(input_string) - i) + 1):
            substring = input_string[i:i + j]
            if substring in input_string[max(0, i - window_size):i]:
                match = substring
                offset = i - input_string.rfind(substring, 0, i)
                length = len(match)

        if i + length < len(input_string):
            predicted_char = input_string[i + length]

        if match:
            compressed_data.append((offset, length, predicted_char))
            i += length + 1
        else:
            compressed_data.append((0, 0, predicted_char))
            i += 1

    return compressed_data

def lzmc_decompress(compressed_data):
    decompressed_string = ""
    for (offset, length, predicted_char) in compressed_data:
        if offset == 0:
            decompressed_string += predicted_char
        else:
            start = len(decompressed_string) - offset
            for i in range(length):
                decompressed_string += decompressed_string[start + i]
            decompressed_string += predicted_char

    return decompressed_string

if __name__ == "__main__":
    input_string = "abracadabraabracadabra"
    window_size = 10
    lookahead_buffer_size = 5

    compressed_data = lzmc_compress(input_string, window_size, lookahead_buffer_size)
    print("Compressed Data:", compressed_data)

    decompressed_string = lzmc_decompress(compressed_data)
    print("Decompressed String:", decompressed_string)