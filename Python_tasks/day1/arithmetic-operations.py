# Write a function to perform basic arithmetic operations.

def basic_arithmetic(operation, num1, num2):
    if operation == '+':
        return num1 + num2
    elif operation == '-':
        return num1 - num2
    elif operation == '*':
        return num1 * num2
    elif operation == '/':
        if num2 != 0:
            return num1 / num2
        else:
            return "Error: Division by zero."
    else:
        return "Error: Unsupported operation."
    
print(basic_arithmetic('+', 10, 6))
print(basic_arithmetic('*', 7, 12))
print(basic_arithmetic('/', 6, 0))