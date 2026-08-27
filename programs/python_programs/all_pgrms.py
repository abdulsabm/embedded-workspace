def reverse_int_num(num):
    reverse_nu = 0
    while num >0:
        reverse_nu = (reverse_nu*10)+(num%10)
        num//=10
    return reverse_nu

def reverse_string(s):
    return s[::-1]

num = '12345678'
# num = 12345678
if type(num) == str:
    print(f"reversed string: {reverse_string(num)}")
else:
    print(f"reversed num: {reverse_int_num(num)}")
#####################################################################################################

def is_string_palindrome(s):
    clean_s = "".join(c for c in s if c.isalnum()).lower()
    return clean_s == clean_s[::-1]

def is_int_palindrome(n):
    if n < 0 or (n%10 == 0 and n != 0): return False
    reversed_num = 0
    while n>reversed_num:
        reversed_num = (reversed_num*10) +(n%10)
        n//=10
    return n == reversed_num or n == reversed_num//10

s = '12gtktg21'
s = 1212121
if type(s) == str:
    if is_string_palindrome(s): print(f'The string {s} is a palindrome')
    else: print(f'The string {s} is not apalindrome')
else:
    if is_int_palindrome(s): print(f'The int number {s} is a palindrome')
    else:  print(f'The int number {s} is not  a palindrome')
#####################################################################################################

def is_prime(n):
    if type(n) == str:
        print("charecter variables are not a part of prime number give the integer number")
        return False
    if n <= 1: return False
    if n <= 3: return True
    if n%2 == 0 or n%3 == 0: return False
    i = 5
    while(i*i <= n):
        if n%i == 0 or n%(i+2) == 0: return False
        i += 6
    return True

for i in range(50):
    if is_prime(i):
        print(f'The number {i} is a prime number')
    else: print(f'The number {i} is not a prime number')
#####################################################################################################

def set_bit(num, bit_set): return num |(1<<bit_set)

def clear_bit(num, bit_clear): return num & (~(1<< bit_clear))

def toggle_bit(num, bit_num):
    return num ^ (1<< bit_num)

def filp_all_bits(num):
    if num == 0: return 1
    mask = (1<<num.bit_length())-1
    return num^mask

def count_once_in_num(num):
    temp = num
    count = 0
    while temp > 0:
        temp &= (temp-1)
        count += 1
    return count

def count_zeroes_in_num(num):
    temp = num
    zeroes = 0
    count = num.bit_length() -1
    while(count>= 0):
        if temp& (1<<count) == 0:
            zeroes +=1
        count -= 1
    return zeroes

print(set_bit(0x0, 3))
print(clear_bit(0xf, 3))
print(toggle_bit(0xf, 2))
print(filp_all_bits(5))
print(count_once_in_num(0xf0))
print(count_zeroes_in_num(0xf))
#####################################################################################################

def bubble_sort_array(arr):
    length = len(arr)
    for i in range(length):
        for j in range(length-i-1):
            if arr[j] > arr[j+1]:
                temp = arr[j]
                arr[j] = arr[j+1]
                arr[j+1] = temp
    return arr

arr = [1, 332, 54, 5, 76, 8]
print(bubble_sort_array(arr))
#####################################################################################################
