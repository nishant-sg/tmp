def FCFS(requests, initial_head):
    print("\n********** First Come First Serve **************")
    print("Average Rotational Delay: ", avg_rotational_delay,"ms",sep =  '')
    
    time = 0
    for i in requests:
        time += abs(initial_head-i)
        initial_head = i
    return time
    
def C_SCAN(requests, initial_head, tracks):
    print("\n********** C-SCAN **************")
    
    requests.append(initial_head)
    requests.sort()
    index = requests.index(initial_head)
    requests.pop(index)
    
    time = 0
    
    if (initial_head > tracks//2):
        print("Travelling in right direction....")
        for i in range(index, len(requests)):
            time += abs(initial_head-requests[i])
            initial_head = requests[i]
            
        if initial_head != tracks-1:
            time += abs(initial_head-tracks+1)
            initial_head = tracks - 1
            
        time += abs(initial_head - 0)
        initial_head = 0
        
        for i in range(0, index):
            time += abs(initial_head-requests[i])
            initial_head = requests[i]
        
    else:
        print("Travelling in left direction....")
        for i in range(index-1, -1, -1):
            time += abs(initial_head-requests[i])
            initial_head = requests[i]
            
        if initial_head != 0:
            time += abs(initial_head-0)
            initial_head = 0
            
        time += abs(initial_head-tracks+1)
        initial_head = tracks - 1
        
        for i in range(len(requests)-1, index-1, -1):
            time += abs(initial_head-requests[i])
            initial_head = requests[i]
        
    print("Average Rotational Delay: ", avg_rotational_delay,"ms",sep =  '')
    return time

file = open("input.txt","r")

tracks = int(file.readline())
sectors = int(file.readline())
bps = int(file.readline())
RPM = float(file.readline())
seek_time = float(file.readline())
initial_head = int(file.readline())

request = [int(i) for i in file.readline().split()]

avg_rotational_delay = 30/RPM * 1000

time = FCFS(request,initial_head) * seek_time
print("Total Seek Time:",time)

time = C_SCAN(request,initial_head,tracks) * seek_time
print("Total Seek Time:",time)
