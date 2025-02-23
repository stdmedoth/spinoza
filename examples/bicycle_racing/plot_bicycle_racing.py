import sys

import pandas as pd
import matplotlib.pyplot as plt

# Read CSV file
data = pd.read_csv(sys.argv[1])

# Plot the data
plt.plot(data['x'], data['y'])

# Add titles and labels
plt.title('Graph of X vs Y')
plt.xlabel('x')
plt.ylabel('y')

# Show the plot
plt.show()

