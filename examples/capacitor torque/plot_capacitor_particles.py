import pandas as pd
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
from mpl_toolkits.mplot3d import Axes3D
import glob
import numpy as np

# Read data files
files = sorted(glob.glob('body-position-*.dat'))
bodies_data = [pd.read_csv(file) for file in files]

# Verify required columns exist
for i, data in enumerate(bodies_data):
    if not {'x', 'y', 'z'}.issubset(data.columns):
        raise ValueError(f'File {files[i]} must contain "x", "y", and "z" columns')

# Setup 3D plot
fig = plt.figure(figsize=(10, 8))
ax = fig.add_subplot(111, projection='3d')
ax.set_xlim(-1000, 1000)
ax.set_ylim(-1000, 1000)
ax.set_zlim(-1000, 1000)

# Create body artists
colors = plt.cm.rainbow(np.linspace(0, 1, len(bodies_data)))
bodies = []
for i, c in enumerate(colors):
    # Plot and store the artist object (only the first one, safely)
    artist, = ax.plot([], [], [], 'o', color=c, markersize=8, )
    bodies.append(artist)

# Initialize function
def init():
    empty = np.array([])
    for body in bodies:
        body.set_data(empty, empty)
        body.set_3d_properties(empty)
    return bodies

def update(frame):
    for i, body in enumerate(bodies):
        if frame < len(bodies_data[i]):
            row = bodies_data[i].iloc[frame]
            x, y, z = row['x'], row['y'], row['z']
            body.set_data(np.array([x]), np.array([y]))
            body.set_3d_properties(np.array([z]))  # ✅ FIXED
    return bodies


# Create animation
ani = FuncAnimation(
    fig,
    update,
    frames=min(len(data) for data in bodies_data),
    init_func=init,
    blit=True,  # ✅ NOW safe to use
    interval=1,
    repeat=True
)

# Labels and legend
ax.set_xlabel('X Axis')
ax.set_ylabel('Y Axis')
ax.set_zlabel('Z Axis')
ax.legend()
ax.set_title('Simplified 3D Orbital Simulation')

plt.tight_layout()
plt.show()
