import heapq

class Node:
    def __init__(self, char, freq):
        self.char = char
        self.freq = freq
        self.left = None
        self.right = None
    def __lt__(self, other):
        return self.freq < other.freq

    def __eq__(self, other):
        return self.freq == other.freq

def build_huffman_tree(frequencies):
    nodes = [Node(char, freq) for char, freq in frequencies.items()]
    heapq.heapify(nodes)
    
    while len(nodes) > 1:
        left = heapq.heappop(nodes)
        right = heapq.heappop(nodes)
        parent = Node(None, left.freq + right.freq)
        parent.left = left
        parent.right = right
        
        heapq.heappush(nodes, parent)
    return nodes[0]

def generate_huffman_codes(node, current_code, huffman_codes):
    if node is None:
        return
    if node.char is not None:
        huffman_codes[node.char] = current_code
    generate_huffman_codes(node.left, current_code + "0", huffman_codes)
    generate_huffman_codes(node.right, current_code + "1", huffman_codes)

frequencies = {'a': 5, 'b': 9, 'c': 12, 'd': 13, 'e': 16, 'f': 45}

huffman_tree = build_huffman_tree(frequencies)
huffman_codes = {}
generate_huffman_codes(huffman_tree, "", huffman_codes)

for char, code in huffman_codes.items():
    print(f"'{char}': {code}")
