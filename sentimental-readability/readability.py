# TODO
from cs50 import get_string

def grade(s):
    letters, words, sentences = 0, 1, 0
    for letter in s:
        if letter <=  'z' and letter >= 'A':
            letters += 1
        if letter == ' ':
            words += 1
        if letter in ('.', '?', '!'):
            sentences += 1
    L, S = letters * 100 / words, sentences * 100 / words
    index = round(0.0588 * L - 0.296 * S - 15.8)
    return index


text = get_string('Text: ')
index = grade(text)
if index < 1:
    print('Before Grade 1')
elif index >= 16:
    print('Grade 16+')
else:
    print(f'Grade {index}')
