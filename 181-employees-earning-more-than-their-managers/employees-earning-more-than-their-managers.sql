WITH newTable as(
    select e.id, e.name, e.salary, e.managerId, t.name as managerName, t.salary as managerSalary
    from employee as e
    left join employee as t
    on e.managerId=t.id
)

SELECT name as Employee
from newTable
where salary>managerSalary;
