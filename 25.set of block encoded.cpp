import math<stdio.h>
def gcd(a, b):
while b:
a, b = b, a % b
return a
def common_factor_attack(n, e, blocks):
common_factor = None
for i in range(len(blocks)):
for j in range(i + 1, len(blocks)):
if gcd(blocks[i], n) != 1 and gcd(blocks[j], n) != 1:
common_factor = gcd(blocks[i], n)
break
if common_factor:
p = common_factor
q = n // p
phi = (p - 1) * (q - 1)
d = pow(e, -1, phi) 
phi
plaintext_blocks = [pow(block, d, n) for block in blocks]
return plaintext_blocks
else:
return None

n = 3233 
e = 17 
blocks = [1791, 123, 2509, 1281] 
plaintext_blocks = common_factor_attack(n, e, blocks)
if plaintext_blocks:
print("Plaintext blocks:", plaintext_blocks)
else:
print("No common factor found.")
