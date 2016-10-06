# Write your MySQL query statement below
select D.Name Department, E.Name Employee, E.Salary
from Department D, Employee E
where D.Id = E.DepartmentId and 3 > (
    select count(distinct E1.Salary)
    from Department D1, Employee E1
    where D1.Id = E1.DepartmentId and D.Id = D1.Id and E.Salary < E1.Salary
    );
