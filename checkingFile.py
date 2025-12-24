import os
import pandas as pd

if os.path.exists("marks.csv"):
    df = pd.read_csv("marks.csv")
    print(df)
else:
    print("⚠️ 'marks.csv' not found!")
