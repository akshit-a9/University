# Take input paragraph from the user
paragraph = input("Enter a paragraph: ")

# Take input for the file name
file_name = input("Enter the name of the file: ")

# Add a .txt extension to the file name if not provided
if not file_name.endswith(".txt"):
    file_name += ".txt"

# Open the file in write mode and write the paragraph to it
try:
    with open(file_name, "w") as file:
        file.write(paragraph)
    print(f"The paragraph has been saved to {file_name}")
except IOError:
    print("An error occurred while saving the file.")
