import matplotlib.pyplot as plt

x = [1,2,3,4,5]
y = [9,8,7,6,5]

plt.scatter(x,y,color = "red")

plt.title("Scatter Plot")
plt.xlabel("X-Values")
plt.ylabel("Y-Values")

plt.grid(True)

plt.show()