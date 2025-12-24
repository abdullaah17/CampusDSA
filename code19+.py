import pandas as pd                                   
import numpy as np

data = {
    "Name": ["Ahsan","Zara","Imran","Maria"],
    "Age": [28,35,24,42],
    "Salary": [50000,60000,45000,70000]
}

df = pd.DataFrame(data)

df.to_csv("employees.csv", index = False)

df = pd.read_csv("employees.csv")

highSalary= df[df["Salary"]>50000]

print("Emplyees with Salaries higher than 50k")
print(highSalary["Name"])