import pandas as pd
import numpy as np

data = {
    "Month": ["Jan", "Feb","Mar","Apr"],
    "Sales": [10000,12000,9000,15000]
}

df = pd.DataFrame(data)

df.to_csv("sales.csv", index = False)

df = pd.read_csv("sales.csv")

maxSales = df["Sales"].max
minSales = df["Sales"].min

bestMonth = df[df["Sales"]==maxSales]["Month"].values

print("Maximum Sales:",maxSales)
print("Minimum Sales:",minSales)
print("Best Month:", bestMonth)