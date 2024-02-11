def left_justify_text(str, L):
    words = str.split()
    lines = []
    current_line = []

    for word in words:
        if len(' '.join(current_line + [word])) <= L:
            current_line.append(word)
        else:
            lines.append(current_line)
            current_line = [word]

    lines.append(current_line)

    justified_lines = []
    for line in lines[:-1]:
        total_chars = sum(len(word) for word in line)
        total_spaces_needed = L - total_chars
        space_slots = len(line) - 1
        spaces_per_slot = total_spaces_needed // space_slots
        extra_spaces = total_spaces_needed % space_slots

        justified_line = ''
        for i, word in enumerate(line):
            justified_line += word
            if i < len(line) - 1:
                justified_line += '_' * spaces_per_slot
                if extra_spaces > 0:
                    justified_line += '_'
                    extra_spaces -= 1

        justified_lines.append(justified_line)

    last_line = '_'.join(lines[-1])
    total_chars_last_line = sum(len(word) for word in lines[-1])
    total_spaces_last_line = L - total_chars_last_line
    last_line_with_spaces = '_'.join(lines[-1]) + '_' * total_spaces_last_line
    justified_lines.append(last_line_with_spaces)

    return justified_lines

def right_justify_line(words, max_width):
    space_count = max_width - sum(len(word) for word in words)
    justified_line = '_' * space_count + '_'.join(words)
    return justified_line

def right_justify_text(text, max_width):
    words = text.split()
    lines = []
    current_line = []
    current_line_width = 0

    for word in words:
        if current_line_width + len(word) + len(current_line) <= max_width:
            current_line.append(word)
            current_line_width += len(word)
        else:
            lines.append(right_justify_line(current_line, max_width))
            current_line = [word]
            current_line_width = len(word)

    if current_line:
        lines.append(right_justify_line(current_line, max_width))

    justified_text = '\n'.join(lines)
    return justified_text
    
input_text = input("Enter the text to be justified: ")
width = int(input("Enter the width of line: "))
justified_text = left_justify_text(input_text, width)
for line in justified_text:
    print(line)
print()

justified_text = right_justify_text(input_text, width)
print(justified_text)