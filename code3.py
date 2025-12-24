def greet(name, language = "English"):
    if language == "Spanish":
        return f"Hola {name}!"
    return f"hello {name}"

print(greet("Abd","Spanish")) 