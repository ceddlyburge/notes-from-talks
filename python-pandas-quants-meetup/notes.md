# Full Stack Quants Meetup - Royal Road to Python Pandas magic

http://fullstackquants.org/meetings/
http://fullstackquants.org/data-science-meets-poker/

Start working with a series, which is conceptually a list. Then move on to DataFrame's, which are conceptually a list of tuples.

A data fram is just a collection of series

Series are like lists but
- Filtering / selecting
- Summaries like describe
- Group By
- Boolean summaries: Any / All (u  == v).all(), (u > 3).any()
- handling duplicates
- NaN handling fill
- rolling: u.rolling(2, min_periods=1).sum(). creates a rolling sum of 2 adjacent items. Min periods means that the first value gets calculated, even though it doesn't have 2 things to sum yet
- shifting
- time series and resampling

for x in series print x // prints series values
for x in series.index print x // prints series keys / index

for x in dataframe print x // prints column headings
for x in dataframe print dataframe[x] // prints column values

# resampling
create a list of dates
idx = pd.DatetimeIndexx(start='2017-05-01', end='2017-06-01',freq='d')
can then add a series with some random values
then resample in to weeks

# data frames

can have multi value index