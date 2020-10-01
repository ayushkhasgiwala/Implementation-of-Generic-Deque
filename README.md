# Implementation-of-Generic-Deque

## What is deque?

a)  Deque is the same as dynamic arrays with the ability to resize
itself automatcally when an element is inserted or deleted, with
their storage being handled automatcally by the container.

b) They support inserton and Deleton from both ends in amortzed
constant tme.

c)  Insertng and erasing in the middle is linear in tme.


## Expectations

Implementaton of deque must satsfy the following performance
requirements

a) deque() - initalize a blank deque.-  `O(1)`

b) deque(n,x) - initalize a deque of length n with all values as x. - `O(1)` 

c) push_back(x) - append data x at the end.- `amortized O(1)`

d) pop_back() - erase data at the end. - `amortized O(1)`

d) push_front(x) - append data x at the beginning.- `amortized O(1)`

e) pop_front() - erase data at the beginning. - `amortized O(1)`

f) front() - returns the frst element(value) in the deque. - `O(1)`

g) back() - returns the last element(value) in the deque. - `O(1)`

h) empty() - returns true if deque is empty else returns false. - `O(1)`

i) size() - returns the current size of deque. - `O(1)`
 
j) resize(x) - changes the size dynamically. -`O(n)`

k) clear() - remove all elements of deque. - `O(1)`

l) D[n] - returns the nth element of the deque. - `O(1)`
