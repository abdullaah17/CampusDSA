def divide(a, b):
    try:
        return a / b
    except ZeroDivisionError:
        return "Cannot divide by zero"
    except TypeError:
        return "Invalid input"
    finally:
        print("Division attempted")

print(divide(10, 2))
print(divide(10, 0))
print(divide(10, "a"))
