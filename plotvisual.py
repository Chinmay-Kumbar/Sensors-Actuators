import pandas as pd
import matplotlib.pyplot as plt

# Load the CSV data
df = pd.read_csv("sensordata.csv")

# Ensure necessary columns exist
if "ID" not in df.columns or "Temperature" not in df.columns:
    raise ValueError("CSV file must contain 'ID' and 'Temperature' columns!")

# Compute average temperature for each time step
df_avg = df.groupby("ID")["Temperature"].mean().reset_index()
df_avg.rename(columns={"Temperature": "Avg_Temp"}, inplace=True)

# Merge with actions if available
if "Action" in df.columns:
    df_avg = df_avg.merge(df[["ID", "Action"]].drop_duplicates(), on="ID", how="left")

# Extract relevant columns
time = df_avg["ID"]
avg_temp = df_avg["Avg_Temp"]

# Identifing Fan ON and Heater ON conditions
df_avg["Fan_ON"] = (df_avg["Avg_Temp"] > 35).astype(int)
df_avg["Heater_ON"] = (df_avg["Avg_Temp"] < 6).astype(int)

# Create figure
plt.figure(figsize=(12, 6))

# Plot average temperature
plt.plot(time, avg_temp, label="Average Temperature", marker='o', linestyle='-', color="green", zorder=1)

# Highlight Fan ON and Heater ON regions with scatter points
fan_on_indices = df_avg[df_avg["Fan_ON"] == 1].index
heater_on_indices = df_avg[df_avg["Heater_ON"] == 1].index

plt.scatter(time[fan_on_indices], avg_temp[fan_on_indices], color="red", label="Fan ON", zorder=2)
plt.scatter(time[heater_on_indices], avg_temp[heater_on_indices], color="purple", label="Heater ON", zorder=2)

#threshold lines
plt.axhline(y=35, color="red", linestyle="--", label="Upper Threshold (35°C)", zorder=0)
plt.axhline(y=6, color="purple", linestyle="--", label="Lower Threshold (6°C)", zorder=0)

# Shaded regions for Fan and Heater ON
plt.fill_between(time, 35, max(avg_temp), where=(df_avg["Fan_ON"] == 1), color='red', alpha=0.1)
plt.fill_between(time, min(avg_temp), 6, where=(df_avg["Heater_ON"] == 1), color='purple', alpha=0.1)

# Labels, title, and legend
plt.title("Temperature Readings with Fan/Heater Activation")
plt.xlabel("Time (Reading ID)")
plt.ylabel("Temperature (°C)")
plt.legend()
plt.grid(True, linestyle="--", alpha=0.7)

# Show plot
plt.show()
