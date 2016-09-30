# Write your MySQL query statement below
select  distinct  L1.Num ConsecutiveNums
from  Logs  L1
where  3 =  (select  count (*) from  Logs  where  L1.Id -  3 <  Id and  Id <=  L1.Id)
    and  L1.Num =  all  (
    select  Num
    from  Logs 
    where  L1.Id -  3 <  Id and  Id <=  L1.Id
)
