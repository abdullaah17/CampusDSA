import pandas as pd 

data = {
    "Name": ["Alice", "Bob", "Charlie"],
    "Age": [14, 15, 13],
    "Grade": ["A", "B", "C"]
}

df = pd.DataFrame(data) # Create a DataFrame

df.to_csv("students.csv", index= False)

print(df)
print(df.head())
print(df.head(2))
print(df.columns)
print(df.shape)

print(df["Age"])
print(df["Age"].mean())

print(df[["Name","Age"]])
print(df[["Age","Grade"]])

highAge = df[df["Age"]>14]
print(highAge)

print(df.describe)
