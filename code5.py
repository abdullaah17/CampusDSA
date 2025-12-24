def is_even(n):
    return n%2 == 0

even_list = [n for n in range(21) if is_even(n)]



print(even_list)