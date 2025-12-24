def greet(name):
    return f"Hello, {name}"

def add(a, b):
    return a + b

def stats(marks):
    total = sum(marks)
    avg = total / len(marks)
    return total, avg

print(greet("Sir"))
print(add(4, 6))

total, avg = stats([80, 70, 90]) #tupple unpacking 
print("Total:", total)
print("Average:", avg)

# Business logic lives in functions

# APIs call functions

# Testing focuses on functions