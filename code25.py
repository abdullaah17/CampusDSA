import matplotlib.pyplot as plt
import pandas as pd
from sklearn.datasets import load_iris

# Load the Iris dataset
iris = load_iris()
df = pd.DataFrame(iris.data, columns=iris.feature_names)

# Create a boxplot for petal length
df.boxplot(column="petal length (cm)")
plt.title("Boxplot of Petal Length")
plt.ylabel("Length (cm)")
plt.show()
