import random
name= input("Enter Your Name :- ")
choice= input("Do You Want to Play:- ")
if choice == 'y':
    num = random.randint(0, 100)
    while(1):
        n=eval(input("Guess A Number :-"))
        if num==n:
            print("\tcongratulation You Win %s"%name,end="\n ")
            break;
        elif num<n:
            print("\tOOPS! No Is Greater \n \tTry Again",name,end="\n")
            continue
        elif num>n:
            print("\tOOPS! No Is Less \n\tTry Again", name, end="\n")
            continue

