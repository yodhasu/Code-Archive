from pick import pick
import os
import random as rd

class character:
    def __init__(self, name, hp, armor):
        self.name = name
        self.hp = hp
        self.armor = armor
    
    def health(self, health):
        self.hp = health
    
    def plate(self, plate):
        self.armor = plate

    def __str__(self) -> str:
        return f"  Name: {self.name}\n  Health: {self.hp}\n  Armor: {self.armor}"




Asmodeus = character("Asmodeus", 100, 100)
Samael = character("Samael", 100, 50)
Belial = character("Belial", 150, 0)

def charSelect():
    title = "Choose your character"
    option = ['Asmodeus', 'Samael', 'Belial']
    option, index = pick(option, title)
    choice = str(option)
    return choice

def addHealth(charsel, health):
    if charsel == 'Asmodeus':
        newHealth = Asmodeus.hp + health
        Asmodeus.health(newHealth)
    elif charsel == 'Samael':
        newHealth = Samael.hp + health
        Samael.health(newHealth)
    elif charsel == 'Belial':
        newHealth = Belial.hp + health
        Belial.health(newHealth)

def reducHealth(charsel, health):
    if charsel == 'Asmodeus':
        newHealth = Asmodeus.hp - health
        Asmodeus.health(newHealth)
    elif charsel == 'Samael':
        newHealth = Samael.hp - health
        Samael.health(newHealth)
    elif charsel == 'Belial':
        newHealth = Belial.hp - health
        Belial.health(newHealth)

        
def reducArmor(charsel, plate):
    if charsel == 'Asmodeus':
        newArmor = Asmodeus.armor - plate
        Asmodeus.plate(newArmor)
    elif charsel == 'Samael':
        newArmor = Samael.armor - plate
        Samael.plate(newArmor)
    elif charsel == 'Belial':
        newArmor = Belial.armor - plate
        Belial.plate(newArmor)

def battleopt(enemy, characters):
    title = "Choose your action"
    option = ['Attack', 'Drink random potion']
    option, index = pick(option, title)
    choice = str(option)
    if choice == 'Attack':
        if characters == 'Asmodeus':
            attack = 50
            if Samael.armor != 0:
                attack = attack/2
                reducHealth(enemy, attack)
                reducArmor(enemy, attack)
            else:
                reducHealth(enemy, attack)
        elif characters == 'Samael':
            attack = 25
            if Belial.armor != 0:
                attack = attack/2
                reducHealth(enemy, attack)
                reducArmor(enemy, attack)
            else:
                reducHealth(enemy, attack)
        elif characters == 'Belial':
            attack = 35
            if Asmodeus.armor != 0:
                attack = attack/2
                reducHealth(enemy, attack)
                reducArmor(enemy, attack)
            else:
                reducHealth(enemy, attack)
        return
        
    elif choice == 'Drink random potion':
        potion = rd.randint(1,5)
        return potion

def enemyMove():
    if characters == 'Asmodeus':
        dmg = 25 + 20
        opponent = Asmodeus
    elif characters == 'Samael':
        dmg = 35 + 20
        opponent = Samael
    elif characters == 'Belial':
        dmg = 50 + 20
        opponent = Belial
    
    if enemy == 'Asmodeus':
        initHP = 100
        enchar = Asmodeus
    elif enemy == 'Samael':
        initHP = 100
        enchar = Samael
    elif enemy == 'Belial':
        initHP = 150
        enchar = Belial
    
    move = rd.randint(1, 2)

    if move == 1:
        if opponent.armor > 0:
            dmg = dmg/2
            reducHealth(characters, dmg)
            reducArmor(characters, dmg)
        else:
            reducHealth(characters, dmg)
        potion = 0
        return move, potion
    else:
        potion = rd.randint(1,5)
        if potion == 1:
            while (countturn < 5):
                addHealth(enemy, 5)
            return move, potion
        elif potion == 2:
            while (countturn < 3):
                dmg = dmg*2
            return move, potion
        elif potion == 3:
            return move, potion
        elif potion == 4:
            addHealth(enemy, 50)
            return move, potion
        elif potion == 5:
            turn = turn + 2
            return move, potion


