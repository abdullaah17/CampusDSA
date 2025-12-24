age = 18
cgpa = 2.6
name = "Sir"
is_student = True

skills = ["Python", "C++", "Git"] # list, changeable
profile = {  #dictionary/dic, Value mapping, This is how JSON data looks in APIs
    "name": name,
    "age": age,
    "cgpa": cgpa
}

print(type(age))  #type() tells you what Python thinks this variable is.
print(type(cgpa))
print(type(name))
print(type(skills))
print(type(profile))

skills.append("FastAPI") #.append() modifies the list
print("Updated skills:", skills)

# Backend relevance
# APIs send/receive dicts
# DB records map to dicts
# Lists = query results
