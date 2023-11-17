import json
import matplotlib.pyplot as plt

json_file_path = "C:\Qt\Projects\CIR\Data\Plots\RK3\\time.json"

with open(json_file_path, 'r') as file:
    data = json.load(file)
    results = data.get("results", [])

iterations = [result["numberOfIterations"] for result in results]
elapsed_times = [result["elapsedTime"] for result in results]

plt.plot(iterations, elapsed_times, marker='o', linestyle='-')
plt.title('Dependence of time on the number of trajectories')
plt.xlabel('m, trajectories')
plt.ylabel('t, time')
plt.grid(True)
plt.show()
