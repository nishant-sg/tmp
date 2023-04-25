def FCFS(requests, initial_head):
    print("\nFOR First Come First Serve")
    avg_rotational_delay = 30 / RPM
    print("Average Rotational Delay:", avg_rotational_delay, "ms")

    time = 0
    for i in requests:
        time += abs(initial_head - i)
        initial_head = i
    return time

def LOOK(requests, initial_head):
    print("\nFOR LOOK")
    avg_rotational_delay = 30 / RPM
    print("Average Rotational Delay:", avg_rotational_delay, "ms")

    requests.sort()
    index = requests.index(initial_head)

    time = 0
    if initial_head > requests[len(requests) - 1]:
        for i in range(index - 1, -1, -1):
            time += abs(initial_head - requests[i])
            initial_head = requests[i]
        for i in range(index, len(requests)):
            time += abs(initial_head - requests[i])
            initial_head = requests[i]
    elif initial_head < requests[0]:
        for i in range(index + 1, len(requests)):
            time += abs(initial_head - requests[i])
            initial_head = requests[i]
        for i in range(index, -1, -1):
            time += abs(initial_head - requests[i])
            initial_head = requests[i]
    else:
        for i in range(index, len(requests)):
            time += abs(initial_head - requests[i])
            initial_head = requests[i]
        for i in range(index - 1, -1, -1):
            time += abs(initial_head - requests[i])
            initial_head = requests[i]
    return time

file = open("C:/Users/91932/Desktop/test.txt", "r")

tracks = int(file.readline())
sectors = int(file.readline())
bps = int(file.readline())
RPM = float(file.readline())
seek_time = float(file.readline())
initial_head = int(file.readline())

requests = [int(i) for i in file.readline().split()]

time = FCFS(requests, initial_head) * seek_time
print("Total Seek Time (FCFS):", time, "ms")

time = LOOK(requests, initial_head) * seek_time
print("Total Seek Time (LOOK):", time, "ms")