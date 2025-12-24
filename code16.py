User_input = input("Enter Anything:")


User_input = float(User_input) if "." in User_input else int(User_input) if User_input.isdigit() else User_input

print("User Input:", User_input )
print("User Input Data Type:", type(User_input)) # input() always returns a string in Python, unless you convert it.