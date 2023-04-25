import threading
from time import sleep

balance = 1000

process_number_s1 = 1
lock_s1 = threading.Lock()

P1_inside_s2, P2_inside_s2 = False, False
lock_s2 = threading.Lock()

P1_wants_to_enter_s3, P2_wants_to_enter_s3 = False, False
lock_s3 = threading.Lock()

P1_wants_to_enter_s4, P2_wants_to_enter_s4 = False, False
lock_s4 = threading.Lock()


def withdraw1(w_amt):
    global balance
    temp = balance-w_amt
    sleep(3)
    balance = temp


def deposit1(d_amt):
    global balance
    temp = balance+d_amt
    balance = temp


def withdraw2(w_amt):
    sleep(2)
    global balance
    temp = balance-w_amt
    balance = temp


def deposit2(d_amt):
    global balance
    temp = balance
    temp += d_amt
    sleep(3)
    balance = temp


def withdraw3(w_amt):
    global balance
    temp = balance-w_amt
    balance = temp


def deposit3(d_amt):
    sleep(3)
    global balance
    temp = balance+d_amt
    balance = temp


def withdraw4(w_amt):
    sleep(3)
    global balance
    temp = balance-w_amt
    balance = temp


def deposit4(d_amt):
    sleep(3)
    global balance
    temp = balance+d_amt
    balance = temp


def process1_s1():
    global process_number_s1
    global balance
    while process_number_s1 == 2:
        sleep(1/100000)
    lock_s1.acquire()
    print("Process 1")
    temp = balance
    temp += 300
    balance = temp
    process_number_s1 = 2
    lock_s1.release()
    for ch in "Hello from process1":
        print(ch, end="")
    print()


def process2_s1():
    global process_number_s1
    global balance
    while process_number_s1 == 1:
        sleep(1/100000)
    lock_s1.acquire()
    print("Process 2")
    temp = balance
    temp -= 200
    balance = temp
    process_number_s1 = 1
    lock_s1.release()
    for ch in "Hello from process2":
        print(ch, end="")
    print()


def process1_s2():
    global P1_inside_s2, P2_inside_s2, balance
    while P2_inside_s2:
        sleep(1/100000)
    lock_s2.acquire()
    P1_inside_s2 = True
    print("Process 1")
    temp = balance
    temp += 300
    balance = temp
    P1_inside_s2 = False
    lock_s2.release()
    for ch in "Hello from process1":
        print(ch, end="")
    print()


def process2_s2():
    global P1_inside_s2, P2_inside_s2, balance
    while P1_inside_s2:
        sleep(1/100000)
    lock_s2.acquire()
    P2_inside_s2 = True
    print("Process 2")
    temp = balance
    temp -= 200
    balance = temp
    P2_inside_s2 = False
    lock_s2.release()
    for ch in "Hello from process2":
        print(ch, end="")
    print()


def process1_s3():
    global P1_wants_to_enter_s3, P2_wants_to_enter_s3, balance
    P1_wants_to_enter_s3 = True
    while P2_wants_to_enter_s3:
        sleep(1/100000)
    lock_s3.acquire()
    print("Process 1")
    temp = balance
    temp += 300
    balance = temp
    P1_wants_to_enter_s3 = False
    lock_s3.release()
    for ch in "Hello from process1":
        print(ch, end="")
    print()


def process2_s3():
    global P1_wants_to_enter_s3, P2_wants_to_enter_s3, balance
    P2_wants_to_enter_s3 = True
    while P1_wants_to_enter_s3:
        sleep(1/100000)
    lock_s3.acquire()
    print("Process 2")
    temp = balance
    temp -= 200
    balance = temp
    P2_wants_to_enter_s3 = False
    lock_s3.release()
    for ch in "Hello from process2":
        print(ch, end="")
    print()


def process1_s4():
    global P1_wants_to_enter_s4, P2_wants_to_enter_s4, balance
    P1_wants_to_enter_s4 = True
    while P2_wants_to_enter_s4:
        P1_wants_to_enter_s4 = False
        sleep(0.1)
        P1_wants_to_enter_s4 = True
    lock_s4.acquire()
    print("Process 1")
    temp = balance
    temp += 300
    balance = temp
    P1_wants_to_enter_s4 = False
    lock_s4.release()
    for ch in "Hello from process1":
        print(ch, end="")
    print()


def process2_s4():
    global P1_wants_to_enter_s4, P2_wants_to_enter_s4, balance
    P2_wants_to_enter_s4 = True
    while P1_wants_to_enter_s4:
        P2_wants_to_enter_s4 = False
        sleep(0.1)
        P2_wants_to_enter_s4 = True
    lock_s4.acquire()
    print("Process 2")
    temp = balance
    temp -= 200
    balance = temp
    P2_wants_to_enter_s4 = False
    lock_s4.release()
    for ch in "Hello from process2":
        print(ch, end="")
    print()


# Execution Instance 1
print("***************************")
print("Execution Instance 1")

t11 = threading.Thread(target=withdraw1, args=(200,))
t12 = threading.Thread(target=deposit1, args=(300,))

t11.start()
t12.start()

t11.join()
t12.join()

print("Balance: {}".format(balance))

balance = 1000

# Execution Instance 2
print("***************************")
print("Execution Instance 2")

t21 = threading.Thread(target=withdraw2, args=(200,))
t22 = threading.Thread(target=deposit2, args=(300,))

t21.start()
t22.start()

t21.join()
t22.join()

print("Balance: {}".format(balance))

balance = 1000

# Execution Instance 3
print("***************************")
print("Execution Instance 3")

t31 = threading.Thread(target=withdraw3, args=(200,))
t32 = threading.Thread(target=deposit3, args=(300,))

t31.start()
t32.start()

t31.join()
t32.join()

print("Balance: {}".format(balance))

balance = 1000

# Execution Instance 4
print("***************************")
print("Execution Instance 4")

t41 = threading.Thread(target=withdraw4, args=(200,))
t42 = threading.Thread(target=deposit4, args=(300,))

t41.start()
t42.start()

t41.join()
t42.join()

print("Balance: {}".format(balance))

balance = 1000

# Solution 1 for Critical Section
print("***************************")
print("Solution 1 for Critical Section")

t51 = threading.Thread(target=process1_s1)
t52 = threading.Thread(target=process2_s1)

t51.start()
t52.start()

t51.join()
t52.join()

print("Balance: {}".format(balance))

balance = 1000

# Solution 2 for Critical Section
print("***************************")
print("Solution 2 for Critical Section")

t61 = threading.Thread(target=process1_s2)
t62 = threading.Thread(target=process2_s2)

t61.start()
t62.start()

t61.join()
t62.join()

print("Balance: {}".format(balance))

balance = 1000

# Solution 3 for Critical Section
print("***************************")
print("Solution 3 for Critical Section")

t71 = threading.Thread(target=process1_s3)
t72 = threading.Thread(target=process2_s3)

t71.start()
t72.start()

t71.join()
t72.join()

print("Balance: {}".format(balance))

balance = 1000

# Solution 4 for Critical Section
print("***************************")
print("Solution 4 for Critical Section")

t81 = threading.Thread(target=process1_s4)
t82 = threading.Thread(target=process2_s4)

t81.start()
t82.start()

t81.join()
t82.join()

print("Balance: {}".format(balance))
print("***************************")

