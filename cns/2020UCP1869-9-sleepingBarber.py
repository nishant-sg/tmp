import threading
import time

waiting_room = threading.Semaphore(10)
barber_chair = threading.Semaphore(1)
customers = 0

def barber():
    global customers
    while True:
        # wait for a customer to enter the waiting room
        waiting_room.acquire()
        customers -= 1
        
        # wake up the barber
        barber_chair.release()
        
        # cut hair
        print("Barber is cutting hair")
        time.sleep(2)
        
        # release the barber's chair
        barber_chair.acquire()
        waiting_room.release()
        
def customer():
    global customers
    while True:
        # wait for a seat in the waiting room
        waiting_room.acquire()
        customers += 1
        
        # wake up the barber if he's asleep
        if customers == 1:
            barber_chair.acquire()
        
        # release the waiting room seat
        waiting_room.release()
        
        # get a haircut
        print("Customer is getting a haircut")
        time.sleep(1)
        
        # leave the barber shop
        if customers == 0:
            barber_chair.release()

# create a barber thread
barber_thread = threading.Thread(target=barber)
barber_thread.start()

# create 10 customer threads
for i in range(10):
    customer_thread = threading.Thread(target=customer)
    customer_thread.start()