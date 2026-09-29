# About this

This is the Minimum cut of the proton-sde model which can generate
cross-reference data for a different implementation of particle
advance and tracking.

For simplicity, it dumps C++ code containing the data which can
be pasted into your test. This is to avoid needing to synchronise
data files for such a small sub-set of numbers.

## What's the gsl subdirectory for?

We want exact reproducibility between this code and whatever other
implementation we might be looking at. Thus, we need a 'mock' RNG
that can simply spit out a pre-determined sequence of numbers. 

See also the file "example\_prn.cpp" showing one way to implement
the equivalent using a free function.

Make sure NOT to load the gsl library, which is not needed for anything else
in this cut-down version, to avoid confusing errors. 
