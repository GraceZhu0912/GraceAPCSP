# pesudocode:
'''
functions:
print menu
get choice
based on chioce, go to different places (case)
guessing game (check letters etc. )
store score and print (if wins)

0 - exit
1,2,3 - dictionary to guess (sponge bob, Alice in wonderland, spiderman)

1,2,3:
chance = n - 1
randomly choose 1 word from the dictionary
tell the user the no. of letters
for n -1:
    let the user guess
if the guess is one letter:
    check like hangman
elif the guess is multiple letters & same no. of letters
    check like wordo
else
    reject it

if user guess it before change = 0 aka wins
    get name
    calculate score
    store score into another dirctionary
    print the directionary

format of scoreboard:
[name]: [score]

'''

# start the program
import random

sets = {
    "sponge_bob": ["sponge bob", "squidward", "patrick", "sandy", "mr. krabs", "plankton", "larry"],
    "alice_in_wonderland": ["alice", "alice", "white rabbit", "queen of hearts", "mad hatter", "cheshire cat", "caterpillar", "tweedledee", "tweedledum", "knave of hearts", "white queen", "red queen"],
    "spiderman": ["spiderman", "gwen", "peter parker", "aunt may", "uncle ben", "doctor octopus"]
}

# menu:
def print_menu():
    print("Menu\n")
    print("********************************************")

    # instruction
    print("instructions:")
    print("guess the random word that is selected")
    print("all words are in lower case")
    print("you can guess: \n One letter at a time or the whole word at once\n\n")
    print("score: length of the word - the tries you had\n\n")

    #each list of word selection
    print("press number of letters you want to guess: ")
    print("********************************************\n")
    print("1: Sponge Bob theme")
    print("2: Alice in Wonderland theme")
    print("3: Spiderman theme")
    print("4: random theme")
    #a scoreboard option (You must decide how to score your game)
    print("5: scoreboard")

    #an Exit Option
    print("Exit: 0\n\n")

def case(choice): # based on choice of dict, get a random word from it
    cat = " " # get the choice of
    if choice == 1:
        cat = "sponge_bob"

    elif choice == 2:
        cat = "alice_in_wonderland"

    elif choice == 3:
        cat = "Spiderman"

    elif choice == 4:
        # random
        choice = random.randint(1,3) # get a random choice
        cat = case(choice) # recall

    elif choice == 5: # scoreboard
        printscore()
        # stop the function as the user is not guessing, thus no need for cat

    print("theme choosen: ", cat) # give the user the theme they choose
    return cat # return the theme choosen if one is choosen

def single(word, letter): # check if a single letter is in the word and get the index
    find = False
    for i in range (len(word)): # check guess letter for every letter in random word
        if letter != " ": # ignore space
            if letter == word[i]: # if the letter matches with any letter form word
                print("the letter", letter, "is the ", i + 1, "th place")
                find = True # the letter is found at least once

    if find == False: # the letter was never found
        print("the letter", letter, "is not in the word")

def lines(word): # print underscore for vision
    for num in range (len(word)):
        print("_", end = "")

def guess(word):
    print("the length is: ", len(word))

    find = False # initiallizing find for every round
    tries = len(word) - 1 # initiallizing tries for every round

    while (find == False) and (tries != 0): # while the word is not found
        print("you have: ",tries, "tries")
        # lines(word)
        guess = input("inter guess: ")

        if len(guess) == 1:
            # single letter guess
            single(word, guess)
            tries -=1

        elif len(guess) == len(word):
            # whole word guess
            if guess == word:
                find = True

            else:
            # lenght of guess does not match critieria
                print("wrong word") # wrong word but still check for right letters
                for each in range (len(guess)): # check each letter
                    letter = guess[each]
                    single(word, letter) # call the function for each letter
                tries -= 1

        else:
            print("you should re-read the instructions :(")
            tries -= 1 # still take off 1 try
            print("either single letters or whole word")

    result(find, word, tries) # when the game ended, call function result


def scoreboard(tries): # add name and score to txt file, only if the user wins
    # get score and name
    score = 1 + tries # set score for each individual
    name = input("name: ") # get user name as told
    print("your score is: ", score) # output score

    # apend info in txt file
    with open("scoreboard.txt", "a") as file: # open file
        # append informations
        file.write(name)
        file.write(":")
        file.write(str(score))
        file.write("\n")

    file.close() #close file

def printscore():
    score = {} # declear local dictionary

    with open("scoreboard.txt", "r") as file:  # open file in read mode
        for line in file:
            key, value = line.strip().split(":")
            score[key] = value # input the value inside the dictionary
    file.close() # close life
    # print(score)

    # sort the dictionary based on score
    # Bubble sort
    temp = {}
    for i in range(len(score)): # for every item
        print("i = ", i)
        for j in range (len(score) - i - 1): # do:
            print("j = ", j)
            if score[j][0] < score[j+1][0]:
                temp = score[j]
                score[j] = score[j+1]
                score[j+1] = temp

    # output the score
    for key, value in score.items():
        print(key, ':', value)

def result(find, word, tries):
    if find == True: # when win
        print("YES! the right word is ", word) #prompt right word and tries
        print("you did it in ", tries, "tries")
        scoreboard(tries) # enter name and score into txt

    else: # when lost
        print("NO! you ran out of tries!")
        print("the right word is ", word) # prompt right word

# check functions
def check(choice):
    check = True # set bool value for looping
    while check: # start loop until choice is in right form
        try:
            # if (choice.numeric()) and (int(choice) >= 0) and (int(choice) <= 5): # checks
            if (int(choice) >= 0) and (int(choice) <= 5) and (choice.isdigit()):
                check = False # exit loop
        except:
            print("incorrect input, try again") # prompt and re-enter
            choice = input("choice:")
    return choice # return right form of chioce

def checkzero(choice):
    check = False
    if choice == "0": # choice is in string form
        check = True
    return check

print_menu() # first round
choice = input("choice: ") # get choice as string

while checkzero(choice) == False: # in case choice is not 0, choice = false
    choice = check(choice) # check type (integer) and range (0 - 5)
    choice = int(choice) # convert choice into int

    if choice >= 1 and choice <= 4: # if the user wants to guess
        print("Game starts:") # game start prompt
        cat = case(choice) # cat --> dictonary choosen
        word = random.choice(sets[cat])
        guess(word)

    else: # when user input 5, scoreboard
        cat = case(choice)


    print_menu() # second round
    choice = input("choice:")

print("exit") # exit prompt
print("thank you for playing")
