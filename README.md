# Restrained-Domination-Plynomial-
Restrained Domination Plynomial of cycle [BTP Project]
In algorithm 1 is brute force approach to compute the RDP of any graph, in which firstly we are finding all the possible subset for given number of vertices in a graph and for each subset checking weather the subset is satisfying the properties of restrained dominating set.

And in int_partition the program namede "cycle_algo" takes input n where n is the number of vertex in cycle, then for each integer n>k>=restrained domination number of C_n(\gamma_r(C_n)), it will calculate (n-k)/2 intiger partition of of k , then calculate the total number of circular arrangement possible for each partition, after this multiply this total number with n which gives the total number of restrained dominating set of cardinality k, and it is calculoating for all k between \gamma_r(C_n) and n
including \gamma_r(C_n), whiuch will finally result the RDP of C_n.

And the program in int_partition/cycle_coeff will take input n and k where n is number of vertex in cycle and k is coefficient of x^k in RPD of C_n ( input k means find total number of restrained dominating set with cardinality k ) and using the same above approach it will give output "total number of restrained dominating set with cardinality k"
