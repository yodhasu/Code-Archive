import os

class BackpackItem:
    def __init__(self, itemID, amm):
        self.itemID = itemID
        self.val = amm
        self.next = None
        self.prev = None


def input_item(item, amm):
    global head, tail, curr
    new_item = BackpackItem(item, amm)

    if head is None:
        head = tail = new_item
        head.prev = None
        tail.next = None
    else:
        curr = head
        while curr.itemID != item:
            curr = curr.next
            if curr is None:
                curr = tail
                break

        if curr.itemID == item:
            curr.val += amm
        else:
            tail.next = new_item
            new_item.prev = tail
            tail = new_item
            tail.next = None


def del_all():
    global head, curr
    while head is not None:
        curr = head
        head = head.next
        del curr


def del_head():
    global head, tail, curr
    if head is None:
        print("Backpack empty!")
    else:
        if head == tail:
            del head
            del tail
        else:
            curr = head
            head = head.next
            del curr
            head.prev = None


def del_tail():
    global head, tail, curr
    if head is None:
        print("Backpack empty!")
    else:
        if head == tail:
            del head
            del tail
        else:
            curr = tail
            tail = tail.prev
            del curr
            tail.next = None


def del_select(item):
    global head, tail, curr
    deleted = 0
    curr = head
    while curr.itemID != item:
        curr = curr.next
        if curr is None:
            return deleted

    if curr.val > 1:
        curr.val -= 1
    else:
        if head == tail:
            del head
            del tail
            head = None
            tail = None
        elif curr == head:
            del_head()
        elif curr == tail:
            del_tail()
        else:
            curr.prev.next = curr.next
            del curr
    return 1


def open_backpack(open_val):
    global head, tail, curr
    if open_val != 0:
        count = 1
        curr = head
        if head is None:
            print("Backpack is empty!")
            return
        print("No.\tItem Ammount\t\tItem ID\n\n")
        while curr is not None:
            print(f"{count}.\t{curr.val}\t\t\t{curr.itemID}\n\n")
            curr = curr.next
            count += 1


def open_backpack_reverse(open_val):
    global head, tail, curr
    if open_val != 0:
        count = 1
        curr = tail
        if tail is None or head is None:
            print("Backpack is empty!")
            return
        print("No.\tItem Ammount\t\tItem ID\n\n")
        while curr is not None:
            print(f"{count}.\t{curr.val}\t\t\t{curr.itemID}\n\n")
            curr = curr.prev
            count += 1


def menu():
    print("1. Add Items")
    print("2. Open/Close Backpack")
    print("3. Delete")
    print("4. Reverse Backpack List")
    print("5. Exit")

def delMenu():
    print("1. Delete selected item ammount from backpack")
    print("2. Empty backpack")
    print("3. Cancel")


head = None
tail = None
curr = None

count = 0
open_val = 0
flag = 0

while True:
    os.system('cls')
    if count == 20:
        print("Backpack is full!")
    print("Backpack menu:")
    if flag == 0:
        open_backpack(open_val)
    else:
        open_backpack_reverse(open_val)
    print("Item in backpack:", count, "\n")
    menu()
    try:
        input_val = int(input("Input menu: "))
    
    except:
        input("Menu not available...")
        continue
    
    if input_val == 1:
        if count == 20:
            print("Backpack is full!")
        else:
            itemID = input("Input item ID: ").lower()
            try:
                itemAmmount = int(input("Input ammount: "))
            except:
                input("Item ammount must be in integer...")
                continue
            count += itemAmmount
            if count > 20:
                input("Input failed! Backpack is full!")
                count -= itemAmmount
            else:
                input_item(itemID, itemAmmount)
                input("Item added!")
    elif input_val == 2:
        open_val = 1 if open_val == 0 else 0
    elif input_val == 3:
        
        if count == 0:
            input("Backpack is empty!")
        else:
            delMenu()
            try:
                select = int(input("Input menu: "))
            except:
                input("Menu not available, canceling deletion...")
                continue

            if select != 1:
                del_all()
                input("Backpack cleared!")
                continue
            
            else:
                itemID = input("Input item ID: ").lower()
                del_status = del_select(itemID)
                if del_status != 0:
                    input("Item deleted!")
                    count -= 1
                else:
                    input("Item not exist!")
    elif input_val == 4:
        flag = 1 if flag == 0 else 0
    elif input_val == 5:
        break
    else:
        input("Menu not available...")
    #input("Press Enter to continue...")
