# Implement a Fibonacci Sequence Generator.

def fibonacci_sequence(n):
    fib_seq = [0, 1]
    for i in range(2, n):
        fib_seq.append(fib_seq[i-1] + fib_seq[i-2])
    return fib_seq[:n]

fib_numbers = fibonacci_sequence(10)  
print(fib_numbers)
print(fibonacci_sequence(5))
