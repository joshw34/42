def can_be_sorted_by_rotation(numbers):
    n = len(numbers)
    for i in range(n):
        rotated_list = numbers[i:] + numbers[:i]
        if rotated_list == sorted(numbers, reverse=True):
            return True
    return False

def read_numbers_from_file(filename):
    with open(filename, 'r') as file:
        numbers = [int(line.strip()) for line in file]
    return numbers

def main():
    filename = 'result.txt'
    numbers = read_numbers_from_file(filename)
    if can_be_sorted_by_rotation(numbers):
        print("The list can be sorted into reverse numerical order by rotations.")
    else:
        print("The list cannot be sorted into reverse numerical order by rotations.")

if __name__ == "__main__":
    main()
