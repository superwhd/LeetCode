# Write your MySQL query statement below
select D.Name Department, E.Name Employee, E.Salary
from Employee E, Department D
where E.DepartmentId = D.Id and E.Salary = 
    (
        select max(Salary)
        from Employee E2
        where E2.DepartmentId = E.DepartmentId
    )
