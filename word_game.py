# pesudocode:
"""
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


pirnt score board --> formated
clear screan option
"""

# start the program
import random
import os

sets = {
    "sponge bob": [
        "sponge bob",
        "squidward",
        "patrick",
        "sandy",
        "mr. krabs",
        "plankton",
        "larry",
    ],
    "alice in wonderland": [
        "alice",
        "white rabbit",
        "queen of hearts",
        "mad hatter",
        "cheshire cat",
        "caterpillar",
        "tweedledee",
        "tweedledum",
        "knave of hearts",
        "white queen",
        "red queen",
    ],
    "spiderman": [
        "spiderman",
        "gwen",
        "peter parker",
        "aunt may",
        "uncle ben",
        "doctor octopus",
    ],
}


# menu:
def print_menu():
    print("                  Menu\n")
    print("********************************************")
    # each list of word selection
    print("press number of letters you want to guess: ")
    print("********************************************")
    print("|           1: Sponge Bob theme            |")
    print("|           2: Alice in Wonderland theme   |")
    print("|           3: Spiderman theme             |")
    print("|           4: random theme                |")
    # a scoreboard option (You must decide how to score your game)
    print("|           5: scoreboard                  |")
    # instructions:
    print("|           6: instructions                |")
    # clear screen
    print("|           7: clear screen                |")
    # an Exit Option
    print("|           0: Exit                        |")
    print("********************************************")


def case(choice):  # based on choice of dict, get a random word from it
    cat = " "  # get the choice of
    if choice == 1:
        cat = "sponge bob"
        print("theme choosen: ", cat)  # give the user the theme they choose

    elif choice == 2:
        cat = "alice in wonderland"
        print("theme choosen: ", cat)  # give the user the theme they choose

    elif choice == 3:
        cat = "spiderman"
        print("theme choosen: ", cat)  # give the user the theme they choose

    elif choice == 4:
        # random
        choice = random.randint(1, 3)  # get a random choice
        cat = case(choice)  # recall
        print("theme choosen: ", cat)  # give the user the theme they choose

    elif choice == 5:  # scoreboard
        printscore()
        # stop the function as the user is not guessing, thus no need for cat
    elif choice == 6:
        # instruction
        print("              instructions:")
        print("guess the random word that is selected")
        print("all words are in lower case")
        print("you can guess: \n One letter at a time or the whole word at once\n")
        print("score: length of the word - the tries you had\n")
    elif choice == 7:
        os.system("clear")

    return cat  # return the theme choosen if one is choosen


def single(
    word, letter, tries
):  # check if a single letter is in the word and get the index
    find = False
    for i in range(len(word)):  # check guess letter for every letter in random word
        if letter != " ":  # ignore space
            if letter == word[i]:  # if the letter matches with any letter form word
                print("the letter", letter, "is the ", i + 1, "th place")
                find = True  # the letter is found at least once

    if find == False:  # the letter was never found
        print("the letter", letter, "is not in the word")

    return find


def lines(word):  # print underscore for vision
    for num in range(len(word)):
        print("_", end="")


def guess(word):
    print("the length is: ", len(word))

    find = False  # initiallizing find for every round
    tries = len(word) - 1  # initiallizing tries for every round

    while (find == False) and (tries != 0):  # while the word is not found
        print("you have: ", tries, "tries")
        # lines(word)
        guess = input("inter guess: ")

        if len(guess) == 1:
            # single letter guess
            singlefind = single(word, guess, tries)
            if singlefind == False:
                tries -= 1

        elif len(guess) == len(word):
            # whole word guess
            if guess == word:
                find = True
            else:
                # lenght of guess does not match critieria
                print("wrong word")  # wrong word but still check for right letters
                for each in range(len(guess)):  # check each letter
                    letter = guess[each]
                    single(word, letter, tries)  # call the function for each letter
                tries -= 1
        else:
            print("you should re-read the instructions :(")
            tries -= 1  # still take off 1 try
            print("either single letters or whole word")

    result(find, word, tries)  # when the game ended, call function result


def scoreboard(tries):  # add name and score to txt file, only if the user wins
    # get score and name
    score = tries  # set score for each individual
    name = input("name: ")  # get user name as told
    print("your score is: ", score)  # output score

    # apend info in txt file
    with open("scoreboard.txt", "a") as file:  # open file
        file.write(f"{name}: {score}\n")
    file.close()  # close file


# output the sorted score board
def printscore():
    try:
        with open("scoreboard.txt", "r") as file:
            scores = [line.strip().split(": ") for line in file.readlines()]
            scores.sort(key=lambda x: int(x[1]), reverse=True)  # formula from world cup
            print("Scores: ")
            for score in scores:
                if score == 10:
                    return  # only output the first 10 if there is more
                print(f"{score[0]}: {score[1]}")  # output statement
    except FileNotFoundError:
        print("empty scoreboard")


def result(find, word, tries):
    if find == True:  # when win
        print("the right word is ", word)  # prompt right word and tries
        print("you did it in ", len(word) - tries, "tries")
        scoreboard(tries)  # enter name and score into txt

    else:  # when lost
        print("the right word is ", word)  # prompt right word


# print menu --> get input [check input (type and range) --> check 0] --> process input --> print menu again and get new input
def main():
    print_menu()
    choice = 1
    while choice != 0:
        choice = input("choice: ")  # get choice as string
        # choice = check(choice) # check type (integer) and range (0 - 5)
        while choice.isnumeric() == False or int(choice) > 7 or int(choice) < 0:
            choice = input("not valid, input again: ")
        choice = int(choice)

        if choice >= 1 and choice <= 4:  # if the user wants to guess
            print("Game starts:")  # game start prompt
            cat = case(choice)  # cat --> dictonary choosen
            word = random.choice(sets[cat])
            guess(word)

        else:  # when user input 5 or 6
            cat = case(choice)

    print("exit")  # exit prompt
    print("thank you for playing")
    return ()


main()
