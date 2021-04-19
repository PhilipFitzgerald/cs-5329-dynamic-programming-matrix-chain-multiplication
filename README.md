# cs-5329-dynamic-programming-matrix-chain-multiplication

using the tabulation method found here: https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/

i modified it to also find and print the M and S tables related to matrix chain multiplication. Unforunately, the indexes of the pyramid M and S tables
(visually they are pyramids) are in reverse order. Instead of the left side being 1-6 from the bottom up, it is 6-1 and the same for the right side being in 
reverse. I also modified the code to print out the dimensions of the matrices being inserted, and did a comparison of the number of scalar multiplcations 
needed using dynamic programming vs not using dynamic programming (i did this portion of math by hand)
