from queue import deque
class Node:
   def __init__(self, value, child = None) -> None:
      self.val = value
      self.children = []

def printNTree(x,flag,depth,isLast):
    # Condition when node is None
    if x == None:
        return
       
    # Loop to print the depths of the
    # current node
    for i in range(1, depth):
        # Condition when the depth
        # is exploring
        if flag[i]:
            print("| ","", "", "", end = "")
           
        # Otherwise print
        # the blank spaces
        else:
            print(" ", "", "", "", end = "")
       
    # Condition when the current
    # node is the root node
    if depth == 0:
        print(x.val)
       
    # Condition when the node is
    # the last node of
    # the exploring depth
    elif isLast:
        print("+---", x.val)
           
        # No more childrens turn it
        # to the non-exploring depth
        flag[depth] = False
    else:
        print("+---", x.val)
   
    it = 0
    for i in x.children:
        it+=1
         
        # Recursive call for the
        # children nodes
        printNTree(i, flag, depth + 1, it == (len(x.children) - 1))
    flag[depth] = True

main = Node(0)
print("\n\nParent process creared with id: 0")
printNTree(main,[True],0,False)
print("\n\n")
process = [main]
while True:
	print("1. Create a child process")
	print("2. Delete a process")
	print("3. Show process")
	print("4. Exit")
	ch = int(input("Enter choice: "))
	
	if (ch==1):
		pid = int(input("Enter process id: "))
		ppid = int(input("Enter parent id: "))
		child = Node(pid)
		process.append(child)
		for i in process:
			if i.val == ppid:
				i.children.append(child)
				
	elif (ch==2):
		pid = int(input("Enter process id: "))
		for i in process:
			for j in i.children:
				if pid == j.val:
					i.children.remove(j)
					process.remove(i)
					break
	elif (ch==3):
		flag = [True]*(len(process))
		print()
		printNTree(main,flag,0,False)
		print("\n\n")
	else:
		break

