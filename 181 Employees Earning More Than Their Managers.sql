# Write your MySQL query statement below
select  E1.Name Employee
from  Employee E1, Employee E2
where  E1.Salary >  E2.Salary and  E1.ManagerId =  E2.Id

