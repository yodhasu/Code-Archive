import random as rd
import os

# 0.0.1
# def encrypt(arr, length, key):
#     for i in range(length):
#         if arr[i] != 32 and arr[i] != 46 and arr[i] != 44 and arr[i] != 63:
#             arr[i] = arr[i] + key[i]
#             if arr[i] > 122:
#                 arr[i] = arr[i] - 122 + 32
            
#     real = [chr(i) for i in arr]
#     print("Encryption key   :  ", key)
#     print("Encrypted string :   "+''.join(real))

# def decrypt(arr, length, decrypt_key):
#     for i in range(length):
#         if arr[i] != 32:
#             if arr[i] < 43:
#                 arr[i] = 122 + (arr[i] - 32) 
#             if arr[i] != 32 and arr[i] != 46 and arr[i] != 44 and arr[i] != 63:
#                 arr[i] = arr[i] - decrypt_key[i]
#     real = [chr(i) for i in arr]
#     print("Decrypted string :   "+''.join(real))

# def encrypt_write(arr, length, key):
#     for i in range(length):
#         if arr[i] != 32:
#             arr[i] = arr[i] + key[i]-key[i]
            
#     real = [chr(i) for i in arr]
#     outfile.write("Encryption key   :  "+''.join(str(key).replace('[', '').replace(']', '').replace(',', ''))+"\n")
#     #print("Encrypted string :   "+''.join(real))1
#     outfile.write("Encrypted string :  "+''.join(real)+"\n")

# def decrypt_write(arr, length, decrypt_key):
#     for i in range(length):
#         if arr[i] != 32:
#             arr[i] = arr[i] - decrypt_key[i]-(decrypt_key[i]-(decrypt_key[i]*2))
#     real = [chr(i) for i in arr]
#     outfile.write("Encryption key   :  "+''.join(str(decrypt_key).replace('[', '').replace(']', '').replace(',', ''))+"\n")
#     outfile.write("Decrypted string :  "+''.join(real)+"\n")


# #real = [chr(i) for i in asc]

# """for i in range(length):
#     asc[i] = str(asc[i])"""
# #default = "C:/Users/user/Documents/gabut/Encrypt/"
# #namedef = "Result.txt"
# symbols = "!\\#$%^&*()_-+=<>:|\{[]}~`"



# while (True):
#     os.system('cls')
#     flag = 0
#     print("=============================")  
#     print("Encrypt/Decrypt string")
#     print("=============================")
#     print("Unusual symbols will automaticly removed!")
#     print("1. Encrypt")
#     print("2. Decrypt")
#     print("Else: exit")
#     num = input()
#     print("=============================")
#     if num == "1":
#         key = []
#         char = input("Input string     :   ")
#         for move in symbols:
#             char = char.replace(move, '')
#         print("=============================")
#         asc = [ord(i) for i in char]
#         length = len(asc)
#         for i in range(length):
#             random = rd.randint(0,9)
#             key.append(random)
#         print("String           :  ", char)
#         encrypt(asc, length, key)

#     elif num == "2":
#         decrypt_key = input("Decryption key needed: ")
#         arr_key = decrypt_key.split()
#         key_len = len(arr_key)
#         for i in range(key_len):
#             arr_key[i] = int(arr_key[i])
#         if decrypt_key != "":
#             char = input("Input string     :   ")
#             print("=============================")
#             asc = [ord(i) for i in char]
#             length = len(asc)
#             print("String           :  ", char)
#             decrypt(asc, length, arr_key)
#     else:
#         print("Menu not availabe!")
#         flag = 1
#     print("=============================")

#     default = ""
#     namedef_enc = "Encrypted.txt"
#     namedef_dec = "Decrypted.txt"

#     if flag == 0:
#         write = input("Write to output file? (Y/y)").lower()

#         if write == "y" and num == "1":
#             dir_change = input("Change output file directory? (Y/y)").lower()
#             if dir_change == "y" and write == "y":
#                 print("Default directory: "+default)
#                 default = input("New directory  : ")

#             name_change = input("Change output file name? (Y/y)").lower()
#             if name_change == "y" and write == "y":
#                 print("Default name: "+namedef_enc)
#                 namedef_enc = input("New file name  : ")
            
#             outfile = open(default+namedef_enc, 'a', encoding='utf-8')
#             outfile.write("============================="+"\n")
#             #outfile.write("String           :  "+char+"\n")
#             encrypt_write(asc, length, key)
#             outfile.write("============================="+"\n")
#             print("Output file edited!")
#             input("Press enter to continue...")
#             outfile.close()

#         elif write == "y" and num == "2":
#             dir_change = input("Change output file directory? (Y/y)").lower()
            
#             if dir_change == "y" and write == "y":
#                 print("Default directory: "+default)
#                 default = input("New directory  : ")
            
            
#             name_change = input("Change output file name? (Y/y)").lower()
            
#             if name_change == "y" and write == "y":
#                 print("Default name: "+namedef_dec)
#                 namedef_dec = input("New file name  : ")
#             outfile = open(default+namedef_dec, 'a', encoding='utf-8')

#             outfile.write("============================="+"\n")
#             #outfile.write("String           :  "+char+"\n")
#             decrypt_write(asc, length, arr_key)
#             outfile.write("============================="+"\n")
#             print("Output file edited!")
#             input("Press enter to continue...")
#             outfile.close()

