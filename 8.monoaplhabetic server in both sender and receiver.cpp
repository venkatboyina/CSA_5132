def generate_cipher_sequence(keyword):
keyword = keyword.upper()
alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
cipher_sequence = ""
for char in keyword:
if char not in cipher_sequence:
cipher_sequence += char
for char in alphabet:
if char not in cipher_sequence:
cipher_sequence += char
return cipher_sequence
def encrypt(plain_text, cipher_sequence):
plain_text = plain_text.upper()
encrypted_text = ""
for char in plain_text:
if char.isalpha():
index = ord(char) - ord('A')
encrypted_text += cipher_sequence[index] else:
encrypted_text += char
return encrypted_text
def decrypt(encrypted_text,
cipher_sequence): encrypted_text =
encrypted_text.upper()
decrypted_text = ""
for char in encrypted_text:
if char.isalpha():
index = cipher_sequence.index(char)
decrypted_text += chr(index + ord('A')) else:
decrypted_text += char
return decrypted_text
keyword = "CIPHER"
cipher_sequence =
generate_cipher_sequence(keyword) plain_text = "helloworld"
encrypted_text = encrypt(plain_text, cipher_sequence)
decrypted_text = decrypt(encrypted_text,
cipher_sequence) print("Plain Text:", plain_text)
print("Cipher:", encrypted_text)
print("Decrypted Text:", decrypted_text)
