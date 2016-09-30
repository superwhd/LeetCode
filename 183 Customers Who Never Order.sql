# Write your MySQL query statement below
select  Name Customers
from  Customers 
where  Id not  in  (
    select  C.Id
    from  Customers C, Orders O
    where  C.Id =  O.CustomerId
)
