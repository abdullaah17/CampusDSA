num1 = input("Enter First number: ")
operator = input("Enter operator(+,-,*,/):")
num2 = input("Enter Second Number: ")

try:
    num1 = float(num1) if '.' in num1 else int(num1)
    num2 = float(num2) if '.' in num2 else int(num2)
except ValueError:
    print("Please enter valid numbers only!")
    exit()

result = None

if operator == "+":      
    result = num1+num2
elif operator == "-":
    result = num1-num2
elif operator == "*":
    result = num1 * num2
elif operator  == "/":
    if num2 == 0:
        print("Invalid Number2")
        exit()
        result = num1/num2
    else: print("Invald Operator!")
print("Result:", result)
print("Type of result:", type(result))

