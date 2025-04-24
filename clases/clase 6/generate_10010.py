import random
import string

# Constants
ROWS, COLS = 100, 100
DIRECTIONS = [
    (-1, 0),
    (1, 0),  # vertical
    (0, -1),
    (0, 1),  # horizontal
    (-1, -1),
    (-1, 1),
    (1, -1),
    (1, 1),  # diagonal
]
CONSONANTS = "".join(set(string.ascii_uppercase) - set("AEIOU"))


def create_empty_grid(rows, cols):
    return [[" " for _ in range(cols)] for _ in range(rows)]


def can_place(grid, word, row, col, dr, dc):
    for i in range(len(word)):
        r, c = row + dr * i, col + dc * i
        if not (0 <= r < ROWS and 0 <= c < COLS):
            return False
        if grid[r][c] != " " and grid[r][c] != word[i]:
            return False
    return True


def place_word(grid, word):
    attempts = 1000
    while attempts > 0:
        row = random.randint(0, ROWS - 1)
        col = random.randint(0, COLS - 1)
        dr, dc = random.choice(DIRECTIONS)
        if can_place(grid, word, row, col, dr, dc):
            for i in range(len(word)):
                grid[row + dr * i][col + dc * i] = word[i]
            return True
        attempts -= 1
    return False


def fill_with_consonants(grid):
    for r in range(ROWS):
        for c in range(COLS):
            if grid[r][c] == " ":
                grid[r][c] = random.choice(CONSONANTS)


def print_grid(grid):
    for row in grid:
        print("".join(row))


# Example 20 words
words = [
    "computador",
    "mouse",
    "teclado",
    "audifonos",
    "lapiz",
    "cuaderno",
    "fideos",
    "cafe",
    "verde",
    "informacion",
    "data",
    "plumon",
    "perro",
    "alerce",
    "pajaro",
    "pescado",
    "lobo",
    "mercado",
    "pendulo",
    "agua",
    # 10
    "universidad",
    "diversidad",
    "politica",
    "estudiantes",
    "docentes",
    "funcionarios",
    "lluvia",
    "bicicleta",
    "televisor",
    "internet",
]

# Normalize to uppercase
words = [w.upper() for w in words]

# Create and fill grid
grid = create_empty_grid(ROWS, COLS)
for word in words:
    if not place_word(grid, word):
        print(f"Failed to place word: {word}")

print_grid(grid)
print("\n\n")

fill_with_consonants(grid)
print_grid(grid)
