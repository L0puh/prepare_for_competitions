"""
Given an array of jobs where every job has a deadline
and associated profit if the job is finished before the deadline. 
It is also given that every job takes a single unit of time, 
so the minimum possible deadline for any job is 1.  Maximize the total profit if only one job can be scheduled at a time.

# Examples: 

Input: Four Jobs with following deadlines and profits

JobID  Deadline  Profit

  a           4          20   
  b           1          10
  c           1          40  
  d           1          30

Output: Following is maximum profit sequence of jobs: c, a   

Input:  Five Jobs with following deadlines and profits

JobID   Deadline  Profit

  a            2          100
  b            1          19
  c            2          27
  d            1          25
  e            3          15

Output: Following is maximum profit sequence of jobs: c, a, e

"""


jobs= [['a', 2, 100],  # Job Array
       ['b', 1, 19],
       ['c', 2, 27],
       ['d', 1, 25],
       ['e', 3, 15]]


def main():
    # actually don't work properly...
    jobs.sort(key=lambda x: x[2], reverse=True) #sort based on profit 
                                                # decresed 
    a = max(jobs, key=lambda x: x[1])[1] # maximum deadline (size
                                         # an array essentially)
    solutions = [0] * a
    job = []
    for i in range(len(jobs)):
        #find a free slot for this job 
        m = min(a-1, jobs[i][1]-1)
        for j in range(m, -1, -1):
            if solutions[j] == 0:
                solutions[j] = 1
                job.append(jobs[i][0])
                break
    print(job)


main()
