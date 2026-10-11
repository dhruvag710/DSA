-- Write your PostgreSQL query statement below
WITH rank_salary AS(
    SELECT salary,
    DENSE_RANK() OVER (ORDER BY salary DESC) AS ranks
    FROM employee
)

SELECT MAX(salary) AS SecondHighestSalary
FROM rank_salary
WHERE ranks=2
LIMIT 1;

