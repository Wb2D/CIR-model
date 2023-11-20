import json
import matplotlib.pyplot as plt
import numpy as np

json_file_path = r"C:\Qt\Projects\CIR\Data\Plots\TeylorMethod\time.json"

with open(json_file_path, 'r') as file:
    data = json.load(file)
    results = data.get("results", [])

iterations = [result["numberOfIterations"] for result in results]
elapsed_times = [result["elapsedTime"] for result in results]

# линейная аппроксимация
coefficients = np.polyfit(iterations, elapsed_times, 1)
polynomial = np.poly1d(coefficients)

# угловой коэффициент
k = coefficients[0]
print(f"Угловой коэффициент (k): {k}")

plt.plot(iterations, polynomial(iterations), linestyle='-', label=f'Trendline (k={k:.4f})', zorder=99)
plt.plot(iterations, elapsed_times, marker='o', markersize=5, linestyle='-', label='Actual Data')

plt.title('Dependence of time on the number of trajectories')
plt.xlabel('m, trajectories')
plt.ylabel('t, time')
plt.grid(True)
plt.legend()
plt.show()
