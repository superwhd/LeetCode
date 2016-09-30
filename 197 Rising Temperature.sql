# Write your MySQL query statement below
select  W2.Id
from  Weather W1, Weather W2
where  W2.Temperature >  W1.Temperature 
and  DATEDIFF(W2.Date, W1.Date) =  1
