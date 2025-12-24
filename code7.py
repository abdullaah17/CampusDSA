with open("notes.txt","w") as file:
    file.write("My name is Abd")

with open("notes.txt","r") as file:
    content = file.read()

print(content)