#         else:
#             choice = input("Rerun? (Y/y)").lower()
#             if choice == "y":
#                 os.system('cls')
#                 continue
#             else:
#                 break
#     else:
#         choice = input("Rerun? (Y/y)").lower()
#         if choice == "y":
#             os.system('cls')
#             continue
#         else:
#             break

# UPDATED to version 0.0.2
# Change log:
# 1. New encryption method
# 2. increase efficiency by removing some function

# 0.0.2

def encrypt(arr, length, key):
    for i in range(length):
        if arr[i] != 32 and arr[i] != 46 and arr[i] != 44 and arr[i] != 63:
            if i % 2 == 0:
                arr[i] = arr[i] + (key[i] + key[i-1])
            else:
                arr[i] = arr[i] + key[i]
        if arr[i] > 123:
            arr[i] = arr[i] - 123 + 32
            
    real = [chr(i) for i in arr]
    # print("Encryption key   :  ", key)
    # print("Encrypted string :   "+''.join(real))
    return real

def decrypt(arr, length, decrypt_key):
    for i in range(length):
        if arr[i] != 32:
            if arr[i] < 43:
                arr[i] = 123 + (arr[i] - 32) 
            if arr[i] != 32 and arr[i] != 46 and arr[i] != 44 and arr[i] != 63:
                if i % 2 == 0:
                    arr[i] = arr[i] - (decrypt_key[i] + decrypt_key[i-1])
                else:
                    arr[i] = arr[i] - decrypt_key[i]
    real = [chr(i) for i in arr]
    # print("Decrypted string :   "+''.join(real))
    return real

#real = [chr(i) for i in asc]

"""for i in range(length):
    asc[i] = str(asc[i])"""
#default = "C:/Users/user/Documents/gabut/Encrypt/"
#namedef = "Result.txt"
symbols = "!\\#$%^&*()_-+=<>:|\{[]}~`"



while (True):
    os.system('cls')
    flag = 0
    print("=============================")  
    print("Encrypt/Decrypt string")
    print("=============================")
    print("Unusual symbols will automaticly removed!")
    print("1. Encrypt")
    print("2. Decrypt")
    print("Else: exit")
    encrypted = []
    decrypted = []
    num = input()
    print("=============================")
    if num == "1":
        key = []
        char = input("Input string     :   ")
        for move in symbols:
            char = char.replace(move, '')
        print("=============================")
        asc = [ord(i) for i in char]
        length = len(asc)
        for i in range(length):
            random = rd.randint(0,9)
            key.append(random)
        
        print("String           :  ", char)
        print("Encryption key   :  ", key)
        encrypted = encrypt(asc, length, key)
        print("Encrypted string :   "+''.join(encrypted))
        #encrypt(asc, length, key)

    elif num == "2":
        decrypt_key = input("Decryption key needed: ")
        arr_key = decrypt_key.split()
        key_len = len(arr_key)
        for i in range(key_len):
            arr_key[i] = int(arr_key[i])
        if decrypt_key != "":
            char = input("Input string     :   ")
            print("=============================")
            asc = [ord(i) for i in char]
            length = len(asc)
            print("String           :  ", char)
            decrypted = decrypt(asc, length, arr_key)
            print("Decrypted string :   "+''.join(decrypted))
            
    else:
        print("Menu not availabe!")
        flag = 1
    print("=============================")

    default = ""
    namedef_enc = "Encrypted.txt"
    namedef_dec = "Decrypted.txt"

    if flag == 0:
        write = input("Write to output file? (Y/y)").lower()

        if write == "y":
            dir_change = input("Change output file directory? (Y/y)").lower()
            name_change = input("Change output file name? (Y/y)").lower()
            if dir_change == "y":
                print("Default directory: "+default)
                default = input("New directory  : ")

            
            if name_change == "y":
                print("Default name: "+namedef_enc)
                namedef_enc = input("New file name  : ")
            
            if num == "1":
                outfile = open(default+namedef_enc, 'a', encoding='utf-8')

                outfile.write("============================="+"\n")
                #outfile.write("String           :  "+char+"\n")
                outfile.write("Encryption key   :  "+''.join(str(key).replace('[', '').replace(']', '').replace(',', ''))+"\n")
                #print("Encrypted string :   "+''.join(real))1
                outfile.write("Encrypted string :  "+''.join(encrypted)+"\n")
                outfile.write("============================="+"\n")
                print("Output file edited!")
                input("Press enter to continue...")
                outfile.close()

            else:
                outfile = open(default+namedef_dec, 'a', encoding='utf-8')

                outfile.write("============================="+"\n")
                #outfile.write("String           :  "+char+"\n")
                outfile.write("Encryption key   :  "+''.join(str(decrypt_key).replace('[', '').replace(']', '').replace(',', ''))+"\n")
                outfile.write("Decrypted string :  "+''.join(decrypted)+"\n")
                
                outfile.write("============================="+"\n")
                print("Output file edited!")
                input("Press enter to continue...")
                outfile.close()

    else:
        choice = input("Rerun? (Y/y)").lower()
        if choice == "y":
            os.system('cls')
            continue
        else:
            break

