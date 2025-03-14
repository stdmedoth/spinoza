import pandas as pd
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import glob

# Ler todos os arquivos CSV de corpos
files = sorted(glob.glob('body-*.dat'))

# Ler os dados de cada arquivo
bodies_data = [pd.read_csv(file) for file in files]

# Verificar se as colunas estão corretas
for data in bodies_data:
    if not {'x', 'y'}.issubset(data.columns):
        raise ValueError('Os arquivos CSV devem conter as colunas "x" e "y"')

# Criar a figura e o eixo
fig, ax = plt.subplots()

# Determinar os limites para manter todos os corpos visíveis
ax.set_xlim(-1000, 1000)
ax.set_ylim(-1000, 1000)

# Criar listas para corpos e rastros
bodies = []
trails = []
trail_data = []
trail_length = 10

colors = ['r', 'b', 'g', 'm', 'c', 'y']  # Lista de cores para os corpos

# Inicializar corpos e rastros
for i, data in enumerate(bodies_data):
    color = colors[i % len(colors)]
    body, = ax.plot([], [], f'{color}o', label=f'Corpo {i+1}')
    trail, = ax.plot([], [], f'{color}-', alpha=0.5)
    bodies.append(body)
    trails.append(trail)
    trail_data.append([])

# Inicializar a animação
def init():
    for body, trail in zip(bodies, trails):
        body.set_data([], [])
        trail.set_data([], [])
    return bodies + trails

# Atualizar a animação
def update(frame):
    min_x, max_x = float('inf'), float('-inf')
    min_y, max_y = float('inf'), float('-inf')

    for i, data in enumerate(bodies_data):
        if frame < len(data):
            x, y = data['x'].iloc[frame], data['y'].iloc[frame]
            bodies[i].set_data(x, y)
            trail_data[i].append((x, y))
            if len(trail_data[i]) > trail_length:
                trail_data[i].pop(0)
            min_x, max_x = min(min_x, x), max(max_x, x)
            min_y, max_y = min(min_y, y), max(max_y, y)

    for i, trail in enumerate(trails):
        if trail_data[i]:
            trail.set_data(*zip(*trail_data[i]))

    return bodies + trails

# Determinar o número de frames com base no maior arquivo
frames = max(len(data) for data in bodies_data)

# Criar a animação
ani = FuncAnimation(fig, update, frames=frames, init_func=init, blit=True, interval=1)

plt.legend()
plt.show()
