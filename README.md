# MP2
## Running Executable
### Used the recommended compilation by the instructor. 
nasm -f win64 saxpy.asm <br />
gcc -c MP2c.c -o MP2c.obj -m64 <br />
gcc MP2c.obj saxpy.obj -o MP2c.exe -m64 <br />
MP2c.exe<br />  

## Comparative Result
### Due to the recommendation by the instructor, we can get the comparative execution time by running it for 30 times.
### Array Size = 3, A value = 3, x and y values = respectively 1,2,3 for the x, 11, 12, 13 for the y.
### Calcation: <br/>
0.000027000
0.000028000
0.000028000
0.000028000
0.000029000
0.000028000
0.000028000
0.000028000
0.000028000
0.000042000
0.000028000
0.000044000
0.000028000
0.000028000
0.000028000
0.000028000
0.000028000
0.000043000
0.000028000
0.000028000
0.000028000
0.000028000
0.000051000
0.000042000
0.000029000
0.000042000
0.000028000
0.000028000
0.000028000
0.000028000
= 0.00093900 Average time execution 

## Result Analysis

In a separation test case input we have input the same length and vector, but different array data,
but only with a sample size of 7. When random data was input, all of the time taken to be executed was different
but with the same sets of data that were run 30 times, the same amount of time it was executed was seen, specifically 0.00028000.

## Correctness Check

![Correctness Check](https://github.com/user-attachments/assets/d742dc1f-6e79-41da-9d23-1802970a6955) <br/> Array Size = 3, A value = 3, x and y values = respectively 1,2,3 for the x, 11, 12, 13 for the y.

![Correcnesst Check  2](https://github.com/user-attachments/assets/b75f5172-8565-408a-898c-c0cb5f4023bf) <br/> Array Size = 10, A value = 3, x and y values = 1,2,3,4,5,6,7,8,9,10 and 11,12,13,14,15,16,17,18,19,20

![Correcnesst Check  2](https://github.com/user-attachments/assets/6dc67add-d324-4cc1-9746-7030657e189e) <br/> Manual Checking of the 2 previous inputs. 

