import numpy as np

a = np.array([1,2,3])
print(a)

b = np.array([[1,2], [4,5]])
print((b))

print(np.zeros(3))         # [0. 0. 0.]
print(np.ones((2, 2)))     # 2×2 matrix of ones
print(np.arange(5))        # [0 1 2 3 4]
print(np.linspace(0, 1, 5))  # 5 values from 0 to 1
print(a.ndim)
print(a.dtype)

a.shape      # returns (3,) for a 1D array
b.shape      # returns (2, 2)
a.ndim       # number of dimensions
a.dtype      # data type of elements
