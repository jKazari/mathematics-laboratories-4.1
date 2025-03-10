import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("project-0a\\results.csv")

algorithms = df["Function"].unique()

plt.figure(figsize=(10, 6))

colors = plt.cm.Set2(range(len(algorithms)))

for i, algo in enumerate(algorithms):
    subset = df[df["Function"] == algo]
    plt.plot(subset["k"], subset["Time (ms)"], label=algo, color=colors[i])

plt.xlabel("Input size k")
plt.ylabel("Execution time (ms)")
plt.title("Execution Time vs. Input Size")
plt.legend()
plt.show()
