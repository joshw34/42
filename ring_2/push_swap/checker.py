def check_ascending_order(filename):
    numbers = []
    
    with open(filename, 'r') as file:
        for line in file:
            line = line.strip()
            if line.isdigit() or (line[0] == '-' and line[1:].isdigit()):  # Check if the line is a number
                numbers.append(int(line))
    
    for i in range(1, len(numbers)):
        if numbers[i] < numbers[i - 1]:
            return False
    return True

if __name__ == "__main__":
    filename = "result.txt"
    if check_ascending_order(filename):
        print("The numbers are in ascending numerical order.")
    else:
        print("The numbers are not in ascending numerical order.")

