import pandas as pd

data = {
    "Name":["Alice","Bob","Charlie","David","Eva"],
    "Math_score":[85,78,95,60,92],
    "Science_score":[90,82,96,55,89],
    "English_score":[88,80,94,58,95]
}
df = pd.DataFrame(data)
df.to_csv("studentsScore.csv", index=False)

# Print the first 3 rows.
print(df.head(3))

# Add a new column called average_score which is the average of all 3 subjects for each student.
df["AverageScore"] = (df["Math_score"]+df["Science_score"]+df["English_score"])/3
print(df)

# Who has the highest average score?
TopStudent = df.loc[df["AverageScore"].idxmax()]
print("Top Scorer:")
print(TopStudent)

# How many students scored above 90 in science?
ScorersAbove90 = df[df["Science_score"]>90]
count = len(ScorersAbove90)
print("Numbers of Students who scored above 90 in Science:", count)

# Save the updated DataFrame (with average_score) to a new CSV called updated_scores.csv.
df.to_csv("updated_scores.csv", index=False)
print("Saved updated DataFrame to 'updated_scores.csv'")

# Create a new column called status:
df["Status"] = ["Pass" if score >= 70 else "Fail" for score in df["AverageScore"] ]
print(df)

print(df.describe)