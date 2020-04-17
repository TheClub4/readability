text = input("Text: ")

# Number of words in text
word_count = len(text.split())

# Number of letters in text
letter_count = 0
for letters in text:
    if letters.isalpha():                        # only consider alphabetical characters
        letter_count = letter_count + 1
    else:
        pass

# Number of sentences in text
sentences_count = 0
for i in text:
    sentences_count += i.count('.') + i.count('!') + i.count('?')

# Coleman-Liau index
L = (letter_count / word_count) * 100
S = (sentences_count / word_count) * 100
index = round(0.0588 * L - 0.296 * S - 15.8)

if index < 1:
    print("Before Grade 1")
elif index > 16:
    print("Grade 16+")
else:
    print("Grade %s" % index)