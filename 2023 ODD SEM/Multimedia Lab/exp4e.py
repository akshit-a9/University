import heapq
from collections import defaultdict, Counter

class HuffmanNode:
    def __init__(self, symbol, freq):
        self.symbol = symbol
        self.freq = freq
        self.left = None
        self.right = None

    def __lt__(self, other):
        return self.freq < other.freq

def build_huffman_tree(freq_dict):
    priority_queue = [HuffmanNode(symbol, freq) for symbol, freq in freq_dict.items()]
    heapq.heapify(priority_queue)

    while len(priority_queue) > 1:
        left = heapq.heappop(priority_queue)
        right = heapq.heappop(priority_queue)
        new_node = HuffmanNode(None, left.freq + right.freq)
        new_node.left = left
        new_node.right = right
        heapq.heappush(priority_queue, new_node)

    return priority_queue[0]

def build_huffman_codes(node, current_code, huffman_codes):
    if node.symbol is not None:
        huffman_codes[node.symbol] = current_code
    if node.left is not None:
        build_huffman_codes(node.left, current_code + '0', huffman_codes)
    if node.right is not None:
        build_huffman_codes(node.right, current_code + '1', huffman_codes)

def huffman_encode(input_string):
    freq_dict = Counter(input_string)
    huffman_tree = build_huffman_tree(freq_dict)
    huffman_codes = {}
    build_huffman_codes(huffman_tree, '', huffman_codes)

    encoded_string = ''.join(huffman_codes[char] for char in input_string)

    return encoded_string, huffman_tree

def huffman_decode(encoded_string, huffman_tree):
    decoded_string = ""
    current_node = huffman_tree

    for bit in encoded_string:
        if bit == '0':
            current_node = current_node.left
        else:
            current_node = current_node.right

        if current_node.symbol is not None:
            decoded_string += current_node.symbol
            current_node = huffman_tree

    return decoded_string

if __name__ == "__main__":
    input_string = "this is an example for huffman encoding"

    encoded_string, huffman_tree = huffman_encode(input_string)
    print("Encoded String:", encoded_string)

    decoded_string = huffman_decode(encoded_string, huffman_tree)
    print("Decoded String:", decoded_string)