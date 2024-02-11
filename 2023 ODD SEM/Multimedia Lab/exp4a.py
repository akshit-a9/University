class Node:
    def __init__(self, char, freq):
        self.char = char
        self.freq = freq
        self.left = None
        self.right = None

def build_huffman_tree(frequencies):
    nodes = [Node(char, freq) for char, freq in frequencies.items()]

    while len(nodes) > 1:
        nodes.sort(key=lambda x: x.freq)
        
        left = nodes.pop(0)
        right = nodes.pop(0)
        
        parent = Node(None, left.freq + right.freq)
        parent.left = left
        parent.right = right
        
        nodes.append(parent)
    
    return nodes[0]

def generate_huffman_codes(node, current_code, huffman_codes):
    if node is None:
        return
    
    if node.char is not None:
        huffman_codes[node.char] = current_code
    
    generate_huffman_codes(node.left, current_code + "0", huffman_codes)
    generate_huffman_codes(node.right, current_code + "1", huffman_codes)

# Input character frequencies (replace with your character frequencies)
frequencies = {'a': 5, 'b': 9, 'c': 12, 'd': 13, 'e': 16, 'f': 45}

# Build the Huffman tree
huffman_tree = build_huffman_tree(frequencies)

# Generate Huffman codes
huffman_codes = {}
generate_huffman_codes(huffman_tree, "", huffman_codes)

# Print Huffman codes
for char, code in huffman_codes.items():
    print(f"'{char}': {code}")
