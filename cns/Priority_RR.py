'''
Write a C/Python program to simulate CPU scheduling. Following CPU scheduling mechanisms need to be implemented:
1. priority [using lottery scheduling]  (pre-emptive)
2. priority  [using lottery scheduling] (non-pre-emptive)
3. Round Robin

The process traces should be read from a file called "process.dat". Format for this file is as follows:
<number of processes>
<quantum-time>
<number of lottery-tickets>
<pid> <arrival time> <share> <cpu-burst> <io-burst> <cpu-burst> <io-burst> .... <-1>
...... 
<pid> <arrival time> <share> <cpu-burst> <io-burst> <cpu-burst> <io-burst> .... <-N>

So first line describes number of processes (say N).
Second line specify quantum.
Each of next N lines describe process id <pid> , time this process is put into ready queue <arrival time> . <share> means number of tickets assigned in lottery (proportional share) scheduling. <cpu-burst> shall be an integer value between [2 - 20]. <io-burst> shall be an integer value in range [25 - 100]

For Round Robin scheduling, quantum shall be as specified by second line.

Output should be process wise Gantt chart, CPU wise Gantt chart and system should output the following:
Turnaround Time : process-wise, total and average.
Waiting Time : process-wise, total and average.
Response Time : process-wise, total and average.
'''

# Non-Preemptive Priority Scheduling Algorithm
class Priority:
	def __init__(self, process, N, bt):
		self.process = []
		for temp in process:
			self.process.append(temp)
		self.scheduleProcesses(N, bt)
	
	def scheduleProcesses(self, N, bt):
		self.process.sort(key=lambda x:x[3], reverse=True)
		newProcesses = [x for x in self.process]
		st_time = []
		end_time = []
		s_time = 0
		for i in range(len(newProcesses)):
			st_time.append(s_time)
			s_time += newProcesses[i][2]
			e_time = s_time
			end_time.append(e_time)
			newProcesses[i].append(e_time)
		t_time = self.calculateTT(newProcesses)
		w_time = self.calculateWT(newProcesses)
		
		newProcesses.sort(key=lambda x:x[0])
		print("Processes  Burst_Time	Waiting_Time  Turn-Around_Time")
		total_wt = 0
		tatal_tat = 0
		for i in range(len(newProcesses)):
			print(" ", i + 1, "\t\t", bt[i],"\t\t", newProcesses[i][7], "\t\t", newProcesses[i][6])

		print("\nAverage waiting time = %.5f "%w_time )
		print("Average turn around time = %.5f "% t_time)
	
	def calculateTT(self, newProcesses):
		total_turnaround_time = 0
		for i in range(len(newProcesses)):
			turnaround_time = newProcesses[i][5] - newProcesses[i][3]
			total_turnaround_time += turnaround_time
			newProcesses[i].append(turnaround_time)
		att = total_turnaround_time / len(newProcesses)
		return att
	
	def calculateWT(self, newProcesses):
		twt = 0
		for i in range(len(newProcesses)):
			waiting_time = newProcesses[i][6] - newProcesses[i][3]
			twt += waiting_time
			newProcesses[i].append(waiting_time)
		awt = twt / len(newProcesses)
		return awt

# Round Robin Scheduling Algorithm
class RR:
	def findWaitingTime(self, proc, N, wt, quantum, bt):
		rem_bt = [0] * N

		for i in range(N):
			rem_bt[i] = bt[i]
			
		t = 0 
		while(1):
			done = True

			for i in range(N):
				if (rem_bt[i] > 0):
					done = False
					if (rem_bt[i] > quantum) :
						t += quantum
						rem_bt[i] -= quantum
					else:
						t = t + rem_bt[i]
						wt[i] = t - bt[i]
						rem_bt[i] = 0
			if (done == True):
				break
			
	def findTurnAroundTime(self, proc, N, wt, tat, bt):
		for i in range(N):
			tat[i] = bt[i] + wt[i]


	def Round_Robin(self,N, quantum, proc, bt):
		wt = [0]*N
		tat = [0]*N
		
		self.findWaitingTime(proc, N, wt, quantum, bt)

		self.findTurnAroundTime(proc, N, wt, tat, bt)
		
		print("Processes  Burst_Time	Waiting_Time  Turn-Around_Time")
		total_wt = 0
		total_tat = 0
		for i in range(N):
			total_wt = total_wt + wt[i]
			total_tat = total_tat + tat[i]
			print(" ", i + 1, "\t\t", bt[i],"\t\t", wt[i], "\t\t", tat[i])

		print("\nAverage waiting time = %.5f "%(total_wt /N) )
		print("Average turn around time = %.5f "% (total_tat / N))

proc = []
N = 0
quantum = 0
with open('process.dat') as f:
	N = int(f.readline())
	quantum = int(f.readline())
	tickets = int(f.readline())
	for i in range(N):
		proc.append([int(x) for x in f.readline().split(" ")])
		
burst_time = []
for i in range(N):
	burst_time.append(proc[i][3])
	
print("\nROUND ROBIN:")
rr = RR()
rr.Round_Robin(N,quantum,proc,burst_time)

print("\nPRIORITY NON-PREEMPTIVE:")
np = Priority(proc, N, burst_time)
