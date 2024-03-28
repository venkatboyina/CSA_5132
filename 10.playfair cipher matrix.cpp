def create_playfair_matrix(key):
key += ''.join(chr(65 + i) for i in range(25) if chr(65 + i) not in key and chr(65 + i) != 'J')
matrix = [list(key[i:i+5]) for i in range(0, 25, 5)]
return matrix
def encrypt_message(matrix, message):
message = [message[i:i+2] if i + 1 < len(message) else message[i:i+1] for i in range(0, len(message),
2)]
def find_coordinates(c):
for row, row_vals in enumerate(matrix):
if c in row_vals:
return row, row_vals.index(c)
return None, None
encrypted = ''
for pair in message:
r1, c1 = find_coordinates(pair[0])
r2, c2 = find_coordinates(pair[1]) if len(pair) == 2 else (r1, c1)
if r1 is not None and r2 is not None and c1 is not None and c2 is not None: if
r1 == r2:
encrypted += matrix[r1][(c1 + 1) % 5] + matrix[r2][(c2 + 1) % 5]
elif c1 == c2:
encrypted += matrix[(r1 + 1) % 5][c1] + matrix[(r2 + 1) % 5][c2]
else:
encrypted += matrix[r1][c2] + matrix[r2][c1]
else:
encrypted += pair
return encrypted
def main():
key = "MFHIJKUNOPQZVWXYELARGDSTBC"
matrix = create_playfair_matrix(key)
message = "MUSTSEEYOUOVERCADOGANWESTCOMINGATONCE"
encrypted = encrypt_message(matrix, message)
print("Original Message:", message)
print("Encrypted Message:", encrypted)
if name == "main":
main()
