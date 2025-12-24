#Numpy, Panda  and CSV Practice Q

import pandas as pd                                     #first we created an array, converted it into csv file, then we read the file and got the name and math column
import numpy as np

data = {
    "Name": ["Ali", "Sara", "John"],
    "Math": [78, 90, 65],
    "Science": [85, 88, 70]
}

df = pd.DataFrame(data)

df.to_csv("marks.csv", index=False)

df = pd.read_csv("marks.csv")

print("Students Name:")
print(df["Name"])

math_score = df["Math"].values
avg_mathsScore = np.mean(math_score)