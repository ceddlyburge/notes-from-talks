import pandas as pd
from random import randint
import string

s = pd.Series(range(6), index = list('abcdef'))
df = pd.concat([s, u], axis = 1)

x = df['letter']

u = pd.Series(range(10))
v = pd.Series(list('abcdefghij'))
pd.concat([u,v],axis = 1) # creates a dataframe from series
pd.concat([u,v],axis = 1, keys=['u', 'v']) # keys are the column heaaders

#filtering
r1 = pd.Series([randint(1, 10) for _ in range(10)])
r2 = pd.Series([randint(1, 10) for _ in range(10)])
r1[r1 > 3] # values in r1 that are bigger than 3
r1[r2 > 3] # values in r1 where the corresponding value in r2 > 3
r2 > 3 # returns a list or bools
r1[r1 > r2] # returns r1 where bigger than the corresponding r2

# Using series with an identical index is a valid technique, instead of using a dataframe. Can do the same thing to work with data frames, as long as the indexes are still the same.
# order of items in series / dataframe is not important, the index is

r1[[True, False]* 5] # returns every other value in r1 (select alternate rows)
# can do similar things to pick a random 20% of the series

# duplicates causes problems, but do work on order (I think) so as long as you don't change th order it will probably still work.

# Can filter a data frame with series
s = pd.Series('blah')
S = pd.Series('blAh')
df = pd.concat([s, S], axis=1, keys=['col1', 'col2'])
df[s != S] # where df is a dataframe generaated from s and S above
# tis is equivalent to
df[df['col1'] != df['col2']]

#groupby can work in the same way as filtering (normally you specify a column I think)
s.groupby[[True, False]* 5] # groups s by alternating values
