from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes
from Crypto.Util.Padding import pad

def ecb_encrypt(plaintext, key):
cipher = AES.new(key, AES.MODE_ECB)
ciphertext = cipher.encrypt(plaintext)
return ciphertext

def cbc_encrypt(plaintext, key, iv):
cipher = AES.new(key, AES.MODE_CBC, iv)
ciphertext = cipher.encrypt(plaintext)
return ciphertext

def cfb_encrypt(plaintext, key, iv):
cipher = AES.new(key, AES.MODE_CFB, iv)
ciphertext = cipher.encrypt(plaintext)
return ciphertext
def main():
key = get_random_bytes(16) 
iv = get_random_bytes(16) 
plaintext = b'This is a sample plaintext for encryption.'
block_size = AES.block_size

plaintext = pad(plaintext, block_size)
ecb_ciphertext = ecb_encrypt(plaintext, key)
cbc_ciphertext = cbc_encrypt(plaintext, key, iv)
cfb_ciphertext = cfb_encrypt(plaintext, key, iv)
print("Plaintext:", plaintext)
print("ECB Ciphertext:", ecb_ciphertext.hex())
print("CBC Ciphertext:", cbc_ciphertext.hex())
print("CFB Ciphertext:", cfb_ciphertext.hex())
if name == "main":
main()
