alph = "абвгдежзийклмнопрстуфхцчшщъыьэюя"
sipher_file = 'C:\\Users\\rangv\\PycharmProjects\\pc2.3\\work.txt'

def vigenere_decrypt(ciphertext, key):
    plaintext = ''
    key_len = len(key)
    for i, c in enumerate(ciphertext):
        if not c.isalpha() or ord(c) < 1072 or ord(c) > 1105:
            plaintext += c
            continue
        shift = ord(key[i % key_len]) - ord('а')
        plaintext += chr((ord(c) - 1072 - shift) % 32 + 1072)
    return plaintext


def index_of_coincidence(text):
    freq = [0] * 32
    for c in text:
        if c in alph:
            freq[alph.index(c)] += 1
    coincidence_index = 0.0
    for i in range(len(freq)):
        coincidence_index += freq[i] * (freq[i] - 1)
    coincidence_index /= len(text) * (len(text) - 1)
    return coincidence_index

def guess_key_length(ciphertext):
    coincidence_indices = []
    for i in range(1, min(30, len(ciphertext))):
        coincidence_index = 0
        for j in range(i):
            substring = ''
            k = j
            while k < len(ciphertext):
                substring += ciphertext[k]
                k += i
            coincidence_index += index_of_coincidence(substring)
        coincidence_indices.append((i, coincidence_index / i))
    key_length = sorted(coincidence_indices, key=lambda x: x[1], reverse=True)[0][0]
    return key_length

def count_frequencies(text):
    freqs = {}
    for char in text:
        if char in freqs:
            freqs[char] += 1
        else:
            freqs[char] = 1
    return freqs

def guess_key(ciphertext, key_length):
    key = ''
    for i in range(key_length):
        subtext = ''
        j = i
        while j < len(ciphertext):
            subtext += ciphertext[j]
            j += key_length
        freqs = count_frequencies(subtext)
        sorted_freqs = sorted(freqs.items(), key=lambda x: x[1], reverse=True)
        expected_char = ord('о') - ord('а') - 1072
        shift = (ord(sorted_freqs[0][0]) - expected_char) % 32
        key += chr(shift + 1072 if shift >= 0 else shift + 1104)
    return key

with open(sipher_file, 'r', encoding='utf-8') as f:
    ciphertext = f.read().rstrip()

key_length = guess_key_length(ciphertext)
print('Guessed key length:', key_length)

key = guess_key(ciphertext, key_length)
print('Guessed key:', key)

plaintext = vigenere_decrypt(ciphertext, 'абсолютныйигрок') 
print('Plaintext:', plaintext)