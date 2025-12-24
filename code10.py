from sklearn.datasets import load_iris
import pandas as pd

iris = load_iris()

df = pd.DataFrame(iris.data, columns=iris.feature_names)

df["target"] = iris.target

print(df.shape)       # Rows × Columns
print(df.columns)     # Feature names
print(df.describe)

df.isnull().sum()        # Checks for missing values (NaNs)
df.duplicated().sum()    # Checks for exact duplicate rows
