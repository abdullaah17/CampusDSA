import random

secretNum = random.randint(1,100)
attempts = 0

print("Guess the number between 1-100")

while True :
    guess = input("Enter your Guess: ")

    if not guess.isdigit():
        print("Numbers only!")
        continue 
    guess = int(guess)

    attempts += 1

    if guess < secretNum:
        print("Too Low!")
    elif guess > secretNum:
        print("Too High!")
    else: 
        print("Right")
        break