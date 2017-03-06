//This is a readme file describing the questions//


Q.no.5-

The plot of time calculated using the clock function for mergesort vs the ((nlogn)/10000000) axis is a straight line with slope 5.6228 and intercept of -0.3495. which proves that it is approximately a staight line. The y-intercept being close to 0 signifies that 0 time will be taken for no input. The x-axis has been reduced so as to form the graph and compress it for visibility. The graph is present in the shared folder.

Q.no.6-

Applying multithreading recursively doesn't seem a good idea as the number of threads keep increasing but we don't have that many number of cores to run all those threads parallely.. So, rather since we have 4 cores in a CPU in my laptop, so I divided the initial mergesort into 4 parallel threads which are all mutually exclusive,and thus it uses all the 4 cores and thus reduces the time. Then i applied merge to 2 threads at a time requiring 2 processors, and then the final merging was conducted. 
