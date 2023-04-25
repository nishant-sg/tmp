import java.io.*;
import java.util.*;

public class _2020UCP1778_1 {

    static class Process {
        int pid;
        int priority;
        int arrivalTime;
        int[] bursts;

        public Process(int pid, int priority, int arrivalTime, int[] bursts) {
            this.pid = pid;
            this.priority = priority;
            this.arrivalTime = arrivalTime;
            this.bursts = bursts;
        }
    }

    static public class Scheduler {
        static List<Process> processList = new ArrayList<>();
        static int quantum;

        Scheduler() throws Exception {
            // Read data from input.dat file
            BufferedReader reader = new BufferedReader(new FileReader("input.dat"));
            int numProcesses = Integer.parseInt(reader.readLine());
            quantum = Integer.parseInt(reader.readLine());

            // Read information for each process
            for (int i = 0; i < numProcesses; i++) {
                String[] processInfo = reader.readLine().split(" ");
                int pid = Integer.parseInt(processInfo[0]);
                int priority = Integer.parseInt(processInfo[1]);
                int arrivalTime = Integer.parseInt(processInfo[2]);

                // Read bursts for the process
                List<Integer> bursts = new ArrayList<>();
                for (int j = 4; j < processInfo.length; j++) {
                    if (processInfo[j].equals("I") || processInfo[j].equals("O")) {
                        continue;
                    } else if (processInfo[j].equals("-1")) {
                        break;
                    } else {
                        bursts.add(Integer.parseInt(processInfo[j]));
                    }
                }

                // Create process object and add to the list
                int[] burstsArray = new int[bursts.size()];
                for (int j = 0; j < bursts.size(); j++) {
                    burstsArray[j] = bursts.get(j);
                }
                processList.add(new Process(pid, priority, arrivalTime, burstsArray));
            }

            reader.close();

            // FCFS scheduling
            fcfs();

            // SJF scheduling
            sjf();
        }

        public static void fcfs() {
            System.out.println("FCFS Scheduling:");

            int[] turnaroundTime = new int[processList.size()];
            int[] responseTime = new int[processList.size()];
            int[] waitingTime = new int[processList.size()];

            int currentTime = 0;

            for (int i = 0; i < processList.size(); i++) {
                Process p = processList.get(i);

                // Calculate waiting time for the process
                waitingTime[i] = currentTime - p.arrivalTime;

                // Calculate response time for the process
                responseTime[i] = currentTime - p.arrivalTime;

                // Calculate turnaround time for the process
                turnaroundTime[i] = waitingTime[i] + p.bursts[0];

                // Update the current time
                currentTime += p.bursts[0];

            }

            // Calculate average turnaround time, response time, and waiting time
            double avgTurnaroundTime = 0;
            double avgResponseTime = 0;
            double avgWaitingTime = 0;

            for (int i = 0; i < processList.size(); i++) {
                avgTurnaroundTime += turnaroundTime[i];
                avgResponseTime += responseTime[i];
                avgWaitingTime += waitingTime[i];
            }

            avgTurnaroundTime /= processList.size();
            avgResponseTime /= processList.size();
            avgWaitingTime /= processList.size();

            // Print out the values
            for (int i = 0; i < processList.size(); i++) {
                Process p = processList.get(i);
                System.out.println("Process " + p.pid);
                System.out.println("Turnaround Time: " + turnaroundTime[i] + ", " + "Average Turnaround Time: "
                        + avgTurnaroundTime);
                System.out.println(
                        "Response Time: " + responseTime[i] + ", " + "Average Response Time: " + avgResponseTime);
                System.out
                        .println("Waiting Time: " + waitingTime[i] + ", " + "Average Waiting Time: " + avgWaitingTime);
            }
        }

        public static void sjf() {
            System.out.println();
            System.out.println("SJF Scheduling:");

            int[] turnaroundTime = new int[processList.size()];
            int[] responseTime = new int[processList.size()];
            int[] waitingTime = new int[processList.size()];

            int currentTime = 0;

            // Copy the process list to a new list to maintain the original order
            List<Process> processes = new ArrayList<>(processList);

            // Sort the new list by process burst time
            Collections.sort(processes, (p1, p2) -> Integer.compare(p1.bursts[0], p2.bursts[0]));

            for (int i = 0; i < processes.size(); i++) {
                Process p = processes.get(i);

                // Calculate waiting time for the process
                waitingTime[i] = currentTime - p.arrivalTime;

                // Calculate response time for the process
                responseTime[i] = currentTime - p.arrivalTime;

                // Calculate turnaround time for the process
                turnaroundTime[i] = waitingTime[i] + p.bursts[0];

                // Update the current time
                currentTime += p.bursts[0];
            }

            // Calculate average turnaround time, response time, and waiting time
            double avgTurnaroundTime = 0;
            double avgResponseTime = 0;
            double avgWaitingTime = 0;

            for (int i = 0; i < processList.size(); i++) {
                avgTurnaroundTime += turnaroundTime[i];
                avgResponseTime += responseTime[i];
                avgWaitingTime += waitingTime[i];
            }

            avgTurnaroundTime /= processList.size();
            avgResponseTime /= processList.size();
            avgWaitingTime /= processList.size();

            // Print out the values
            for (int i = 0; i < processList.size(); i++) {
                Process p = processList.get(i);
                System.out.println("Process " + p.pid);
                System.out.println("Turnaround Time: " + turnaroundTime[i] + ", " + "Average Turnaround Time: "
                        + avgTurnaroundTime);
                System.out.println(
                        "Response Time: " + responseTime[i] + ", " + "Average Response Time: " + avgResponseTime);
                System.out
                        .println("Waiting Time: " + waitingTime[i] + ", " + "Average Waiting Time: " + avgWaitingTime);
            }
        }
    }

    public static void main(String args[]) throws Exception {
        Scheduler sch = new Scheduler();
    }
}
