def lz77_compress(input_string, window_size, lookahead_buffer_size):
    compressed_data = []
    i = 0

    while i < len(input_string):
        match = ""
        offset = 0
        length = 0

        for j in range(1, min(lookahead_buffer_size, len(input_string) - i) + 1):
            substring = input_string[i:i + j]
            if substring in input_string[max(0, i - window_size):i]:
                match = substring
                offset = i - input_string.rfind(substring, 0, i)
                length = len(match)

        if match:
            compressed_data.append((offset, length, input_string[i + length]))
            i += length + 1
        else:
            compressed_data.append((0, 0, input_string[i]))
            i += 1

    return compressed_data

def lz77_decompress(compressed_data):
    decompressed_string = ""
    for (offset, length, char) in compressed_data:
        if offset == 0:
            decompressed_string += char
        else:
            start = len(decompressed_string) - offset
            for i in range(length):
                decompressed_string += decompressed_string[start + i]
            decompressed_string += char

    return decompressed_string

if __name__ == "__main__":
    input_string = "abracadabraabracadabra"
    window_size = 10
    lookahead_buffer_size = 5

    compressed_data = lz77_compress(input_string, window_size, lookahead_buffer_size)
    print("Compressed Data:", compressed_data)

    decompressed_string = lz77_decompress(compressed_data)
    print("Decompressed String:", decompressed_string)