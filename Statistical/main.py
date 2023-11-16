import json
import numpy as np
from scipy.stats import skew, kurtosis, skewtest, kurtosistest


def calculate_stats(data):
    trajectory_stats = []
    for i, traj in enumerate(data["trajectories"]):
        trajectory_data = np.array(traj["data"])
        mean_value = np.mean(trajectory_data)
        variance_value = np.var(trajectory_data)
        std_deviation = np.std(trajectory_data)
        coefficient_of_variation = std_deviation / mean_value if mean_value != 0 else 0
        percentile_25 = np.percentile(trajectory_data, 25)
        percentile_50 = np.percentile(trajectory_data, 50)
        percentile_75 = np.percentile(trajectory_data, 75)
        iqr = np.percentile(trajectory_data, 75) - np.percentile(trajectory_data, 25)

        # асимметрию и эксцесс
        skewness = skew(trajectory_data)
        kurt = kurtosis(trajectory_data)

        # тесты на асимметрию и эксцесс
        skewness_test_statistic, skewness_p_value = skewtest(trajectory_data)
        kurtosis_test_statistic, kurtosis_p_value = kurtosistest(trajectory_data)

        trajectory_stats.append({
            "trajectory_id": i,
            "mean": mean_value,
            "variance": variance_value,
            "std_deviation": std_deviation,
            "coefficient_of_variation": coefficient_of_variation,
            "percentile_25": percentile_25,
            "percentile_50": percentile_50,
            "percentile_75": percentile_75,
            "iqr": iqr,
            "skewness": skewness,
            "kurtosis": kurt,
            "skewness_test_statistic": skewness_test_statistic,
            "skewness_p_value": skewness_p_value,
            "kurtosis_test_statistic": kurtosis_test_statistic,
            "kurtosis_p_value": kurtosis_p_value
        })
    return trajectory_stats


input_file_path = "C:\Qt\Projects\\build-CIR-Desktop_Qt_5_12_12_MinGW_64_bit-Debug\\test1.json"
output_file_path = "C:\Qt\Projects\\build-CIR-Desktop_Qt_5_12_12_MinGW_64_bit-Debug\\test2.json"

with open(input_file_path, 'r') as file:
    json_data = json.load(file)

stats = calculate_stats(json_data)

output_json = {
    "trajectory_stats": stats
}

with open(output_file_path, 'w') as output_file:
    json.dump(output_json, output_file, indent=2)

print(f"success!")
