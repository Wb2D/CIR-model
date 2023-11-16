import json
import matplotlib
import matplotlib.pyplot as plt
matplotlib.use('Qt5Agg')

with open('C:\\Qt\Projects\\build-CIR-Desktop_Qt_5_12_12_MinGW_64_bit-Debug\\test1.json') as file:
    data = json.load(file)

trajectories = {}
plt.figure()

for traj in data['trajectories']:
    traj_id = traj['trajectory_id']
    if traj_id not in trajectories:
        trajectories[traj_id] = {'A': [], 'B': []}
    trajectories[traj_id]['A'] = traj['data']
    plt.plot(trajectories[traj_id]['A'], label=f'Trajectory {traj_id + 1}', linewidth=1)

plt.title('Simulation of CIR Model Trajectories')
plt.xlabel('t, Time')
plt.ylabel('r(t), dividend')
plt.legend()

plt.xticks([tick for tick in plt.xticks()[0] if 0 <= tick <= 1000],
          [str(int(tick) * 3 / 1000) for tick in plt.xticks()[0] if 0 <= tick <= 1000])

plt.show()
