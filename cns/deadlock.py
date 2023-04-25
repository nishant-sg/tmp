# Read the input file
with open('input.txt', 'r') as f:
    lines = f.readlines()

# Extract the number of resources and their instances
num_resources = int(lines[0])
resources = [int(x) for x in lines[1].split()]

# Extract the number of processes and their resource requirements
num_processes = int(lines[num_resources][:-1])
processes = []
for i in range(num_resources+2, num_resources+num_processes+2):
    p = [int(x) for x in lines[i].split()[:-1]]
    processes.append(p)

# Initialize the available resources and the allocation matrix
available = resources[:]
allocation = [[0 for j in range(num_resources)] for i in range(num_processes)]
for i in range(num_processes):
    for j in range(num_resources):
        allocation[i][j] = processes[i][j+1]

# Calculate the need matrix
need = [[0 for j in range(num_resources)] for i in range(num_processes)]
for i in range(num_processes):
    for j in range(num_resources):
        need[i][j] = processes[i][j+1]

# Initialize the work and finish arrays
work = available[:]
finish = [False for i in range(num_processes)]

# Perform the Banker's algorithm
safe = True
while True:
    # Find an unfinished process whose need can be satisfied with the available resources
    found = False
    for i in range(num_processes):
        if not finish[i]:
            can_allocate = True
            for j in range(num_resources):
                if need[i][j] > work[j]:
                    can_allocate = False
                    break
            if can_allocate:
                found = True
                finish[i] = True
                for j in range(num_resources):
                    work[j] += allocation[i][j]
                break
    if not found:
        # Check if all processes have finished
        if all(finish):
            safe = True
            break
        else:
            safe = False
            break

if safe:
    print("The system is in a safe state, so there is no deadlock.")
else:
    print("The system is in an unsafe state, so there is a possibility of deadlock.")