#include <bits/stdc++.h>
using namespace std;

/*
So what are bloom filters?
It is just an efficient method to use k hashes and m bits to check if an id exists in a software. 
It will tell you if it doesn't exist with 100% certainty.  While it will sometimes say it could exist if it matches
with anothe hash.  But the point it to avoid unecssary calls to check the record id in database or whatever that
may be computational expensive.  

This is apparently used in Apache Cassandra, may want to look into how it it used that would be interesting for system
design and algorithms.  

TODO:  Research more on this related to Apache Cassandra
*/