characters = charSelect()

if characters == 'Asmodeus':
    charstats = Asmodeus
elif characters == 'Samael':
    charstats = Samael
elif characters == 'Belial':
    charstats = Belial

if charstats.armor <= 0:
    charstats.armor = 0
stats = 0
countturn = 0
turn = 1
while True:
    print('Turn:', turn)
    if characters == 'Asmodeus':
        enemy = 'Samael'
        print("Your enemy:")
        print(Samael)
        print("Your character:")
        print(Asmodeus)

        if Samael.hp <= 0:
            stats = 1
            break
        elif Asmodeus.hp <= 0:
            break
    elif characters == 'Samael':
        enemy = 'Belial'
        print("Your enemy:")
        print(Belial)
        print("Your character:")
        print(Samael)

        if Belial.hp <= 0:
            stats = 1
            break
        elif Samael.hp <= 0:
            break
    elif characters == 'Belial':
        enemy = 'Asmodeus'
        print("Your enemy:")
        print(Asmodeus)
        print("Your character:")
        print(Belial)
        if Asmodeus.hp <= 0:
            stats = 1
            break
        elif Belial.hp <= 0:
            break
    input("Kill the enemy to win! (Press any key to continue...)")
    #input()
    if turn % 2 == 1:
        potionstats = battleopt(enemy, characters)

        if potionstats == 1:
            while (countturn < 5):
                addHealth(characters, 5)
            print("\nPotion effect:")
            print("Health potion consumed, give 5 health for 5 turns")
        elif potionstats == 2:
            while (countturn < 3):
                attack = attack*2
            print("\nPotion effect:")
            print("Rage potion consumed, double attack for 3 turns")
        elif potionstats == 3:
            print("\nPotion effect:")
            print("Water consumed, no effect")
        elif potionstats == 4:
            addHealth(characters, 50)
            print("\nPotion effect:")
            print("Special item: Dragon Heart consumed, restore 50 health")
        elif potionstats == 5:
            turn = turn + 2
            print("\nPotion effect:")
            print("Alcohol consumed, stunned for 1 turn")
        
    else:
        os.system('cls')
        enemy_move, enemy_potion = enemyMove()
        print('Enemy turn!')
        if enemy_move == 1:
            print(enemy, 'launch an attack!')
        else:
            print(enemy, 'drink a potion!')

            if enemy_potion == 1:
                print("\nPotion effect:")
                print("Health potion consumed, give 5 health for 5 turns")
            elif enemy_potion == 2:
                print("\nPotion effect:")
                print("Rage potion consumed, double attack for 3 turns")
            elif enemy_potion == 3:
                print("\nPotion effect:")
                print("Water consumed, no effect")
            elif enemy_potion == 4:
                print("\nPotion effect:")
                print("Special item: Dragon Heart consumed, restore 50 health")
            elif enemy_potion == 5:
                print("\nPotion effect:")
                print("Alcohol consumed, stunned for 1 turn")
            
        input('Press any key to continue...')
    #Asmodeus.plate(50)
    os.system('cls')
    countturn = countturn + 1
    turn = turn + 1
    continue

os.system('cls')
if stats == 1:
    print("You win")
    print('Total Turn:', turn)
else:
    print("You lose")
    print('Total Turn:', turn)

input()
#health = int(input("Add health by: "))
#addHealth(health)

#os.system('cls')
#if characters == 'Asmodeus':
#    print("Your character:")
#    print(Asmodeus)
#elif characters == 'Samael':
#    print("Your character:")
#    print(Samael)
#elif characters == 'Belial':
#    print("Your character:")
#    print(Belial)

#input()
#choice = 'Asmodeus'
#print(choice.replace("'", ""))
#print(char1, "\n")
#print(char2, "\n")
#print(char3, "\n")