# Create a function that checks whether a given string is a palindrome(reads the same forward and backward).

def replace(str, old, new):
    result = ''
    for smb in str:
        if smb == old:
            result += new
        else:
            result += smb
    return result

def is_palindrome(s):
    s = replace(s, ' ', '')
    return s == s[::-1]

result1 = is_palindrome("b a non a b")
result2 = is_palindrome("Hello")
print(result1) 
print(result2) 
