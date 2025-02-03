#! python3

import math

# Ensure this is the same as in frame.c
TILES_TO_DRAW_COUNT = 110

# Function to calculate the distance from the origin
def distance_from_origin(x, y):
    return math.sqrt(x**2 + 0.4 * (y + 0.49)**2)

# Generate coordinate pairs and their distances
coordinates = []
for x in range(-20, 21):
    for y in range(-20, 21):
        # Apply the filter condition
        if y >= abs(x) * 0.5 - 2:
            coordinates.append((x, y, distance_from_origin(x, y)))

# Sort coordinates by their distance from the origin
sorted_coordinates = sorted(coordinates, key=lambda coord: coord[2])

# Extract the first coordinate pairs
first_coordinates = sorted_coordinates[:TILES_TO_DRAW_COUNT]

## Print the coordinate pairs
#for index, (x, y, dist) in enumerate(first_coordinates, start=1):
#    print(f"{index}: ({x}, {y}) ({distance_from_origin(x, y)})")

print('struct TILE_REL_COORDS lookahead_tiles_supersight[TILES_TO_DRAW_COUNT] = {')
u = ',\n'.join([f'{{ {c[0]:3}, {c[1]:3} }}' for c in reversed(first_coordinates)])
print(u)
print('};')
