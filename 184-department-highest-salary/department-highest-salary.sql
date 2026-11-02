WITH newTable as(
    SELECT departmentId, name, salary,
    RANK() OVER(PARTITION BY departmentId ORDER BY salary DESC) AS rankDep
    FROM employee
)

SELECT n.name as employee, n.salary, d.name as Department
FROM newTable as n
left join department as d
on n.departmentId=d.id
WHERE rankDep=1;