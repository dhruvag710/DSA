SELECT e.name AS Employee
FROM Employee e
JOIN Employee t
    ON e.managerId = t.id
WHERE e.salary > t.salary;